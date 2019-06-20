#include<iostream>
#include "generalmethods.h"

using namespace std;

int maxint(int *Array, int listsize) {
	int maxint=Array[0];
	for(int i=0;i<listsize;i++) {
		if(Array[i]>maxint)
			maxint=Array[i];
	}
	return maxint;
}

void countingsort(int *array, /*int *B,*/ int size) {
	/*int n=maxint(A,listsize);
	int C[n+1];
	for(int i=0;i<=n;i++){ //populate C with zeros
		C[i]=0;
	}

	for(int j=0;j<listsize;j++){ //count elements equal to i and store in C[i]
		C[A[j]]=C[A[j]]+1;
	}

	for(int i=1;i<=n;i++){ //find total number of items less than i and store in C[i]
		C[i]=C[i]+C[i-1];
	}

	for(int j=listsize-1;j>=0;j--){
		B[C[A[j]]-1]=A[j]; //populate B with elements in correct position
		C[A[j]]=C[A[j]]-1; //decrement number of items less than in in C[i]
	}*/

	int largest = array[0];
        for (int i=1; i<size; i++) {
            if(array[i] > largest ) {
                largest = array[i];
            }
        }

        int tempsize = largest+1;
        int temp[tempsize];

        for (int i=0; i<tempsize; i++) {
            temp[i] = 0;
        }

        for (int i=0; i<size; i++) {
            temp[array[i]] = temp[array[i]] + 1;
        }

        int j = 0;
        for (int i=0; i<tempsize; i++) {
            while (temp[i] > 0) {
                array[j] = i;
                temp[i] = temp[i] - 1;
                j++;
            }
        }
}

int main() {
	using namespace algo;
	int listsize;
	cout<<"Enter list size"<<endl;
	cin>>listsize;

	/*int A[listsize],B[listsize];
	createlist(A,listsize);
	listprint(A,listsize);
	countingsort(A,B,listsize);
	listprint(B,listsize);*/

	int array[listsize];
	createlist(array, listsize);
	listprint(array, listsize);
	countingsort(array, listsize);
	listprint(array, listsize);

	return 0;
}
