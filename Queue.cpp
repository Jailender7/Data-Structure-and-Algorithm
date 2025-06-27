#include<bits/stdc++.h>
using namespace std;

class Queue{
    int capicity = 100;
    int *arr = new int[capicity];
    int front;
    int rear;

    public:
    Queue(){
        front = -1;
        rear = -1;
    }

    // function for push element in queue
    void push(int value){
        // check queue is full or not
        if(rear == capicity){
            cout<<"Queue is Overflow"<<endl;
        }else if(front== -1){ // push first element in the queue
            front=0;
            rear = 0;
            arr[rear] = value;
        }else{
            rear++;
            arr[rear] = value;
        }
    }

    // Function for find front element of queue
    int frontElement(){
        // check queue is empty or not
        if(rear == -1){
            cout<<"Your Queue is empty \n";
            return -1;
        }

        return arr[front];
    }
};

int main(){

    Queue q;

    q.push(90);
    q.push(34);
    q.push(89);
    q.push(69);

    cout<<"Front element of your queue is "<<q.frontElement()<<endl;



    return 0;
}