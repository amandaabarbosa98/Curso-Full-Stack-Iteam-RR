#include <iostream>
using namespace std;

class ContaBancaria {
private:
    string titular;
    double saldo;
public:
    ContaBancaria(string titular, double saldo){
        this -> titular = titular;
        this->saldo = saldo;
    }

    void depositar(double valor){
        if (valor > 0){
            this -> saldo += valor;
            cout << "Deposito realizado com sucesso." << endl; 
        }else{
            cout << "Valor para deposito invalido." << endl;
        }
    }

    void sacar(double valor){
        if (valor <= this-> saldo){
            this -> saldo -= valor;
            cout << "Saque realizado com sucesso." << endl; 
        }else{
            cout << "Valor para saque invalido." << endl;
        }
    }

    void mostrar_saldo(){
        cout << "Seu saldo atual é: " << this -> saldo << endl;
    }
};

int main(){
    ContaBancaria c1("Gabriel", 760.50);

    c1.mostrar_saldo();
    c1.depositar(10);
    c1.mostrar_saldo();
    c1.sacar(500);
    c1.mostrar_saldo();
}