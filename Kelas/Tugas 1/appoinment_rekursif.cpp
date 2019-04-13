/**
 *	  Nama  : Sachi Hongo
 *	  NPM   : 140810160014
 *	  Kelas : B
 *    Deskripsi : Implementasi Algoritma Pemangkatan metode Rekursif dengan running time
 **/

#include <iostream>
#include <time.h>
using namespace std;

int Pangkat(int y){
    if (y==0){
        return 1;
    }
    else{
        return (2*Pangkat(y-1));
    }
}

int main() {

    clock_t start, end;
    float time;
    int p;
    cout<<"PROGRAM MENGHITUNG PANGKAT"<<endl;

    cout<<"\nMasukkan pangkat : ";
    cin>>p;
    cout<<endl;

    start = clock();

    cout<<"Hasil = "<<Pangkat(p)<<endl;

    end = clock();
    //Perhitungan waktu dari clock time yang ada
    time = (float) (end - start)*1000000000000000.0;
    cout<<"Process Time : "<<time<<" s"<<endl;

}
