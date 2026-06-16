#include <iostream>
using namespace std;

int fibonacci(int num) {
    if (num == 1){
        return 0;
    }

    if(num == 2){
        return 1;
    }

    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main () {
    int x;
    cout << "Informe a posição da sequência de fibonnaci que você quer: " << endl;
    cin >> x;
    cout << "O número da posição " << x << " eh " << fibonacci(x) << endl;

    return 0;
}