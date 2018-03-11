#include <iostream>
#include <time.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void mergesort(int a [], int first, int last);
void mergelists(int a [], int start1, int end1, int start2,int end2);
void llenarArreglo(int *a,int n,int i);
void mostrarArreglo(int *a,int n,int i);
using namespace std;
int main(int argc, char** argv) {
	srand (time(NULL));
	int *a;
	int n;
	int i;
	cin>>n;
	a= new int [n];
	llenarArreglo(a,n,i);
	mostrarArreglo(a,n,i);
	system("pause");
	mergesort(a,0,n-1);
	cout<<"Ordenado ";
	mostrarArreglo(a,n,i);
	
	delete a;
	return 0;
}
void mergesort(int a [], int first, int last){
	int middle;
	if (first<last){
		middle =(first + last)/2;
		mergesort(a,first, middle);
		mergesort (a,middle+1,last);
		mergelists(a,first,middle,middle+ 1,last);
	}
}
void mergelists(int a [], int start1, int end1, int start2,int end2){
	int *result = new int[(end2-start1+1)];
	int finalStart= start1;
	int finalEnd = end2;
	int indexC=0;
	int i;
	while (start1<=end1 && start2<=end2){
		if (a[start1]<a[start2]){
			result [indexC]=a[start1];
			start1++;
		}
		else {
			result [indexC]=a[start2];
			start2++;
		}
		indexC++;
	}
	if(start1<=end1){
		for (i=start1; i<=end1;i++){
			result [indexC]=a[i];
			indexC++;
		} 				
	}	
	else {
		for (i=start2; i<=end2;i++){
			result [indexC]=a[i];
			indexC++;
		} 
	}
	indexC=0;
	for(i=finalStart;i<=finalEnd; i++){
		a[i]=result [indexC];
		indexC++;
		mostrarArreglo(result,(end2-start1+1),i);
		cout<<"\n";
	}
}
void llenarArreglo(int *a,int n,int i){
	for(i=0;i<n;i++){
		a[i]= 1+rand()%(501-1);
	}
}
void mostrarArreglo(int *a,int n,int i){
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
