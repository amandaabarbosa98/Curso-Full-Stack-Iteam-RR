#include <iostream>
using namespace std;

class Carro {
private:
    string __marca;
    float __velocidade;
public:
    Carro (string m, float v) : __marca(m), __velocidade(v) {}

    void acelerar(float valor) {
        if (valor > 0) {
            __velocidade += valor;
            cout << "Você acelerou, sua velocidade é " << __velocidade << " KM/h" << endl;
        }else{
            cout << "Aceleração não detectada." << endl; 
        }
    }

    void frear (float valor) {
        if(valor > 0 && valor < __velocidade){
            __velocidade -= valor;
            cout << "Você desacelerou, sua velocidade é " << __velocidade << " KM/h" << endl;
        }else{
            cout << "Desaceleração não detectada." <<  endl; 
        }
    }

    string get_marca() const {
        return __marca;
    }

    float get_velociadade() const {
        return __velocidade;
    }

};

int main () {
    Carro c("Fiat", 40);
    cout << "Seu carro da marca " << c.get_marca() << " está na velocidade " << c.get_velociadade() << endl; 
    c.frear(5);
    c.acelerar(30);
    return 0;
}