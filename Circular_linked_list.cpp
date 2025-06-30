#include <bits/stdc++.h>
using namespace std;

// Creating node for list
class node
{

public:
    int data;
    node* next;

    node(int d)
    {
        this->data = d;
        next = NULL;
    }

    ~node(){
        int v = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Node is delete for "<<v<<endl;
    }
};

// creating a circular linked list
class circular_linked_list{

    node* tail;
    public:
    circular_linked_list(){
        tail = NULL;
    }

//Function for insert in circular linked list
void insert(int element, int value)
{
    node* temp = new node(value);

    // list is empty and insert first node in CLL
    if (tail == NULL)
    {
        tail = temp;
        temp->next = temp;
    }
    else
    { // List is non empty nodes are exist in CLL
        node* curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        temp->next = curr->next;
        curr->next = temp;
    }
}


// Traverse circular linked list
void print(){
    node* curr = tail;
    do{
        cout<<curr->data<<" -> ";
        curr = curr->next;

    }while(curr != tail);
    cout<<endl;
}

// Deletion in circular linked list
void deleteNode(int value){
    // List is empty
    if(tail == NULL){
        cout<<"Delete is not possible because list is empty"<<endl;
    }else{
        // List is non empty
        node* prev = NULL;
        node* curr = tail;
        while(curr->data != value){
            prev = curr;
            curr = curr->next;
            // node is not present in this list
            if(curr==tail){
                cout<<"Node "<<value<<" is not present to delete in this list."<<endl;
                return;
            }

        }

        if(prev == NULL){
            node* temp = tail;
            while(temp->next != tail){
                prev = temp;
                temp = temp->next;
            }
            tail = curr->next;
            prev->next = tail;
            curr->next = NULL;
            delete curr;
        }else{
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }

    }
}

};

int main()
{

    circular_linked_list cll;
    cll.insert(0,9);    
    cll.insert(9,10);    
    cll.insert(10,11);    
    cll.insert(11,12);    
    cll.insert(12,13);
    cll.insert(10,15);
    cll.insert(9,100);
    cll.insert(10,10);

    
    cll.print();

    cll.deleteNode(10);
    cll.print();
    cll.deleteNode(10);
    cll.print();
    cll.deleteNode(10);
    cll.print();
    cll.deleteNode(13);
    cll.print();
    cll.deleteNode(11);
    cll.print();



    return 0;
}