#pragma once
#include<string>
using std::string;

class Player
{
private:
    int wins;
    int loses;
    string name;
public:
    Player();
    Player(string name);
    ~Player();
    int getWins();
    int getLoses();
    string getName();
    void setName(string name);
    void setWins(int wins);
    void setLoses(int loses);
};

inline Player::Player()
{
}
inline Player::Player(string name)
{
    this->name = name;
}

inline Player::~Player()
{
}

inline int Player::getWins()
{
    return wins;
}

inline int Player::getLoses()
{
    return loses;
}

inline string Player::getName()
{
    return name;
}

inline void Player::setName(string name)
{
    this->name = name;
}

inline void Player::setWins(int wins)
{
    this->wins = wins;
}
inline void Player::setLoses(int loses)
{
    this->loses = loses;
}