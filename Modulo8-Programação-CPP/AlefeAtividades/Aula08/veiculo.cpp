#include <iostream>
using namespace std;

class Veiculo {
protected:
    string marca;
public:
    Veiculo(string m) : marca(m) {}

    virtual void mostrar(){
        cout << "A marca do meu carro é " << marca << "." << endl ; 
    }
};

class Carro : public Veiculo {
private:
    string modelo;
public:
    Carro(string m, string mod): Veiculo(m), modelo(mod) {}

    void mostrar() override{
        cout << "A marca do meu carro é " << marca << ".\nE o modelo é: " << modelo << endl ; 
    }
};

int main() {
    Veiculo v("Fiat");
    Carro c("Corrola", "ESPORTIVO");
    v.mostrar();
    c.mostrar();
    return 0;
}