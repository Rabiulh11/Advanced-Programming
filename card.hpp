#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/**
 * @brief An object of type Card represents a playing card from a
 * standard Poker deck, including Jokers.  The card has a suit, which
 * can be spades, hearts, diamonds, clubs, or joker.  A spade, heart,
 * diamond, or club has one of the 13 values: ace, 2, 3, 4, 5, 6, 7,
 * 8, 9, 10, jack, queen, or king.  Note that "ace" is considered to be
 * the smallest value.  A joker can also have an associated value;
 * this value can be anything and can be used to keep track of several
 * different jokers.
 *
 */
struct Card
{
    private:
    /**
     * This card's suit, one of the constants SPADES, HEARTS, DIAMONDS,
     * CLUBS, or JOKER.  The suit cannot be changed after the card is
     * constructed.
     */
    int suit;

    /**
     * The card's value.  For a normal card, this is one of the values
     * 1 through 13, with 1 representing ACE.  For a JOKER, the value
     * can be anything.  The value cannot be changed after the card
     * is constructed.
     */
    int value;

public:
    static const int SPADES = 0; // Codes for the 4 suits, plus Joker.
    static const int HEARTS = 1;
    static const int DIAMONDS = 2;
    static const int CLUBS = 3;
    static const int JOKER = 4;
    static const int ACE = 1;    // Codes for the non-numeric cards.
    static const int JACK = 11;  //   Cards 2 through 10 have their
    static const int QUEEN = 12; //   numerical values for their codes.
    static const int KING = 13;
    /**
     * @brief Get the Suit As String object.
     * Returns a String representation of the card's suit.
     *
     * @return string which is one of the numbers 1 through 13, inclusive for
     * a regular card, and which can be any value for a Joker.
     */
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
    /**
     * @brief Get the Value As String object. A representation of the card's value.
     *
     * @return string  regular card, one of the strings "Ace", "2",
     * "3", ..., "10", "Jack", "Queen", or "King".  For a Joker, the
     * string is always numerical.
     */
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
    /**
     * @brief Returns a string representation of this card, including both
     * its suit and its value (except that for a Joker with value 1,
     * the return value is just "Joker").  Sample return values
     * are: "Queen of Hearts", "10 of Diamonds", "Ace of Spades",
     * "Joker", "Joker #2"
     *
     * @return string string representation of this card
     */
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
    /**
     * @brief Construct a new Card object. Creates a card with a specified suit and value.
     * @param val the value of the new card.  For a regular card (non-joker),
     * the value must be in the range 1 through 13, with 1 representing an Ace.
     * You can use the constants Card.ACE, Card.JACK, Card.QUEEN, and Card.KING.
     * For a Joker, the value can be anything.
     * @param sut  the suit of the new card.  This must be one of the values
     * Card.SPADES, Card.HEARTS, Card.DIAMONDS, Card.CLUBS, or Card.JOKER.
     */
    Card(int val, int sut)
    {
        if (sut != this->SPADES && sut != this->HEARTS && sut != this->DIAMONDS && sut != this->CLUBS && sut != this->JOKER)
        {
            cout << "Illegal playing card suit" << endl;
            return;
        }
        if (sut != this->JOKER && (val < 1 || val > 13))
        {
            cout << "Illegal playing card value" << endl;
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
