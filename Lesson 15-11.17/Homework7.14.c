/*
同分时输出第一个最高分数的学生和课程编号
*/

#include <stdio.h>
#define M 3
#define N 5

int h_s,h_c; // h_s:最高分数的学生下标，h_c:最高分数的课程下标

void process1(float score[M][N],float ave_s[M]) {
    for(int i=0;i<M;i++) {
        float sum=0;
        for(int j=0;j<N;j++)
            sum+=score[i][j];
        ave_s[i]=sum/N;
    }
}

void process2(float score[M][N],float ave_c[N]) {
    for(int j=0;j<N;j++) {
        float sum=0;
        for(int i=0;i<M;i++)
            sum+=score[i][j];
        ave_c[j]=sum/M;
    }
}

void highest(float score[M][N]) {
    float high=score[0][0];
    h_s=0;
    h_c=0;
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            if(score[i][j]>high) {
                high=score[i][j];
                h_s=i;
                h_c=j;
            }
        }
    }
}

double var(float ave_s[M]) {
    double sum=0,mean=0;
    for(int i=0;i<M;i++)
        mean+=ave_s[i];
    mean/=M;
    for(int i=0;i<M;i++)
        sum+=(ave_s[i]-mean)*(ave_s[i]-mean);
    return sum/M;
}

int main() {
    float score[M][N]={{70,70,70,70,70},{70,70,70,70,70},{70,70,70,70,70}};
    float ave_s[M],ave_c[N];
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            printf("%.1f ",score[i][j]);
        }
        printf("\n");
    }
    process1(score,ave_s);
    for(int i=0;i<M;i++)
        printf("第%d个学生的平均分为:%.2f\n",i+1,ave_s[i]);
    process2(score,ave_c);
    for(int j=0;j<N;j++)
        printf("第%d门课程的平均分为:%.2f\n",j+1,ave_c[j]);
    highest(score);
    printf("最高成绩为%.1f,是第%d个学生的第%d门课程\n",score[h_s][h_c],h_s+1,h_c+1);
    var(ave_s);
    printf("学生平均分的方差为:%.3f\n",var(ave_s));
    return 0;
}