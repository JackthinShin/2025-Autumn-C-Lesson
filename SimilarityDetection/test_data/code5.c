#include <stdio.h>

// 数组排序程序
void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int array[10] = {5, 2, 8, 1, 9, 3, 7, 4, 6, 0};
    int size = 10;
    
    bubble_sort(array, size);
    
    for (int k = 0; k < size; k++) {
        printf("%d ", array[k]);
    }
    printf("\n");
    
    return 0;
}

