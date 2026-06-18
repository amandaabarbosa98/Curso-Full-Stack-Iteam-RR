#include <iostream>
#include <string>


using namespace std;

class Pessoa{
protected:
    string nome;
    int idade;
public:
    Pessoa(string n, int(i)):nome(n),idade(i){}

    virtual void falar(){
        cout << nome << " está falando." << endl;
    }
};

class Professor : public Pessoa {
private:
    string disciplina;
public:
    Professor(string n,int i, string d): Pessoa(n,i), disciplina(d){}

    void falar() override {
        cout << "Professor(a) " << nome <<" com " << idade << " está ensinando " << disciplina << "." << endl;
    }
};

class Aluno : public Pessoa {
private:
    int matricula;
public:
    Aluno(string n, int i, int m): Pessoa(n,i),matricula(m){}
    
    void falar() override {
        cout << "Aluno(a) " <<" com idade "<< idade << " " << nome << " (matrícula: " << matricula << ") está aprendendo." << endl;
    }
};

void fazerFalar(Pessoa *p){
    p->falar();
}

int main(){
    Pessoa *p1 = new Pessoa("Maria",18);
    Pessoa *p2 = new Professor("Carlos",20, "Matemática");
    Pessoa *p3 = new Aluno("Ana", 40, 101);

    fazerFalar(p1);
    fazerFalar(p2);
    fazerFalar(p3);

    delete p1;
    delete p2;
    delete p3;

    return 0;

}