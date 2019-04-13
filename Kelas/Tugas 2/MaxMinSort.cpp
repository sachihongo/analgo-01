    /**
     *	  Nama  : Sachi Hongo
     *	  NPM   : 140810160014
     *	  Kelas : B
     *    Deskripsi : Analisa Algoritma MaxMinSort dengan Running Time
     **/


#include<iostream>
#include<conio.h>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;


int main()
{
    
 int n;
 int i,temp,j;
 
 cout << "Masukan panjang array :";
 cin >> n;
    
 int a[n];
 
 unsigned seed = time(0);
 srand(seed);
    
    // Buat Random Array
    for(int i = 0; i<n; i++)
    {
        a[i]=rand()%1000+1;
    }
 
 cout << "Data array sebelum sort :";
     for(j=0;j<n;j++)
     {
        cout<<a[j]<<" ";
     }
     
 auto start = chrono::steady_clock::now();

 for(i=0;i<n;i++)
 {
     for(j=0;j<n;j++)
     {
         if(a[j]>a[j+1])
         {
             temp=a[j];
             a[j]=a[j+1];
             a[j+1]=temp;
         }
     }
 }
 
 auto end = chrono::steady_clock::now();
 auto diff = end - start;
 
 cout<<endl;
 
 cout<<"\nData setelah sorting (ASC): ";
 for(j=0;j<n;j++)
 {
    cout<<a[j]<<" ";
 }
 
 cout<<"\nData setelah sorting (DESC): ";
 for(j=n-1;j>=0;j--)
 {
    cout<<a[j]<<" ";
 }
 
 cout << endl <<endl <<"Runtime : " << chrono::duration <double, milli> (diff).count() << " ms" << endl;
 
}
