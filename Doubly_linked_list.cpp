#include<iostream>
using namespace std;


class node{
    public:

    int data;
    node* next;
    node* prev;

    node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }

};

class doublyList{
    node* head = NULL;
    node* tail = NULL;

    public:
    // Iteration in doubly linked list or access or print the doubly linked list
    void print(){
        node* curr = head;
        if(curr==NULL){
            cout<<"List is empty "<<endl;
        }else{
            while(curr){
                cout<<curr->data<<" -> ";
                curr = curr->next;
            }
            cout<<endl;
        }
    }

    // Insertation at tail or end of the doubly linked list
    void insertAtTail(int value){
        node* temp = new node(value);

        if(head==NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        
    }

    // Insetation at head or starting of the doubly linked list
    void insertAtHead(int value){
        node* temp = new node(value);
        if(head==NULL){
            head = temp;
            tail = temp;
        }else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    // Deletion at start or head of the list
    void deleteAtStart(){
        if(head==NULL){
            cout<<"List is empty. Deletion is not possible"<<endl;
        }else{
            node* t = head;
            head->next->prev = NULL;
            head = head->next;
            delete t;
        }
    }

    // Deletion at End or tail of the list
    void deleteAtEnd(){
        if(head==NULL){
            cout<<"List is empty. Deletion is not possible. "<<endl;
        }else{
            node* t = tail;
            tail->prev->next = NULL;
            tail = tail->prev;
            delete t;
        }
    }
};


int main(){
    doublyList dl;
    
    dl.insertAtTail(1);
    dl.insertAtTail(2);
    dl.insertAtTail(3);
    dl.insertAtTail(4);
    dl.insertAtTail(5);
    dl.insertAtTail(-1);
    dl.insertAtTail(-2);
    


    /*
    dl.insertAtHead(1);
    dl.insertAtHead(2);
    dl.insertAtHead(3);
    dl.insertAtHead(4);
    dl.insertAtHead(5);
    dl.insertAtHead(-3);
    dl.insertAtHead(-5);
    
    dl.print();
    dl.deleteAtStart();
    dl.print();
    */

    dl.print();
    dl.deleteAtEnd();
    dl.print();
    return 0;
}