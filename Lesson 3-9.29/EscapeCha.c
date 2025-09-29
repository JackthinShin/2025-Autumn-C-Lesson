// 转义字符(Escape Character)
// \n       换行
// \t       水平制表符(Horizontal Tab)
// \123     ASCII码
// \(num)   八进制
// \\       '\'     反斜杠
// \'       '''     单引号
// \"       '"'     双引号
// \0       字符串结束标记

#include <stdio.h>

int main(){
    printf("Hello\nWorld\n");
    printf("12345\t67890\n");
    printf("123\t456\n");
    printf("\101\n");
    printf("\\\'\"\0");
    return 0;
}