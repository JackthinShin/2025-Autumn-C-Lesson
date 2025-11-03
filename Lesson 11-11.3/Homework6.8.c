/*
1 2 3 4
5 6 7 8
9 10 11 12
鞍点是4,在第1行第4列上
1 2 3 8
5 6 7 4
9 10 11 12
无鞍点
*/
#include <stdio.h>

int main(){
    int flag=0;
    int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // int a[3][4]={{1,2,3,8},{5,6,7,4},{9,10,11,12}};
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++)
            printf("%3d",a[i][j]);
        printf("\n");
    }
    for(int i=0;i<3;i++){
        int max=a[i][0],maxj=0;
        for(int j=1;j<4;j++)
            if(a[i][j]>max){
                max=a[i][j];
                maxj=j;
            } 
        int min=a[0][maxj],mink=0;
        for(int k=0;k<3;k++){
            if(a[k][maxj]<min){
                min=a[k][maxj];
                mink=k;
            }
        }
        if(mink==i){
            printf("鞍点是%d,在第%d行第%d列上\n",max,i+1,maxj+1);
            flag=1;
        }
    }
    if(!flag) printf("无鞍点\n");
    return 0;
}