#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int idade;
    cout << "Digite sua idade:" << endl;
    cin >> idade;
    cout << "Sua idade eh " << idade << "." << endl;

    double pi = 3.1415; 

    double dinheiro = 10.9; // ou 5
    //cout << "a " << setprecision(pi) << endl;
    cout << fixed << setprecision(2) << pi << endl;
    cout << "R$ " << fixed << setprecision(2) << dinheiro << endl;
    return 0;
}