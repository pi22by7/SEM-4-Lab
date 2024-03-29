#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define range 500
#define max 500
int A[max];

void heapSort(int);
void buildHeap(int);
void maxHeapify(int,int);
void swap(int *, int *);

int main(void)
{
    srand(time(0));
    int n,i,j;
    clock_t start,end;
    double cpu_exec_time;

    printf("\nEnter the value of n: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        A[i] = rand()%range;

    printf("\nArray elements: \n");
    for(i=0;i<n;i++)
        printf("%d\t",A[i]);
    
    start = clock();
    for(i=0;i<1000;i++)
    for(j=0;j<1000;j++)
        heapSort(n);
    end = clock();
    
    
    //cpu_exec_time = (double) (end - start) / CLK_TCK;    
    cpu_exec_time = (double) (end - start) / CLOCKS_PER_SEC;

    printf("\nSorted array: \n");
    for(i=0;i<n;i++)
        printf("%d\t",A[i]);
    printf("\nCPU execution time = %lf\n", cpu_exec_time);
    return 0;
}

void heapSort(int n)
{
    int i;
    buildHeap(n);
    
    for(i=n-1; i>0; i--)
    {
         swap(&A[0], &A[i]);
         maxHeapify(i-1,0);
    }
}

void buildHeap(int n)
{
    int i;
    for(i=(n-2)/2 ; i>=0 ; i--)
        maxHeapify(n,i);
}
void maxHeapify(int n, int i)
{
    int largest=i, left=2*i+1, right=2*i+2;
   
    if(left<n && A[left]>A[largest])
        largest = left;
    if(right<n && A[right] > A[largest])
        largest = right;
    if(largest != i)
    {
        swap(&A[largest] ,&A[i]);
        maxHeapify(n, largest);
    }
}

void swap(int *p, int *q)
{
    int t = *p;
    *p = *q;
    *q = t;
}
