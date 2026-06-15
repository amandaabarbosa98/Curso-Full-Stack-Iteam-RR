#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string times[8] = {"BRA", "EGT", "RSA", "MAR", "FRA", "ARG", "GER", "COS"};
int placares[4][2] = {3, 0, 1, 1, 1, 2, 4, 2};

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
    if(valor > 0){
        return 1;
    }else{
        return 0;
    }


}

int nova_aposta(int num_jogo){
    int aposta[2];
    int pontos = 0;
    
    for (int i = 0; i < num_jogo; i++){
        cout << i + 1 <<"º Jogo: " << times[i * 2] << " X " << times[i * 2 + 1] << endl;
        cout << "Digite o placar para o time " << times[i * 2] << ":" << endl;
        cin >> aposta[0];
        while(!validar_valor(aposta[0])){
            cout << "Informe um valor positivo para o número de gols." << endl;
            cin >> aposta[0];
        }
        
        cout << "Digite o placar para o time " << times[i * 2 + 1] << ":" <<endl;
        cin >> aposta[1];
        while(!validar_valor(aposta[1])){
            cout << "Informe um valor positivo para o número de gols." << endl;
            cin >> aposta[1];
        }

        pontos += comparar_resultado(placares[i][0], placares[i][1], aposta[0], aposta[1]);
    }
    return pontos;
}

void mostrar_classificacao(vector<string> &apostadores, vector<int> &pontuacoes){
    cout << "\n\n========== Ranking SportBet ==========" << endl;
    vector<pair<int, string>> ranking;
    
    for (size_t i = 0; i < apostadores.size(); ++i) {
        ranking.push_back({pontuacoes[i], apostadores[i]});
    }
    sort(ranking.begin(), ranking.end(), greater<pair<int, string>>());

    for (size_t i = 0; i < ranking.size(); ++i) {
        cout << (i + 1) << "º Lugar: " 
             << ranking[i].second << " - " 
             << ranking[i].first << " pontos" << endl;
    }
    cout << "======================================" << endl;
}

void menu(vector<string> &apostadores, vector<int> &pontuacoes, int qtde_jogos){
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
            apostadores.push_back(novo_apostador);
            pontuacoes.push_back(nova_aposta(qtde_jogos));
        }else if(op == 2){
            mostrar_classificacao(apostadores,pontuacoes);
        }else if (op == 0){
            cout << "Saindo..." << endl;
            break;
        }else {
            cout << "Opção inválida. Por favor escolha 1, 2 ou 0 conforme o menu." << endl;
        }

    } while(op != 0);
}

int main() {
    vector<string> apostadores;
    vector<int> pontuacoes;
    

    menu(apostadores, pontuacoes, 4);

    return 0;
}