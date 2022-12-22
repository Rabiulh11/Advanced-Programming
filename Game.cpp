#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
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
    static const int SPADES = 0; // Codes for the 4 suits, plus Joker.
    static const int HEARTS = 1;
    static const int DIAMONDS = 2;
    static const int CLUBS = 3;
    static const int JOKER = 4;
    static const int ACE = 1; // Codes for the non-numeric cards.
    static const int JACK = 11; //   Cards 2 through 10 have their
    static const int QUEEN = 12; //   numerical values for their codes.
    static const int KING = 13;

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
    }

};

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
            int r = rand() %(i+1);
            Card temp = deck[i];
            deck[i] = deck[r];
            deck[r] = temp;
        }
        cardsUsed = 0;
    }

    Card dealCard()
    {
        // NOTE:  Cards are not literally removed from the array
        // that represents the deck. We keep track of how many cards
        // have been used.
        if (cardsUsed == size)
        {
            cout << ("No cards are left in the deck.") << endl;
            return Card();
        }
        cardsUsed++;
        return deck[cardsUsed - 1];
        
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
    Deck( bool noJokers)
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

int play(bool hasjoker)
{
    // Get a new deck of cards, and
    //   store a reference to it in
    //   the variable, deck.
    Deck deck(hasjoker);

    // The current card, which the user sees.
    Card currentCard;
    // The next card in the deck.  The user tries
    //    to predict whether this is higher or lower
    //    than the current card.
    Card nextCard;
    // The number of correct predictions the
    //   user has made.  At the end of the game,
    //   this will be the user's score.
    int correctGuesses;
    // The user's guess.  'H' if the user predicts that
    //   the next card will be higher, 'L' if the user
    //   predicts that it will be lower.
    char guess;
    // Shuffle the deck into a random order before
    //    starting the game.
    deck.shuffle(); 

    correctGuesses = 0;
    currentCard = deck.dealCard();
    cout << "The first card is the " << currentCard.toString() << endl;

    while (true)
    { 
        // Loop ends when user's prediction is wrong.

        /* Get the user's prediction, 'H' or 'L' (or 'h' or 'l'). */

       cout << "Will the next card be higher (H) or lower (L)?: ";;
        do
        {
            cin >> guess;
            guess = toupper(guess);
            if (guess != 'H' && guess != 'L')
                cout << "Please respond with H or L: ";
        } while (guess != 'H' && guess != 'L');

        /* Get the next card and show it to the user. */

        nextCard = deck.dealCard();
        cout << "\nThe next card is " + nextCard.toString() << endl;

        /* Check the user's prediction. */

        if (nextCard.value == currentCard.value)
        {
            cout << "The value is the same as the previous card." << endl;
            cout << "You lose on ties.  Sorry!" << endl;
            break; // End the game.
        }
        else if (nextCard.value > currentCard.value)
        {
            if (guess == 'H')
            {
                cout << "Your prediction was correct." << endl;
                correctGuesses++;
            }
            else
            {
                cout << "Your prediction was incorrect." << endl;
                break; // End the game.
            }
        }
        else
        { // nextCard is lower
            if (guess == 'L')
            {
                cout << "Your prediction was correct." << endl;
                correctGuesses++;
            }
            else
            {
                cout << "Your prediction was incorrect." << endl;
                break; // End the game.
            }
        }

        /* To set up for the next iteration of the loop, the nextCard
           becomes the currentCard, since the currentCard has to be
           the card that the user sees, and the nextCard will be
           set to the next card in the deck after the user makes
           his prediction.  */

        currentCard = nextCard;
        cout << endl
             << "The card is " + currentCard.toString() << endl;

    } // end of while loop

    cout << endl <<"The game is over." << endl;
    cout << "You made "<< correctGuesses << " correct predictions." << endl;
    cout << endl;

    return correctGuesses;
}


/// @brief MAIN METHOD
/// @param argc 
/// @param argv 
/// @return 
int main(int argc, char const *argv[])
{
    cout << "Welcome to a simple Card Game Dabbed [High ~ Low]."
         << "A card is dealt from a deck of cards.\nYou have to predict"
         << "whether the next card will be higher or lower.\nYour score in the game is the "
         << "number of correct predictions you make before you guess wrong."
         << "\n\nYour Turn is now!\n"
         << endl;
    // Number of games user has played.
    int gamesPlayed = 0;
    // The sum of all the scores from
    //      all the games played.
    int sumOfScores = 0;
    // Average score, computed by dividing
    //      sumOfScores by gamesPlayed.
    double averageScore;
    // Record user's response when user is
    //   asked whether he wants to play
    //   another game.
    char playAgain;           

    do
    { 
        // Score for one game.
        int scoreThisGame;
        // Play the game and get the score.
        scoreThisGame = play(false); 
        sumOfScores += scoreThisGame;
        gamesPlayed++;
        
        cout<<"Play again(Y/N)? ";
        cin >> playAgain;
        playAgain = toupper(playAgain);

    } while (playAgain != 'N');

      averageScore = ((double)sumOfScores) / gamesPlayed;

      cout << endl
           << "You played " << gamesPlayed << " games." << endl;
      printf("Your average score was %1.4f\n", averageScore);

      return 0;
}
