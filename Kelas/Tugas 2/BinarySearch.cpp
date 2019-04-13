    /**
     *	  Nama  : Sachi Hongo
     *	  NPM   : 140810160014
     *	  Kelas : B
     *    Deskripsi : Analisa Algoritma BinarySearch dengan Running Time
     **/

#include <iostream>
#include <chrono>
using namespace std;

main () {
	int n, i, search, first, last, middle;
	cout << "Masukkan Jumlah Elemen: ";
	cin >> n;
	

	int arr[n];
	unsigned seed = time(0);
	srand(seed);
    
    cout << "Array Angka Random: " <<endl;
    
    for(int i = 0; i<n;i++) //to get random numbers inside the array.
    {
        arr[i]=rand()%1000+1;
     	cout << arr[i]<<" ";
    }
	
	cout<<endl<<"Masukkan angka yang akan dicari :";
	cin>>search;
	
	int posisi;
	for (int i=0; i<n-1; i++) {
		posisi=i;
		for (int j=i+1;j<n;j++) {
			if (arr[posisi]>arr[j]) {
				posisi=j; 
			}
		}
		swap(arr[i], arr[posisi]);
	}
	
	cout << endl << "Array Angka Sorted: " <<endl;
	for(int i = 0; i<n;i++) //to get random numbers inside the array.
    {
     	cout << arr[i]<<" ";
    }
	
	auto start = chrono::steady_clock::now();
	
	first = 0;
	last = n-1;
	middle = (first+last)/2;        
	
	while (first <= last)
	{
		if(arr[middle] < search)
		{
			first = middle + 1;
		}
		else if(arr[middle] == search)
		{
			cout<< endl <<"Angka "<< search<<" ditemukan"<<endl;
			break;
		}
		else
		{
			 last = middle - 1;
		}
		middle = (first + last)/2;
	}
	
	if(first > last)
	{
		cout<<endl<<"Error! "<<search<<" tidak ditemukan dalam Array" <<endl;
	}
	
	auto end = chrono::steady_clock::now();
    auto diff = end - start;
    
    cout << "waktu program :" <<chrono::duration <double, milli> (diff).count() << " ms" << endl;

}