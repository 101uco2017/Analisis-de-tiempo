#include <iostream>
#include <stdlib.h>
#include <windows.h>
void hanoi(int num,char A,char C,char B);
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);
using namespace std;
int main()
{
        int n;
        char A,B,C;
 		LARGE_INTEGER t_ini, t_fin;
  		double secs;
        cout<<"Los clavijas son A B C\n";
        cout<<"Numero de discos: ";
        cin>>n;
        QueryPerformanceCounter(&t_ini); //Midiendo tiempos
        hanoi(n,'A','C','B');
        QueryPerformanceCounter(&t_fin); //Midiendo tiempos
        secs = performancecounter_diff(&t_fin,&t_ini)*1000;
		cout<<n<<" Tiempo total: "<<secs<<"\n";
    	return 0;     
}
void hanoi(int num,char A,char C,char B)
{

    if(num==1)
    {
    		
            //cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
    }
    else
    {
        hanoi(num-1,A,B,C);
        //cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
        hanoi(num-1,B,C,A);      
    }
}
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

