#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
    private:
        string nom;
        string token;

    public:
        Player();
        Player(string n);
        string getNom() const;  
        void setNom(const string& value);
        void setToken(const string& value);
        string getToken() const;
};

#endif