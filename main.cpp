#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
int play(Deck *deck)
{
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
    // deck->shuffle(); 

    correctGuesses = 0;
    currentCard = deck->dealCard();
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

        nextCard = deck->dealCard();
        cout << "\nThe next card is " + nextCard.toString() << endl;

        if (nextCard.getValue() == currentCard.getValue())
        {
            cout << "The value is the same as the previous card." << endl;
            cout << "You lose on ties.  Sorry!" << endl;
            break; // End the game.
        }
        else if (nextCard.getValue() > currentCard.getValue())
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
    // Get a new deck of cards, and
    //   store a reference to it in
    //   the variable, deck.
    Deck *deck = new Deck(false);

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
    int scoreThisGame;
    int i;
    int numPLayers = 1;
    cout << "Enter the number of players: ";
    cin >> numPLayers;

    Player *players;
    
    //initialize number of players
    players = new Player[numPLayers];
    string name;
    for (i = 0; i < numPLayers; i++)
    {
        cout << "Enter the player [" << i + 1 << "] name: ";
        cin>> name;
        players[i] = Player(name);
    }
    

    do
    {

        // each player turn to play
        for (i = 0; i < numPLayers; i++)
        {
            cout << "\nPlayer: " << players[i].getName() << " is playing." << endl;
            // Play the game and get the score.
            scoreThisGame = play(deck);
            sumOfScores += scoreThisGame;
            players[i].setWins(sumOfScores);
        }
        gamesPlayed++;

        cout<<"Play again(Y/N)? ";
        cin >> playAgain;
        playAgain = toupper(playAgain);

    } while (playAgain != 'N');

    cout << endl
         << "Games played: " << gamesPlayed << endl;
    cout << "..............\nResults\n..................\n " << endl;

    printf("Your average score was %1.4f\n", averageScore);
    for (i = 0; i < numPLayers; i++)
    {
        averageScore = ((double)players[i].getWins()) / gamesPlayed;

        cout << "Player: " << players[i].getName() << endl
             << "Average score : " << averageScore << endl;
        cout << "......" << endl;
    }

    delete deck;
    delete players;

    return 0;
}
