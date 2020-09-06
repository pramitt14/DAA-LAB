//Compilation time for best,worst and average case for insertionSort.

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(long int *x, long int *y){
    long int temp = *x;
    *x = *y;
    *y = temp;
}



void insertionSort(long int arr[], long int n) 
{ 
    long int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1;
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

//rev() -- for sort the array in reverse order

void rev(long int a[], long int n) 
{ 
    for (long int i = 0; i < n - 1; i++) { 
        for (long int j = 0; j < n - 1 - i; j++) { 
            if (a[j] < a[j + 1]) { 
                swap(&a[j], &a[j + 1]); 
            } 
        } 
    } 
}

void main() 
{
    clock_t s, e,s1,s2,s3,s4;
    long int time,time1,time2;
    int n = 10000;
    while(n<=100000){
    long int a[n];
    for(int i=0;i<n;i++){
        long int no = rand();
        a[i]=no;
    }

    //for average case
    
    s=clock();
    insertionSort(a, n);
    e=clock();

    //for best case -- sorting a sorted array

    s1=clock();
    insertionSort(a, n);
    s2=clock();
    
    //for worst case -- sorting a reversed array

    rev(a,n);//Reverse

    s3=clock();
    insertionSort(a,n);
    s4=clock();

    time=((double)(e-s));//average
    time1=((double)(s2-s1));//best
    time2=((double)(s4-s3));//worst
    printf("Best Case :  %li\n",(long int)time1);
    printf("Average Case : %li\n",(long int)time);
    printf("Worst case : %li\n",(long int)time2);
    printf("ELements:  %d\n\n",n);
    n+=10000;
    }
}





