#include <stdio.h>

int main(){
    /*
    switch(整型表达式)
    {
        case 常量1: ……;
        case 常量2: ……;
        ……
        case 常量n: ……;
        default: ……;
    }
    */
    char ch=getchar();

    // switch(ch)
    // {
    //     case 'A': printf("优秀\n");
    //     case 'B': printf("良好\n");
    //     case 'C': printf("一般\n");
    //     default: printf("差\n");
    // }
    // 默认输出进入对应case以下的所有内容

    switch(ch)
    {
        case 'A': printf("优秀\n"); break;
        case 'B': printf("良好\n"); break;
        case 'C': printf("一般\n"); break;
        default: printf("差\n"); break;
    }

    return 0;
}