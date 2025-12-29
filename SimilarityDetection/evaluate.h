#ifndef EVALUATE_H
#define EVALUATE_H

// 抄袭评估结果
typedef struct {
    double similarity;      // 相似度值 (0.0 - 1.0)
    int is_plagiarized;     // 是否抄袭 (1=是, 0=否)
    const char *level;      // 抄袭等级描述
} PlagiarismResult;

// 评估抄袭情况
PlagiarismResult evaluate_plagiarism(double similarity);

#endif // EVALUATE_H

