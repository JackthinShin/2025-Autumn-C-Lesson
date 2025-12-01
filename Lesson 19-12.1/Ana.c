/*
程序实现了一个将整数转换为字符串的功能。函数numtos通过递归方式将整数num转换为字符串形式并存储在字符数组s中。
主要逻辑如下：
1. 使用静态变量i来跟踪当前字符数组s中的位置。
2. 递归调用numtos函数，直到num为0为止。
3. 在递归返回的过程中，将num的每一位转换为字符并存储在s数组中。
4. 主函数中读取一个整数n，调用numtos函数进行转换，并输出结果字符串。
注意事项：
str的内容是数字num的字符串表示形式。例如，num为123时，str应为"123"。
static去掉会导致i每次调用numtos时都被初始化为0，从而无法正确累积字符位置，最终导致str内容不正确。
if块的两条语句交换位置会导致递归调用顺序错误，最终生成的字符串顺序颠倒，无法正确表示数字。
*/

#include <stdio.h>

void numtos(int num, char s[]) {
    static int i=0;
    if (num) {
        numtos(num/10,s);
        s[i++]=num%10+'0';
    }
}

int main() {
    char str[12]={0};
    int n;
    scanf("%d", &n);
    numtos(n, str);
    puts(str);
    return 0;
}