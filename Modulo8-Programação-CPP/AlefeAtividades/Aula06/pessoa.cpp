#include <iostream>
using namespace std;

class Pessoa {
private:
    string nome;
    int idade;
public:
    Pessoa(string nome, int idade){
        this -> nome = nome;
        this -> idade = idade;
    }

    void apresentarse(){
        cout << "Ola, meu nome eh " << this -> nome << " e eu tenho " << this-> idade << endl;
    }
};

int main(){
    Pessoa p1("Joao", 12);
    Pessoa p2("Carlos", 15);

    p1.apresentarse();
    p2.apresentarse();
}