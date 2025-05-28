#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node* next;

    // constructor
    node(){
        next = NULL;
    }

};

class linkedList{

    node* head; // to point at starting element of linked list
    node* tail; // to point at ending element of linked lsit

    public:
    // constructor
    linkedList(){
        head=NULL;
        tail=NULL;
    }

    

};

int main(){

    linkedList ll;
    
    return 0;
}