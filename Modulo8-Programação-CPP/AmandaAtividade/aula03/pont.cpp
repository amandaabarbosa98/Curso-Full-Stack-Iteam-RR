#include <iostream>

void trocar(int *a, int *b) {
    int temp = *a; 
    *a = *b;      
    *b = temp;     
}

int main() {
    int x = 10;
    int y = 20;

    std::cout << "Antes: x = " << x << ", y = " << y << "\n";

    
    trocar(&x, &y);

    std::cout << "Depois: x = " << x << ", y = " << y << "\n";

    return 0;
}