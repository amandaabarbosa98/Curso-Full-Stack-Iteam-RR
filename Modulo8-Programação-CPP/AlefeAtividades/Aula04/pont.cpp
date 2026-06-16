#include <iostream>

using namespace std;

int main () {
    int *pi = new int;
    *pi = 10;
    cout << "Referencia: " << *pi << "\nEndereço Ponteiro: " << pi << endl;
    double *pd = new double;
    *pd = 50.5;
    cout << "Referencia: " << *pd << "\nEndereço Ponteiro: " << pd << endl << endl;

    cout << "Tamanho da referencia: "<< sizeof(*pi) << endl;
    cout << "Tamanho do ponteiro: " << sizeof(pi) << endl << endl;
     
    cout << "Tamanho da referencia: "<< sizeof(*pd) << endl;
    cout << "Tamanho do ponteiro: " << sizeof(pd) << endl << endl;

    delete[] pi;
    delete[] pd;

    return 0;
}