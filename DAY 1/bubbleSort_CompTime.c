/*This code is to find out the compilation time for Bubble Sort for its best, worst and average case. Time complexity for bubble sort ---
        best case = O(n)
        average case = O(n^2)
        worst case = O(n^2)
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(long int *x,long int *y){
    long int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(long int a[], long int n) 
{ 
    for (long int i = 0; i < n - 1; i++) { 
        for (long int j = 0; j < n - 1 - i; j++) { 
            if (a[j] > a[j + 1]) { 
                swap(&a[j], &a[j + 1]); 
            } 
        } 
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
    int n;
    printf("Enter no of elements\n");
    scanf("%d",&n);
    long int a[n];
    for(int i=0;i<n;i++){
        long int no = rand();
        a[i]=no;
    }

    //for average case

    s=clock() ;
    bubbleSort(a,n);
    e=clock() ;

    //for best case -- sorting a sorted array

    s1=clock();
    bubbleSort(a, n);
    s2=clock();

    //for worst case -- sorting a reversed array
    rev(a, n);//reverse

    s3=clock();
    bubbleSort(a,n);
    s4=clock();

    time = ((double)(e-s));//Average
    time1=((double)(s2-s1));//Best
    time2=((double)(s4-s3));//Worst
    printf("Best Case:%li\n",(long int)time1);
    printf("Average Case : %li\n",(long int)time);
    printf("Worst case:%li\n",(long int)time2);
}