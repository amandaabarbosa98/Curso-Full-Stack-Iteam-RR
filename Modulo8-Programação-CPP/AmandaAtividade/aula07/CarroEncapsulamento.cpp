#include <iostream>

using namespace std;

class Carro{
private:
    string marca;
    int velocidade;
public:
    Carro(string m, int v) : marca(m), velocidade(v){}

    string getmarca() const { return marca; }
    int getvelocidade() const { return velocidade; }

    void acelerar(int valor){
        if (valor > 0){
            velocidade += valor;
            cout << getmarca() << " :" << endl;
            cout << "O carro está acelerando a " << velocidade << "km/h" << endl;
        }else{
            cout << getmarca() << " :" << endl;
            cout << "Valor inválido" << endl;
        }
    }
    void frear(int valor){
        if ((valor > 0) && (valor < velocidade)){
            velocidade -= valor;
            cout << getmarca() << " :" << endl;
            cout << "O carro está reduzinho a " << velocidade << "km/h" << endl;
        }else{
            cout << getmarca() << " :" << endl;
            cout << "Valor inválido" << endl;
        }
    }
};
    

int main(){
    Carro c1("Fiat",60);
    Carro c2("corolla",50);
    c1.acelerar(20);
    c2.frear(60);
    c2.acelerar(-20);
    return 0;
}