//this code continuously increases number of inputs by 10000 and finds out the compilation time in ms

#include<stdio.h>
#include<time.h>
#include<stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(long int arr[], long int n) 
{ 
    long int i, j, midx; 
  
    for (i = 0; i < n - 1; i++) {  
        midx = i;
        for (j = i + 1; j < n; j++) 
            if (arr[j] < arr[midx]) 
                midx = j; 
        swap(&arr[midx], &arr[i]); 
    } 
} 

int main(){
    long int n = 10000;
    int i_t=0;
    double time[10];
    while(i_t++<10){
        long int a[n];
        for(int i=0;i<n;i++){
            long int no = rand()%n+1;
            a[i]=no;
        }
        clock_t start,end;
        
        start = clock();
        selectionSort(a,n);
        end = clock();
        time[i_t]=((double)(end-start));
        printf("%li \n%li\n",n,(long int)time[i_t]);
        n+=10000;

    }
}
