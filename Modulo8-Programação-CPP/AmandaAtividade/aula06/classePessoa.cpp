#include <iostream>

using namespace std;

class Pessoa {
private:
    int idade;
    string nome;


public: 
    Pessoa(int idade,string nome){
        this->idade = idade;
        this->nome = nome;
    }
    void Apresentar(){
        cout << "Nome: " << this->nome << endl;
        cout << "Idade: " << this->idade << " anos" <<endl <<endl;
    }
};

int main(){
    Pessoa p1(27,"Amanda");
    Pessoa p2(21,"Alefe");
    p1.Apresentar();
    p2.Apresentar(); 
    return 0;
}