#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>
using namespace std;

#ifdef _WIN32
#include <windows.h>
#endif
 
int comparar_resultado(int timex, int timey, int apostax, int apostay) {
    if (timex == apostax && timey == apostay){
        return 10;
    }
    
    if (timex > timey){
        //Time x ganhou
        if (apostax > apostay){
            return 5;
        }else{
            return 0;
        }    
    }
    
    if (timex < timey) {
        if (apostax < apostay){
            return 5;
        }else{
            return 0;
        }

    }if (timex == timey){
        if (apostax == apostay){
            return 2;
        }else{
            return 0;
        }
    }
}

int validar_valor(int valor){
    if(valor >= 0){
        return 1;
    }else{
        return 0;
    }
}


class Jogo{
private:
    string time1;
    string time2;
    int gols1;
    int gols2;
public:
    Jogo(string time1, string time2, int gols1, int gols2){
        this -> time1 = time1;
        this -> time2 = time2;
        this -> gols1 = gols1;
        this -> gols2 = gols2; 
    }

    string nome_time1(){
        return time1;
    }

    string nome_time2(){
        return time2;
    }

    int gols_time1(){
        return gols1;
    }

    int gols_time2(){
        return gols2;
    }

};

class Apostador {
private:
    string nome;
    int apostas[4][2];
public:
    
    int pontuacao = 0;

    Apostador(string nome){
        this -> nome = nome; 
    }

    string retornar_nome(){
        return this -> nome;
    }

    void registrar_aposta(vector<Jogo> jogos){
        int c = 0;
        for (Jogo x : jogos){
            cout << c + 1 <<"º Jogo: " << x.nome_time1() << " X " << x.nome_time2() << endl;
            cout << "Digite o placar para o time " << x.nome_time1() << ":" << endl;
            cin >> apostas[c][0];
            while(!validar_valor(apostas[c][0])){
                cout << "Informe um valor positivo para o número de gols." << endl;
                cin >> apostas[c][0];
            }
            
            cout << "Digite o placar para o time " << x.nome_time2() << ":" <<endl;
            cin >> apostas[c][1];
            while(!validar_valor(apostas[c][1])){
                cout << "Informe um valor positivo para o número de gols." << endl;
                cin >> apostas[c][1];
            }

            pontuacao += comparar_resultado(x.gols_time1(), x.gols_time2(), apostas[c][0], apostas[c][1]);
            c++;
        }
    }
};


void mostrar_classificacao(vector<Apostador> &apostadores){
    cout << "\n\n========== Ranking SportBet ==========" << endl;
    vector<pair<int, string>> ranking;
    
    sort(apostadores.begin(), apostadores.end(), [](const Apostador& a, const Apostador& b){return a.pontuacao > b.pontuacao;});

    int c = 0;
    for (Apostador x : apostadores){
        cout << (c + 1) << "º Lugar: " 
            << x.retornar_nome() << " - " 
            << x.pontuacao << " pontos" << endl;
        c++;
    }

    cout << "======================================" << endl;
}

void menu(vector<Apostador> &apostadores, vector<Jogo>jogos, int qtde_jogos){
    int op;

    do{
        cout << "\n\n========== MENU ==========" << endl;   
        cout << "1. Nova Aposta " << endl;
        cout << "2. Mostrar classificação" << endl;
        cout << "0. Sair " << endl;
        cout << "==========================" << endl << endl;
        cin >> op;

        if(op == 1){
            cout << "Digite seu nome: ";
            string novo_apostador;
            cin >> novo_apostador;
            apostadores.push_back(Apostador(novo_apostador));
            apostadores.back().registrar_aposta(jogos);
        }else if(op == 2){
            mostrar_classificacao(apostadores);
        }else if (op == 0){
            cout << "Saindo..." << endl;
            break;
        }else {
            cout << "Opção inválida. Por favor escolha 1, 2 ou 0 conforme o menu." << endl;
        }

    } while(op != 0);
}

int main() {

    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #else
    setlocale(LC_ALL, "pt_BR.UTF-8");
    #endif
    
    //setlocale(LC_ALL, "portuguese");
    vector<Apostador> apostadores;
    vector<Jogo> jogos;

    int usar_padrao;
    cout << "Você deseja registrar os times e placares para os 4 jogos ou usar os placares e times padrões?" << endl;
    cout << "Digite 0 - Para registrar os times e placares;" << endl;
    cout << "Digite 1 - Para usar os times e placares padroes;" << endl;
    cin >> usar_padrao;
    
    if(!usar_padrao){
        string time1;
        string time2;
        int gols1, gols2;

        for (int i = 0; i < 4; i++) {
            cout << "\n\nJogo " << i + 1 << ":" << endl; 
            cout << "Informe o nome do primeiro time: " << endl;
            cin >> time1;
            cout << "Informe o nome do segundo time: " << endl;
            cin >> time2;
            cout << "Informe o número de gols do primeiro time: " << endl;
            cin >> gols1;
            cout << "Informe o número de gols do segundo time: " << endl;
            cin >> gols2;
            
            
            jogos.push_back(Jogo(time1, time2, gols1, gols2));
        }
    }else {
        jogos.push_back(Jogo("BRA", "EGT", 3, 0));
        jogos.push_back(Jogo("RSA", "MAR", 1, 1));
        jogos.push_back(Jogo("FRA", "ARG", 1, 2));
        jogos.push_back(Jogo("GER", "COS", 4, 2));
    }

    menu(apostadores, jogos, 4);

    return 0;
}