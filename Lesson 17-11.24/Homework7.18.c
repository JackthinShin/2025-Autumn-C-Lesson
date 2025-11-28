/*
请输入起始日期：2020-3-12
请输入终止日期：2020-3-13
dis=1
起始年月日sy,sm,sd
终止年月日fy,fm,fd
*/
#include <stdio.h>

int all_days(int fy, int fm, int fd, int sy) {
    int days = 0;
    int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    for (int year = sy; year < fy; year++) {
        days += 365;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            days += 1;
        }
    }
    for (int month = 1; month < fm; month++) {
        days += month_days[month];
        if (month == 2 && ((fy % 4 == 0 && fy % 100 != 0) || (fy % 400 == 0))) {
            days += 1;
        }
    }
    days += fd;
    return days;
}

int main() {
    int sy, sm, sd;
    int fy, fm, fd;
    printf("请输入起始日期：");
    scanf("%d-%d-%d", &sy, &sm, &sd);
    printf("请输入终止日期：");
    scanf("%d-%d-%d", &fy, &fm, &fd);
    int days = all_days(fy, fm, fd, sy) - all_days(sy, sm, sd, sy);
    printf("dis=%d\n", days);
    return 0;
}