#include <iostream>
using namespace std;
int fat_recusivo(int num) {
    if (num == 1)
        return 1;

    return num * fat_recusivo(num-1);
}

int main () {

    int n;

    cout << "Informe o numero para calculo do fatorial: " << endl;
    cin >> n;

    cout << "O fatorial de " << n << " eh " << fat_recusivo(n) << endl;
    return 0;
}