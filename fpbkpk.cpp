#include<iostream>
using namespace std;
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
