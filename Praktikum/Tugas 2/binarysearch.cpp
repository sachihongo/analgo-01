#include <iostream>
using namespace std;

int main()
{
	int count, i, arr[100], num, first, last, middle;
	cout<<"\nMasukkan jumlah dari elemen :";
        cin>>count;

	for (i=0; i<count; i++)
	{
		cout<<"Masukkan angka : ";
                cin>>arr[i];
	}
	cout<<"\nMasukkan angka yang ingin dicari :";
        cin>>num;
	first = 0;
	last = count-1;
	middle = (first+last)/2;
	while (first <= last)
	{
	   if(arr[middle] < num)
	   {
		first = middle + 1;

	   }
	   else if(arr[middle] == num)
	   {
		cout<<num<<" ditemukan pada posisi "<<middle+1<<"\n";
                break;
           }
           else {
                last = middle - 1;
           }
           middle = (first + last)/2;
        }
        if(first > last)
	{
	   cout<<num<<" tidak ditemukan ";
	}
	return 0;
}
