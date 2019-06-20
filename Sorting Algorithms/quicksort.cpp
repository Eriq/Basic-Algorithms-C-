#include<iostream>
#include "generalmethods.h"
using namespace std;
using namespace algo;

int partition (int *Array, int p, int r) {
	int x=Array[r];
	int i=p-1;

	for(int j=p;j<r;j++) {
		if(Array[j]<=x) {
			i=i+1;
			exchange(Array[i], Array[j]);
		}
	}
    exchange(Array[i+1], Array[r]);

    return i+1;
}

int randomPartition(int *Array, int p, int r) {
    int i=random(p,r);
    exchange(Array[r],Array[i]);
    return partition(Array,p,r);
}

void quicksort (int *Array, int p, int r) {
	if (p<r) {
		int q=randomPartition(Array,p,r);
		quicksort(Array, p, q-1);
		quicksort(Array, q+1, r);
	}
}

int main() {
    using namespace algo;

    int listsize;
    cout<<"Enter the listsize ";
    cin>>listsize;
    int Array[listsize];

    createlist(Array,listsize);

    listprint(Array,listsize);

    int p=0;
    int r=listsize-1;
    quicksort(Array, p, r);

    listprint(Array,listsize);



	return 0;
}
