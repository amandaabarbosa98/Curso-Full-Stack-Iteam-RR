#include <iostream>

using namespace std;

class Veiculo{
protected:
    string marca;
public:
    Veiculo(string m): marca(m){}

    virtual void apresentar() {
        cout << "Marca: " << marca << endl;
    }
};
class Carro : public Veiculo{
private: 
    string modelo;
public:
    Carro(string m,string m2) : Veiculo(m), modelo(m2){}

    void apresentar() override {
        cout << "\nMarca: " << marca << "\nCarro: "<< modelo << endl;
    }
};
int main(){
    Veiculo v("Fiat");
    Carro meuCarro("Toyota", "Corolla");
    v.apresentar();
    meuCarro.apresentar();
    return 0;
}