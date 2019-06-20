#include<iostream>
#include<limits>
using namespace std;

/*
    *This method divides the original array into two disticnt array of equal sizes in the divide step
    *Compares the elements in each array and copies them back to the original accordingly during the combine step
    *It uses an extra place holder element as the last element in each of the new arrays with an "infinite" value
    *The extra element identifies the end of the array during the combine step
*/

void merge(int *Array, int lowIndex, int highIndex, int mid) {
    int nL=mid-lowIndex+1; //declare size of the Left Array
    int nR=highIndex-mid; //declares size of the Right Array

    int L[nL+1]; //declares Left Array
    int R[nR+1]; //declares Right Array

    //populates Left Array
    for(int i=0;i<nL;i++) {
        L[i]=Array[lowIndex+i];
    }
    L[nL]=std::numeric_limits<int>::max(); //sets the last element in the left array to max positive int "infinite" 

    //populates Right Array
    for(int j=0;j<nR;j++) {
        R[j]=Array[mid+j+1];
    }
    R[nR]=std::numeric_limits<int>::max(); //sets the last element in the right array to max positive int "infinite"

    int i=0;
    int j=0;

    //retutn sorted values to the orginal Array
    for(int k=lowIndex;k<highIndex+1;k++) {
        if(L[i]<=R[j]) {
            Array[k]=L[i];
            i++;
        }

        else {
            Array[k]=R[j];
            j++;
        }
    }
}

void mergesort(int *Array, int lowIndex, int highIndex) {
    int mid;

    if (lowIndex<highIndex) {//checks for the base case: ie. whether the passed array has a single element
        mid=(highIndex+lowIndex)/2;

        mergesort(Array, lowIndex, mid);
        mergesort(Array, mid+1, highIndex);

        merge(Array, lowIndex, highIndex, mid);
    }
}

int main() {
	//ask the user to input the size of the array and the elements in the array
    int n;

    cout<<"Enter the size of the Array ";
    cin>>n;

    int Array[n]; //declare the array after getting the size
    for(int i=0;i<n;i++) { //loop to initialize values in the array
        cout<<"Enter item "<<i+1<<" into the Array ";
        cin>>Array[i];
    }

    cout<<"Array = {";
    for(int i=0;i<n-1;i++) { //function to display items entered into the array
        cout<<Array[i]<<", ";
    }
    cout<<Array[n-1]<<"}";

    mergesort(Array, 0, n-1);//merge sort function call

    cout<<"\n\nSorted Array = {";
    for(int i=0;i<n-1;i++) { //function to display items entered into the array
        cout<<Array[i]<<", ";
    }
    cout<<Array[n-1]<<"}\n\n";

	return 0;
}
