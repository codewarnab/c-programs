#include<iostream> 
using namespace std ; 


class MaxHeap{
    int * arr ; 
    int size ; // total elements in heap 
    int total_size ; // total size of the array

    public : 
    MaxHeap(int n ){
        arr = new int[n];
        size = 0 ; 
        total_size = n ; 
    }
    // insert into the heap 

    void insert(int value){
        // if the heap size is avaialble or not 
        if(size == total_size){
            cout << "Heap Overflow \n";
            return;
        }
        // we insert at last 
        arr[size] = value;
        int index = size;
        size++; 

        while(index >0 && arr[(index-1)/2]<arr[index]){
            // swappting with parent if current index value is greater then the parent 
            swap(arr[index], arr[(index - 1) / 2]);
            // updating the current index 
            index = (index - 1) / 2; 
        }

        cout << arr[index] << " is insterted into the heap ";
        cout << endl;
    }

    void print(){
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
            cout << endl;
        }
    }

    void Heapify(int index){
        int largest =  index ;
        int left = 2 * index + 1; 
        int right = 2 * index+2; 

        // largest will store the index of element which is greater between parent , left child and right child 
        if(left < size && arr[left]>arr[largest])
            largest = left ; 
        if(right < size && arr[right] > arr[largest])
        largest = right ; 

        if ( largest != index ){
            swap(arr[index],arr[largest]);
            Heapify(largest);
        }

    }
    void Delete(){
        if(size == 0 ){
            cout<< "Heap Underflow"<<endl;
            return;
        }
        cout<< arr[0] <<"deleted from the heap ";
        arr[0] = arr[size - 1];
        size-- ; 
        if(size ==0  ){
            return;
        }
        Heapify(0); 

    }

};

int main()
{
    MaxHeap H1(10);

    // Inserting elements into the heap
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);
    H1.insert(9);
    H1.insert(20);
    H1.insert(15);

    cout << "\nInitial heap:" << endl;
    H1.print();

    // Deleting the root element (maximum element) a few times
    cout << "\nDeleting elements from the heap:" << endl;
    H1.Delete();
    H1.print();

    H1.Delete();
    H1.print();

    H1.Delete();
    H1.print();

    return 0;
}