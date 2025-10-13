//3.6
//明文为:ABCXYZabcxyz
//密文为:EFGBCDefgbcd
//字符个数不一定 在一行以内 只有大小写字母
//除中文提示符外 其余字符应使用getchar()及putchar()实现
//char ch;
//while ((ch=getchar()) != '\n')

#include <stdio.h>

int main(){
    // char ch;
    // printf("明文为:");
    // while ((ch=getchar()) != '\n')
    // {
    //     putchar((char)(int)ch+4);
    // }
    // 以上代码无法在合适的位置输出“密文为:”

    // char ch;
    // printf("明文为:");
    // ch=getchar();
    // printf("密文为:");
    // do
    // {
    //     putchar((char)(int)ch+4);
    //     ch=getchar();
    // } while (ch!='\n');
    // 以上代码需在至少有一个有效字符的情况下正确工作

    char ch;
    printf("明文为:");
    ch=getchar();
    printf("密文为:");
    while (ch!='\n')
    {
        ch+=4;
        if(ch>'Z'&&ch<'a'||ch>'z') ch-=26;
        putchar(ch);
        ch=getchar();
    } 

    putchar('\n');
    return 0;
}