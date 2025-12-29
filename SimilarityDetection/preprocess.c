#include "preprocess.h"
#include "utils.h"
#include <ctype.h>
#include <string.h>

// 去除单行注释 //
static void remove_single_line_comment(String *result, const char *code, int *i) {
    while (code[*i] != '\0' && code[*i] != '\n') {
        (*i)++;
    }
    if (code[*i] == '\n') {
        string_append(result, " ");
    }
}

// 去除多行注释 /* */
static void remove_multi_line_comment(String *result, const char *code, int *i) {
    (*i) += 2; // 跳过 /*
    while (code[*i] != '\0') {
        if (code[*i] == '*' && code[*i + 1] == '/') {
            (*i) += 2;
            string_append(result, " ");
            return;
        }
        (*i)++;
    }
}

// 去除字符串字面量
static void remove_string_literal(String *result, const char *code, int *i) {
    char quote = code[*i];
    (*i)++; // 跳过开始引号
    
    while (code[*i] != '\0') {
        if (code[*i] == '\\' && code[*i + 1] != '\0') {
            (*i) += 2; // 跳过转义字符
            continue;
        }
        if (code[*i] == quote) {
            (*i)++; // 跳过结束引号
            string_append(result, " ");
            return;
        }
        (*i)++;
    }
}

// 去除头文件包含
static int is_include_directive(const char *code, int i) {
    // 检查是否是 #include
    if (code[i] == '#') {
        int j = i + 1;
        while (j < i + 10 && isspace(code[j])) j++;
        if (strncmp(code + j, "include", 7) == 0) {
            return 1;
        }
    }
    return 0;
}

// 跳过头文件行
static void skip_include_line(String *result, const char *code, int *i) {
    while (code[*i] != '\0' && code[*i] != '\n') {
        (*i)++;
    }
    if (code[*i] == '\n') {
        string_append(result, " ");
    }
}

// 主预处理函数
char* preprocess_code(const char *code) {
    if (!code) return NULL;
    
    String *result = string_create();
    if (!result) return NULL;
    
    int len = strlen(code);
    int i = 0;
    
    while (i < len) {
        // 跳过空白字符（保留一个空格作为分隔符）
        if (isspace(code[i])) {
            // 如果是换行符，跳过
            if (code[i] == '\n' || code[i] == '\r') {
                i++;
                continue;
            }
            // 其他空白字符转换为单个空格
            if (result->length > 0 && result->data[result->length - 1] != ' ') {
                string_append(result, " ");
            }
            i++;
            continue;
        }
        
        // 检查是否是头文件包含
        if (is_include_directive(code, i)) {
            skip_include_line(result, code, &i);
            continue;
        }
        
        // 检查是否是单行注释
        if (code[i] == '/' && code[i + 1] == '/') {
            remove_single_line_comment(result, code, &i);
            continue;
        }
        
        // 检查是否是多行注释
        if (code[i] == '/' && code[i + 1] == '*') {
            remove_multi_line_comment(result, code, &i);
            continue;
        }
        
        // 检查是否是字符串字面量
        if (code[i] == '"' || code[i] == '\'') {
            remove_string_literal(result, code, &i);
            continue;
        }
        
        // 保留其他字符
        char ch[2] = {code[i], '\0'};
        string_append(result, ch);
        i++;
    }
    
    // 去除多余的空格
    char *processed = string_get(result);
    char *cleaned = (char*)malloc(strlen(processed) + 1);
    if (!cleaned) {
        string_free(result);
        return NULL;
    }
    
    int j = 0;
    int k = 0;
    int prev_space = 0;
    while (processed[j] != '\0') {
        if (processed[j] == ' ') {
            if (!prev_space && k > 0) {
                cleaned[k++] = ' ';
            }
            prev_space = 1;
        } else {
            cleaned[k++] = processed[j];
            prev_space = 0;
        }
        j++;
    }
    cleaned[k] = '\0';
    
    string_free(result);
    return cleaned;
}

