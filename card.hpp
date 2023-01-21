#pragma once
#include <string>

using std::string;

/// @brief An object of type Card represents a playing card from a standard Poker deck
struct Card
{
private:
    int suit;
    int value;

public:
    static const int SPADES = 0;
    static const int HEARTS = 1;
    static const int DIAMONDS = 2;
    static const int CLUBS = 3;
    static const int JOKER = 4;
    static const int ACE = 1;
    static const int JACK = 11;
    static const int QUEEN = 12;
    static const int KING = 13;

    /// @brief Get the Suit As String object.
    /// @return a String representation of the card's suit.
    string getSuitAsString()
    {
        switch (suit)
        {
        case SPADES:
            return "Spades";
        case HEARTS:
            return "Hearts";
        case DIAMONDS:
            return "Diamonds";
        case CLUBS:
            return "Clubs";
        default:
            return "Joker";
        }
    }
    /// @brief  Get the Value As String object.
    /// @return A representation of the card's value.
    string getValueAsString()
    {
        if (this->suit == this->JOKER)
            return "" + value;
        else
        {
            switch (this->value)
            {
            case 1:
                return "Ace";
            case 2:
                return "2";
            case 3:
                return "3";
            case 4:
                return "4";
            case 5:
                return "5";
            case 6:
                return "6";
            case 7:
                return "7";
            case 8:
                return "8";
            case 9:
                return "9";
            case 10:
                return "10";
            case 11:
                return "Jack";
            case 12:
                return "Queen";
            default:
                return "King";
            }
        }
    }

    /// @brief Returns a string representation of this card
    /// @return string
    string toString()
    {
        if (this->suit == this->JOKER)
        {
            if (value == 1)
                return "Joker";
            else
                return "Joker #" + value;
        }
        else
            return this->getValueAsString() + " of " + this->getSuitAsString();
    }

    /// @brief Default constructor
    Card()
    {
        this->suit = JOKER;
        this->value = 1;
    }

    /// @brief Construct a new Card object. Creates a card with a specified suit and value.
    /// @param val card value
    /// @param sut card suit
    Card(int val, int sut)
    {
        if (sut != this->SPADES && sut != this->HEARTS && sut != this->DIAMONDS && sut != this->CLUBS && sut != this->JOKER)
        {
            return;
        }
        if (sut != this->JOKER && (val < 1 || val > 13))
        {
            return;
        }
        this->value = val;
        this->suit = sut;
    }

    int getSuit()
    {
        return this->suit;
    }
    int getValue()
    {
        return this->value;
    }
};
