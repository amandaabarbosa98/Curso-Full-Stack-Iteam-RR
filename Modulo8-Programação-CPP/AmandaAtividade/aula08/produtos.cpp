#include <iostream>
#include <string>

using namespace std;

class Produto{
protected:
    string nome;
    float preco;
public:
    Produto(string n, float p) : nome(n), preco(p) {}

    virtual void MostrarProduto(){
        cout << "Produto: " << nome << " | Preco: R$" << preco <<endl;
    }
};

class Livro : public Produto{
private:
    string autor;
public:
    Livro(string n, float p,string a) : Produto(n,p), autor(a) {}

    void MostrarProduto() override {
        cout << "Nome do Livro: " << nome << " | Preco: R$" << preco << " | Autor: "<< autor << endl;
    }
};

class Eletronico : public Produto{
private:
    string marca;
public:
    Eletronico(string n, float p,string m) : Produto(n,p), marca(m) {}

    void MostrarProduto() override {
        cout << "Eletronico: " << nome << " | Preco: R$" << preco << " | Marca: "<< marca << endl;
    }
};
int main(){
    Produto p("Arroz", 8.95);
    Produto p1("Farinha", 15);

    Livro l("Harry Potter e as Reliquias da Morte", 55.5, "J.K Rowling");
    Livro l2("Hobbit", 80, " J. R. R. Tolkien");

    Eletronico e("Fone de ouvido",200,"JBL");
    Eletronico e2("Teclado",30,"acer");
    
    p.MostrarProduto();
    p1.MostrarProduto();

    l.MostrarProduto();
    l2.MostrarProduto();
    
    e.MostrarProduto();
    e2.MostrarProduto();
    return 0;
}