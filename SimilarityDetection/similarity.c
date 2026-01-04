#include "similarity.h"
#include <math.h>
#include <string.h>

// 词频向量结构
typedef struct {
    char **words;
    int *freqs;
    int count;
    int capacity;
} WordFreqVector;

// 生成2-gram序列（token对）
static StringArray* generate_bigrams(StringArray *tokens) {
    if (!tokens || tokens->count < 2) return NULL;
    
    StringArray *bigrams = string_array_create();
    if (!bigrams) return NULL;
    
    for (size_t i = 0; i < tokens->count - 1; i++) {
        // 创建bigram字符串: "token1|token2"
        size_t len1 = strlen(tokens->items[i]);
        size_t len2 = strlen(tokens->items[i + 1]);
        char *bigram = (char*)malloc(len1 + len2 + 2); // +2 for '|' and '\0'
        if (!bigram) {
            string_array_free(bigrams);
            return NULL;
        }
        sprintf(bigram, "%s|%s", tokens->items[i], tokens->items[i + 1]);
        string_array_add(bigrams, bigram);
        free(bigram);
    }
    
    return bigrams;
}

// 创建词频向量
static WordFreqVector* create_word_freq_vector(StringArray *tokens) {
    WordFreqVector *vec = (WordFreqVector*)malloc(sizeof(WordFreqVector));
    if (!vec) return NULL;
    
    vec->capacity = tokens->count * 2;
    vec->count = 0;
    vec->words = (char**)malloc(vec->capacity * sizeof(char*));
    vec->freqs = (int*)malloc(vec->capacity * sizeof(int));
    
    if (!vec->words || !vec->freqs) {
        free(vec->words);
        free(vec->freqs);
        free(vec);
        return NULL;
    }
    
    // 统计词频
    for (size_t i = 0; i < tokens->count; i++) {
        int found = 0;
        for (int j = 0; j < vec->count; j++) {
            if (strcmp(vec->words[j], tokens->items[i]) == 0) {
                vec->freqs[j]++;
                found = 1;
                break;
            }
        }
        
        if (!found) {
            if (vec->count >= vec->capacity) {
                vec->capacity *= 2;
                vec->words = (char**)realloc(vec->words, vec->capacity * sizeof(char*));
                vec->freqs = (int*)realloc(vec->freqs, vec->capacity * sizeof(int));
            }
            vec->words[vec->count] = (char*)malloc(strlen(tokens->items[i]) + 1);
            strcpy(vec->words[vec->count], tokens->items[i]);
            vec->freqs[vec->count] = 1;
            vec->count++;
        }
    }
    
    return vec;
}

// 释放词频向量
static void free_word_freq_vector(WordFreqVector *vec) {
    if (vec) {
        for (int i = 0; i < vec->count; i++) {
            free(vec->words[i]);
        }
        free(vec->words);
        free(vec->freqs);
        free(vec);
    }
}

// 获取词频
static int get_word_freq(WordFreqVector *vec, const char *word) {
    for (int i = 0; i < vec->count; i++) {
        if (strcmp(vec->words[i], word) == 0) {
            return vec->freqs[i];
        }
    }
    return 0;
}

// 计算两个词频向量的余弦相似度（辅助函数）
static double cosine_similarity_vectors(WordFreqVector *vec1, WordFreqVector *vec2) {
    if (!vec1 || !vec2) return 0.0;
    if (vec1->count == 0 && vec2->count == 0) return 1.0;
    if (vec1->count == 0 || vec2->count == 0) return 0.0;
    
    // 计算点积和向量模长
    double dot_product = 0.0;
    double norm1 = 0.0;
    double norm2 = 0.0;
    
    // 计算vec1的模长
    for (int i = 0; i < vec1->count; i++) {
        double freq = (double)vec1->freqs[i];
        norm1 += freq * freq;
    }
    norm1 = sqrt(norm1);
    
    // 计算vec2的模长
    for (int i = 0; i < vec2->count; i++) {
        double freq = (double)vec2->freqs[i];
        norm2 += freq * freq;
    }
    norm2 = sqrt(norm2);
    
    // 计算点积（遍历所有词）
    for (int i = 0; i < vec1->count; i++) {
        int freq1 = vec1->freqs[i];
        int freq2 = get_word_freq(vec2, vec1->words[i]);
        dot_product += (double)freq1 * (double)freq2;
    }
    
    // 计算余弦相似度
    if (norm1 == 0.0 || norm2 == 0.0) {
        return 0.0;
    }
    
    return dot_product / (norm1 * norm2);
}

// 计算余弦相似度（改进版：结合1-gram和2-gram）
double calculate_cosine_similarity(StringArray *tokens1, StringArray *tokens2) {
    if (!tokens1 || !tokens2) return 0.0;
    if (tokens1->count == 0 && tokens2->count == 0) return 1.0;
    if (tokens1->count == 0 || tokens2->count == 0) return 0.0;
    
    // 1. 计算1-gram（单个token）的相似度
    WordFreqVector *vec1_1gram = create_word_freq_vector(tokens1);
    WordFreqVector *vec2_1gram = create_word_freq_vector(tokens2);
    
    double similarity_1gram = 0.0;
    if (vec1_1gram && vec2_1gram) {
        similarity_1gram = cosine_similarity_vectors(vec1_1gram, vec2_1gram);
    }
    free_word_freq_vector(vec1_1gram);
    free_word_freq_vector(vec2_1gram);
    
    // 2. 计算2-gram（token对）的相似度
    StringArray *bigrams1 = generate_bigrams(tokens1);
    StringArray *bigrams2 = generate_bigrams(tokens2);
    
    double similarity_2gram = 0.0;
    if (bigrams1 && bigrams2 && bigrams1->count > 0 && bigrams2->count > 0) {
        WordFreqVector *vec1_2gram = create_word_freq_vector(bigrams1);
        WordFreqVector *vec2_2gram = create_word_freq_vector(bigrams2);
        
        if (vec1_2gram && vec2_2gram) {
            similarity_2gram = cosine_similarity_vectors(vec1_2gram, vec2_2gram);
        }
        free_word_freq_vector(vec1_2gram);
        free_word_freq_vector(vec2_2gram);
    } else if (bigrams1 && bigrams2 && bigrams1->count == 0 && bigrams2->count == 0) {
        // 如果两个都没有2-gram（token数量<2），2-gram相似度设为1.0
        similarity_2gram = 1.0;
    }
    
    string_array_free(bigrams1);
    string_array_free(bigrams2);
    
    // 3. 加权组合：2-gram权重0.8，1-gram权重0.2
    // 这样更关注token序列的模式，而不仅仅是token频次
    // 提高2-gram权重可以更好地区分功能不同但结构相似的代码
    double final_similarity = 0.8 * similarity_2gram + 0.2 * similarity_1gram;
    
    return final_similarity;
}

