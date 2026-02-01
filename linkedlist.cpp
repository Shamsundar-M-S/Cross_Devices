#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node(int val){
            next=NULL;
            data=val;
        }
};

class LinkedList{
    private:
        Node * head;
    public:
        LinkedList(){
            head=NULL;
        }
        //insert at begining 
        void insertAtFront(int val){
            Node * newnode = new Node(val);
            if (!head){
                head=newnode;
            }
            else{
                newnode->next=head;
                head=newnode;
            }
            cout<<"inserted at front"<<endl;
        }
        //insert at end
        void insertAtEnd(int val){
            Node * newnode = new Node(val);
            Node * curr=head;
            while(curr->next!=NULL){
                curr=curr->next;
            }
            curr->next=newnode;
            cout<<"inserted at end"<<endl;
        }
        //insert at given position
        void insertAtPosition(int val, int pos){
            Node * newnode= new Node(val);
            Node * curr = head;
            if (pos<1){
                cout<<"Invalid position provided";
            }
            if (pos=1){
                newnode->next=head;
                head=newnode;
            }
            else{
                int count=1;
                while(curr && count<pos-1){
                    curr=curr->next;
                }
                newnode->next=curr->next;
                curr->next=newnode;
                cout<<"Inserted at given position";
            }
        }
        //insert after data
        void insertAfterData(int val, int DATA){
            Node * newnode = new Node(val);
            Node * curr=head;
            while( curr && curr->data!=DATA){
                curr=curr->next;
            }
            if (!curr){
                cout<<"data Not found"<<endl;
            }
            newnode->next=curr->next;
            curr->next=newnode;
            cout<<"Inserted after given data"<<endl;
        }
        //insert before given data
        void InsertBeforeData(int val, int DATA){
            Node * newnode= new Node(val);
            Node * curr=head;
            Node * prev = NULL;
            while(curr && curr->data!=DATA){
                prev=curr;
                curr=curr->next;
            }
            if (!curr){
                cout<<"data not found"<<endl;
            }
            if(!prev){
                newnode->next=head;
                head=newnode;
            }
            else{
                newnode->next=curr;
                prev->next=newnode;
            }
        }
        //delete from front
        void deleteFromStart(){
            if(!head){
                cout<<"list is empty deletion failed"<<endl;
            }
            Node * temp =head;
            head=head->next;
            delete temp;
            cout<<"deleted from start"<<endl;
        }
        //delete from end 
        void deleteFromEnd(){
            if (!head){
                cout<<"invalid"<<endl;
            }
            Node * curr=head;
            Node * prev=NULL;
            while(curr){
                prev=curr;
                curr=curr->next;
            }
            if (!prev){
                head=NULL;
            }
            prev->next=NULL;
            delete curr;
            cout<<"deleted from end"<<endl;
        }
};