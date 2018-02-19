#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void llenarArreglo(int *a,int i,int n);
void mostrarArreglo(int *a,int i,int n);
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);
int busquedaBinaria(int *a, int tamano, int clave);

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int c=1;
	while(c=1){
		//Variables para calcular tiempos
		LARGE_INTEGER t_ini, t_fin;
  		double secs;
  		//
		int i,j,n,*a;
		cout<<"Digite la dimesion del arreglo: ";
		cin>>n;
		srand(time(NULL));
		a = new int[n];  //se inicializa el arreglo
		llenarArreglo(a,i,n); //se llena el arreglo
		cout<<"Mostrando el arreglo: \n";
		mostrarArreglo(a,i,n); //se muestra el arreglo
		QueryPerformanceCounter(&t_ini); //Midiendo tiempos
		busquedaBinaria(a,n,busca); //
		QueryPerformanceCounter(&t_fin); //Midiendo tiempos
		cout<<"Mostrando arreglo ordenado: \n";
		mostrarArreglo(a,i,n); //se muestra el arreglo
		secs = performancecounter_diff(&t_fin,&t_ini)*1000;
		cout<<"\nTiempo total: "<<secs<<"\n";
		delete a;
		cin>>c;
	}
	system("pause");
	return 0;
}


int busquedaBinaria(int *a, int tamano, int clave)
{
	int iArriba = tamano-1;
	int iAbajo = 0;
	int iCentro;
	while (Iabajo <= iArriba)
	{
		Icentro = (iArriba + Iabajo)/2;
		if (a[Icentro] == clave)
 			return Icentro;
      	else
 		if (clave < a[Icentro])
   			iArriba=iCentro-1;
 		else
   			iAbajo=iCentro+1;
    }
  	return -1;
}

void llenarArreglo(int *a,int i,int n){
	int x=50*n;
	for(i=0;i<n;i++){
		a[i] = 1+rand()%(50+1-1)+x;
		x-=50;
	}
}

void mostrarArreglo(int *a,int i,int n){
	for(i=0;i<n;i++){
		cout<<a[i]<<"\n";
	}
	cout<<"\n\n";
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
