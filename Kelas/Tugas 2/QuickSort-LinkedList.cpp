    /**
     *	  Nama  : Sachi Hongo
     *	  NPM   : 140810160014
     *	  Kelas : B
     *    Deskripsi : Analisa Algoritma QuickSort with Linked List dengan Running Time
     **/

#include <iostream> 
#include <cstdio> 
#include <ctime>
#include <cstdlib>
#include <chrono>


using namespace std; 

/* node singly linked list */
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

/* function insert first linked list */
void push(struct Node** head_ref, int new_data) 
{ 
	/* buat node baru */
	struct Node* new_node = new Node; 

	/* masukan node di data */
	new_node->data = new_data; 

	/* link node baru ke head */
	new_node->next = (*head_ref); 

	/* pindahkan head ke node baru */
	(*head_ref) = new_node; 
} 

/* function cetak linked list */
void printList(struct Node *node) 
{ 
	while (node != NULL) 
	{ 
		printf("%d ", node->data); 
		node = node->next; 
	} 
	printf("\n"); 
} 

// mengambil nilai terakhir dari list 
struct Node *getTail(struct Node *cur) 
{ 
	while (cur != NULL && cur->next != NULL) 
		cur = cur->next; 
	return cur; 
} 

// Partisi list mengambil last element sebagai pivot 
struct Node *partition(struct Node *head, struct Node *end, 
					struct Node **newHead, struct Node **newEnd) 
{ 
	struct Node *pivot = end; 
	struct Node *prev = NULL, *cur = head, *tail = pivot; 

	// Saat Partisi, head dan tail mengalami perubahan jadi newHead dan newEnd
	while (cur != pivot) 
	{ 
		if (cur->data < pivot->data) 
		{ 
			// Node pertama yang memiliki value kurang dari pivot menjadi head baru 
			
			if ((*newHead) == NULL) 
				(*newHead) = cur; 

			prev = cur; 
			cur = cur->next; 
		} 
		else // Jika node lebih besar dari pivot 
		{ 
			// Pindahkan node ke next dari tail, dan ubah tail 
			if (prev) 
				prev->next = cur->next; 
			struct Node *tmp = cur->next; 
			cur->next = NULL; 
			tail->next = cur; 
			tail = cur; 
			cur = tmp; 
		} 
	} 

	// Jika pivot adalah element terkecil di list, 
	// pivot jadi head 
	if ((*newHead) == NULL) 
		(*newHead) = pivot; 

	// Update newEnd
	(*newEnd) = tail; 

	// Return node pivot 
	return pivot; 
} 


//here the sorting happens exclusive of the end node 
struct Node *quickSortRecur(struct Node *head, struct Node *end) 
{ 
	// base condition 
	if (!head || head == end) 
		return head; 

	Node *newHead = NULL, *newEnd = NULL; 

	// Partis list, newHead dan newEnd akan diupdate berdasarkan function partisi
	struct Node *pivot = partition(head, end, &newHead, &newEnd); 

	// Jika pivot adalah element terkecil - tidak perlu recur bagian kiri. 
	if (newHead != pivot) 
	{ 
		// Set node sebelum pivot = NULL 
		struct Node *tmp = newHead; 
		while (tmp->next != pivot) 
			tmp = tmp->next; 
		tmp->next = NULL; 

		// Recur for the list before pivot 
		newHead = quickSortRecur(newHead, tmp); 

		// Ubah next dari node terakhir dari bagian kiri pivot 
		tmp = getTail(newHead); 
		tmp->next = pivot; 
	} 

	// Recur for the list after the pivot element 
	pivot->next = quickSortRecur(pivot->next, newEnd); 

	return newHead; 
} 

// main function untuk quick sort. 
// function quickSortRecur() 
void quickSort(struct Node **headRef) 
{ 
	(*headRef) = quickSortRecur(*headRef, getTail(*headRef)); 
	return; 
} 

int main() 
{ 
	struct Node *a = NULL;
	
	int n;
    cout << "Masukan panjang array :";
    cin >> n;
    
    int A[n];
    
    unsigned seed = time(0);
    srand(seed);
    
    // Buat Random Array
    for(int i = 0; i<n; i++)
    {
        A[i]=rand()%1000+1;
    }
    
    for(int i = 0; i<n; i++)
    {
        push(&a, A[i]); 
    }
    
	cout << endl << "List sebelum sorting \n"; 
	printList(a); 
    
    auto start = chrono::steady_clock::now();
    
	quickSort(&a); 

    auto end = chrono::steady_clock::now();
    auto diff = end - start;

	cout << "List setelah sorting \n"; 
	printList(a); 
	
	cout << endl <<"Runtime : " << chrono::duration <double, milli> (diff).count() << " ms" << endl;

	return 0; 
}
