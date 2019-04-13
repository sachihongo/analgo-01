    /**
     *	  Nama  : Sachi Hongo
     *	  NPM   : 140810160014
     *	  Kelas : B
     *    Deskripsi : Analisa Algoritma LinearSearch dengan Running Time
     **/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;
 
int linearSearch(const int [], int, int);
int SIZE;

 int main() {
     
     cout << "Masukkan Banyak Elemen : " ;
     cin >> SIZE;
    
    int array[SIZE];
    unsigned seed = time(0);
    srand(seed);
    
    cout << "Array Angka Random: " <<endl;
    
     for(int i = 0; i<100;i++)
     {
        array[i]=rand()%100+1;
     	cout << array[i]<<" ";
     }
 
    int results; 
    int input; 

    cout << endl << endl <<"Masukkan Angka yang Dicari: ";
    cin >> input;
 
    auto start = chrono::steady_clock::now();

    results = linearSearch(array, SIZE, input);

    if (results == -1){
        cout << "Angka Tidak Ditemukan di Array\n";
    }
    else {
         cout << "Angka Ditemukan di indeks ke " << results;
         cout << " pada array.\n" <<endl;
    }
    
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Running Time: "<<chrono::duration <double, milli> (diff).count() << " ms" << endl;

   return 0;
 }
 
int linearSearch(const int array[], int size, int value){
 int lokasi = 0; 
 bool found = false; 
 
 while (!found && lokasi < size) {
  if (array[lokasi] == value){
   found = true;
  }
  else {
   lokasi=lokasi+1;
  }
 }
 
 return lokasi;
}