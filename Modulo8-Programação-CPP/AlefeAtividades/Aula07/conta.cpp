#include <iostream>;
using namespace std;

class ContaBancaria {
private:
    string titular;
    double saldo;
public:
    ContaBancaria(string t, double s) : titular(t), saldo(s) {}
    
    string getTitular() const {return titular;}
    double getSaldo() const {return saldo;}

    void depositar(double valor){
        if (valor > 0) {
            saldo += valor;
            cout << "Depósito de R$" << valor << " realizado." << endl;
        } else{
            cout << "Valor inválido para depósitar!" << endl;
        }
    }

    bool sacar(double valor){
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            cout << "Saque de R$" << valor << " realizado." << endl;
            return true;
        }else {
            cout << "Saldo insuficiente ou valor inválido!" << endl;
            return false;
        }
    }
};

int main () {
    ContaBancaria conta("João", 1000.0);

    cout << "Titular: " << conta.getTitular() << endl;
    cout << "Saldo: R$" << conta.getSaldo() << endl;

    conta.depositar(500);
    conta.sacar(200);
    conta.sacar(2000);

    cout << "Saldo final: R$" << conta.getSaldo() << endl;

    return 0;
}