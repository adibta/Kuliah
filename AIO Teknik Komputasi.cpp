#include<iostream>
#include<cmath>
using namespace std;

//Class
class func
{
	public:
		double a,b,c;
		void set_value(double,double,double);
		double fresult(double);
		double ffresult(double);
};

void func::set_value(double x,double y,double z)
{
	a = x;
	b = y;
	c = z;
}

double func::fresult(double nil_x)
{
	return(a*pow(nil_x,2)+b*nil_x+c);
}

double func::ffresult(double nil2_x)
{
	return(2*a*nil2_x+b);
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
	int counter=1;
	input_value(persamaan);
	cout<<"#Metode Bisection# "<<endl;
	cout<<"||Toleransi Error =  0.00001||"<<endl;
	cout<<"Tentukan Batas atas dan batas bawah"<<endl;
	cout<<"Batas atas = ";
	cin>>xu;
	cout<<"Batas bawah = ";
	cin>>xl;
	if (persamaan.fresult(xu)*persamaan.fresult(xl) <= 0 )
	{
		while (true)
		{
			cout<<"##Iterasi ke-"<<counter<<"##"<<endl;
			cout<<"Batas atas = "<<xu<<endl;
			cout<<"Batas bawah = "<<xl<<endl;
			xr = (xu + xl)/2;
			cout<<"Nilai tengah = "<<xr<<endl;
			if (abs(persamaan.fresult(xr)) < 0.00001)
			{
				cout <<"akar persamaannya adalah : "<<xr<<endl;
				cout <<"Operasi Bisection berhenti pada iterasi ke-"<<counter<<endl;
				break;
			}
			else if (persamaan.fresult(xl)*persamaan.fresult(xr) < 0)
				xu = xr;
			else
				xl = xr;
			cout <<endl;
			counter++;
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
	int counter;
	input_value(persamaan);
	cout<<"#Metode False Position#"<<endl;
	cout<<"||Toleransi Error =  0.00001||"<<endl;
	cout<<"Tentukan Batas atas dan batas bawah (f(xl) harus < 0 dan f(xu) harus > 0)"<<endl;
	cout<<"Batas atas = ";
	cin>>xu;
	cout<<"Batas bawah = ";
	cin>>xl;
	if ((persamaan.fresult(xu))>0 && (persamaan.fresult(xl) <0) )
	{
		while (true)
		{
			cout<<"##Iterasi ke-"<<counter<<"##"<<endl;
			cout<<"Batas atas = "<<xu<<endl;
			cout<<"Batas bawah = "<<xl<<endl;
			xr = (xl*persamaan.fresult(xu)-xu*persamaan.fresult(xl))/(persamaan.fresult(xu)-persamaan.fresult(xl));
			cout<<"Nilai tengah = "<<xr<<endl;
			if (abs(persamaan.fresult(xr)) < 0.00001)
			{
				cout <<"akar persamaannya adalah : "<<xr<<endl;
				cout <<"Operasi False Position berhenti pada iterasi ke-"<<counter<<endl;
				break;
			}
			else if (persamaan.fresult(xr) < 0)
				xl = xr;
			else
				xu = xr;
			cout <<endl;
			counter++;
		}
	}
	else 
		cout<< "Batas bawah atau batas atas tidak memenuhi persyaratan"<<endl;
}

void newtonraphson()
{
	func persamaan;
	double x,xi,xiplus;
	int counter=1;
	input_value(persamaan);
	cout<<"#Metode Newton-Raphson#"<<endl;
	cout<<"||Toleransi Error =  0.00001||"<<endl;
	cout<<"Tentukan nilai x awal (bebas)"<<endl;
	cout<<"x = ";
	xi = x;
	cin>>x;
	while (true)
	{
		cout<<"##Iterasi ke-"<<counter<<"##"<<endl;
		cout<<"x(i) = "<<xi<<endl;
		xiplus = xi - (persamaan.fresult(xi)/persamaan.ffresult(xi));
		cout<<"x(i+1) = "<<xiplus<<endl;
		xi = xiplus;
		if (persamaan.fresult(xi) < 0.00001)
		{
			cout <<"akar persamaannya adalah : "<<xi<<endl;
			cout <<"Operasi Newton-Raphson berhenti pada iterasi ke-"<<counter<<endl;
			break;
		}
		counter++;
	}
}
void secant()
{
	func persamaan;
	double x1,x2,xi,xiplus,ximin;
	int counter=1;
	input_value(persamaan);
	cout<<"#Metode Secant#"<<endl;
	cout<<"||Toleransi Error =  0.00001||"<<endl;
	cout<<"Tentukan nilai x0 dan x1 awal (bebas)"<<endl;
	cout<<"x0 = ";
	cin>>ximin;
	cout<<"x1 = ";
	cin>>xi;
	while (true)
	{
		cout<<"##Iterasi ke-"<<counter<<"##"<<endl;
		cout<<"x(i-1) = "<<ximin<<endl;
		cout<<"x(i) = "<<xi<<endl;
		xiplus = xi - (persamaan.fresult(xi)*((xi-ximin)/(persamaan.fresult(xi)-persamaan.fresult(ximin))));
		cout<<"x(i+1) = "<<xiplus<<endl;
		ximin = xi;
		xi = xiplus;
		if (persamaan.fresult(xi) < 0.00001)
		{
			cout <<"akar persamaannya adalah : "<<xi<<endl;
			cout <<"Operasi Secant Method berhenti pada iterasi ke-"<<counter<<endl;
			break;
		}
		counter++;
	}
}
//Main
int main()
{
	int pilihan;
	cout<< "ALL IN ONE SOLUTION TEKNIK KOMPUTASI"<<endl<<"PILIH METODE"<<endl;
	cout<< "1. Bisection\n2. False Position\n3. Newton-Raphson\n4. Secant";
	cout<<endl;
	cin>>pilihan;
	switch (pilihan)
	{
		case 1: bisection();
		case 2: falsePosition();
		case 3: newtonraphson();
		case 4: secant();
	}
	return 0;
}
//EndMain
