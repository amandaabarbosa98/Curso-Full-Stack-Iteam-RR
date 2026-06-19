#include <iostream>
using namespace std;

class Produto {
private:
    string nome;
    double preco;

public:
    Produto (string n, double p) : nome(n), preco(p) {}

    void set_preco(double p){
        if( p > 0){
            preco = p;
            cout << "Preço adicionado com sucesso!" << endl;
        }else {
            cout << "Preço informado inválido." << endl;
        }
    }

    string get_nome() const {
        return nome;
    }

    double get_preco() const {
        return preco;
    }

};

int main(){
    Produto p1("Arroz", 3.5);
    Produto p2("Feijão", 6.95);

    cout << p1.get_nome() << endl;
    p1.set_preco(10);
    cout << p2.get_nome() << endl;
    p2.set_preco(-2);


    return 0;
}