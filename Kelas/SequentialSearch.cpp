/**
 *	  Nama  : Sachi Hongo
 *	  NPM   : 140810160014
 *	  Kelas : B
 *    Deskripsi : Implementasi Algoritma Linear/Sequential Search dengan running time
 **/


//Menyertakan library
#include <iostream>
#include <time.h>
//Menentukan banyak data
#define MAX 500000
using namespace std;

int main()
{
    clock_t start, end;
    float time;


    //Deklarasi variabel
    int item;
    int nomor[MAX];
    bool found = false;

    //Input Data Nomor
    for(int i=0; i<=MAX ;i++){
        nomor[i] = i+1;
    }

    //Input key untuk pencarian
    cout<<"Masukkan Nomor Pencarian : ";
    cin >> item;

    start = clock();
    //Lakukan iterasi sebanyak jumlah data yang ada
    for(int i=0;i<MAX;i++)
    {
        //Logika ketika key sama dengan data pada array pada indeks i, maka data ditemukan
        if(item==nomor[i])
        {
            //Tampilan ketika data ditemukan
            found = true;
            cout << "Data ditemukan pada lokasi " << i+1 << endl;
            break;
        }
    }
    //Logika jika data tidak ditemukan
    if(found=false)
    {
        //Tampilan ketika data tidak ditemukan
        cout<<"Data tidak ditemukan";
    }

    //Akhir clock time setelah proses
    end = clock();
    //Perhitungan waktu dari clock time yang ada
    time = (float) (end - start)*1000000000000000.0;
    cout<<"Process Time : "<<time<<" s";
}
