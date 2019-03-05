/**
 *	  Nama  : Sachi Hongo
 *	  NPM   : 140810160014
 *	  Kelas : B
 *    Deskripsi : Implementasi Algoritma Pemangkatan metode Iteratif dengan running time
 **/


#include<iostream>
#include <time.h>

using namespace std;

int pangkat (int n)
    {int hasil=1;
    for (int i=1;i<=n;i++)
    {
       hasil=hasil*2;
         }
    return hasil;
}

int main()
{
    clock_t start, end;
    float time;
    int j;

    cout<<"PROGRAM MENGHITUNG PANGKAT"<<endl;
    cout<<endl<<"Masukkan Pangkat : ";
    cin>>j;

    start = clock();

    cout<<endl<<"Hasilnya = ";
    cout<<pangkat(j)<<endl;

    end = clock();
    //Perhitungan waktu dari clock time yang ada
    time = (float) (end - start)*1000000000000000.0;
    cout<<"Process Time : "<<time<<" s"<<endl;
}
