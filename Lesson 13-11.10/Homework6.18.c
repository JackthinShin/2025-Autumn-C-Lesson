/*
char st[] = "ababbab";
目标串为:ababbab
请输入模式串:abb
匹配位置为:2
*/
#include <stdio.h>
#include <string.h>

int BF(char st[], char sp[]) {
    int len1 = strlen(st);
    int len2 = strlen(sp);
    int i, j;
    for (i = 0; i <= len1 - len2; i++) {
        for (j = 0; j < len2; j++) {
            if (st[i + j] != sp[j])
                break;
        }
        if (j == len2) {
            return i;
        }
    }
    return -1;
}

int main() {
    char st[] = "ababbab";
    char sp[20];
    printf("目标串为:%s\n", st);
    printf("请输入模式串:");
    scanf("%s", sp);
    int pos = BF(st, sp);
    if (pos != -1) {
        printf("匹配成功，匹配位置为:%d\n", pos);
    } else {
        printf("匹配失败\n");
    }
    return 0;
}