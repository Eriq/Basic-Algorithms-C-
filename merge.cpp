#include<iostream>
using namespace std;

/*
	*This method logically divides the original array rather than using two distinct arrays in the divide step
	*The combine step involves copying the two arrays to a temporay array which becomes a single sorted array
	*The entire temporay array is then copied back to the original array.
*/

//Method to merge the two sorted arrays 
void Merge(int *a, int low, int high, int mid) {
	int i, j, k, temp[high-low+1];
	i=low;
	k=0;
	j=mid+1;

	//populate the temp array by comparing both halves of the original array
	while(i<=mid && j<=high) {
		if (a[i] < a[j]) {
			temp[k]=a[i];
			k++;
			i++;
		}
		else {
			temp[k]=a[j];
			k++;
			j++;
		}
	}

	//populate the rest of the temp array with the remaining elements in the left after the elements in the right have all already been copied
	while(i<=mid) {
		temp[k]=a[i];
		k++;
		i++;
	}

	//populate the rest of the temp array with the remaining elements in the right after the elements in the left have all already been copied
	while(j<=high) {
		temp[k]=a[j];
		k++;
		j++;
	}

	//copy all the elements in the temporary array back to the original array
	for (i=low;i<=high;i++) {
		a[i]=temp[i-low];
	}
}


//function to split array into two parts
void mergesort(int *a, int low, int high) {
	int mid;
	if( low<high) {//check for the base case: whether the passed array has a single element
		mid=(low+high)/2;

		mergesort(a, low, mid);
		mergesort(a, mid+1, high);

		Merge(a, low, high, mid);
	}
}


int main() {
	//method to ask for the user to input the size of the array and the elements in the array
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