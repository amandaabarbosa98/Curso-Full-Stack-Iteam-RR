#include <iostream>

using namespace std;
int fibo(int x){
    if (x == 1){
        return 0;
    }else if (x == 2){
        return 1;
    }else{
        return (fibo(x-1) + fibo(x-2));
    }
}
int main(){
    int x;
    cout << "Digite quantos numeros você fazer o fibonacci";
    cin >> x;
    cout << (fibo(x));
    return 0;
}