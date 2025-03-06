#include<iostream>
using namespace std;
void bubblesort(int n,int arr[]);
void selectionSort( int n,int arr[]);
void generaterandomarray(int n,int arr[]);
int main(){
    int size=100;
    int arr[size];
   
    generaterandomarray(size,arr);
    cout<<"\n YOOOOOOOOOOO\n";
    
    bubblesort(size,arr);
        
    
    for(int j=0;j<size;j++){
        cout<<arr[j]<<" ";
    }
  
    cout<<"\n YOOOOOOOOOOO\n";

 
    generaterandomarray(size,arr);
    cout<<"\n YOOOOOOOOOOO\n";
     selectionSort(size,arr);


    for(int j=0;j<size;j++){
        cout<<arr[j]<<" ";
    }
 
   
    
    return 0;
}
void bubblesort(int n,int arr[]){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
           if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
           }
        }
    }
}
void selectionSort(int n,int arr[]) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
void generaterandomarray(int n,int arr[]){
    
    for(int i=0;i<n; i++){
        arr[i]=rand()%100;
        cout<<arr[i]<<" ";
    }

}