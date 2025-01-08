#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Queue {
    
    int* arr;
    int qfront;
    int rear;
    int size;
    public:
    Queue(){
        this->qfront = 0;
    this->rear = 0;
    this->size = 100001;
    this->arr = new int[size];
    }
    bool isEmpty(){
        if(qfront == rear ){
            return true;
        }
        else{
            return false;
        }
    }
void enqueue(int data ){
    if(rear == size){
        cout<<"Queue is full"<<endl;

    }
    else{
        arr[rear] = data;
        rear ++;
    }
}
int  dequeue(){
    
 if(qfront == rear){
    return -1;
 }
 else{
int ans = arr[qfront];
arr[qfront] = -1;
qfront++;
if(qfront==rear){
    qfront =0;
    rear = 0;
}
return ans;
 }
}
int front(){
    if(qfront==rear){
        return -1;
    }
    else{
        return arr[qfront];
    }
}
int sizee() {
        return rear - qfront;
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty" <<endl;
        }
        else{
            cout<<"Elemnt of queue are "<<endl;
            for(int i = qfront;i<rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){

    Queue q;
    q.enqueue(3);
    q.enqueue(7);
    q.enqueue(9);
    cout<<"element in queue are "<<q.sizee()<<endl;
    q.display();
    return 0;
}