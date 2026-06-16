#include <iostream>
using namespace std;

class Cachorro {
private:
    string nome;
    string raca;
public:
    Cachorro(string nome, string raca){
        this -> nome = nome;
        this -> raca = raca;
    }

    void latir(){
        cout << "Au Au! O cachorro " << this->nome << " esta latindo." << endl;
    }
};

int main(){
    Cachorro c1("BOB", "Vira lata");
    
    c1.latir();
}