#include <iostream>
using namespace std;

void trocar (int* a, int* b){
    int *temp = a;
    a = b;
    b = temp;

}

int main(){
    int num1 = 0;
    int num2 = 1;

    trocar(&num1, &num2);
    cout << endl;
    return 0;
}