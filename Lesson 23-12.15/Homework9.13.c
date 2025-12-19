/*
华为 VIVO 小米 OPPO
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCORE 3000
#define MIN_SCORE 1000
#define N 4

struct data {
    char name[20];
    int sales[13];
};

void create_data(struct data c[], int n) {
    int i,j,sum,temp;
    unsigned seed,num;
    seed=(unsigned)time(NULL);
    srand(seed);
    for(i=0;i<n;i++) {
        sum=0;
        for(j=1;j<=12;j++) {
            num=rand();
            temp=num%(MAX_SCORE-MIN_SCORE+1)+MIN_SCORE;
            c[i].sales[j]=temp;
            sum+=temp;
        }
        c[i].sales[0]=sum;
    }
}

void print_all(struct data c[], int n) {
    int i,j;
    for(i=0;i<n;i++) {
        printf("%-3d",i+1);
        printf("%s",c[i].name);
        for(j=1;j<=12;j++) {
            printf("%5d",c[i].sales[j]);
        }
        printf("%7d\n",c[i].sales[0]);
    }
    putchar('\n');
}

void swap(struct data *p[], int i, int j) {
    struct data *temp;
    temp=p[i];
    p[i]=p[j];
    p[j]=temp;
}

void month_sort(struct data *p[], int n, int m) {
    int i,j,k;
    for(i=0;i<n-1;i++) {
        k=i;
        for(j=i+1;j<n;j++) if(p[j]->sales[m]>p[k]->sales[m]) k=j;
        if(k!=i) swap(p, i, k);
    }
}

void print_m(struct data *p[], int n, int m) {
    int i;
    for(i=0;i<n;i++) {
        printf("%3d",i+1);
        printf("     %s",p[i]->name);
        printf("%10d\n",p[i]->sales[m]);
    }
}

int main() {
    int i,m;
    struct data *p[N], mobile[N]={{"华为"}, {"VIVO"}, {"小米"}, {"OPPO"}};
    create_data(mobile, N);
    print_all(mobile, N);
    for(i=0;i<N;i++) p[i]=&mobile[i];
    printf("Please input m(-1<=m<=12, -1 for exit): ");
    scanf("%d", &m);
    while(m>=0 && m<=12) {
        month_sort(p, N, m);
        print_m(p, N, m);
        printf("\nPlease input m(-1<=m<=12, -1 for exit): ");
        scanf("%d", &m);
    }
    putchar('\n');
    return 0;
}