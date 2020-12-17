#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// эта функция будет сортировать подотрезок массива arr от low до high (включительно)
// параметр n используется только чтоб можно было выводить массив и смотреть как работает сортировка
void QuickSort( int n, int arr[], int low, int high ){ 
    if (low >= high) { // если отрезок пустой или состоит из одного элемента, то он уже отсортирован
        return;
    }
    int pivot; // опора
    int left = low; // левая часть
    int right = high; // правая часть
    int m = (low + high) / 2; // средний элемент имеет стоит на позиции (low + high) / 2
    pivot = arr[m];
    printf("От %d до %d", low, high);
 
    // <------------------------------------------> //
    printf("\n Опорный элемент - %d\n", pivot);
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
    // <------------------------------------------> //
 
    /*
    как работает QuickSort:
    разбиваем отрезок на две части - в левой все элементы <= pivot, в правой >= pivot
    рекурсивно сортируем левую и правую части
 
    когда верхний while отработал наши left и right поменялись таким образом, что
 
    все элементы [low .. left-1] <= pivot
    все элементы [right+1 .. high] >= pivot
 
    это почти дает нам нужное разбиение на две половинки:
    если left - 1 == right, то левая часть массива - [low .. right], правая - [right+1 .. high]
    если left == right, то элемент a[left] ни в какую часть не входит и нужно понять куда его отправить
    */
    if (left == right && arr[right] > pivot) {  // если arr[right] > pivot, 
        right = right - 1;                      // то он отправляется в правую часть, иначе - в левую
    }
    
    // выводим массив, чтобы увидеть процесс сортировки
    for (int i = 0; i < low; ++i) {
        printf("%d ", arr[i]);      
    }
    printf("| ");
    for (int i = low; i <= right; ++i) {
        printf("%d ", arr[i]);      
    }
    printf("/ ");
    for (int i = right + 1; i <= high; ++i) {
        printf("%d ", arr[i]);     
    }
    printf("| ");
    for (int i = high + 1; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    QuickSort(n, arr, low, right);      // сортируем левую часть
    QuickSort(n, arr, right + 1, high); // сортируем правую часть
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
        arr[i] = rand() % 50;
        printf("%d ", arr[i]);
    }
    printf("\n");
    QuickSort( n, arr, 0, n - 1 );
    printf("Отсортированный массив:\n ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
