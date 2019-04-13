 /**
     *	  Nama  : Sachi Hongo
     *	  NPM   : 140810160014
     *	  Kelas : B
     *    Deskripsi : Analisa Algoritma CountSort dengan Running Time
     **/

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>

using namespace std;

int k = 0;

// Method untuk melakukan sorting pada Array
void Counting_Sort(int A[], int B[], int n) {
    
   int C[k];
    for(int i = 0; i < k+1; i++) {
        // Inisiasi array C == 0
        C[i]=0;
    }

    for(int j = 1; j <= n; j++) {
        // Menghitung kemunculan setiap elemen x dalam A
       // dan menambahkannya pada posisi x di C
        C[A[j]]++;       	  
    }

    for(int i = 1; i <= k; i++) {
       // Menyimpan kemunculan elemen i terakhir
        C[i] += C[i-1];
    }

    for(int j = n; j >= 1; j--) {
        // Menaruh elemen pada tempatnya
        B[C[A[j]]] = A[j];         
        // elemen yang muncul dua kali akan membuat lebih mudah
        C[A[j]] = C[A[j]]-1;     	
    }
}

int main() {
    int n;
    cout << "Masukan panjang array :";
    cin >> n;
    
    cout << "Data array sebelum sort :";
    
    /*A, menyimpan elemen yang dimasukan oleh user ke array */
    /*B, menyimpan hasil sorting*/      
    int A[n], B[n];
    
    unsigned seed = time(0);
    srand(seed);
    
    // Buat Random Array
    for(int i = 1; i<=n; i++)
    {
        A[i]=rand()%10+1;
    }
    
    // Buat nilai k dan cetak Array terbentuk
    for(int i = 1; i <= n; i++) {
        cout << A[i] << " ";
        if(A[i] > k) {
           // Merubah nilai k jika pada elemen i nilainya lebih besar dari k
            k = A[i];             
        }
    }

   auto start = chrono::steady_clock::now();
    
   Counting_Sort(A, B, n);

   auto end = chrono::steady_clock::now();
   auto diff = end - start;
    // Print array yang telah di sorting
    
   cout << endl << "Data array setelah sort :";
   for(int i = 1; i <= n; i++) {
        cout << B[i] << " ";
    }
    
   cout << endl <<"Runtime : " << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    return 0;
}