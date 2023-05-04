#include <iostream>
#include <vector>

using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    /*even though this goes by name heapify, we are impllementing a max heapify here*/
   // build heapify
   int left_child_idx = 2*root +1;
   int right_child_idx = 2*root+2;
   int largest,temp;
   if (left_child_idx<n && arr[left_child_idx]>arr[root]){
       largest = left_child_idx;
   }
   else{
       largest = root;
   }

   if(right_child_idx<n && arr[right_child_idx]>arr[largest]){
       largest = right_child_idx;
   }

   if (root!=largest){
       //Exchange
       temp = arr[root];
       arr[root] = arr[largest];
       arr[largest] = temp;
       //to maintain the heap property recursively call the heapify again
       heapify(arr,n,largest);
   }


  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
    int temp;
   // build heap
   for (int i= n/2;i>=0;i--){
       heapify(arr,n,i);
   }

   
  
   // extracting elements from heap one by one

   for (int i = n-1;i>0;i--){
       temp = arr[0];
       arr[0] = arr[i];
       arr[i] = temp;
       n-=1;
       heapify(arr,n,0);
   }

}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    //int heap_arr[] = {4,17,3,12,9,6};
    cout << "Enter the size of the array: "<<endl;

    int n ;
    cin>> n;
    int* heap_arr = new int[n]; //dynamic memory allocation
    cout <<"Enter values"<< endl;
    for (int i = 0; i < n; i++){
        cin >> heap_arr[i];
    }
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
    delete[] heap_arr;

}
