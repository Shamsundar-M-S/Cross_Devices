#include <iostream>
using namespace std;
const int max_size=100;
class List{
    private:
        int array[max_size];
        int size;
    public:
        List(){
            size=0;
        }
        //insertion 
        void insert(int val){
            if (size< max_size){
                array[size++]=val;
                cout<<"element inserted at pos "<<size-1<<endl;
            }
            else{
                cout<<"list is already fulled"<<endl;
            }
        }
        //deletion
        void deleteElement(int val){
            int pos=-1;
            for (int i=0; i < size; ++i){
                if (array[i]==val){
                    pos=i;
                    break;
                }
            }
            if (pos !=-1){
                cout<<"element "<<array[pos]<<" deleted from postion "<<pos<<endl;
                for (int i=pos; i<size-1;++i){
                    array[i]=array[i+1];
                }
                size--;
            }
            else{
                cout<<"element not found"<<endl;
            }
        }
        //searching 
        int search(int val){
            for(int i=0; i<size;++i){
                if(array[i]==val){
                    cout<<"Element Found at: "<< i <<endl;
                    return i;
                }
            }
            cout<<"element not found"<<endl;
        }   
};

int main(){
    List l1;
    l1.insert(5);
    l1.insert(10);
    l1.insert(15);
    l1.insert(20);
    l1.insert(25);
    l1.insert(30);
    l1.deleteElement(20);
    l1.search(30);
}
