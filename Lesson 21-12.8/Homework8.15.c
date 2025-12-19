/*
有⼀个班4个学⽣，5⻔课程。①求第n(默认为1)⻔课程的平均分；②找出有两⻔以上课程
不及格的学⽣，输出他们的学号和全部课程成绩及平均成绩；③找出平均成绩在9分以上
或全部课程成绩在85分以上的学⽣。分别编3个函数实现以上3个要求。

输入样例：
84 91 93 92 87.5
63 56 87 73 92
51 78 77 65 47
85 86 87 90 84
87 85 91 85 89
73 56 47 52 81
99 98 97 58 98
输出样例：
***原始成绩如下***
1  84.0 91.0 93.0 92.0 87.5   89.50
2  63.0 56.0 87.0 73.0 92.0   74.20
3  51.0 78.0 77.0 65.0 47.0   63.60
4  85.0 86.0 87.0 90.0 84.0   86.40
5  87.0 85.0 91.0 85.0 89.0   87.40
6  73.0 56.0 47.0 52.0 81.0   61.80
7  99.0 98.0 97.0 58.0 98.0   90.00

第1门课程的平均成绩为: 77.43

***两门(含)以上不及格的学生信息***
3  51.0 78.0 77.0 65.0 47.0   63.60
6  73.0 56.0 47.0 52.0 81.0   61.80

***总体上成绩比较优秀的学生信息***
5  87.0 85.0 91.0 85.0 89.0   87.40
7  99.0 98.0 97.0 58.0 98.0   90.00
*/

#include <stdio.h>
#define M 7
#define N 5

float ave_cou(float (*p)[N+1], int n) {
    int i;
    float sum = 0;
    for(i=0;i<M;i++) {
        sum += *(*(p+i)+n);
    }
    return sum / M;
}

float* fail(float *p) {
    int i,count=0;
    for(i=1;i<=N;i++) {
        if(*(p+i)<60)
            count++;
        if(count>=2)
            return p;
    }
    return NULL;
}

float* good(float (*p)[N+1]) {
    int i;
    if(**p>=90) return *p;
    for(i=1;i<=N;i++) {
        if(*(*p+i)<85)
            return NULL;
    }
    return *p;
}

int main() {
    float score[M][N+1],sum,*p;
    int i,j,n;
    for(i=0;i<M;i++) {
        sum=0;
        for(j=1;j<=N;j++) {
            scanf("%f",*(score+i)+j);
            sum += *(*(score+i)+j);
        }
        score[i][0] = sum / N;
    }
    printf("***原始成绩如下***\n");
    for(i=0;i<M;i++) {
        printf("%d ",i+1);
        for(j=1;j<=N;j++) {
            printf("%.1f ",*(*(score+i)+j));
        }
        printf("%.2f\n",*(*(score+i)));
    }
    n=1;
    printf("\n第%d门课程的平均成绩为: %.2f\n",n,ave_cou(score,n));
    printf("\n***两门(含)以上不及格的学生信息***\n");
    for(i=0;i<M;i++) {
        p = fail(*(score+i));
        if(p!=NULL) {
            printf("%d ",i+1);
            for(j=1;j<=N;j++) {
                printf("%.1f ",*(p+j));
            }
            printf("%.2f\n",*(*(score+i)));
        }
    }
    printf("\n***总体上成绩比较优秀的学生信息***\n");
    for(i=0;i<M;i++) {
        p = good(score+i);
        if(p!=NULL) {
            printf("%d ",i+1);
            for(j=1;j<=N;j++) {
                printf("%.1f ",*(*(score+i)+j));
            }
            printf("%.2f\n",*(*(score+i)));
        }
    }
    return 0;
}