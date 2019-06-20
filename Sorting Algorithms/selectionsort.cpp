#include<iostream>
using namespace std;

int main() {
	int Array[10]={8,2,6,1,9,4,3,5,7,10};
	int n=10;

	for(int i=0;i<n-1;i++) {

		int smallest=Array[i];
		int position=i;

		for(int j=i+1;j<n;j++) {
			if(Array[j]<smallest) {
				smallest=Array[j];
				position=j;
			}
		}

		Array[position]=Array[i];
		Array[i]=smallest;
	}

	for(int k=0;k<n;k++){
		cout<<Array[k]<<" ";
	}

return 0;
}
