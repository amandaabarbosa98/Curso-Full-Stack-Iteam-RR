#include <iostream>
#include <string>

using namespace std;

class Funcionario{
protected:
    string nome;
    float salario;
public:
    Funcionario(string n, float s) : nome(n), salario(s) {}

    virtual void MostrarSalario(){
        cout << "Funcionario: " << nome << " | Salário: " << salario <<endl;
    }
};

class Gerente : public Funcionario{
private:

public:
    Gerente(string n, float s) : Funcionario(n,s){}

    void MostrarSalario() override {
        float AumentoSalario = salario * 0.20;
        cout << "Funcionario: " << nome << " | Salário: " << salario <<endl;
        cout << "Voce recebeu um aumento de bonus de R$ " << AumentoSalario << " reais" << endl;
    }
};





int main(){
    Gerente g1("Amanda",3000);
    g1.MostrarSalario();

    return 0;
}