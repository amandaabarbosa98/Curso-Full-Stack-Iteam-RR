#include <iostream>

using namespace std;
int fatorial(int y1){
    if (y1 = 0){
        return 0;
    }
    if (y1 !=1){
        return y1*fatorial(y1 - 1);
    }else{
        return 1;
    }
    
}
int main(){
    int x;
    cout << "Digite um numero para fazer o fatorial: ";
    cin >> x;
    int resultado = fatorial(x);
    if(resultado = 0){
        cout << "Não existe fatorial de 0" << endl;
    }else{
        cout << "O fatorial de " << x << " = " << resultado << endl;
    }
    
    return 0;
}