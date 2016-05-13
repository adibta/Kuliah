#include<stdio.h>

void Selection_Sort(int X[],int N);
void Insertion_Sort(int X[],int N);
void Bubble_Sort(int X[],int N);
void Sequential_Search(int X[],int N, int src);
void Binary_Search(int X[],int N,int src);
void Print_Array(int X[], int N);

int main()
{
	int A[10] = {4,6,5,7,1,9,0,3,8,2}, n = 10, valid = 1,x,y,z,cari;
	
	printf("Array A : ");
	Print_Array(A,n);
	
	do
	{
		printf("Pilih Operasi : \n1.Sorting\n2.Searching(Sequential Search)\n");
		scanf("%d",&x);
		switch (x) 
		{
			case 1 :
				{
					printf("Pilih metode : \n1.Selection Sort\n2.Insertion Sort\n3.Bubble Sort\n");
					scanf("%d",&y);
					do
					{
						switch (y)
						{
							case 1 : 
								Selection_Sort(A,n);
								valid = 1;
								break;
							case 2 : 
								Insertion_Sort(A,n);
								valid = 1;
								break;
							case 3 :
								Bubble_Sort(A,n);
								valid = 1;
								break;
							default :
								valid = 0;
								break;
						}
					}while (valid == 0);
					printf("Array setelah urut : ");
					Print_Array(A,n);
					do
					{
						printf("ingin melakukan searching?(binary search) insert 1 = yes, 2 = no \n");
						scanf("%d",&z);
						switch (z) 
						{						
							case 1 :
								valid = 1;
								printf("Cari bilangan?\n");
								scanf("%d",&cari);
								Sequential_Search(A,n,cari);
								break;
							case 2 :
								valid = 1;
								break;
							default :
								valid = 0;
								break;
						}
					}while (valid == 0);
				}
				break; 
			case 2 :
				printf("Cari bilangan?\n");
				scanf("%d",&cari);
				Sequential_Search(A,n,cari);
				break;
			default : 
				valid = 0;
				break;
		}
	}while(valid == 0);
	return 0;
}
void Print_Array(int X[], int N)
{
	int i;
	for (i = 0;i<N;i++)
	{
		printf("%d ",X[i]);
	}
	printf("\n");
}
void Selection_Sort(int X[],int N)
{
	int i,j,min,tmp;
	for (i = 0; i < N-1; i++)
	{
		min = i;
		for (j = i; j < N;j++)
		{
			if (X[j] < X[min])
				min = j;
		}
		tmp = X[i];     //swap
		X[i] = X[min];
		X[min] = tmp;
	}
}
void Insertion_Sort(int X[],int N)
{
	int i,j,key;
	for (i = 1; i < N; i++)
	{
		key = X[i];
		j = i-1;
		while ((j>=0) && (X[j]>key))
		{
			X[j+1] = X[j];
			j--;
		}
		X[j+1] = key;
	}
}
void Bubble_Sort(int X[],int N)
{	
	int i = 0,j, swap,tmp;
	do
	{
		swap = 0;
		for (j = 0; j < N-1-i;j++)
		{
			if (X[j]>X[j+1])
			{
				swap = 1;
				tmp = X[j];
				X[j] = X[j+1];
				X[j+1] = tmp;
			}
		}
		i++;
	}while ((swap = 1) && (i<N-1));
}
void Sequential_Search(int X[],int N,int src)
{
	int i,ketemu = 0;
	for (i=0;i<N;i++)
	{
		if (src==X[i])
		{
			ketemu = 1;
			break;
		}
	}
	if (ketemu) 
		printf("Bilangan yang dicari ada dan terdapat pada indeks %d",i);
	else 
		printf("Bilangan yang dicari tidak ditemukan");	
}
void Binary_Search(int X[],int N,int src)
{
	int awal = 0, akhir = N-1,middle = (awal+akhir)/2;
	while (awal<=akhir)
	{
		if (src == X[middle])
		{
			printf("Bilangan yang dicari ada dan terdapat pada indeks %s",middle);
			break;
		}
		else if (src < X[middle])
			akhir = middle - 1;
		else 
			awal = middle + 1;
		middle = (awal+akhir)/2;
	}
	if (akhir < awal)
		printf ("Bilangan yang dicari tidak ditemukan");
	
}
