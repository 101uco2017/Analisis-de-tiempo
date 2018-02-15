#include <iostream>
#include <time.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void llenarArreglo(int *a,int i,int n);
void mostrarArreglo(int *a,int i,int n);
void ordenamientoInsercion(int *a,int i,int j, int n);

int main(int argc, char** argv) {
	int i,j,n,*a;
	cout<<"Digite un número mayor a 500";
	cin>>n;
	//if(n<500) return 0;
	srand(time(NULL));
	a = new int[n];  //se inicializa el arreglo
	llenarArreglo(a,i,n); //se llena el arreglo
	mostrarArreglo(a,i,n); //se muestra el arreglo
	ordenamientoInsercion(*a,i,j,n); //se ordena el arreglo
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

void ordenamientoInsercion(int *a,int i,int j, int n){
	int b;
	for(i=1;i<n;i++){
		b=a[i];
		j=i-1;
		while(j>-1 && b<a[j]){
			a[j+1]=a[j];
			j-=1;
		}
		a[j+1]=b;
	}
}

