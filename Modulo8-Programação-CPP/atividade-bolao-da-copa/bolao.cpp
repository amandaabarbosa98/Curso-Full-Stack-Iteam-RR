#include <iostream>
#include <string>

using namespace std;

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

int main(){
    string apostador1;
    string apostador2;
    string apostador3;
    int pontuacao1 = 0;
    int pontuacao2 = 0;
    int pontuacao3 = 0;
    char time1[4] = "BRA";
    char time2[4] = "EGT";
    char time3[4] = "RSA";
    char time4[4] = "MAR";
    char time5[4] = "FRA";
    char time6[4] = "ARG";
    char time7[4] = "GER";
    char time8[4] = "COS";
    int placar1 = 3;
    int placar2 = 0;
    int placar3 = 1;
    int placar4 = 1;
    int placar5 = 1;
    int placar6 = 2;
    int placar7 = 4;
    int placar8 = 2;

    int aposta1, aposta2;

    for (int i = 0; i < 3 ; i++){
        cout << "Digite seu nome: ";
        if (i == 0) {
            cin >> apostador1;
        }else if (i == 1){
            cin >> apostador2;
        }else {
            cin >> apostador3;
        }

        
        int opcao = 1;
        while (opcao != 0){
            cout << "========MENU========" << endl;
            cout << "0. Sair " << endl;
            cout << "1. Apostar " << endl;
            cout << "2. Mostrar classificação" << endl;
            cin >> opcao;
        
            if (opcao == 1){
                cout << "1º Jogo: " << time1 << " X " << time2 << endl;
                cout << "Digite o placar para o time " << time1 << endl;
                cin >> aposta1;
                cout << "Digite o placar para o time " << time2 << endl;
                cin >> aposta2;
                
                if (i == 0) {
                    pontuacao1 += comparar_resultado(placar1, placar2, aposta1, aposta2);
                }else if (i == 1){
                    pontuacao2 += comparar_resultado(placar1, placar2, aposta1, aposta2);
                }else {
                    pontuacao3 += comparar_resultado(placar1, placar2, aposta1, aposta2);
                }


                cout << "2º Jogo: " << time3 << " X " << time4 << endl;
                cout << "Digite o placar para o time " << time3 << endl;
                cin >> aposta1;
                cout << "Digite o placar para o time " << time4 << endl;
                cin >> aposta2;
                if (i == 0) {
                    pontuacao1 += comparar_resultado(placar3, placar4, aposta1, aposta2);
                }else if (i == 1){
                    pontuacao2 += comparar_resultado(placar3, placar4, aposta1, aposta2);
                }else {
                    pontuacao3 += comparar_resultado(placar3, placar4, aposta1, aposta2);
                }


                cout << "3º Jogo: " << time5 << " X " << time6 << endl;
                cout << "Digite o placar para o time " << time5 << endl;
                cin >> aposta1;
                cout << "Digite o placar para o time " << time6 << endl;
                cin >> aposta2;
                if (i == 0) {
                    pontuacao1 += comparar_resultado(placar5, placar6, aposta1, aposta2);
                }else if (i == 1){
                    pontuacao2 += comparar_resultado(placar5, placar6, aposta1, aposta2);
                }else {
                    pontuacao3 += comparar_resultado(placar5, placar6, aposta1, aposta2);
                }

                cout << "4º Jogo: " << time7 << " X " << time8 << endl;
                cout << "Digite o placar para o time " << time7 << endl;
                cin >> aposta1;
                cout << "Digite o placar para o time " << time8 << endl;
                cin >> aposta2;
                if (i == 0) {
                    pontuacao1 += comparar_resultado(placar7, placar8, aposta1, aposta2);
                }else if (i == 1){
                    pontuacao2 += comparar_resultado(placar7, placar8, aposta1, aposta2);
                }else {
                    pontuacao3 += comparar_resultado(placar7, placar8, aposta1, aposta2);
                }
            }else if (opcao == 2){
                cout << "========== Ranking SportBet ==========" << endl;
                if (pontuacao1 >= pontuacao2 && pontuacao1 >= pontuacao3) {
                    cout << "1º " << apostador1 << " - " << pontuacao1 << " pontos" << endl;
                    if(pontuacao2 >= pontuacao3){
                        cout << "2º " << apostador2 << " - " << pontuacao2 << " pontos" << endl;
                        cout << "3º " << apostador3 << " - " << pontuacao3 << " pontos" << endl;
                    }else{
                        cout << "2º " << apostador3 << " - " << pontuacao3 << " pontos" << endl;
                        cout << "3º " << apostador2 << " - " << pontuacao2 << " pontos" << endl;
                    }
                }

                if (pontuacao2 > pontuacao1 && pontuacao2 > pontuacao3) {
                    cout << "1º " << apostador2 << " - " << pontuacao2 << " pontos" << endl;
                    if(pontuacao1 >= pontuacao3){
                        cout << "2º " << apostador1 << " - " << pontuacao1 << " pontos" << endl;
                        cout << "3º " << apostador3 << " - " << pontuacao3 << " pontos" << endl;
                    }else{
                        cout << "2º " << apostador3 << " - " << pontuacao3 << " pontos" << endl;
                        cout << "3º " << apostador1 << " - " << pontuacao1 << " pontos" << endl;
                    }
                }

                if (pontuacao3 > pontuacao1 && pontuacao3 > pontuacao2) {
                    cout << "1º " << apostador3 << " - " << pontuacao3 << " pontos" << endl;
                    if(pontuacao1 >= pontuacao2){
                        cout << "2º " << apostador1 << " - " << pontuacao1 << " pontos" << endl;
                        cout << "3º " << apostador2 << " - " << pontuacao2 << " pontos" << endl;
                    }else{
                        cout << "2º " << apostador2 << " - " << pontuacao2 << " pontos" << endl;
                        cout << "3º " << apostador1 << " - " << pontuacao1 << " pontos" << endl;
                    }
                }
            }else {
                cout << "Saindo..." << endl;
                break;
            }
        }
    }
    return 0;
}