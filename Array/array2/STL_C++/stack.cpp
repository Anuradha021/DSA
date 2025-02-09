#include<iostream>
using namespace std;
#include<stack>

class Stack{
    public:
    int *arr;
    int size;
    int top;
    Stack(int size){
       this-> size = size;
       top = -1;
        arr = new int[size];
    }
    void push(int element){
       if(size- top >1){
        top++;
        arr[top] = element;
       }
       else{
        cout<<"Stack is overflow"<<endl;
       }
    }
    void  pop(){
        if(top>=0){
            top--;
        }
        else{
cout<<"stack is underflow"<<endl;
        }
    }
    int  peek(){
if(top>=0){
    return arr[top];
}
else{
    cout<<"Satck is empty"<<endl;
}

    }
    bool isEmpty(){
if(top==-1){
    return true;
}
else{
    return false;
}
    }
};
int main(){
    Stack st(5);
    st.push(20);
    st.push(10);
    cout<<"top "<<st.peek()<<endl;

// stack <int> s;
// s.push(6);
// s.push(5);
// s.pop();
// cout<<"Printin the top elment "<<s.top()<<endl;
// if(s.empty()){
//     cout<< " Stack is empty"<<endl;
// }
// else{
//     cout<<"Stack is not empty "<<endl;
// }
// cout<<"Size of stack is "<<s.size()<<endl;
return 0;
}