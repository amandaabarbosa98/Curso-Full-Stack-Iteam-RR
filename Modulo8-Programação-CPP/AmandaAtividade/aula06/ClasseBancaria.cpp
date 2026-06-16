#include <iostream>

using namespace std;

class ContaBancaria {
private:
    string titular;
    float saldo;


public: 
    ContaBancaria(string titular,float saldo){
        this-> titular = titular;
        this->saldo = saldo;
    }
    void Sacar(float valor){
        if (valor < this->saldo){
            this->saldo -= valor;
            cout << "Você sacou R$" << valor << " reais" << endl;
            cout << "Saldo final de " << this->titular << " : " << this->saldo << " reais\n" << endl;
        }else{
            cout << "Saldo insuficiente" << endl;
            cout << "Saldo final de " << this->titular << " : " << this->saldo << " reais\n" << endl;
        }
    }
    void Depositar(float valor){
        this->saldo += valor;
        cout << "Você depositou: R$ " << valor << " reais" << endl;
        cout << "Saldo final de " << this->titular << " : " << this->saldo << " reais\n" << endl;
    }
};

int main(){
    ContaBancaria conta1("Amanda",1000);
    ContaBancaria conta2("Ana",400);
    conta1.Depositar(300);
    conta2.Sacar(600);
    return 0;
}