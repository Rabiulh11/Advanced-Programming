#pragma once
#include "card.hpp"

/**
 * @brief Deck represents a deck of playing cards.  The deck
 *  is a regular poker deck that contains 52 regular cards and that can
 *  also optionally include two Jokers.
 *
 */
struct Deck
{
    /// @brief Array of cards
    Card *deck;
    /**
     * Keeps track of the number of cards that have been dealt from
     * the deck so far.
     */
    int cardsUsed;
    /**
     * Keeps track of the deck size
     */
    int size;
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
        cardsUsed = 0;
    }

    Card dealCard()
    {
        // NOTE:  Cards are not literally removed from the array
        // that represents the deck. We keep track of how many cards
        return deck[random() % 10];
    }

    /**
     * @brief Test whether the deck contains Jokers.
     *
     * @return true
     * @return false
     */
    bool hasJokers()
    {
        return (size == 54);
    }

    /**
     * As cards are dealt from the deck, the number of cards left
     * decreases.  This function returns the number of cards that
     * are still left in the deck.  The return value would be
     * 52 or 54 (depending on whether the deck includes Jokers)
     * when the deck is first created or after the deck has been
     * shuffled.  It decreases by 1 each time the dealCard() method
     * is called.
     */
    int cardsLeft()
    {
        return size - cardsUsed;
    }
    /**
     * Put all the used cards back into the deck (if any), and
     * shuffle the deck into a random order.
     */
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
        cardsUsed = 0;
    }
};