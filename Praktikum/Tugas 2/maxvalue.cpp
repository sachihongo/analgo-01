#include <iostream>
using namespace std;

int main()
{
    int i, n;
    float arr[100];

    cout << "Masukkan jumlah dari elemen(1 s/d 100): ";
    cin >> n;
    cout << endl;

    // Store number entered by the user
    for(i = 0; i < n; ++i)
    {
       cout << "Masukkan angka " << i + 1 << " : ";
       cin >> arr[i];
    }

    // Loop to store largest number to arr[0]
    for(i = 1;i < n; ++i)
    {
       // Change < to > if you want to find the smallest element
       if(arr[0] < arr[i])
           arr[0] = arr[i];
    }
    cout << "\nNilai maksimal = " << arr[0];

    return 0;
}
