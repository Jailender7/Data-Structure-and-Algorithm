#include<bits/stdc++.h>
using namespace std;

class Stack{
    int capacity = 5;
    int *arr = new int[capacity];
    int index;

    public:

    Stack(){
        index = -1;
    }

    void push(int data){
        if(index == capacity-1){
            cout<<"Stack is overflow"<<endl;
            return;
        }

        index++;
        arr[index] = data;
    }

    int top(){
        if(index == -1){
            cout<<"Stack is underflow"<<endl;
            return -1;
        }
        return arr[index];
    }

    void pop(){
        if(index == -1){
            cout<<"Stack is underflow"<<endl;
            return;
        }else{
            index--;
        }
    }

};


int main(){

    Stack s;
    
    s.push(12);
    s.push(15);
    s.push(20);
    s.push(-1);
    
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.push(78);

    
    cout<<"Top element of stack is "<<s.top()<<endl;

    return 0;
}