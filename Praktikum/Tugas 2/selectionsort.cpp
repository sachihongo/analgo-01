#include<iostream>

using namespace std;

int main()
{
    int i,j,n,loc,temp,min,a[30];
    cout<<"\nMasukkan jumlah dari elemen : ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"Masukkan angka : ";
        cin>>a[i];
    }

    for(i=0;i<n-1;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                loc=j;
            }
        }

        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }

    cout<<"\nHasil sorting\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
