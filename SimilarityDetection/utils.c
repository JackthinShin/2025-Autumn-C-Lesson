#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 256

// 动态字符串实现
String* string_create(void) {
    String *str = (String*)malloc(sizeof(String));
    if (!str) return NULL;
    
    str->capacity = INITIAL_CAPACITY;
    str->length = 0;
    str->data = (char*)malloc(str->capacity);
    if (!str->data) {
        free(str);
        return NULL;
    }
    str->data[0] = '\0';
    return str;
}

void string_append(String *str, const char *text) {
    if (!str || !text) return;
    
    size_t text_len = strlen(text);
    if (str->length + text_len + 1 >= str->capacity) {
        str->capacity = (str->length + text_len + 1) * 2;
        str->data = (char*)realloc(str->data, str->capacity);
        if (!str->data) return;
    }
    
    strcpy(str->data + str->length, text);
    str->length += text_len;
}

void string_free(String *str) {
    if (str) {
        free(str->data);
        free(str);
    }
}

char* string_get(String *str) {
    return str ? str->data : NULL;
}

// 字符串数组实现
StringArray* string_array_create(void) {
    StringArray *arr = (StringArray*)malloc(sizeof(StringArray));
    if (!arr) return NULL;
    
    arr->capacity = 16;
    arr->count = 0;
    arr->items = (char**)malloc(arr->capacity * sizeof(char*));
    if (!arr->items) {
        free(arr);
        return NULL;
    }
    return arr;
}

void string_array_add(StringArray *arr, const char *str) {
    if (!arr || !str) return;
    
    if (arr->count >= arr->capacity) {
        arr->capacity *= 2;
        arr->items = (char**)realloc(arr->items, arr->capacity * sizeof(char*));
        if (!arr->items) return;
    }
    
    arr->items[arr->count] = (char*)malloc(strlen(str) + 1);
    if (arr->items[arr->count]) {
        strcpy(arr->items[arr->count], str);
        arr->count++;
    }
}

void string_array_free(StringArray *arr) {
    if (arr) {
        for (size_t i = 0; i < arr->count; i++) {
            free(arr->items[i]);
        }
        free(arr->items);
        free(arr);
    }
}

// 读取文件内容
char* read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *content = (char*)malloc(file_size + 1);
    if (!content) {
        fclose(file);
        return NULL;
    }
    
    size_t read_size = fread(content, 1, file_size, file);
    content[read_size] = '\0';
    fclose(file);
    
    return content;
}

// 写入文件内容
int write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error: Cannot create file %s\n", filename);
        return 0;
    }
    
    fprintf(file, "%s", content);
    fclose(file);
    return 1;
}

