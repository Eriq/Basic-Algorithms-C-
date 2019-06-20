#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
namespace algo {

	template <typename T>
	void exchange(T &x, T &y) {
		T w = x;
		x = y;
		y = w;
	}

	static void listprint(int *Array, int listsize) {
		cout<<"\nArray = {";
		for (int i=0;i<listsize-1;i++) {
			cout<<Array[i]<<", ";
		}
		cout<<Array[listsize-1]<<"}\n";
	}

	static void createlist(int *Array, int listsize) {
		for(int i=0;i<listsize;i++) {
	        cout<<"Enter item "<<i+1<<" ";
	        cin>>Array[i];
    	}
	}

	int random(int min, int max) {
		static bool first = true;
		if (first) {
			srand(time(NULL));
			first=false;
		}
		return min+rand()%((max+1)-min);
	}

}
