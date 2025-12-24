#include <iostream>
using namespace std;

bool prime(int num){
    for (int i = 2; i<(num/2+1);i++){
        if (num%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"Number is prime?: "<< prime(n);
    return 0;
}