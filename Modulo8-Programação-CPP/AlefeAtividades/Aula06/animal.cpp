#include <iostream>
using namespace std;

class Animal {
private:
    string especie;
    string som;
public:
    Animal(string especie, string som){
        this -> especie = especie;
        this -> som = som;
    }

    void emitir_som(){
        cout << "O "<< especie << " faz o som "  << som << endl;
    }
};

int main(){
    Animal a1("Cachorro", "AU AU");
    
    a1.emitir_som();
}