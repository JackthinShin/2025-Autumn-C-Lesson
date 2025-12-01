/*
[原始字符串]
123 456 17960 302 5876
共5个整数
将其中连续的数字作为一个整数，依次存放到一个数组a中。例如，123放在a[0]，456放在a[1]
统计共有多少个整数，并输出这些数。
前后分别加'0'也能输出
要使用子函数，指针实现
*/

#include <stdio.h>

void f(char *s, int *a, int *count) {
    int i = 0, num = 0, flag = 0;
    *count = 0;
    while (s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
            flag = 1;
        } else {
            if (flag) {
                a[(*count)++] = num;
                num = 0;
                flag = 0;
            }
        }
        i++;
    }
    if (flag)
        a[(*count)++] = num;
}

int main() {
    char str[] = "A123x456 17960? 302tab5876";
    printf("%s\n", str);
    int a[100], count = 0;
    f(str, a, &count);
    printf("共%d个整数\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}