#include <stdio.h>
#include <string.h>

int f(char s[]) {
    // strcat中参数要求第一个参数是一个可修改的字符数组，第二个参数是一个字符串常量或字符数组。
    // 将第二个参数连接到第一个参数的末尾。
    // 结果会放到第一个参数中。
    char str1[20] = "Hello, ";
    char str2[] = "World!";
    strcat(str1, str2);

    // strcpy中参数要求第一个参数是一个可修改的字符数组，第二个参数是一个字符串常量或字符数组。
    // 将第二个参数复制到第一个参数中。
    // 结果会放到第一个参数中。
    strcpy(str1, str2);
    // str1 = str2; 是错误的。
    char str1[20] = "China";
    strncpy(str1, str2, 3); // 只复制前3个字符。
    //此时的str1内容为 "Wor" + "na"
    // 末尾的'\0'需要手动添加

    // strcmp中参数要求两个都是字符串常量或字符数组。
    // 比较两个字符串的大小,按字典顺序比较。
    // '\0'的ASCII码值最小。所以较短的字符串小于较长的字符串（当较长的字符串以较短的字符串为前缀时）。
    // 返回值小于0表示第一个字符串小于第二个字符串
    // 返回值等于0表示两个字符串相等
    // 返回值大于0表示第一个字符串大于第二个字符串。
    char s[] = "B";
    strcmp(s, "A"); // 返回值大于0
    strcmp(s, "B"); // 返回值等于0
    strcmp(s, "C"); // 返回值小于0
    char str1[] = "ABC\0E";
    char str2[] = "ABC\0";
    strcmp(str1, str2); // 返回值等于0
    
    // strlen中参数要求是字符串常量或字符数组。
    // 计算字符串的长度，不包括结尾的'\0'。返回值即为字符串的长度。
    int len = strlen(s);
    // strlen("ABC\0E"); // 返回3

    return 0;
}

int main() {
    char b[100];
    scanf("%s",b);
    printf("%s\n",b);
    // Note: gets()可以读取包含空格的字符串，包括换行符，直到遇到换行符为止。
    // gets(b);
    // Note: puts()会在输出字符串后自动添加一个换行符。
    // puts(b);
    return 0;
}