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
    for (i = 0; i < ukuran; i++) {
        swapped = false;
        for (j = 0; j < ukuran - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
                //printf("SWAP %d %d\n", arr[j], arr[j+1]);
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}
int hitungmedian (int arr[], int n){
    //bubbleSort(arr, n);
    float median1;
    int median2;
    
    if ((n) % 2 == 0) {
        median1 = (float)(arr[0] + (arr[n-1])) / 2.0;
        printf(" MEDIAN %.2f", median1);
    }
  
  	// If odd, median is the middle element
  	else {
        median2 = (int)arr[(n / 2)];
        printf(" MEDIAN %d", median2);

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
        //printf("INPUT %d\n",input);
    }
    ukuran -= 1;
    bubbleSort(arr, ukuran);
    printf("COUNT %d", ukuran);
    printf("SORTED ");
    for(int l=0; l<ukuran; l++){
        printf("%d", arr[l]);
    }
    printf(" ");
    
   

    float median= hitungmedian(arr, ukuran);

}
