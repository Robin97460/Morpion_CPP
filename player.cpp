#include "Player.h"

Player::Player() {}

Player::Player(string n) : nom(n) {}

string Player::getNom() const {
    return nom;
}
void Player::setNom(const string& value) {
    nom = value;
}

void Player::setToken(const string& value) {
    token = value;
}

string Player::getToken() const{
    return token;
}