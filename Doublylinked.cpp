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
        // insert at end 
        void insertAtEnd(int val){
            Node * newnode = new Node(val);
            Node * curr=head;
            if(!head){
                head = newnode;
            }
            else{
                while(curr){
                    curr=curr->next;
                }
                newnode->prev=curr;
                curr->next=newnode;
                cout<<"inserted at the end: "<<endl;
            }
        }
        //insert at given pos
        void insertAtPos(int val, int pos){
            Node * newnode = new Node(val);
            Node * curr= head;
            if (!head ||pos <1){
                cout<<"invalid"<<endl;
            }
            int count=1;
            while(count<pos-1 && curr){
                curr=curr->next;
            }
            newnode->next=curr->next;
            newnode->prev=curr;
            if(curr->next){
                curr->next->prev=newnode;

            }
            curr->next=newnode;
            cout<<"inserted at given position"<<endl;
        }       
        //insert after given element
        void insertafternode(int val,int daata){
            Node * newnode= new Node(val);
            Node * curr= head;
            if(!head){
                cout<<"invalid"<<endl;
            }
            while(curr && curr->data!=daata){
                curr=curr->next;
            }
            newnode->prev=curr;
            newnode->next=curr->next;
            if(curr->next){
                curr->next->prev=newnode;
            }
            curr->next=newnode;
        }
        //insert befoe given element
        void insertbeforeelement(int val,int DATA){
            Node * newnode= new Node(val);
            Node * curr=head;
            if(!head){
                cout<<"invalid"<<endl;
            }
            while(curr && curr->data==DATA){
                curr=curr->next;
            }
            newnode->next=curr;
            newnode->prev=curr->prev;
            curr->prev->next=newnode;
            curr->prev=newnode;

        }
        //delete from begining
        void deletefromfront(){
            if (!head){
                cout<<"invalid"<<endl;
            }
            Node * temp=head;
            head=head->next;
            head->prev=NULL;
            delete temp;
        }
        //delete from the end 
        void deletefromend(){
            
        }

};