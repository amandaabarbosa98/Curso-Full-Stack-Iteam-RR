#include <iostream>
using namespace std;

class Produto {
protected:
    string nome;
    double preco;
public:
    Produto(string n, double p): nome(n), preco(p) {}
    virtual void mostrar_infor() {
        cout << "Nome do produto: " << nome
        << "\nPreço: " << preco << endl;
    }
};

class Livro : public Produto {
private:
    string autor;
public:
    Livro(string n, double p, string a) : Produto(n, p), autor(a) {}
    
    void mostrar_infor() override {
        cout << "Nome do produto: " << nome
        << "\nPreço: " << preco 
        << "\nNome do autor: " << autor << endl;
    }
};

class Eletronico: public Produto{
private:
    string marca;
public:
    Eletronico(string n, double p, string m) : Produto(n, p), marca(m) {}

    void mostrar_infor() override {
        cout << "Nome do produto: " << nome
        << "\nPreço: " << preco 
        << "\nNome da marca: " << marca << endl;
    }    
};

int main(){
    Produto p1("Arroz", 4.50);
    Produto p2("Feijão", 10.50);

    Livro a1("A volta dos que não foram", 59.45, "Fábio Peixoto");
    Livro a2("Tente outra vez", 85.65, "João Carvalho");

    Eletronico e1("Notebook", 2559.49, "Dell");
    Eletronico e2("Caixa de Som", 1500.00, "JBL");

    p1.mostrar_infor();
    cout << endl;
    p2.mostrar_infor();
    cout << endl;
    a1.mostrar_infor();
    cout << endl;
    a2.mostrar_infor();
    cout << endl;
    e1.mostrar_infor();
    cout << endl;
    e2.mostrar_infor();

    return 0;
}