#include <iostream>

using namespace std;

class ContaBancaria{
private:
    string titular;
    double saldo;
public:
    ContaBancaria(string t, double s) : titular(t), saldo(s){}

    string getTitular() const { return titular; }
    double getSaldo() const { return saldo; }

    void Depositar(double valor){
        if (valor > 0 ){
            saldo += valor;
            cout << "Deposito de R$ " << valor << " realizado." << endl;
        }else{
            cout << "Valor inválido para deposito" << endl;
        }
    }

    bool Sacar(double valor){
        if (valor > 0 && valor <= saldo){
            saldo -= valor;
            cout << "Saque de R$ " << valor << " realizado." << endl;
            return true;
        }else{
            cout << "Saldo insuficiente ou valor inválido!" << endl;
            return false;
        }
    }
};
    

int main(){
    ContaBancaria conta1("Amanda",1000);
    cout << "Titular: " << conta1.getTitular() << endl;
    cout << "Saldo: " << conta1.getSaldo() << endl;
    conta1.Depositar(500);   
    conta1.Depositar(-200);
    conta1.Sacar(300);
    
    cout << "Saldo Final: R$" << conta1.getSaldo() << endl;
    return 0;
}