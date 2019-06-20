#include<iostream>
#include"generalmethods.h"
using namespace std;


void maxHeapify (int *Array, int i, int arraysize) {
	int l = 2*i+1;
	int r = 2*i+2;
	int largest;

	if(l < arraysize && Array[l] > Array[i]) {
		largest = l;
	}
	else {
		largest=i;
	}

	if(r < arraysize && Array[r] > Array[largest]) {
		largest=r;
	}

	if(largest != i) {
		int temp = Array[i];
		Array[i]=Array[largest];
		Array[largest]=temp;

		maxHeapify(Array, largest, arraysize);
	}
}

void buildMaxheap(int *Array, int arraysize) {
	int n=arraysize-1;
	for(int i=n/2;i>=0;i--) {
		maxHeapify(Array, i, arraysize);
	}
}

void heapSort(int *Array, int arraysize) {
	buildMaxheap(Array, arraysize);
	int n=arraysize-1;
	for(int i=n;i>=1;i--) {
		int temp=Array[0];
		Array[0]=Array[i];
		Array[i]=temp;

		arraysize=arraysize-1;
		maxHeapify(Array, 0, arraysize);
	}
}

int main() {
    using namespace algo;
    
    int n;
    cout<<"Enter the size of the Array ";
    cin>>n;
	int Array[n];

    createlist(Array, n);
    listprint(Array, n);
    heapSort(Array, n);
    listprint(Array, n);

	return 0;
}
