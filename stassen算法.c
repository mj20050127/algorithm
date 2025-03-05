#include<stdio.h>
#include<stdlib.h>
void matrixP_multiplication(int **A,int **B,int **C,int n)//矩阵乘法
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            C[i][j]=0;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

void matrix_addition(int **A,int **B,int **C,int n)//矩阵加法
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            C[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}

void matrix_subtraction(int **A,int **B,int **C,int n)//矩阵减法
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            C[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            C[i][j]=A[i][j]-B[i][j];
        }
    }
}

void matrix_partition(int **A,int **A11,int **A12,int **A21,int **A22,int n)//矩阵分离
{
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            A11[i][j]=A[i][j];
        }
    }

    for(int i=0;i<n/2;i++)
    {
        for(int j=n/2;j<n;j++)
        {
            A12[i][j-n/2]=A[i][j];
        }
    }

    for(int i=n/2;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            A21[i-n/2][j]=A[i][j];
        }
    }

    for(int i=n/2;i<n;i++)
    {
        for(int j=n/2;j<n;j++)
        {
            A22[i-n/2][j-n/2]=A[i][j];
        }
    }
}

void matrix_connection(int **A,int **A11,int **A12,int **A21,int **A22,int n)//矩阵连接
{
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            A[i][j]=A11[i][j];
        }
    }

    for(int i=0;i<n/2;i++)
    {
        for(int j=n/2;j<n;j++)
        {
            A[i][j]=A12[i][j-n/2];
        }
    }

    for(int i=n/2;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            A[i][j]=A21[i-n/2][j];
        }
    }

    for(int i=n/2;i<n;i++)
    {
        for(int j=n/2;j<n;j++)
        {
            A[i][j]=A22[i-n/2][j-n/2];
        }
    }
}

