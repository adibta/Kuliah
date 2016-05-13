#include<stdio.h>

int main()
{
	int N,i,j,k;
	printf("##Program solusi persamaan linier dengan N peubah dengan menggunakan metode doolittle##\n");
	printf("Tugas akhir praktikum pemrograman dasar oleh :\n");
	printf("Adibta Triantama 15/379157/TK/43099\n");
	printf("\nKeterangan : Setiap kolom dalam matrik dipisahkan oleh 1 spasi, dan setiap baris dalam matrik dipisahkan oleh baris baru (berlaku untuk input dan output)\n");
	printf("\nMasukkan nilai N : ");
	scanf("%d",&N);
	double A[N][N],B[N],Y[N],X[N],L[N][N],U[N][N],tmp;
	printf("\nPersamaan Linier : A * x = B\n");
	//input
	printf("\nMasukkan Matrik A (%d x %d)\n",N,N);
	for (i=0;i<N;i++)                 
	{
		for (j=0;j<N;j++)
		{
			scanf("%lf",&A[i][j]);
		}
	}
	printf("Masukkan Matrik B (%d x 1)\n",N);
	for (i=0;i<N;i++)                 
		scanf("%lf",&B[i]);
	printf("Matriks x (%d x 1): \n",N);
	for (i=0;i<N;i++)
		printf("x%d\n",i);
	printf("\nMetode Doolittle : A = L * U\n");
//	LU Processor
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			if (i>j)
			{	
				U[i][j]=0;
				tmp = 0;
				for (k=0;k<(j);k++)
					tmp += L[i][k]*U[k][j];
				L[i][j] = (A[i][j] - tmp)/U[j][j];
			
			}
			else if (i==j)
			{
				L[i][j]=1;
				tmp = 0;
				for (k=0;k<(i);k++)
					tmp += L[i][k]*U[k][j];
				U[i][j] = A[i][j] - tmp;
			}
			else
			{	
				L[i][j]=0;
				tmp = 0;
				for (k=0;k<(i);k++)
					tmp += L[i][k]*U[k][j];
				U[i][j] = A[i][j] - tmp;
				
			}
		}
	}
	printf("\nMatrik L : \n");
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			printf("%.2lf ",L[i][j]);
		}
		printf("\n");
	}				
	printf("\nMatrik U : \n");
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			printf("%.2lf ",U[i][j]);
		}
		printf("\n");
	}	
	printf("\nPersamaan A * x = B dapat dijabarkan menjadi L * U * x = B\n");
	printf("Misal U * x = Y, maka L * Y = B\n");
	//Y processor
	for (i=0;i<N;i++)
	{
		tmp = 0;
		for (k=0;k<i;k++)
			tmp += L[i][k] * Y[k];
		Y[i] = B[i] - tmp;

	}
	printf("\nMatrik Y : \n");
	for (i=0;i<N;i++)
	{
		printf("%.2lf ",Y[i]);
		printf("\n");
	}
	printf("\nKarena U * x = Y, maka\n");
	//X Processor
	for (i=(N-1);i>=0;i--)
	{
		tmp = 0;
		for (k = i+1;k<N+1;k++)
			tmp += U[i][k]*X[k]; 
		X[i] = (Y[i] - tmp)/U[i][i];
	}
	printf("\nMatrik x(Jawaban) : \n");
	for (i=0;i<N;i++)
	{
		printf("x%d = %.2lf\n",i,X[i]);
	}
	return 0;
}

