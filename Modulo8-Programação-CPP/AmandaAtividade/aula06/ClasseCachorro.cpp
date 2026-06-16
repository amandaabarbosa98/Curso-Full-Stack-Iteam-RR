#include <iostream>

using namespace std;

class Cachorro {
private:
    string nome;


public: 
    Cachorro(string nome){
        this->nome = nome;
    }
    void Latir(){
        cout << "Au au! "<< this->nome << " está latindo..." << endl;
    }
};

int main(){
    Cachorro c1("Plutão");
    c1.Latir();
    return 0;
}