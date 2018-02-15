#include <time.h>
#include <iostream>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void llenarArreglo(int *a,int i,int n);
void mostrarArreglo(int *a,int i,int n);
void ordenamientoSeleccion(int *a,int i,int j, int n);
void intercambio(int *a,int min,int i);

int main(int argc, char** argv) {
	int i,j,n,*a;
	cout<<"Digite un número mayor a 500";
	cin>>n;
	//if(n<500) return 0;
	srand(time(NULL));
	a = new int[n];  //se inicializa el arreglo
	llenarArreglo(a,i,n); //se llena el arreglo
	mostrarArreglo(a,i,n); //se muestra el arreglo
	ordenamientoSeleccion(*a,i,j,n); //se ordena el arreglo
	cout<<"Mostrando arreglo ordenado: \n"
	mostrarArreglo(a,i,n); //se muestra el arreglo
	system("pause");
	return 0;
}

void llenarArreglo(int *a,int i, int j,int n){
	for(i=0;i<n;i++){
		a[i] = 500+rand()%(1000+1-500);
	}
}

void mostrarArreglo(int *a,int i,int n){
	cout<<"Mostrando el arreglo: \n"
	for(i=0;i<n;i++){
		cout<<a[i]<<"\n";
	}
	cout<<"\n\n"
}

void ordenamientoSeleccion(int *a,int i,int j, int n){
	int min;
	for(i=1;i<n;i++){
		min=i;
		for(j=i+1;j<=n;j++){
			if(a[j]<a[min]) min=j;
			intercambio(*a,min,i)
		}
	}
}

void intercambio(int *a, int i, int min){
	int temp = a[i];
	a[i]=a[min];
	a[min]=temp;
}

