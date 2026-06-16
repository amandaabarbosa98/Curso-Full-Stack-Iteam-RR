#include <iostream>

using namespace std;

class Animal{
private:
    string especie;
    string som;


public: 
    Animal(string especie, string som){
        this->especie = especie;
        this->som = som;
    }
    void emitir_som(){
        cout << this->especie << " faz um som de"<< this->som << endl;
    }
};

int main(){
    Animal animal1("Cachorro", " Au au");
    Animal animal2("Gato", " miau");
    animal1.emitir_som();
    animal2.emitir_som();
    return 0;
}