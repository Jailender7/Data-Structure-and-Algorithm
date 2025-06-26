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
    
    // Here, is push functionality in stack
    void push(int data){
        if(index == capacity-1){
            cout<<"Stack is overflow"<<endl;
            return;
        }

        index++;
        arr[index] = data;
    }

    // Getting top element of the stack
    int top(){
        if(index == -1){
            cout<<"Stack is underflow"<<endl;
            return -1;
        }
        return arr[index];
    }

    // pop or delete element from the stack
    void pop(){
        if(index == -1){
            cout<<"Stack is underflow"<<endl;
            return;
        }else{
            index--;
        }
    }

    // Check Stack is empty or not
    bool isEmpty(){
        if(index == -1){
            return true;
        }else{
            return 0;
        }
    }

    // Find the size of the Stack
    int size(){
        return (index+1);
    }

};


int main(){

    Stack s;
    
    // Calling the function to push the element in the stack
    s.push(12);
    s.push(15);
    s.push(20);
    s.push(-1);
    
    // Calling the function to pop or delete the element from the stack
    s.pop();
    s.pop();
    s.pop();
    s.pop();


    s.push(78);
    s.pop();


    if(s.isEmpty()){
        cout<<"Stack is Empty"<<endl;
    }else{
        cout<<"Stack is non empty"<<endl;
    }

    cout<<"Size of Stack is "<<s.size()<<endl;
    
    cout<<"Top element of stack is "<<s.top()<<endl;

    return 0;
}