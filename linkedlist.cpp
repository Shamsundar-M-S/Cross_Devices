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
        //delete by value
        void deleteByValue(int val){
            Node * curr=head;
            Node * prev=NULL;
            while(curr && curr->data!=val){
                prev=curr;
                curr=curr->next;
            }
            prev->next=curr->next;
            delete curr;
            cout<<"deleted by value"<<endl;
        }
        //delete by position
        void deleteNyPos(int pos){
            Node * curr=head;
            Node * prev=NULL;
            if (!head){
                cout<<"invalid list"<<endl;
            }
            int count=1;
            while(count<pos){
                prev=curr;
                curr=curr->next;
            }
            if(!prev){
                head=curr->next; 
            }
            prev->next=curr->next;
            delete curr;
        }
        //search an element
        void search(int DATA){
            Node * curr=head;
            while (curr){
                if (curr->data=DATA){
                    cout<<"Found"<<endl;
                }
                else{
                    cout<<"Not found"<<endl;
                }
                curr=curr->next;
            }
        }
        //count
        void count(){
            Node * curr=head;
            int count=0;
            while(curr){
                count++;
                curr=curr->next;
            }
            cout<<"No of elements in the list is: "<<count<<endl;
        }
};