#include <iostream>
#include <vector>
#include <optional>
#include <memory>

using namespace std;

class Personagem {
protected:
    string nome;
    int poder;
    string tipo_personagem;

public:
    Personagem(string n, int p, string tp) : nome(n), poder(p), tipo_personagem(tp){}    
    virtual ~Personagem() = default;

    int getPoder() const { return poder; }

    virtual void exibir() const {
        cout << "Nome: " << nome << " | Tipo: " << tipo_personagem << " | Poder: " << poder;
    }
};

class ChefesDaFloresta : public Personagem {
private: 
    string reino;
public:
    ChefesDaFloresta (string n, int p, string tp, string r) : Personagem(n,p,tp) , reino (r) {}
    
    void exibir() const override {
        Personagem::exibir();
        cout << " | Reino: " << reino;
    }
};

class No {
public:
    shared_ptr<Personagem> personagem; 
    optional<int> indice_esquerda;     
    optional<int> indice_direita;      
    
    No(shared_ptr<Personagem> p, optional<int> esquerda = nullopt, optional<int> direita = nullopt)
        : personagem(p), indice_esquerda(esquerda), indice_direita(direita) {}
};

class ArvoreBinaria {
private:
    vector<No> nos;         
    optional<int> raiz = nullopt;
    
public:
    void inserir(shared_ptr<Personagem> p) {
        No novo_no(p);
        nos.push_back(novo_no);
        int novo_idx = nos.size() - 1;

        if (!raiz.has_value()) {
            raiz = novo_idx;
            return;
        }

        int atual_idx = raiz.value();
        while (true) {
            if (p->getPoder() < nos[atual_idx].personagem->getPoder()) {
                if (!nos[atual_idx].indice_esquerda.has_value()) {
                    nos[atual_idx].indice_esquerda = novo_idx;
                    break;
                }
                atual_idx = nos[atual_idx].indice_esquerda.value();
            } 
            else {
                if (!nos[atual_idx].indice_direita.has_value()) {
                    nos[atual_idx].indice_direita = novo_idx;
                    break;
                }
                atual_idx = nos[atual_idx].indice_direita.value();
            }
        }
    }
    
    void percorrer_em_ordem() {
        percorrer_em_ordem_aux(raiz);
    }

private:
    void percorrer_em_ordem_aux(optional<int> indice) {
        if (!indice.has_value()) {
            return;
        }
        
        int idx = indice.value();
        
        if (idx < 0 || idx >= static_cast<int>(nos.size())) {
            return;
        }
        
        percorrer_em_ordem_aux(nos[idx].indice_esquerda);
        
        nos[idx].personagem->exibir();
        cout << endl;
        
        percorrer_em_ordem_aux(nos[idx].indice_direita);
    }
};

int main(){
    ArvoreBinaria floresta;

    floresta.inserir(make_shared<Personagem>("Goblin", 30, "Monstro"));
    floresta.inserir(make_shared<Personagem>("Lupi", 50, "Animal"));
    floresta.inserir(make_shared<Personagem>("Groot", 70, "Planta"));
    floresta.inserir(make_shared<Personagem>("Mago Merlin", 95, "Mago"));
    floresta.inserir(make_shared<ChefesDaFloresta>("Rainha Elfa", 110, "Elfo", "Vales Verdes"));
    floresta.inserir(make_shared<ChefesDaFloresta>("Chefe Dragao", 150, "Dragao", "Montanhas de Fogo"));

    cout << "--- Personagens da Floresta (Do menos ao mais poderoso) ---\n" << endl;
    floresta.percorrer_em_ordem();

    return 0;
}