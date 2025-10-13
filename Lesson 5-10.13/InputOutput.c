#include <stdio.h>

int main(){
    /*
    输入输出
    printf("格式字符串",输出表列);
    格式说明 %标志m.n l或h 格式字符
    标志：- 左对齐
        0 前空位填零
        + #
    m  域宽
    .n 精度
    • %a ：⼗六进制浮点数，字⺟输出为⼩写。
    • %A ：⼗六进制浮点数，字⺟输出为⼤写。
    • %c ：字符。
    • %d ：⼗进制整数。
    • %e ：使⽤科学计数法的浮点数，指数部分的 e 为⼩写。
    • %E ：使⽤科学计数法的浮点数，指数部分的 E 为⼤写。
    • %i ：整数，基本等同于 %d 。
    • %f ：⼩数（包含 float 类型和 double 类型）。
    • %g ：6个有效数字的浮点数。整数部分⼀旦超过6位，就会⾃动转为科学计数法，指数部分的 e 为⼩写。
    • %o ：⼋进制整数。
    • %s ：字符串。
    • %x ：⼗六进制整数。
    • %% ：输出⼀个百分号。
    */

    float a=3.14;
    int b=5;
    printf("%-9f %05d\n",a,b);
    printf("%-3.4f %05d\n",a,b);
    printf("%.1f\n",3.17);
    
    /*
    scanf("格式字符串",地址表列);
    double x,y;
    scanf("%lf,%lf",&x,&y);
    double类型必须使用%lf
    匹配与忽略
    1.能匹配的一定要匹配
    2.不能匹配的白字符可忽略
    scanf格式字符串一般不加换行符(\n)
    */ 

    // int x,y;
    // scanf("a=%d,b=%d",&x,&y);

    // int x,y;
    // scanf("a=%d b=%d",&x,&y);
    // printf("%d,%d\n",x,y);

    /*
    getchar();
    char ch1,ch2;
    ch1=getchar();
    ch2=getchar();
    若输入：
        A
        B
    则ch1=‘A' ch2=’\n'
    可在中间加入一句
    getchar();
    将回车“吞下”
    */ 
    
    /*
    putchar("");
    ’\n'占1字节
    "\n"占2字节(字符串末尾\0标识)
    */
    return 0;
}