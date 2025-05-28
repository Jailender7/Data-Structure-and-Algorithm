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

    // print the Linked List or Traverse linked list
    // T.C = O(n)
    void print(){
        if(head == NULL){
            cout<<"Linked list is empty"<<endl;
        }
        else{
            while(head!=NULL){
                cout<<head->data<<" -> ";
                head = head->next;
            }
        }
    }


    // insert at start of linkedlist
    // T.C = O(1)
    void insert_at_start(int value){
        node* temp = new node();
        temp->data = value;
        if(head==NULL){
            temp->next = head;
            head = temp;
            tail = temp;
        }else{
            temp->next = head;
            head = temp;
        }
    }

    // insert at end of linked list
    // T.C = O(1);
    void insert_at_end(int value){
        node* temp = new node();
        temp->data = value;

        if(head==NULL){
            temp->next = head;
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }
    

    // insert at any position or middle or this function is useful for insert at start or end
    // T.C of this function = O(n) : n is length of linked list or position
    void insert_at_position(int value, int position){
        node* temp = new node();
        temp->data = value;

        // linked list empty
        if(head == NULL || position==1){
            temp->next = head;
            head = temp;
            tail = temp;
        }else{ // linked list is non-empty
            int cnt=0;
            node*curr = head; // to track the element at that position

            while(curr->next !=NULL && cnt !=(position-2)){
                cnt++;
                curr = curr->next;
            }
            // joining the connection b/w nodes using curr node
            temp->next = curr->next;
            curr->next = temp;
        }
    }


};

int main(){

    linkedList ll;
    
    return 0;
}