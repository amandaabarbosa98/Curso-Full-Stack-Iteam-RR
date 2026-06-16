#include <iostream>

using namespace std;

class Aluno {
private:
    string nome;
    int nota1;
    int nota2;


public: 
    Aluno(string nome,int nota1, int nota2){
        this->nome = nome;
        this->nota1 = nota1;
        this->nota2 = nota2;
    }
    float CalcularMedia(){
        float mediaFinal = 0;
        mediaFinal = (this->nota1 + this->nota2) / 2;
        cout << "Media final do " << this->nome << ":"<< mediaFinal << endl;
        return mediaFinal;
    }
    void MostrarResultado(){
        if ((this->CalcularMedia())>=7){
            cout << "Aluno Aprovado" << endl;
        }else{
            cout << "Aluno reprovado" << endl;
        }
        }
};

int main(){
    Aluno Aluno1("Amanda",7,9);
    Aluno Aluno2("Alefe",10,10);
    Aluno Aluno3("Bruno",5,4);
    Aluno1.MostrarResultado();
    Aluno2.MostrarResultado();
    Aluno3.MostrarResultado();
    return 0;
}