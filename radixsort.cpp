#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingsort(vector<int> & arr,int exp){
    int n=arr.size();
    vector <int> output(n);
    vector <int> count(10,0);
    for (int i=0;i<n;i++){
        int digit=(arr[i]/exp)%10;
        count[digit]++;
    }
    for (int i=1;i<10;i++){
        arr[i]+=arr[i-1];
    }
    for(int i=n-1;i>=0;i--){
        int digit=(arr[i]/exp)%10;
        output[count[i]-1]=arr[i];
        count[digit]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
void radixsort(vector <int> & arr){
    int max= * max_element(arr.begin(),arr.end());
    for(int exp=1; max/exp>0;exp*=10){
        countingsort(arr,exp);
    }
}
int main(){
    vector <int> arr={1,2,3,4,5,2142,5435,53542,6424,42};
    cout<<"og"<<endl;
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;
    radixsort(arr);
    cout<<"after sorting"<<endl;
    for(int num : arr){
        cout<<num<<" ";
    }
    cout<<endl;
}