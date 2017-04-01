//            SNIPPET COMPETITIVE PROGRAMMING
//#####################################################
//#1 Template program ICPC
//   Input : testCase(wajib), dll
//   Output : 
//   Case #1 : out1
//   Case #1 : out1
//   dst
#include<iostream>
using namespace std;
int main(){
	int tCase;
	cin >>tCase;
	for(int t = 0;t < tCase; t++){
		
		//Tulis Program disini
		
		cout<<"Case #"<<t+1<<" : ";
		//Tulis Output disini
		
		cout<<endl;
	}
}

//#####################################################
//#2 FPB KPK
//   Input : masing masing 2 integer
//   Output : sebuah integer
int fpb(int a,int b)
{
	if(a%b==0)
		return b;
	else 
		return fpb(b,a%b)
}
int kpk(int a,int b)
{
	return (a*b)/fpb(a,b);
}

//#####################################################
//#3 Mencetak Array
//   Input : pointer Array, jumlah indek Array
//   Output : isi array dipisah spasi
void PrintArray(int X[],int n)
{
	for (int i = 0;i<n;i++)
	{
		cout<<X[i];
		if (i != n-1){
		cout<<" ";
		}
	}
	cout<<endl;
}

//#####################################################
//#3 Searching
//   Input : pointer Array, jumlah indek Array, angka yang dicari
//   Output : indek jawaban
//   keterangan tambahan
//   	indeks output dimulai dari nol
void SequentialSearch(int X[],int n,int src)
{	
	bool ketemu = false;
	int i;
	for (i=0 ;i<n;i++)
	{
		if (src==X[i])
		{
			ketemu = true;
			break;
		}
	}
	if (ketemu) 
		cout<<"Bilangan yang dicari ada dan terdapat pada indeks "<<i<<endl;
	else 
		cout<<"Bilangan yang dicari tidak ditemukan"<<endl;	
}

void BinarySearch(int X[],int n,int src)
{
	int awal = 0, akhir = n-1;
	int middle = (awal+akhir)/2;
	while (awal<=akhir)
	{
		if (src == X[middle])
		{
			cout<<"Bilangan yang dicari ada dan terdapat pada indeks "<<middle;
			break;
		}
		else if (src < X[middle])
			akhir = middle - 1;
		else 
			awal = middle + 1;
		middle = (awal+akhir)/2;
	}
	if (akhir < awal)
		cout<<"Bilangan yang dicari tidak ditemukan";
	cout<<endl;
}


//#####################################################
//#3 Sorting InsertionSort
//   Input : pointer Array, jumlah indek Array, arah menaik atau menurun
//   Output : array terurut
//   keterangan tambahan
//   	masukan berupa pointer sehingga perubahan array langsung memengaruhi pada main
//      arah terurut menaik gunakan 'ASC'
// 		arah terurut menurun gunakan 'DSC'
void InsertionSort(int X[],int n, string arah)
{
	int i,j,key;
	bool condition;
	
	for (i = 1; i < n; i++)
	{
		key = X[i];
		j = i-1;
		if (arah == "ASC"){	
			while ((j>=0) && (X[j]>key))
			{
				X[j+1] = X[j];
				j--;
			}
		}
		else{
			while ((j>=0) && (X[j]<key))
			{
				X[j+1] = X[j];
				j--;
			}
		}
		X[j+1] = key;
	}
}

//#4 ContohImplementasi
void Implementasi(){
	int X[5] = {4,3,6,7,2};
	int n = sizeof(X)/sizeof(*X); 
	PrintArray(X,n);
	SequentialSearch(X,n,2);
	BinarySearch(X,n,4);
	InsertionSort(X,n,"ASC");
	PrintArray(X,n);
	InsertionSort(X,n,"DSC");
	PrintArray(X,n);
}
