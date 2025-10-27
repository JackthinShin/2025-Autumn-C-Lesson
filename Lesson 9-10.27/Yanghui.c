#include <stdio.h>
#define LASTROW 7

int main(){
    int row,col,a[LASTROW];
    a[0]=1;
    printf("%5d\n",a[0]);
    for(row=1;row<LASTROW;row++){
        a[0]=a[row]=1;
        for(col=row-1;col>=1;col--)
            a[col]=a[col-1]+a[col];
        for(col=0;col<=row;col++)
            printf("%5d",a[col]);
        printf("\n");
    }
    return 0;
}