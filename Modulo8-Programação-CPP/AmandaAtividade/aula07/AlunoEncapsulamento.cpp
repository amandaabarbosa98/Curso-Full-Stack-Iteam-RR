#include <iostream>

using namespace std;

class Aluno{
private:
    string nome;
    double nota;
public:
    Aluno(string n, double n1) : nome(n), nota(n1){}

    string getnome() const { return nome; }
    double getnota() const { return nota; }

    void set_nota(double notaAluno){
        if (notaAluno >= 0 && notaAluno <=10 ){
            nota = notaAluno;
            cout <<"\nNota do aluno "<< getnome() << " \nNota "<< notaAluno << " computada com sucesso" << endl;
        }else{
            cout <<"\nNota do aluno "<< getnome() <<  endl;
            cout << "inválida para nota" << endl;
        }
    }

    
};
    

int main(){
    Aluno a("Carlos",8.5);
    Aluno b("Amanda",9);
    b.set_nota(10);
    a.set_nota(12);
    return 0;
}