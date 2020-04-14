#include<stdio.h>
#include "stdlib.h"


void Show(int  arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}

void Merge(int array[], int left, int mid, int right)
{
    int *aux =(int*)malloc((right-left+1)*sizeof(int)) ;  
    int i=left; 
    int j=mid+1; 
    int k;

    for ( k = 0; k <= right - left; k++) 
    {
        
        if (i == mid + 1)
        {
            aux[k] = array[j++];
            continue;
        } 
        if (j == right + 1)
        {
            aux[k] = array[i++];
            continue;
        }
       
        if (array[i] < array[j])
        {
            aux[k] = array[i++];
        }
        
        else
        {
            aux[k] = array[j++];
        }
    }

    
    for (i = left, j = 0; i <= right; i++, j++)
    {
        array[i] = aux[j];
    }
}


void MergeSort(int array[], int start, int end,int t[])
{
    if (start < end)
    {
        
        int mid= (end + start) / 2;
        
        MergeSort(array, start, mid,t);
        
        MergeSort(array, mid + 1, end,t);
        
        Merge(array, start, mid, end);
    }
}

int main()
{   //测试数据
    int b[100] = {0};
    int arr_test[10] = { 8, 4, 2, 3, 5, 1, 6, 9, 0, 7 };
    //排序前数组序列
    Show(arr_test, 10);
    MergeSort(arr_test, 0, 10,b -1 );
    //排序后数组序列
    Show(arr_test, 10);
    return 0;
    
}


