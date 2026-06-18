#include <iostream>

using namespace std;

class Produto{
private:
    string nome;
    double preco;
public:
    Produto(string n, double p) : nome(n), preco(p){}

    string getnome() const { return nome; }
    double getpreco() const { return preco; }

    void set_preco(double valorPreco){
        if (valorPreco != 0 || valorPreco > 0 ){
            preco = valorPreco;
            cout << getnome() << ":" <<endl;
            cout << "Preço R$ " << valorPreco << " reais atualizado com sucesso\n" <<endl;
        }else{
            cout << getnome() << ":" <<endl;
            cout << "Valor inválido para produto" << endl;
        }
    }
};
    

int main(){
    Produto p1("Escova de dente",20.5);
    Produto p2("Arroz",5.95);
    p1.set_preco(22.5);
    p2.set_preco(0);
    return 0;
}