#include <iostream>
#include <cstring>
#include <string>
#include <locale>

#ifdef _WIN32
#include <windows.h> 
#endif

using namespace std;

int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #else
    setlocale(LC_ALL, "pt_BR.UTF-8");
    #endif
    string senhaDigitada = "";
    string senhaCerta = "amanda";
    string loginDigitado = "";
    string loginCerto = "amanda";
    int tentativas;
//     for (tentativas = 4; tentativas != 0; tentativas--){
//         cout << "Digite seu login: ";
//         cin >> loginDigitado;
//         cout << "Digite sua senha: ";
//         cin >> senhaDigitada;
//         if ((senhaDigitada == senhaCerta) && (loginDigitado == loginCerto)){
//             cout << "Login realizado com sucesso" << endl;
//             break;
//         }else{
//             cout << "Login ou senha inválidos ou errado" << endl;
//         }
//         cout << "Voce ainda tem " << tentativas - 1 << " tentativas. " << endl;
//     }
// }
    for(tentativas = 4; tentativas != 0; tentativas--){
            cout << "Digite seu login: ";
            cin >> loginDigitado;
            cout << "Digite sua senha: ";
            cin >> senhaDigitada;
        try {
            if ((senhaDigitada != senhaCerta) || (loginDigitado != loginCerto)){
                throw "Senha e usuarios invalidos";
            }
            cout << "Login realizado com sucesso!" << endl;
            break; 
        }catch (const char* msg){
            cout << msg << endl; 
            cout << "Você ainda tem " << tentativas - 1 << " tentativas." << endl;
            if (tentativas - 1 == 0) {
                cout << "Usuário bloqueado porque suas tentativas acabaram" << endl;
            }
        }
    }
    return 0; 
}