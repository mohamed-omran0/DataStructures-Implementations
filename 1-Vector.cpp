#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
class Vector{
    int *data,size,capacity;
public:
    Vector(){ data= nullptr,size=capacity=0;}
    Vector(int sz,int val){
        data=new int [sz];
        size=capacity=sz;
        for (int i = 0; i < sz; ++i) {
            data[i]=val;
        }
    }
    Vector(int sz){
         data=new int [sz];
         size=capacity=sz;
        for (int i = 0; i < sz; ++i) {
            data[i]=0;
        }
    }
    Vector(Vector &cpy){
        copy(cpy);
    }

    //functions
    int GetSize(){
        return size;
    }
    int GetCapacity(){
        return capacity;
    }
    int back(){
        //exception handling;
        return data[size-1];
    }
    int front (){
        //exception handling;
        return data[0];
    }
    bool empty() {
        return size==0;
    }
    void clear(){
        size=capacity=0;
        if(data!= nullptr){
            delete[]data;
            data= nullptr;
        }
    }
    void copy(Vector &v){
        if(data!= nullptr)data= nullptr,size=capacity=0;
        capacity=size=v.GetSize();
        data=new int [capacity];
        for (int i = 0; i < size; ++i) {
            data[i]=v[i];
        }
    }
    void push_back(int val){
        if(size==capacity){
            UpdateCap((capacity<<1)+(capacity==0));
        }
        data[size++]=val;
    }
    void UpdateCap(int NewCap){
        int *tmp=new int [NewCap];
        for (int i = 0; i < size; ++i) {
            tmp[i]=data[i];
        }
        for (int i = size; i <NewCap ; ++i) {
            tmp[i]=0;
        }
        capacity=NewCap;
        swap(tmp,data);
        delete[]tmp;
        tmp= nullptr;
    }

    void insert(int i,int val){
       int sz=size;
       i--;
        push_back(back());
        for (int j = sz-1; j >=i ; --j) {
           data[j+1]=data[j];
        }
        data[i]=val;
    }

    void erase(int pos){
        pos--;
        for (int i = pos; i < size; ++i) {
            data[i]=data[i+1];
        }
        size--;
    }


    // operator overloading
    void operator=(Vector &v){
        copy(v);
    }
    // (&) to can make cin>>v[i];
    int& operator[](int i) {
        return data[i];
    }


};
int main() {
    fast
    int t = 1;
//    cin >> t;
    while (t--) {

    }
}