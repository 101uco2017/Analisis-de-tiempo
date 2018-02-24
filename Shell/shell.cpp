#include <stdio.h>
#include <iostream>
#include <stdlib.h>



void ordenshell (int *a, int n);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char *argv[]) {
	int *a,n,i,x;
	cin>>n;
	a = new int[n];
	x= n*50;
	for(i=0;i<n;i++){
		a[i] = x;
		x-=50;
	}
	for(i=0;i<n;i++){
		cout<<a[i]<<"\n";
	}
	cout<<"\n";
	system("pause");
	
	ordenshell(a,n);
	
	for(i=0;i<n;i++){
		cout<<a[i]<<"\n";
	}
	delete a;
	return 0;
}

void ordenshell (int *a, int n){
	int i,j,h;  
	int v;
 	for(h=1; h<=n/9; h= 3*h+1);
 	for(; h>0; h/=3)
 	for(i=h+1;i<=n; i+=1){
		v=a[i-1]; j=i;
        while(j >h && a[j-h-1] > v){
			a[j-1] = a[j-h-1];
			j-=h;
		}
        a[j-1]=v;
    }
}


