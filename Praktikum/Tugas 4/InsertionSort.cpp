/**
 *	  Nama  : Sachi Hongo
 *	  NPM   : 140810160014
 *	  Kelas : B
 *    Deskripsi : Analisa Algoritma InsertionSort dengan Running Time
 **/

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct list {
	int data;
	list *next;
};

list* InsertinList(list *head, int n){
	list *newnode = new list;
	list *temp = new list;

	newnode->data = n;
	newnode->next = NULL;

	if(head == NULL){
		head = newnode;
		return head;
	}
	else {
		temp = head;

		if(newnode->data < head->data){
			newnode->next = head;
			head = newnode;
			return head;
		}

		while(temp->next != NULL){
			if(newnode->data < (temp->next)->data)
				break;

			temp=temp->next;
		}

		newnode->next = temp->next;
		temp->next = newnode;
		return head;
	}
}

int main(){
	int n, i, num;
	list *head = new list;
	head = NULL;


	cout<<"INSERTION SORT - ALGORITHM ANALYSY"<<endl;
	cout<<"Masukkan jumlah elemen data yang ingin diurutkan: ";
	cin>>n;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for(i = 0; i < n; i++){
		cout<<"Masukkan elemen ke-"<<i+1<<": ";
		cin>>num;
		head = InsertinList(head, num);
	}

	cout<<"\nArray yang telah diurutkan: ";
	while(head != NULL){
		cout<<" "<<head->data;
		head = head->next;
	}

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
    	auto duration = duration_cast<microseconds>( t2 - t1 ).count();
        cout<<endl<<"\nRunning Time : "<<duration<<" microseconds"<<endl;
    	cout<<endl<<"Running Time : "<<(duration/1000)<<" milliseconds"<<endl;
    	cout<<endl<<"Running Time : "<<(duration/1000000)<<"seconds"<<endl;
}
