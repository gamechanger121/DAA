#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int *A,int n)
{
    for(int i = 0;i < n; i++)
    {
        printf("%d ",A[i]);
        
    }
}

void InsertionSort(int *A,int n)
{
    int key,j;
    for(int i = 0;i <= n-1; i++)
    {
        key = A[i];
        j = i-1;
        while (j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main()
{
    int n,*ptr;
    int cpu_time_used;

    printf("Enter the size of the array\n");
    scanf("%d",&n);

    ptr = (int*)malloc(n*sizeof(int));

    printf("Enter the elements in array\n");
    for(int i = 0;i < n; i++)
    {
        scanf("%d",&ptr[i]);
    }

    printf("Before Sort\n");
    printArray(ptr,n);
    int start = clock();
    InsertionSort(ptr,n);
    int end  = clock();
    printf("\nAfter Sort\n");
    printArray(ptr,n);

    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Time : %d",cpu_time_used);
}

