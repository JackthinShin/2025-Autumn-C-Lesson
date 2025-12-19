/*
未来时光机
*/

#include <stdio.h>
typedef struct {
    int y;
    int m;
    int d;
} DATE;

int isleap(int y) {
    return (y%4==0 && y%100!=0) || (y%400==0);
}

DATE count(DATE sd, int days) {
    DATE fd=sd;
    int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(fd.m<=2) month[2]+=isleap(fd.y);
    while(days>month[fd.m]-fd.d) {
        days-=month[fd.m]-fd.d;
        fd.d=0;
        fd.m++;
        if(fd.m==13) {
            fd.m=1;
            fd.y++;
            while(days>365+isleap(fd.y)) {
                days-=365+isleap(fd.y);
                fd.y++;
            }
            month[2]=28+isleap(fd.y);
        }
    }
    fd.d+=days;
    return fd;
}

int main() {
    DATE sd, td;
    int days;
    printf("请输入起始日期: ");
    scanf("%d-%d-%d", &sd.y, &sd.m, &sd.d);
    printf("旅行天数: ");
    scanf("%d", &days);
    td=count(sd, days);
    printf("未来的日期为: %d-%02d-%02d\n", td.y, td.m, td.d);
    return 0;
}