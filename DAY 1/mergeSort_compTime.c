//Compilation time for best,worst and average case for mergeSort.

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void merge(int a[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    
    int left[n1], right[n2]; 
  

    for (i = 0; i < n1; i++) 
        left[i] = a[l + i]; 
    for (j = 0; j < n2; j++) 
        right[j] = a[m + 1 + j]; 
  

    i = 0;  
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) { 
        if (left[i] <= right[j]) { 
            a[k] = left[i]; 
            i++; 
        } 
        else { 
            a[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) { 
        a[k] = left[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        a[k] = right[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int a[], int l, int r) 
{ 
    if (l < r) { 

        int k = l + (r - l) / 2; 
  

        mergeSort(a, l, k); 
        mergeSort(a, k + 1, r); 
        merge(a, l, k, r); 
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
    int n = 20000;
    while(n<=200000){
    int a[n];
    for(int i=0;i<n;i++){
        int no = rand();
        a[i]=no;
    }

    //for average case
    
    s=clock();
    mergeSort(a,0, n);
    e=clock();

    //for best case -- sorting a sorted array

    s1=clock();
    mergeSort(a,0, n);
    s2=clock();
    
    //for worst case -- sorting a reversed array

    rev(a,n);//Reverse

    s3=clock();
    mergeSort(a,0,n);
    s4=clock();

    time=((int)(e-s));//average
    time1=((int)(s2-s1));//best
    time2=((int)(s4-s3));//worst
    printf("Best Case :  %d\n",(int)time1);
    printf("Average Case : %d\n",(int)time);
    printf("Worst case : %d\n",(int)time2);
    printf("ELements:  %d\n\n",n);
    n+=20000;
    }
}
