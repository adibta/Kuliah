#include<iostream>
#include<cmath>
using namespace std;

//Class
class func
{
	public:
		double a,b,c;
		void set_value(double,double,double);
		double result(double);
};

void func::set_value(double x,double y,double z)
{
	a = x;
	b = y;
	c = z;
}

double func::result(double nil_x)
{
	return(a*pow(nil_x,2)+b*nil_x+c);
}

void input_value(func& pers)
{
	double d,e,f;
	cout<<"Fungsi f(x) = ax2 + bx + c"<<endl;
	cout<<"Masukkan nilai a : ";
	cin>>d;
	cout<<"Masukkan nilai b : ";
	cin>>e;
	cout<<"Masukkan nilai c : ";
	cin>>f;
	pers.set_value(d,e,f);
}
//EndClass

//Methods
void bisection()      //Terbukti valid
{
	func persamaan;
	double xu,xl,xr;
	int iter;
	input_value(persamaan);
	cout<<"#Metode Bisection#"<<endl;
	cout<<"Tentukan Batas atas dan batas bawah"<<endl;
	cout<<"Batas atas = ";
	cin>>xu;
	cout<<"Batas bawah = ";
	cin>>xl;
	cout<<"Jumlah iterasi = ";
	cin>>iter;
	if (persamaan.result(xu)*persamaan.result(xl) <= 0 )
	{
		for (int j = 0;j<iter;j++)
		{
			cout<<"##Iterasi ke-"<<j+1<<"##"<<endl;
			cout<<"Batas atas = "<<xu<<endl;
			cout<<"Batas bawah = "<<xl<<endl;
			xr = (xu + xl)/2;
			cout<<"Nilai tengah = "<<xr<<endl;
			if (persamaan.result(xr) == 0)
			{
				cout <<"akar persamaannya adalah : "<<xr<<endl;
				cout <<"Operasi Bisection berhenti pada iterasi ke-"<<j+1<<endl;
				break;
			}
			else if (persamaan.result(xl)*persamaan.result(xr) < 0)
				xu = xr;
			else
				xl = xr;
			if ((j == iter-1)&&(persamaan.result(xr) != 0))
			{
				cout<<"Akar persamaan hasil pendekatan dengan "<<j+1<<" iterasi adalah : "<<xr<<endl;
			}
			cout <<endl;
		}
	}
	else 
		cout<< "Akar persamaan tidak berada diantara batas atas dan batas bawah"<<endl;
}
//EndMethods
void falsePosition()  //Belum Dibuktikan  
{
	func persamaan;
	double xu,xl,xr;
	int iter;
	input_value(persamaan);
	cout<<"#Metode False Position#"<<endl;
	cout<<"Tentukan Batas atas dan batas bawah (f(xl) harus < 0 dan f(xu) harus > 0)"<<endl;
	cout<<"Batas atas = ";
	cin>>xu;
	cout<<"Batas bawah = ";
	cin>>xl;
	cout<<"Jumlah iterasi = ";
	cin>>iter;
	if ((persamaan.result(xu))>0 && (persamaan.result(xl) <0) )
	{
		for (int j = 0;j<iter;j++)
		{
			cout<<"##Iterasi ke-"<<j+1<<"##"<<endl;
			cout<<"Batas atas = "<<xu<<endl;
			cout<<"Batas bawah = "<<xl<<endl;
			xr = (xl*persamaan.result(xu)-xu*persamaan.result(xl))/(persamaan.result(xu)-persamaan.result(xl));
			cout<<"Nilai tengah = "<<xr<<endl;
			if (persamaan.result(xr) == 0)
			{
				cout <<"akar persamaannya adalah : "<<xr<<endl;
				cout <<"Operasi False Position berhenti pada iterasi ke-"<<j+1<<endl;
				break;
			}
			else if (persamaan.result(xr) < 0)
				xl = xr;
			else
				xu = xr;
			if ((j == iter-1)&&(persamaan.result(xr) != 0))
			{
				cout<<"Akar persamaan hasil pendekatan dengan "<<j+1<<" iterasi adalah : "<<xr<<endl;
			}
			cout <<endl;
		}
	}
	else 
		cout<< "Batas bawah atau batas atas tidak memenuhi persyaratan"<<endl;
}

//Main
int main()
{
	int pilihan;
	cout<< "ALL IN ONE SOLUTION TEKNIK KOMPUTASI"<<endl<<"PILIH METODE"<<endl;
	cout<< "1. Bisection\n2. False Position";
	cout<<endl;
	cin>>pilihan;
	switch (pilihan)
	{
		case 1: bisection();
		case 2: falsePosition();
	}
	return 0;
}
//EndMain
