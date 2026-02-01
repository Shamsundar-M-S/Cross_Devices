#include <iostream>
using namespace std;
const int max_size=100;

class List{
    int array[max_size];
    int size;
    public:
        List(){
            size=0;
        }
        void insert(int val){
            if(size<max_size){
                array[size++]=val;
                cout<<"element "<<val<<" inserted at pos "<<size-1<<endl;
            }
            else{
                cout<<"List is full"<<endl;
            }
        }
        void deleteElement(int val){
            int pos=0;
            for( int i=0; i<size; ++i){
                if (array[i]==val){
                    pos=i;
                }
            }
            if (pos !=1){
                for (int i=pos; i<size-1;++i){
                    array[i]=array[i+1];
                }
                cout<<"element deleted from pos "<< pos <<endl;

            }
            else{
                cout<<"element not found"<<endl;
            }
        }
    int search(int val){
        for (int i=0;i<size;i++){
            if (array[i]==val){
                cout<<"element found ar index "<<i<<endl;
                return i;
            }
        }
        cout<<"element not found "<<endl;
        return 0;
    }
};
int main(){
    List l1;
    l1.insert(5);
    l1.insert(10);
    l1.insert(15);
    l1.insert(20);
    l1.search(15);
    l1.deleteElement(15);
    l1.search(15);
    l1.search(20);
}