#pragma once
#include "card.hpp"

/// @brief Deck represents a deck of playing cards.
struct Deck
{
    // Array of cards
    Card *deck;
    int size;

    /// @brief Shuffles the cards in the deck
    void shuffle()
    {
        // activates the generator
        srand((unsigned int)time(NULL));

        for (int i = size - 1; i > 0; i--)
        {
            int rand = random() % (i + 1);
            Card temp = deck[i];
            deck[i] = deck[rand];
            deck[rand] = temp;
        }
    }

    /// @brief Simulates dealing a card
    /// @return Dealt card
    Card dealCard()
    {
        return deck[random() % 10];
    }

    /// @brief Test whether the deck contains Jokers.
    /// @return true/false
    bool hasJokers()
    {
        return (size == 54);
    }

    /// @brief Constructor to initialize the deck
    /// @param noJokers - marker of whether the deck has jokers
    Deck(bool noJokers)
    {
        if (noJokers)
        {
            deck = new Card[54];
            size = 54;
        }
        else
        {
            deck = new Card[52];
            size = 52;
        }

        int cardCt = 0; // How many cards have been created so far.
        for (int suit = 0; suit <= 3; suit++)
        {
            for (int value = 1; value <= 13; value++)
            {
                deck[cardCt] = Card(value, suit);
                cardCt++;
            }
        }
        if (noJokers)
        {
            deck[52] = Card(1, Card::JOKER);
            deck[53] = Card(2, Card::JOKER);
        }
    }
};