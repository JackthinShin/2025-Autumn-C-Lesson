/*
char nation[][10] = {"CHINA", "USA", "RUSSIA", "UK", "FRANCE"};
输出：
排序次序为:
CHINA
FRANCE
RUSSIA
UK
USA
要求：直接插入排序 for循环 写子函数
*/
#include <stdio.h>
#include <string.h>

void insertSort(char arr[][10], int n) {
    int i, j;
    char temp[10];
    for (i = 1; i < n; i++) {
        strcpy(temp, arr[i]);
        for (j = i - 1; j >= 0 && strcmp(arr[j], temp) > 0; j--) {
            strcpy(arr[j + 1], arr[j]);
        }
        strcpy(arr[j + 1], temp);
    }
}

int main() {
    char nation[][10] = {"CHINA", "USA", "RUSSIA", "UK", "FRANCE"};
    insertSort(nation, 5);
    printf("排序次序为:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", nation[i]);
    }
    return 0;
}