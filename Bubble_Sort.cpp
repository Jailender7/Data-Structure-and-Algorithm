#include<iostream>
using namespace std;

// function for Bubble Sort
void bubbleSort(int a[], int n){
    for(int i=0; i<n; i++){
        int j=0;
        while(j<n-i-1){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);

            j++;
        }
    }

    return;
}


int main(){

    int s; cout<<"Size of Array is : ";
    cin>>s;

    int *arr = new int[s];
    for(int i=0; i<s; i++){
        cin>>arr[i];
    }

    bubbleSort(arr,s);
    cout<<"Sorted Array is : ";
    for(int i=0; i<s; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}