#include <iostream>

using namespace std;

int main(){
    int * pi = new int;
    *pi = 1001;
    cout << "Valor inteiro: " << *pi << endl;
    cout << "Valor endereço: " << pi << endl;

    double * pd = new double;
    *pd = 500.35;
    cout << "Valor: " << *pd << endl;
    cout << "Valor endereço: " << pd << endl;

    float * pf = new float;
    *pf = 500.35;
    cout << "Valor: " << *pf << endl;
    cout << "Valor endereço: " << pf << endl;

    cout << sizeof(pi) << endl;
    cout << sizeof(*pi) << endl << endl;
    cout << sizeof(pd) << endl;
    cout << sizeof(*pd) << endl << endl;
    cout << sizeof(pf) << endl;
    cout << sizeof(*pf) << endl << endl;

    delete[] pi;
    delete[] pd;
    delete[] pf;

    return 0;
}