#include <iostream>
using namespace std;

class Pessoa {
protected:
    string nome;

    int idade;
public:
    Pessoa(string n, int i) : nome(n), idade(i) {}

    virtual void falar(){
        cout << nome << " com idade " << idade << " esta falando." << endl;
    }
};

class Professor : public Pessoa{
private:
    string disciplina;
public:
    Professor(string n, string d, int i) : Pessoa(n, i), disciplina(n) {}

    void falar() override {
        cout << "Professor(a) " << nome << " com idade " << idade <<" esta ensinando " << disciplina << "." << endl;
    }
};

class Aluno : public Pessoa {
private:
    int matricula;
public:
    Aluno(string n, int m, int i) : Pessoa(n, i), matricula(m){}

    void falar() override {
        cout << "Aluno(a) " << nome << " com idade " << idade << " (matrícula: " << matricula << ") está aprendendo." << endl;
    }
};

void fazerfalar(Pessoa *p){
    p->falar();
}

int main () {
    Pessoa* p1 = new Pessoa("Maria", 10);
    Pessoa* p2 = new Professor("Carlos", "Matemática", 35);
    Pessoa* p3 = new Aluno("Ana", 101, 15);


    Professor prof("Carlos", "Matemática", 35);
    //fazerfalar(p1);
    //fazerfalar(p2);
    //fazerfalar(p3);

    fazerfalar(&prof);


    delete p1;
    delete p2;
    delete p3;

    return 0;
}