#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 动态字符串结构
typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} String;

// 字符串数组结构
typedef struct {
    char **items;
    size_t count;
    size_t capacity;
} StringArray;

// 函数声明
String* string_create(void);
void string_append(String *str, const char *text);
void string_free(String *str);
char* string_get(String *str);

StringArray* string_array_create(void);
void string_array_add(StringArray *arr, const char *str);
void string_array_free(StringArray *arr);
char* read_file(const char *filename);
int write_file(const char *filename, const char *content);

#endif // UTILS_H

