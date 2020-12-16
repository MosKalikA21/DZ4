#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort( int n, int arr[n], int low, int high ){
    int pivot; // опора
    int left = 0; // левая часть
    int right = n - 1; // правая часть
    int m = n / 2; 
    pivot = arr[m];
    printf("\nPivot is %d\n", pivot);
    while(left < right){
        while(arr[left] < pivot){
           left = left + 1;
        }
        while(arr[right] > pivot){
           right = right - 1;
        }
        if (left < right){
            int x = arr[left];
            arr[left] = arr[right];
            arr[right] = x;
            left = left + 1;
            right = right - 1;  
        }
    }
    int low = 0;
    int high = right;
    
}



int main()
{
    int n;  
    printf("Введите размер массива: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(0));
    printf("Ваш массив: ");
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 10;
        printf("%d ", arr[i]);
    }
    QuickSort(  n,  arr );
return 0;
}
