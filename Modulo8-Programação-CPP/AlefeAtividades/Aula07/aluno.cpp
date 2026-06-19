#include <iostream>
using namespace std;

class Aluno {
private:
    string nome;
    int nota;

public:
    Aluno(string n, int n1): nome(n), nota(n1) {}
    
    void set_nota(int n) {
        if (n >= 0 && n <= 10){
            nota = n;
            cout << "Nota adicionada com sucesso!" << endl;
        }else{
            cout << "Nota inválida! Informe um valor entre 0 e 10." << endl;
        }
    }

    int get_nota() const{
        return nota;
    }

    string get_nome() const {
        return nome;
    }
};


int main () {
    Aluno a("Carlos", 8);
    a.set_nota(12);

    return 0;
}