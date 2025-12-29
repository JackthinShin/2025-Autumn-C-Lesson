#include "tokenize.h"
#include <ctype.h>
#include <string.h>

// C语言关键字列表
static const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

#define KEYWORD_COUNT (sizeof(keywords) / sizeof(keywords[0]))

// 运算符和分隔符
static const char *operators[] = {
    "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=",
    "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", "++", "--",
    "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=",
    "->", ".", "?", ":", ",", ";", "(", ")", "[", "]", "{", "}"
};

#define OPERATOR_COUNT (sizeof(operators) / sizeof(operators[0]))

// 检查是否是关键字
static int is_keyword(const char *word) {
    for (size_t i = 0; i < KEYWORD_COUNT; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// 检查是否是运算符（从最长到最短匹配）
static int match_operator(const char *code, int pos, int *len) {
    for (size_t i = 0; i < OPERATOR_COUNT; i++) {
        int op_len = strlen(operators[i]);
        if (strncmp(code + pos, operators[i], op_len) == 0) {
            *len = op_len;
            return 1;
        }
    }
    return 0;
}

// 将代码转换为标记序列
StringArray* tokenize_code(const char *code) {
    if (!code) return NULL;
    
    StringArray *tokens = string_array_create();
    if (!tokens) return NULL;
    
    int len = strlen(code);
    int i = 0;
    
    while (i < len) {
        // 跳过空白字符
        if (isspace(code[i])) {
            i++;
            continue;
        }
        
        // 尝试匹配运算符
        int op_len = 0;
        if (match_operator(code, i, &op_len)) {
            char *token = (char*)malloc(op_len + 1);
            strncpy(token, code + i, op_len);
            token[op_len] = '\0';
            string_array_add(tokens, token);
            free(token);
            i += op_len;
            continue;
        }
        
        // 处理标识符和关键字
        if (isalnum(code[i]) || code[i] == '_') {
            int start = i;
            while (i < len && (isalnum(code[i]) || code[i] == '_')) {
                i++;
            }
            
            int token_len = i - start;
            char *token = (char*)malloc(token_len + 1);
            strncpy(token, code + start, token_len);
            token[token_len] = '\0';
            
            // 如果是关键字，保留关键字；否则统一替换为标识符标记
            if (is_keyword(token)) {
                string_array_add(tokens, token);
            } else {
                string_array_add(tokens, "IDENTIFIER");
            }
            free(token);
            continue;
        }
        
        // 处理数字
        if (isdigit(code[i])) {
            while (i < len && (isdigit(code[i]) || code[i] == '.' || 
                              code[i] == 'e' || code[i] == 'E' || 
                              code[i] == '+' || code[i] == '-')) {
                i++;
            }
            string_array_add(tokens, "NUMBER");
            continue;
        }
        
        // 其他字符跳过
        i++;
    }
    
    return tokens;
}

