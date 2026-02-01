#include <iostream>
using namespace std;

class Node{
    public:
        Node * next;
        Node * prev;
        int data;
        Node(int val){
            data=val;
            prev=NULL;
            next=NULL;
        }
};
class Doubly{
    private:
        Node * head;
        Node * tail;
    public:
        Doubly(){
            head=NULL;
            tail=NULL;
        }
        //insert at front
        void insertAtFront(int val){
            Node * newnode= new Node(val);
            if (!head){
                head=newnode;
            }
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
            
        }
        
        

};