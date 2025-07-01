#include<bits/stdc++.h>
using namespace std;

class Cqueue{

    int capacity = 5;
    int *arr = new int[capacity];
    int frontIndex;
    int rear;

    public:
    Cqueue(){
        frontIndex = -1;
        rear = -1;
    }

    // function of insertation in circular queue
    void enqueue(int value){
        // inserting at first position
        if(frontIndex == -1 && rear == -1){
            rear = 0;
            frontIndex = 0;
            arr[rear] = value;
            return;
        }

        if((rear == capacity-1) && frontIndex!=0){
            rear = 0;
            arr[rear] = value;
            //cout<<"Value of rear = "<<rear<<" and value of front Index is "<<frontIndex<<endl;
            return;
        }

        if((frontIndex==0 && (rear == capacity-1)) || (frontIndex == rear+1)){
            cout<<"Queue is overflow"<<endl;
        }else{
            rear++;
            arr[rear] = value;

        }
    }

    // function for find front element of circular queue
    int front(){
        // queue is empty
        if(frontIndex == -1) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        return arr[frontIndex];
    }

    // function for check queue is empty or not
    bool isEmpty(){
        if(frontIndex == -1){
            return true;
        }else{
            return false;
        }
    }

    // function for pop or delete element from circular queue
    void dequeue(){
        // Queue is empty
        if(isEmpty()){
            cout<<"Queue is underflow."<<endl;
            return;
        }

        // Queue is not empty

        if(frontIndex == rear){ // when both element index at same place that all other space is empty then start from start
            arr[rear] = -1;
            frontIndex = rear = -1;
            return;
        }

        arr[frontIndex] = -1; // -1 means at that index element is not present
        frontIndex++;
        
        if((frontIndex == capacity) && rear!=capacity-1 ){  // this line of code is only for maintain circular propery
            frontIndex = 0;
            return;
        }
        
        if(frontIndex == capacity && rear == capacity){
            frontIndex = -1;
            return;
        }
    }
};

int main(){

    Cqueue q;
    
    q.enqueue(13);
    q.enqueue(122);
    q.enqueue(120);
    q.enqueue(12);
    q.enqueue(129);

    cout<<"Front element of the queue is "<<q.front()<<endl;
    q.dequeue();
    q.enqueue(128);
    q.enqueue(45);

    cout<<"Front element of the queue is "<<q.front()<<endl;
    q.dequeue();
    cout<<"Front element of the queue is "<<q.front()<<endl;
    q.dequeue();
    cout<<"Front element of the queue is "<<q.front()<<endl;
    q.dequeue();
    cout<<"Front element of the queue is "<<q.front()<<endl;
    q.dequeue(); 
    cout<<"Front element of the queue is "<<q.front()<<endl;
    q.dequeue();
    q.dequeue();

    q.enqueue(34);
    cout<<"Front element of the queue is "<<q.front()<<endl;
    q.dequeue();
    q.enqueue(90);
    q.enqueue(69);
    cout<<"Front element of queue is "<<q.front()<<endl;

    return 0;
}