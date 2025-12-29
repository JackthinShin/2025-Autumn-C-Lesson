#ifndef SIMILARITY_H
#define SIMILARITY_H

#include "tokenize.h"

// 计算两个标记序列的余弦相似度
double calculate_cosine_similarity(StringArray *tokens1, StringArray *tokens2);

#endif // SIMILARITY_H

