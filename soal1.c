/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3
 *   Hari dan Tanggal    : 27 April 2026
 *   Nama (NIM)          : Michelle (13224098)
 *   Nama File           : soal1.c
 *   Deskripsi           : Menyimpan data valid (sebelum input -1) dalam array dinamis, diurutkan, dan kemudian dicari mediannya
 * 
 */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

void swap(int* xp, int* yp){ //geeksforgeeks
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int ukuran){ //geeksforgeeks
    int i, j;
    bool swapped;
    for (i = 0; i < ukuran - 1; i++) {
        swapped = false;
        for (j = 0; j < ukuran - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}
int hitungmedian (int arr[], int n){
    bubbleSort(arr, n);
    int median;
    if (n+1 % 2 == 0) {
        return (arr[n / 2] + arr[(n+1 / 2) +1]) / 2.0;
    }
  
  	// If odd, median is the middle element
  	else {
        return arr[(n / 2)+1];
    }
}
/*int count (int arr[]){
    int count;
    int i=0;
    while(arr[i]!=-1){
        count++;
        i++;
    }
    return count;
}*/

int main(){
    int ukuran=0;
    int *arr=NULL;
    int i=0;
    int input;
    while(input!=-1){
        arr= (int*)realloc(arr,(i+1) * sizeof(int));
        arr[i]=input;
        i++;
        ukuran++;
        scanf("%d", &input);
    }
    bubbleSort(arr, ukuran-1);
    
    float median= hitungmedian(arr, ukuran-1);
    printf("COUNT %d", ukuran-1);
    printf(" SORTED ");
    for(int k=1; k<ukuran; k++){
        printf("%d ", arr[k]);
    }
    printf(" MEDIAN %.2f\n", median);


}
