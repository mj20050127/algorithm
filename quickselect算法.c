#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int random_partition(int *A,int p,int r)   
{
    int pivot=A[r];
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        if(A[j]<pivot)
        {
            i++;
            swap(&A[j],&A[i]);
        }
    }
    swap(&A[i+1],&A[r]);
    return i+1;
}

int Quickselect(int *A,int left,int right,int k)
{
    if(left==right)
    {
        return A[left];
    }

    int pivot=random_partition(A,left,right);
    if(k==pivot)
    {
        return A[k];
    }else if(k<pivot)
    {
        return Quickselect(A,left,pivot-1,k);
    }else
    {
        return Quickselect(A,pivot+1,right,k);
    }
}

int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    int *A=(int *)malloc(sizeof(int)*1000);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int x=Quickselect(A,0,n,k);
    printf("%d",x);
    free(A);
    return 0;
}