#include <iostream>

using namespace std;

class Carro {
private:
    string marca;
    double preco;

public:
    Carro(string marca, double preco){
        this -> marca = marca;
        this -> preco = preco;
    }

    void mostrar_resumo(){
        cout << "Marca do carro: "<< this->marca <<"\nPreco do carro: " << this->preco << endl;  
    }

};



int main(){
    Carro novo_carro("Marca x", 98749.9);

    novo_carro.mostrar_resumo();
    return 0;
}