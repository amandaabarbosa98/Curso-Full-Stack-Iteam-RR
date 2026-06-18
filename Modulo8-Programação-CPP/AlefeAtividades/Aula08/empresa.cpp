#include <iostream>
using namespace std;

class Funcionario {
protected:
    string nome;
    double salario;
public:
    Funcionario(string n, double s): nome(n), salario(s) {}

    virtual void mostrarSalario(){
        cout << "Valor do Salário: " << salario << endl ;
    }
};

class Gerente : public Funcionario{
private:
    
public:
    Gerente(string n, double s): Funcionario(n, s) {}

    void mostrarSalario() override{
        double salario_bonus = salario * 1.20;
        cout << "Valor do Salário: " << salario << endl;
        cout << "Valor do Salário com Bonus de 20%: " << salario_bonus << endl;
    }
};

int main() {

    Funcionario f("João", 1500);
    Gerente g("Gabriel", 3000);

    f.mostrarSalario();
    g.mostrarSalario();
    return 0;    
}