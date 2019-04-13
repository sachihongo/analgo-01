/**
 *	  Nama  : Sachi Hongo
 *	  NPM   : 140810160014
 *	  Kelas : B
 *    Deskripsi : Implementasi Algoritma Binary Search dengan Running Time
 **/


//Menyertakan library yang dibutuhkan
#include <iostream>
#include <time.h>

//Menentukan banyak data
#define MAX 500000

//namespace
using namespace std;
int main()
{
    //Deklarasi clock
    clock_t start, end;
    double time;
    //Deklarasi variabel
    int nomor[MAX];
    int key, low = 0, high = MAX;
    bool found = false;

    //Input Data Nomor
    for(int i=0; i<=MAX ;i++){
        nomor[i] = i+1;
    }

    //Input key untuk pencarian
    cout<<"Masukkan Nomor Pencarian : ";
    cin>>key;

    //Start clock time setelah input
    start = clock();
    while(low<=high)
    {
        //Deklarasi nilai tengah
        int mid = (low+high)/2;
        //Logika jika key sama dengan data pada array pada indeks i, maka data ditemukan
        if(key == nomor[mid])
        {
            //Tampilan ketika data ditemukan
            cout<<"Data ditemukan pada lokasi "<<mid+1<<endl;
            found = true;
            break;
        }
        //jika key < data pada array maka high = mid - 1
        else if(key<nomor[mid])
        {
            high=mid - 1;
        }
        //jika sebaliknya key > data pada array maka low = mid + 1
        else
        {
            low = mid + 1;
        }

        if(found=false)
        {
            //Tampilan ketika data tidak ditemukan
            cout<<"Data tidak ditemukan";
        }
    }

    //Akhir clock time setelah proses
    end = clock();
    //Perhitungan waktu dari clock time yang ada
    time = (float) (end - start)*1000000000000000.0;
    cout<<"Process Time : "<<time<<" s";
}
