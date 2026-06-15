#include <iostream>

using namespace std;

class Notebook {
private:
    int ano;
    string marca;


public: 
    Notebook(int ano,string marca){
        this->ano = ano;
        this->marca = marca;
    }
    void Apresentar(){
        cout << "Ano de fabricação: " << this->ano << endl;
        cout << "Marca: " << this->marca << endl;
    }
};

int main(){
    Notebook n1(2020,"Dell");
    Notebook n2(2023,"Acer");
    n1.Apresentar(); 
    n2.Apresentar(); 
    return 0;
}