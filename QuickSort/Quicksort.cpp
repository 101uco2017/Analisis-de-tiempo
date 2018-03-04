#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void ordenRapido(int *a, int izq, int der);
void intercambio(int *a,int i,int der);
void llenarArreglo(int *a,int n,int i);
void mostrarArreglo(int *a,int n,int i);
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char *argv[]) {
	//Variables para calcular tiempos
	LARGE_INTEGER t_ini, t_fin;
  	double secs;
	//
	int *a,i,n;
	cout<<"Digite la dimension del arreglo: ";
	cin>>n;
	a = new int[n];
	srand(time(NULL));
	llenarArreglo(a,n,i);
	mostrarArreglo(a,n,i);
	system("pause");
	ordenRapido(a,0,n-1);
	mostrarArreglo(a,n,i);
	return 0;
}

void ordenRapido(int *a, int izq, int der){
	int v,i,j;
	if (der> izq){
		v= a[der]; i = izq -1; j= der;
       	for(;;){
			while (a[++i]<v);
            while (a[--j] >v);
            if(i>=j) break;
            intercambio(a,i,j);
		}
       intercambio(a, i, der);
       ordenRapido(a, izq, i-1);
       ordenRapido(a, i+1,der);
     }
}
void intercambio(int *a,int i,int der){
	int temp;
	temp = a[i];
	a[i]=a[der];
	a[der]=temp;
}

void llenarArreglo(int *a,int n,int i){
	for(i=0;i<n;i++){
		a[i]= 1+rand()%(501-1);
	}
}

void mostrarArreglo(int *a,int n,int i){
	for(i=0;i<n;i++){
		cout<<a[i]<<"\n";
	}
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
	LARGE_INTEGER freq;
  	QueryPerformanceFrequency(&freq);
  	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

