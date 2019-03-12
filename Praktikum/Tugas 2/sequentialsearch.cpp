#include <iostream>

using namespace std;

int main()
{
	int arr[100], i, num, n, c=0, cek;
	cout<<"\nMasukkan jumlah dari elemen(1 s/d 100) : ";
	cin>>n;
	for(i=0; i<n; i++)
	{
	    cout<<"Masukkan angka : ";
		cin>>arr[i];
	}
	cout<<"\nMasukkan angka yang ingin dicari : ";
	cin>>num;


	for(i=0; i<n; i++)
	{
		if(arr[i]==num)
		{
			c=1;
			cek=i+1;
			break;
		}
	}
	if(c==0)
	{
		cout<<"Angka tidak ditemukan..!!";
	}
	else
	{
		cout<<num<<" ditemukan pada posisi "<<cek;
	}

}
