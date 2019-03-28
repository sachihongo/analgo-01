/**
 *	  Nama  : Sachi Hongo
 *	  NPM   : 140810160014
 *	  Kelas : B
 *    Deskripsi : Analisa Algoritma MergeSort dengan Running Time
 **/

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


void merge (int *a, int low, int high, int mid){
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= high){
		if (a[i] < a[j]){
			temp[k] = a[i];
			k++;
			i++;
		}
		else {
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid){
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= high){
		temp[k] = a[j];
		k++;
		j++;
	}

    	for (i = low; i <= high; i++){
		a[i] = temp[i-low];
	}
}

void mergeSort(int *a, int low, int high){
	int mid;
	if (low < high){
		mid=(low+high)/2;
		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);

		merge(a, low, high, mid);
	}
}

int main(){
	int n, i;

	cout<<"MERGE SORT - ALGORITHM ANALYSY"<<endl;
	cout<<"Masukkan jumlah elemen data yang ingin diurutkan: ";
	cin>>n;

	int arr[n];

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for(i = 0; i < n; i++){
		cout<<"Masukkan elemen ke-"<<i+1<<": ";
		cin>>arr[i];
	}

	mergeSort(arr, 0, n-1);

	cout<<"\nArray yang telah diurutkan: ";
	for (i = 0; i < n; i++) cout<<" "<<arr[i];

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
    	auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    	cout<<endl<<"\nRunning Time : "<<duration<<" microseconds"<<endl;
    	cout<<endl<<"Running Time : "<<(duration/1000)<<" milliseconds"<<endl;
    	cout<<endl<<"Running Time : "<<(duration/1000000)<<"seconds"<<endl;
}
