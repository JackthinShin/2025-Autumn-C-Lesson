/*
请输入一行字符: a bb ccc 
最长单词为:ccc,长度为:3
若有多个最长单词，则输出第一个最长单词。
*/
#include <stdio.h>
#include <string.h>

char str[81], longest[81];
int start = 0, length = 0; 

void f(char str[]) {
    char ch, pre = ' ';
    for (int i=0;(ch=str[i])!='\0';i++) {
        if (ch != ' ' && pre == ' ') {
            start = i; // 记录单词起始位置
        }
        if ((ch == ' ' || str[i+1] == '\0') && pre != ' ') {
            int wordLength = (ch == ' ') ? (i - start) : (i - start + 1);
            if (wordLength > length)
                length = wordLength;
        }
        pre = ch;
    }
}
int main() {
    gets(str);
    f(str);
    for(int i=start;i<start+length;i++)
        longest[i-start]=str[i];
    printf("最长单词为:%s,长度为:%d\n", longest, length);
    return 0;
}