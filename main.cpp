#include "player.h"
#include <iostream>
#include "SelectName.h"

using namespace std;

string nom = AskName();

int main() {
    Player player1(nom);
    cout << "Bonjour, " << player1.getNom() << "!" << endl;
    system("pause");
    Player player2(nom);
    cout << "Bonjour, " << player2.getNom() << "!" << endl;
    system("pause");
    return 0;

    
}