/*
有4个圆塔，圆⼼分别为（2,2）、（2,2）、（2,-2）、（-2,-2），圆半径为1。
这4个塔的高度为10m，塔以外⽆建筑物。
今输⼊任⼀点的坐标，求该点的建筑⾼度（塔外的⾼度为零）。
请输入坐标：-2,3.5
塔高：10

*/

#include <stdio.h>

double fabs(double a){
    if(a<0) return -a;
    else return a;
}

int main(){
    double x,y;
    int h;
    printf("请输入坐标：");
    scanf("%lf%lf",&x,&y);
    printf("塔高：");
    scanf("%d",&h);
    x=fabs(x);
    y=fabs(y);
    if((x-2)*(x-2)+(y-2)*(y-2)<=1)  printf("该点的建筑高度为：%dm\n",h);
    else printf("该点的建筑高度为：0m\n");
    return 0;
}