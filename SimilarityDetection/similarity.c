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

// 计算余弦相似度
double calculate_cosine_similarity(StringArray *tokens1, StringArray *tokens2) {
    if (!tokens1 || !tokens2) return 0.0;
    if (tokens1->count == 0 && tokens2->count == 0) return 1.0;
    if (tokens1->count == 0 || tokens2->count == 0) return 0.0;
    
    // 创建词频向量
    WordFreqVector *vec1 = create_word_freq_vector(tokens1);
    WordFreqVector *vec2 = create_word_freq_vector(tokens2);
    
    if (!vec1 || !vec2) {
        free_word_freq_vector(vec1);
        free_word_freq_vector(vec2);
        return 0.0;
    }
    
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
    // 合并所有唯一的词
    for (int i = 0; i < vec1->count; i++) {
        int freq1 = vec1->freqs[i];
        int freq2 = get_word_freq(vec2, vec1->words[i]);
        dot_product += (double)freq1 * (double)freq2;
    }
    
    // 释放资源
    free_word_freq_vector(vec1);
    free_word_freq_vector(vec2);
    
    // 计算余弦相似度
    if (norm1 == 0.0 || norm2 == 0.0) {
        return 0.0;
    }
    
    return dot_product / (norm1 * norm2);
}

