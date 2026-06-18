#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Restaurante{
private:    
    string nome;
    vector<string> cardapio;
public: 
    Restaurante(string n, vector<string> c) : nome(n), cardapio(c){}

    string getNome() const { return nome; }

    void setNome(string novo_nome){
        if(!novo_nome.empty()){
            nome = novo_nome;
            cout << "Nome alterado com sucesso!" << endl;
        }else{
            cout << "Inválido" << endl;
        }
    }

    void adicionarPrato(string prato){
        if(find(cardapio.begin(), cardapio.end(), prato) == cardapio.end()){
            cardapio.push_back(prato);
            cout << "Prato '" << prato << "' adicionado com sucesso!" << endl;
        } else {
            cout << "O prato '" << prato << "' já existe no cardápio." << endl;
        }
    }

    void listarCardapio() const {
        cout << "\n--- Cardápio do Restaurante " << nome << " ---" << endl;
        if(cardapio.empty()){
            cout << "O cardápio está vazio." << endl;
        } else {
            for(const string& prato : cardapio){
                cout << "- " << prato << endl;
            }
        }
        cout << "-----------------------------------" << endl;
    }

    void atenderCliente(string nome_cliente, string prato){
        if(find(cardapio.begin(), cardapio.end(), prato) != cardapio.end()){
            cout << "Pedido confirmado! O cliente " << nome_cliente << " pediu " << prato << "." << endl;
        } else {
            cout << "Infelizmente o prato '" << prato << "' não existe no cardápio." << endl;
        }
    }
};

int main(){
    vector<string> cardapioInicial;
    Restaurante meuRestaurante("Sabor Caseiro", cardapioInicial);

    cout << "--- Adicionando Pratos ---" << endl;
    meuRestaurante.adicionarPrato("Feijoada");
    meuRestaurante.adicionarPrato("Frango Grelhado");
    meuRestaurante.adicionarPrato("Lasanha");

    meuRestaurante.listarCardapio();

    cout << "\n--- Atendendo Clientes ---" << endl;
    meuRestaurante.atenderCliente("João", "Feijoada");
    meuRestaurante.atenderCliente("Maria", "Sushi"); 

    cout << "\n--- Alterando Nome do Restaurante ---" << endl;
    meuRestaurante.setNome("Sabor Caseiro Premium");
    cout << "Novo nome do restaurante: " << meuRestaurante.getNome() << endl;

    return 0;
}