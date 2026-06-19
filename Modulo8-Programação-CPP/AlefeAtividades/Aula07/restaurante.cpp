#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Restaurante {
private:
    string nome;
    vector<string> cardapio;
public: 
    Restaurante(string n) : nome(n) {}

    string getNome() const {
        return nome;
    }

    void setNome(string novo_nome) {
        if (!novo_nome.empty()){
            nome = novo_nome;
            cout << "Nome alterado com sucesso." << endl;
        }else{
            cout << "Alteração não realizada, nome informado é vazio." << endl;
        }
    }

    void adicionarPrato(string prato) {
        if (count(cardapio.begin(), cardapio.end(), prato) ==  0) {
            cardapio.push_back(prato);
            cout << "Prato adicionado com sucesso!" << endl;
        }else {
            cout << "O não adicionado, já presente no cardápio." << endl;
        }
    }

    void listarCardapio() {
        int c = 0;
        cout << "===== Cardápio do Restaurante " << nome << " =====" << endl;
        for (string prato: cardapio) {
            cout << c+1 << ". " << prato << endl;
        }
        cout << "====================================" << endl;
    }

    void atenderCliente(string nome_cliente, string prato) {
        if (count(cardapio.begin(), cardapio.end(), prato) > 0) {
            cout << "Pedido realizado com sucesso!!" << endl;
        }else {
            cout << "O prato desejado não consta em nosso cardápio." << endl;
        }
    }

};

int main() {
    Restaurante r("Sabor caseiro");

    r.adicionarPrato("Sabor Caseiro");
    r.adicionarPrato("Caldeirada");
    r.adicionarPrato("Peixe a Baiana");

    r.atenderCliente("Joãozinho", "Caldeirada");
    r.atenderCliente("Joãozinha", "Refrigerante");

    r.setNome("Sabor do Rio");
    cout << "Novo nome do restaurante: " << r.getNome() << endl;  

    return 0;
}