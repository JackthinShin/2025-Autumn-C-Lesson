#include <stdio.h>
#include <stdlib.h>
#include "preprocess.h"
#include "tokenize.h"
#include "similarity.h"
#include "evaluate.h"
#include "utils.h"

// 打印使用说明
void print_usage(const char *program_name) {
    printf("程序代码相似度检测系统\n");
    printf("使用方法: %s <文件1> <文件2>\n", program_name);
    printf("\n功能说明:\n");
    printf("  1. 代码预处理：去除注释、头文件、字符串、空格和空行\n");
    printf("  2. 代码转换：将代码转换为标记序列\n");
    printf("  3. 相似度计算：使用余弦相似度算法计算相似度\n");
    printf("  4. 抄袭评估：根据多个阈值标准判断是否抄袭\n");
    printf("\n示例:\n");
    printf("  %s code1.c code2.c\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }
    
    const char *file1 = argv[1];
    const char *file2 = argv[2];
    
    printf("========================================\n");
    printf("   程序代码相似度检测系统\n");
    printf("========================================\n\n");
    
    // 读取文件1
    printf("[1/5] 读取文件1: %s\n", file1);
    char *code1 = read_file(file1);
    if (!code1) {
        fprintf(stderr, "错误: 无法读取文件 %s\n", file1);
        return 1;
    }
    printf("      文件1大小: %zu 字节\n", strlen(code1));
    
    // 读取文件2
    printf("[2/5] 读取文件2: %s\n", file2);
    char *code2 = read_file(file2);
    if (!code2) {
        fprintf(stderr, "错误: 无法读取文件 %s\n", file2);
        free(code1);
        return 1;
    }
    printf("      文件2大小: %zu 字节\n", strlen(code2));
    
    // 预处理代码1
    printf("[3/5] 预处理代码1...\n");
    char *processed1 = preprocess_code(code1);
    if (!processed1) {
        fprintf(stderr, "错误: 代码1预处理失败\n");
        free(code1);
        free(code2);
        return 1;
    }
    printf("      预处理后大小: %zu 字节\n", strlen(processed1));
    
    // 预处理代码2
    printf("[3/5] 预处理代码2...\n");
    char *processed2 = preprocess_code(code2);
    if (!processed2) {
        fprintf(stderr, "错误: 代码2预处理失败\n");
        free(code1);
        free(code2);
        free(processed1);
        return 1;
    }
    printf("      预处理后大小: %zu 字节\n", strlen(processed2));
    
    // 转换为标记序列
    printf("[4/5] 转换代码1为标记序列...\n");
    StringArray *tokens1 = tokenize_code(processed1);
    if (!tokens1) {
        fprintf(stderr, "错误: 代码1标记化失败\n");
        free(code1);
        free(code2);
        free(processed1);
        free(processed2);
        return 1;
    }
    printf("      标记数量: %zu\n", tokens1->count);
    
    printf("[4/5] 转换代码2为标记序列...\n");
    StringArray *tokens2 = tokenize_code(processed2);
    if (!tokens2) {
        fprintf(stderr, "错误: 代码2标记化失败\n");
        free(code1);
        free(code2);
        free(processed1);
        free(processed2);
        string_array_free(tokens1);
        return 1;
    }
    printf("      标记数量: %zu\n", tokens2->count);
    
    // 计算相似度
    printf("[5/5] 计算余弦相似度...\n");
    double similarity = calculate_cosine_similarity(tokens1, tokens2);
    
    // 评估抄袭情况
    PlagiarismResult result = evaluate_plagiarism(similarity);
    
    // 输出结果
    printf("\n========================================\n");
    printf("           检测结果\n");
    printf("========================================\n");
    printf("相似度值: %.4f (%.2f%%)\n", similarity, similarity * 100);
    printf("评估结果: %s\n", result.level);
    printf("是否抄袭: %s\n", result.is_plagiarized ? "是" : "否");
    printf("\n阈值标准说明:\n");
    printf("  - 严格标准: >= 0.95 (几乎完全相同，高度疑似抄袭)\n");
    printf("  - 中等标准: >= 0.85 (高度相似，需要人工审核)\n");
    printf("  - 宽松标准: >= 0.7 (中度相似，可能存在相似性)\n");
    printf("  - 不相似:   < 0.7 (功能或结构差异较大)\n");
    printf("========================================\n");
    
    // 清理资源
    free(code1);
    free(code2);
    free(processed1);
    free(processed2);
    string_array_free(tokens1);
    string_array_free(tokens2);
    
    return 0;
}

