#include <iostream> 
#include <iomanip>
using namespace std;

int main(){
    // int idade;
    // cout << "Digite sua idade: \n";
    // cin >> idade;
    // cout << "Sua idade e " << idade << " anos.";

    // double pi = 3.121617617;
    // cout << setprecision(pi) << endl;
    // cout << fixed << setprecision(2) << pi << endl;

    double massa_eletron = 0.000910938;

    // Fixa o número de casas decimais em 8
    cout << fixed << setprecision(8);
    cout << "Massa: " << massa_eletron << " kg" << endl;

    return 0;
}