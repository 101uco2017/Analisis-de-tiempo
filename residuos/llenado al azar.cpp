#include <iostream>
#include <time.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void llenarAleatorio(char a[], int n, int i);
void mostrarArreglo(char a[], int n, int i);
int unsigned  bits (int x, int k, int j);
void cambioresiduos(char a[], int izq, int der, int b,int temp);
void intercambio (char a [],int i,int j, int temp);
using namespace std;
int main(int argc, char** argv) {
	srand (time(NULL));
	int n, i;
	int temp;
	char *a;
	cin>> n;	
	a= new char [n];
	llenarAleatorio(a,n,i);
	mostrarArreglo(a,n,i);
	system ("pause");
	cambioresiduos (a,0,n,5,temp);
	mostrarArreglo(a,n,i);
	delete a;	
	return 0;
	
}

void llenarAleatorio (char a[], int n, int i){
	for (i=0; i<n;i++){
		a[i]= (65+rand()%(80-65));
	}
}
void mostrarArreglo(char a[],int n,int i){
	for(i=0;i<n;i++){
		cout<<a[i]<<"\n";
	}
	cout<<"\n\n";
}
int unsigned  bits (int x, int k, int j){
 return (x>>k)&~(~0<<j);
}

void cambioresiduos(char a[], int izq, int der, int b, int  temp)
{ int i,j;
   if (der>izq && b>0)
     {i= izq; j=der;
       while(j!=i)
          {while(!bits(a[i],b,1) && i<j)i++;
            while(bits(a[j],b,1) && j>i)j--;
             intercambio(a, i, j,temp);
           }
        if (!bits(a[i],b,1)) j++;
            cambioresiduos(a, izq, j-1, b-1,temp);
            cambioresiduos(a, j, der, b-1,temp);
      }
}
void intercambio (char a [],int i,int j, int temp){
	temp = a [i];
	a[i] = a[j];
	a[j] = temp;
}
