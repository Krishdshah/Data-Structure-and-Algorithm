#include <iostream>
using namespace std;
int main(void){
    int a,b,temp;
    cout<<"Enter Number 1"<<endl;
    cin>>a;
    cout<<"Enter Number 2"<<endl;
    cin>>b;
    temp=a;
    a=b;
    b=temp;
    cout<<"a = "<<a<<" b = "<<b;
}