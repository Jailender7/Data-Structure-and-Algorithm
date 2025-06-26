#include<bits/stdc++.h>
using namespace std;

class Stack{
    
    int *arr = new int[20];
    int index;

    public:

    Stack(){
        index = -1;
    }

    void push(int data){
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

};


int main(){

    Stack s;
    
    s.push(12);
    s.push(15);
    s.push(20);
    s.push(-1);
    s.push(03);
    

    cout<<"Top element of stack is "<<s.top()<<endl;

    return 0;
}