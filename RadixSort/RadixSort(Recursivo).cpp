#include <algorithm>
#include <iostream>
#include <iterator>
#include <time.h>
 
 void llenarArreglo(int *a,int n,int i);
 void mostrarArreglo(int *data, int n,int i);
 
 using namespace std;
 
// Radix sort comparator for 32-bit two's complement integers
class radix_test
{
    const int bit; // bit position [0..31] to examine
public:
    radix_test(int offset) : bit(offset) {} // constructor
 
    bool operator()(int value) const // function call operator
    {
        if (bit == 31) // sign bit
            return value < 0; // negative int to left partition
        else
            return !(value & (1 << bit)); // 0 bit to left partition
    }
};
 
// Least significant digit radix sort
void lsd_radix_sort(int *first, int *last)
{
    for (int lsb = 0; lsb < 32; ++lsb) // least-significant-bit
    {
        std::stable_partition(first, last, radix_test(lsb));
    }
}
 
// Most significant digit radix sort (recursive)
void msd_radix_sort(int *first, int *last, int msb = 31)
{
    if (first != last && msb >= 0)
    {
        int *mid = std::partition(first, last, radix_test(msb));
        msb--; // decrement most-significant-bit
        msd_radix_sort(first, mid, msb); // sort left partition
        msd_radix_sort(mid, last, msb); // sort right partition
    }
}
 
// test radix_sort
int main()
{
	int n=10,i;
    int *data = new int [n];
    srand(time(NULL));
 	llenarArreglo(data,n,i);
 	mostrarArreglo(data,n,i);
 	system("pause");
    lsd_radix_sort(data, data + n);
    // msd_radix_sort(data, data + 8);
 
    std::copy(data, data + n, std::ostream_iterator<int>(std::cout, " "));
    return 0;
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
	cout<<endl;
}

