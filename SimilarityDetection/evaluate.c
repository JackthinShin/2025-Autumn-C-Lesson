#include "evaluate.h"
#include <stdlib.h>
#include <string.h>

// 评估抄袭情况
PlagiarismResult evaluate_plagiarism(double similarity) {
    PlagiarismResult result;
    result.similarity = similarity;
    
    // 定义多个阈值标准
    // 标准1：严格标准（阈值0.8）
    // 标准2：中等标准（阈值0.6）
    // 标准3：宽松标准（阈值0.4）
    
    if (similarity >= 0.8) {
        result.is_plagiarized = 1;
        result.level = "高度相似（严格标准：>=0.8）";
    } else if (similarity >= 0.6) {
        result.is_plagiarized = 1;
        result.level = "中度相似（中等标准：>=0.6）";
    } else if (similarity >= 0.4) {
        result.is_plagiarized = 1;
        result.level = "低度相似（宽松标准：>=0.4）";
    } else {
        result.is_plagiarized = 0;
        result.level = "不相似（所有标准：<0.4）";
    }
    
    return result;
}

