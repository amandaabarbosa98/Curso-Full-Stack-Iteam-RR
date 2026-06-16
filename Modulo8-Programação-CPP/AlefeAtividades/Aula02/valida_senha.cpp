#include <iostream>
#include <string>
using namespace std;

int main () {
    string username = "alefe"; 
    string senha = "123";

    string tentativa_u;
    string tentativa_s;

    for (int i = 1; i <= 3; i++) {
        cout << "Informe seu nome de usuario: "<< endl;
        cin >> tentativa_u;

        cout << "Informe sua senha: "<< endl;
        cin >> tentativa_s;
    
        if (username != tentativa_u){
            cout << "Usuario nao encontrado!!!" << endl;
            
            if (i != 3){
                cout << "Voce tem " << 3 - i << " tentativas restantes.\nTente novamente.\n\n" << endl;
            }else{
                cout << "Bloqueado!!!" << endl;
                break;
            } 
            continue;  
        }

        if (senha != tentativa_s) {
            cout << "Senha incorreta!!!" << endl;

            if (i != 3){
                cout << "Voce tem " << 3 - i << " tentativas restantes.\nTente novamente.\n\n" << endl;
            }else{
                cout << "Bloqueado!!!" << endl;
                break;
            }   
            continue;
        }

        cout << "Login realizado com sucesso!!!" << endl;
        break;
    }

    return 0;
}