void Print(int **A,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d",A[i][j]);
			if(j<n-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void Strassen(int **A,int **B,int **C,int n)
{
    if(n==1) 
    {
        C[0][0]=A[0][0]*B[0][0];
        return;
    }

    int **A11=(int**)malloc((n/2)*sizeof(int*));
    int **A12=(int**)malloc((n/2)*sizeof(int*));
    int **A21=(int**)malloc((n/2)*sizeof(int*));
    int **A22=(int**)malloc((n/2)*sizeof(int*));
    int **B11=(int**)malloc((n/2)*sizeof(int*));
    int **B12=(int**)malloc((n/2)*sizeof(int*));
    int **B21=(int**)malloc((n/2)*sizeof(int*));
    int **B22=(int**)malloc((n/2)*sizeof(int*));
    int **C11=(int**)malloc((n/2)*sizeof(int*));
    int **C12=(int**)malloc((n/2)*sizeof(int*));
    int **C21=(int**)malloc((n/2)*sizeof(int*));
    int **C22=(int**)malloc((n/2)*sizeof(int*));
    int **temp1=(int**)malloc((n/2)*sizeof(int*));
    int **temp2=(int**)malloc((n/2)*sizeof(int*));
    int **temp3=(int**)malloc((n/2)*sizeof(int*));
    int **temp4=(int**)malloc((n/2)*sizeof(int*));

    int **S1=(int**)malloc((n/2)*sizeof(int*));
    int **S2=(int**)malloc((n/2)*sizeof(int*));
    int **S3=(int**)malloc((n/2)*sizeof(int*));
    int **S4=(int**)malloc((n/2)*sizeof(int*));
    int **S5=(int**)malloc((n/2)*sizeof(int*));
    int **S6=(int**)malloc((n/2)*sizeof(int*));
    int **S7=(int**)malloc((n/2)*sizeof(int*));
    int **S8=(int**)malloc((n/2)*sizeof(int*));
    int **S9=(int**)malloc((n/2)*sizeof(int*));
    int **S10=(int**)malloc((n/2)*sizeof(int*));

    int **P1=(int**)malloc((n/2)*sizeof(int*));
    int **P2=(int**)malloc((n/2)*sizeof(int*));
    int **P3=(int**)malloc((n/2)*sizeof(int*));
    int **P4=(int**)malloc((n/2)*sizeof(int*));
    int **P5=(int**)malloc((n/2)*sizeof(int*));
    int **P6=(int**)malloc((n/2)*sizeof(int*));
    int **P7=(int**)malloc((n/2)*sizeof(int*));



    for(int i=0;i<n/2;i++)
    {
        A11[i]=(int *)malloc((n/2)*sizeof(int));
        A12[i]=(int *)malloc((n/2)*sizeof(int));
        A21[i]=(int *)malloc((n/2)*sizeof(int));
        A22[i]=(int *)malloc((n/2)*sizeof(int));
        C11[i]=(int *)malloc((n/2)*sizeof(int));
        C12[i]=(int *)malloc((n/2)*sizeof(int));
        C21[i]=(int *)malloc((n/2)*sizeof(int));
        C22[i]=(int *)malloc((n/2)*sizeof(int));
        B11[i]=(int *)malloc((n/2)*sizeof(int));
        B12[i]=(int *)malloc((n/2)*sizeof(int));
        B21[i]=(int *)malloc((n/2)*sizeof(int));
        B22[i]=(int *)malloc((n/2)*sizeof(int));
        S1[i]=(int *)malloc((n/2)*sizeof(int));
        S2[i]=(int *)malloc((n/2)*sizeof(int));
        S3[i]=(int *)malloc((n/2)*sizeof(int));
        S4[i]=(int *)malloc((n/2)*sizeof(int));
        S5[i]=(int *)malloc((n/2)*sizeof(int));
        S6[i]=(int *)malloc((n/2)*sizeof(int));
        S7[i]=(int *)malloc((n/2)*sizeof(int));
        S8[i]=(int *)malloc((n/2)*sizeof(int));
        S9[i]=(int *)malloc((n/2)*sizeof(int));
        S10[i]=(int *)malloc((n/2)*sizeof(int));
        P1[i]=(int *)malloc((n/2)*sizeof(int));
        P2[i]=(int *)malloc((n/2)*sizeof(int));
        P3[i]=(int *)malloc((n/2)*sizeof(int));
        P4[i]=(int *)malloc((n/2)*sizeof(int));
        P5[i]=(int *)malloc((n/2)*sizeof(int));
        P6[i]=(int *)malloc((n/2)*sizeof(int));
        P7[i]=(int *)malloc((n/2)*sizeof(int));
        temp1[i]=(int *)malloc((n/2)*sizeof(int));
        temp2[i]=(int *)malloc((n/2)*sizeof(int));
        temp3[i]=(int *)malloc((n/2)*sizeof(int));
        temp4[i]=(int *)malloc((n/2)*sizeof(int));
    }

    matrix_partition(A,A11,A12,A21,A22,n);
    matrix_partition(B,B11,B12,B21,B22,n);

    matrix_subtraction(B12,B22,S1,n/2);
    matrix_addition(A11,A12,S2,n/2);
    matrix_addition(A21,A22,S3,n/2);
    matrix_subtraction(B21,B11,S4,n/2);
    matrix_addition(A11,A22,S5,n/2);
    matrix_addition(B11,B22,S6,n/2);
    matrix_subtraction(A12,A22,S7,n/2);
    matrix_addition(B21,B22,S8,n/2);
    matrix_subtraction(A11,A21,S9,n/2);
    matrix_addition(B11,B12,S10,n/2);

    Strassen(A11,S1,P1,n/2);
    Strassen(S2,B22,P2,n/2);
    Strassen(S3,B11,P3,n/2);
    Strassen(A22,S4,P4,n/2);
    Strassen(S5,S6,P5,n/2);
    Strassen(S7,S8,P6,n/2);
    Strassen(S9,S10,P7,n/2);

    matrix_addition(P5,P4,temp1,n/2);
    matrix_subtraction(P2,P6,temp2,n/2);
    matrix_subtraction(temp1,temp2,C11,n/2);
    matrix_addition(P1,P2,C12,n/2);
    matrix_addition(P3,P4,C21,n/2);
    matrix_addition(P5,P1,temp3,n/2);
    matrix_addition(P3,P7,temp4,n/2);
    matrix_subtraction(temp3,temp4,C22,n/2);

    matrix_connection(C,C11,C12,C21,C22,n);

    for (int i = 0; i < n / 2; i++) {
        free(A11[i]);
        free(A12[i]);
        free(A21[i]);
        free(A22[i]);
        free(B11[i]);
        free(B12[i]);
        free(B21[i]);
        free(B22[i]);
        free(C11[i]);
        free(C12[i]);
        free(C21[i]);
        free(C22[i]);
        free(S1[i]);
        free(S2[i]);
        free(S3[i]);
        free(S4[i]);
        free(S5[i]);
        free(S6[i]);
        free(S7[i]);
        free(S8[i]);
        free(S9[i]);
        free(S10[i]);
        free(P1[i]);
        free(P2[i]);
        free(P3[i]);
        free(P4[i]);
        free(P5[i]);
        free(P6[i]);
        free(P7[i]);
        free(temp1[i]);
        free(temp2[i]);
        free(temp3[i]);
        free(temp4[i]);
    }
    free(A11);
    free(A12);
    free(A21);
    free(A22);
    free(B11);
    free(B12);
    free(B21);
    free(B22);
    free(C11);
    free(C12);
    free(C21);
    free(C22);
    free(S1);
    free(S2);
    free(S3);
    free(S4);
    free(S5);
    free(S6);
    free(S7);
    free(S8);
    free(S9);
    free(S10);
    free(P1);
    free(P2);
    free(P3);
    free(P4);
    free(P5);
    free(P6);
    free(P7);
    free(temp1);
    free(temp2);
    free(temp3);
    free(temp4);
}

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int **A=(int**)malloc(M*sizeof(int*));
    int **B=(int**)malloc(M*sizeof(int*));
    int **C=(int**)malloc(M*sizeof(int*));
    for(int i=0;i<M;i++)
    {
        A[i]=(int *)malloc(M*sizeof(int));
        B[i]=(int *)malloc(M*sizeof(int));
        C[i]=(int *)malloc(M*sizeof(int));
    }
    for(int k=0;k<N;k++)
    {
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<M;j++)
            {
                scanf("%d",&A[i][j]);
            }
        }
    
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<M;j++)
            {
                scanf("%d",&B[i][j]);
            }
        } 
        Strassen(A,B,C,M);
        Print(C,M);
    }
    for (int i = 0; i < M; i++) {
        free(A[i]); free(B[i]); free(C[i]);
    }
    free(A);
    free(B);
    free(C);
    return 0;
}