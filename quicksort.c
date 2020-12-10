#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//void QuickSort( ){
//    int foot; // опора
//    int a = left; // левая часть
//    int z = right; // правая часть
//}

int main()
{
    int n;  
    printf("Введите размер массива: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(0));
    printf("Ваш массив: ");
    for (int i = 0; i < n; i++){
        arr[i] = rand()% 100;
        printf("%d ", arr[i]);
    }
return 0;}
