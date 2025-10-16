// 4.10. 企业发放的奖⾦根据利润提成。
// 利润I低于或等于100000元的，奖⾦可提成10%；
// 利润⾼于100000元，低于200000元（100000</≤200000）时，
// 低于100000元的部分按10%提成，⾼于100000元的部分，可提成7.5%；
// 200000<I≤400000时，低于200000元的部分仍按上述办法提成（下同）。
// ⾼于200000元的部分按5%提成；
// 400000<I≤600000元时，⾼于400000元的部分按3%提成；
// 600000<I≤1000000时，⾼于600000元的部分按1.5%提成；
// I>1000000时，超过1000000元的部分按1%提成。
// 从键盘输⼊当⽉利润I，求应发奖⾦总数。
// 请输入利润:2e6
// 奖金为:RMB49500.00
// 1)switch
// 2)if else

#include <stdio.h>

double bonus = 0;

double sch(double profit) {
    int level = profit / 100000;
    switch(level) {
        case 10:
        case 9:
        case 8:
        case 7:
        case 6:
            bonus += (profit - 600000) * 0.015;
            profit = 600000;
        case 5:
        case 4:
            bonus += (profit - 400000) * 0.03;
            profit = 400000;
        case 3:
        case 2:
            bonus += (profit - 200000) * 0.05;
            profit = 200000;
        case 1:
            bonus += (profit - 100000) * 0.075;
            profit = 100000;
        case 0:
            bonus += profit * 0.10;
            break;
        default:
            bonus += (profit - 1000000) * 0.01 + 39500;
            break;
    }
    return bonus;
}

double ife(double profit) {
    if (profit > 1000000) {
        bonus += (profit - 1000000) * 0.01;
        profit = 1000000;
    }
    if (profit > 600000) {
        bonus += (profit - 600000) * 0.015;
        profit = 600000;
    }
    if (profit > 400000) {
        bonus += (profit - 400000) * 0.03;
        profit = 400000;
    }
    if (profit > 200000) {
        bonus += (profit - 200000) * 0.05;
        profit = 200000;
    }
    if (profit > 100000) {
        bonus += (profit - 100000) * 0.075;
        profit = 100000;
    }
    bonus += profit * 0.10;
    return bonus;
}

int main() {
    double profit;
    printf("请输入利润:");
    scanf("%lf", &profit);
    // bonus = sch(profit);
    bonus = ife(profit);
    printf("奖金为:RMB%.2f\n", bonus);
    return 0;
}