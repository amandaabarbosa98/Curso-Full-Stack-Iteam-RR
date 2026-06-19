#include <iostream>
#include <vector>
#include <memory>
#include <optional>

using namespace std;

class Personagem {
protected:
    string nome;
    int nivel_poder;
    string tipo; // Animal ou Mago
public:
    Personagem (string n, int nivel, string t): nome(n), nivel_poder(nivel), tipo(t) {}

    string getNome() const {
        return nome;
    }

    int getNivelPoder() const {
        return nivel_poder;
    }

    string getTipo() const {
        return tipo;
    }

    virtual string getReino () const {
        return "";
    }

};

class ChefeFloresta  : public Personagem {
private:
    string reino;
public:
    ChefeFloresta (string n, int nivel, string t, string r) : Personagem(n , nivel, t), reino(r) {}
    
    string getReino() const override {
        return reino;
    }
};


// Classe Nó
class No {
public:
    Personagem p;
    optional<int> indice_esquerda;  // referência lógica (índice)
    optional<int> indice_direita;   // referência lógica (índice)
    
    // Construtor
    No(Personagem p, optional<int> esquerda = nullopt, optional<int> direita = nullopt)
        : p(p), indice_esquerda(esquerda), indice_direita(direita) {}
};

// Classe Árvore Binária
class ArvoreBinaria {
private:
    vector<No> nos;  // lista de nós
    
public:
    // Adicionar nó
    void adicionar_no(Personagem p, optional<int> indice_esquerda = nullopt, 
                      optional<int> indice_direita = nullopt) {
        No no(p, indice_esquerda, indice_direita);
        nos.push_back(no);
    }
    
    // Exibir estrutura da árvore
    void exibir() const {
        for (size_t i = 0; i < nos.size(); i++) {
            if(nos[i].p.getReino() != ""){
                cout << "Nó " << i << ": Personagem= " << nos[i].p.getNome() << ", " << nos[i].p.getNivelPoder() << ", " << nos[i].p.getTipo() << ", " << nos[i].p.getReino();
            }else {
                cout << "Nó " << i << ": Personagem= " << nos[i].p.getNome() << ", " << nos[i].p.getNivelPoder() << ", " << nos[i].p.getTipo();
            }
            
            if (nos[i].indice_esquerda.has_value()) {
                cout << ", esquerda=" << nos[i].indice_esquerda.value();
            } else {
                cout << ", esquerda=None";
            }
            
            if (nos[i].indice_direita.has_value()) {
                cout << ", direita=" << nos[i].indice_direita.value();
            } else {
                cout << ", direita=None";
            }
            
            cout << endl;
        }
    }
    
    // Percorrer em ordem (in-order traversal)
    void percorrer_em_ordem(optional<int> indice = 0) {
        if (!indice.has_value()) {
            return;
        }
        
        int idx = indice.value();
        
        // Verifica se o índice é válido
        if (idx < 0 || idx >= static_cast<int>(nos.size())) {
            return;
        }
        
        // Percorre subárvore esquerda
        percorrer_em_ordem(nos[idx].indice_esquerda);
        
        // Visita o nó atual
        cout << "| " << nos[idx].p.getNome() << " | ";
        
        // Percorre subárvore direita
        percorrer_em_ordem(nos[idx].indice_direita);
    }
};


int main() {
    ArvoreBinaria arvore;

    
    arvore.adicionar_no(Personagem("Lupi", 20, "Animal"), 1, 2);
    arvore.adicionar_no(Personagem("Mago Merlin", 15, "Mago"), 3, 4);
    arvore.adicionar_no(ChefeFloresta("Chefe Dragão", 50, "Mago", "Reino de Gelo"), nullopt, 5);
    arvore.adicionar_no(Personagem("Joey", 9, "Animal"));
    arvore.adicionar_no(Personagem("Ross", 17, "Animal"));
    arvore.adicionar_no(ChefeFloresta("Phoebe", 60, "Animal", "Reino de Fogo"));


    arvore.exibir();

    cout << "\nPercorrendo em ordem:" << endl;
    arvore.percorrer_em_ordem(0);

    return 0;
}