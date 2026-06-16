#include <iostream>
using namespace std;

class Aluno {
private:
    string nome;
    int nota1;
    int nota2;
public:
    Aluno(string nome, int nota1, int nota2){
        this -> nome = nome;
        this -> nota1 = nota1;
        this -> nota2 = nota2;
    }

    double calcular_media(){
        return (this-> nota1 + this -> nota2) /2.0; 
    }

    void situacao(){
        if(this->calcular_media() >= 7){
            cout << "Aluno " << this-> nome << " esta aprovado com media " << this->calcular_media() << "." << endl;
        }else{
            cout << "Aluno " << this-> nome << " esta reprovado com media " << this->calcular_media() << "." << endl;
        }

    }
};

int main(){
    Aluno a1("Gabriel", 7, 6);
    Aluno a2("Felipe", 9, 8);

    a1.situacao();
    a2.situacao();
}