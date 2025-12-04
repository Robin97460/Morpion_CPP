#include <string>
#include <iostream>
#include "SelectName.h"

using namespace std;

string AskName(){
    string pseudo = "";
    cout << "Entrez votre pseudo: ";
    getline(cin, pseudo);
    return pseudo;
}