 /**
     *	  Nama  : Sachi Hongo
     *	  NPM   : 140810160014
     *	  Kelas : B
     *    Deskripsi : Analisa Algoritma HeapSort dengan Running Time
     **/

#include <iostream>
#include <chrono>
 
using namespace std;
using namespace std::chrono;
 
// A function to heapify the array.
void MaxHeapify(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i;
 
 	while (j <= n)
	{
		if (j < n && a[j+1] > a[j])
		j = j+1;
		// Break if parent value is already greater than child value.
		if (temp > a[j])
			break;
		// Switching value with the parent node if temp < a[j].
		else if (temp <= a[j])
		{
			a[j/2] = a[j];
			j = 2*j;
		}
	}
	a[j/2] = temp;
	return;
}
void HeapSort(int a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		// Storing maximum value at the end.
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		// Building max heap of remaining element.
		MaxHeapify(a, 1, i - 1);
	}
}
void Build_MaxHeap(int a[], int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
		MaxHeapify(a, i, n);
}
int main()
{
	int n, i;
	cout<<"\nMasukkan jumlah data yang akan disorting: ";
	cin>>n;
	n++;
	int arr[n];
	for(i = 1; i < n; i++)
	{
		cout<<"Masukkan elemen ke - "<<i<<": ";
		cin>>arr[i];
	}
	
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	// Building max heap.
	Build_MaxHeap(arr, n-1);
	HeapSort(arr, n-1);
	
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>( t2 - t1 ).count();
        
	// Printing the sorted data.
	cout<<"\nHasil Sorting Data ";
 
	for (i = 1; i < n; i++)
		cout<<"->"<<arr[i];
	
	cout<<endl<<"\nRunning Time : "<<duration<<" milliseconds"<<endl;
 
 
	return 0;
}