#include "evaluate.h"
#include <stdlib.h>
#include <string.h>

// 评估抄袭情况
PlagiarismResult evaluate_plagiarism(double similarity) {
    PlagiarismResult result;
    result.similarity = similarity;
    
    // 定义多个阈值标准（调整后更严格，避免误判功能不同但结构相似的代码）
    // 标准1：严格标准（阈值0.95）- 几乎完全相同，高度疑似抄袭
    // 标准2：中等标准（阈值0.85）- 高度相似，需要人工审核
    // 标准3：宽松标准（阈值0.7）- 中度相似，可能存在相似性
    // 低于0.7：不相似，功能或结构差异较大
    
    if (similarity >= 0.95) {
        result.is_plagiarized = 1;
        result.level = "高度相似（严格标准：>=0.95）";
    } else if (similarity >= 0.85) {
        result.is_plagiarized = 1;
        result.level = "高度相似（中等标准：>=0.85）";
    } else if (similarity >= 0.7) {
        result.is_plagiarized = 1;
        result.level = "中度相似（宽松标准：>=0.7）";
    } else {
        result.is_plagiarized = 0;
        result.level = "不相似（所有标准：<0.7）";
    }
    
    return result;
}

