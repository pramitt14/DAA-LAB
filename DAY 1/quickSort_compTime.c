//Compilation time for best,worst and average case for QuickSort.

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//Partition function

int partition (int arr[], int l, int h) 
{ 
    int pivot = arr[h]; 
    int i = (l - 1); 
  
    for (int j = l; j <= h - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;   
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[h]); 
    return (i + 1); 
} 

void quickSort(int arr[], int l, int h) 
{ 
    if (l < h) 
    { 
        int p = partition(arr, l, h); 
        quickSort(arr, l, p - 1); 
        quickSort(arr, p + 1, h); 
    } 
}   


void rev(int a[],int n) 
{ 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - 1 - i; j++) { 
            if (a[j] < a[j + 1]) { 
                swap(&a[j], &a[j + 1]); 
            } 
        } 
    } 
}

void main() 
{
    clock_t s, e,s1,s2,s3,s4;
    int time,time1,time2;
    int n = 5000;
    while(n<=50000){
    int a[n];
    for(int i=0;i<n;i++){
        int no = rand();
        a[i]=no;
    }

    //for average case
    
    s=clock();
    quickSort(a,0, n-1);
    e=clock();

    //for best case -- sorting a sorted array

    s1=clock();
    quickSort(a,0, n-1);
    s2=clock();
    
    //for worst case -- sorting a reversed array

    rev(a,n);//Reverse

    s3=clock();
    quickSort(a,0,n-1);
    s4=clock();

    time=((int)(e-s));//average
    time1=((int)(s2-s1));//best
    time2=((int)(s4-s3));//worst
    printf("Best Case :  %d\n",(int)time1);
    printf("Average Case : %d\n",(int)time);
    printf("Worst case : %d\n",(int)time2);
    printf("ELements:  %d\n\n",n);
    n+=5000;
    }
}
