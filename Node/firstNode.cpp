#include<iostream>
using namespace std;
class Node{
    public :
    int data ;
    Node* next ;
    Node(int data ){
        this->data = data ;
        this->next = NULL;
    }

};
void inseartAtHead(Node* &head, int d){
    Node* temp =new Node(d);
    temp->next = head;//here we create a node temp which next part conatain the address of  head 
    head = temp;//now we have to move head cursor to the temp bcz now temp become first element of the LL 
    //thats why head has to indicate temp .

}
void insertAtTail(Node* &tail,int d){
Node* temp = new Node(d);
tail->next = temp;
tail = tail->next;
}
void insertAtPosition(Node* & head, int position , int d){
    Node* temp = head ;
    int cnt = 1;
    while(cnt < position -1){
        temp = temp->next;
        cnt++;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert ->next = temp->next;
    temp->next = nodeToInsert;
}
void print(Node* &head){
   Node* temp = head;
   while(temp != NULL){
    cout<<temp->data << " ";
    temp = temp->next; // because we have to move temp to next and temp nex part is containg the addres 
    //of next node thats why we do this ..
   }
   cout<<endl;
}
int main(){
    //created node
    Node* node1 = new Node(10);
   Node* tail = node1;
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;


    //head pointed to Node1
    Node* head = node1;
    print(head);
   // inseartAtHead(head,18);
   insertAtTail(tail,20);
    print(head);
    insertAtTail(tail,30);
    print(head);
    insertAtPosition(head, 3, 40);
print(head);
    return 0;
}