#include <iostream>
#include <string>
#include <vector>

using namespace std;



//If this goes above 10000 it stops the game
int TOTALCARDSCREATED = 0;


////////////////////////
//Game Class
//
//Creates the game, holds the rules, ya know, the thing.
////////////////////////


class Dealer{
    private:
        //Hand dealerHand;
    public:
};

class Player{
    private:
        //Hand playerHand;
        string playerName;
        int bank;
    public:
        Player(){
            //playerHand = ?
            playerName = "Player 1";
            bank = 10000;
        }
        Player(string name){
            //playerHand = ?
            playerName = name;
            bank = 10000;
        }
        Player(int startingAmount){
            //playerHand = ?
            playerName = "Player 1";
            bank = startingAmount;
        }
        Player(int startingAmount, string name){
            //playerHand = ?
            playerName = name;
            bank = startingAmount;
        }
};

// Class: Card
// makes up deck
class Card{
  private:
    Card* next;
    Card* prev;
  protected:
  /////////////////////////
  //0-12: spades
  //13-25: clubs
  //26-38: diamonds
  //39-51: hearts
  /////////////////////////
    
    string suit;
    int value;
  public:
//Constructors
    Card(){
      if(TOTALCARDSCREATED >= 10000){
          cout << "error occured. restart game.";
          return;
      }
      suit = " ";
      value = -1;
      //cout << "made a card\n";
      TOTALCARDSCREATED++;
    }
    Card(int val){
      if(TOTALCARDSCREATED >= 10000){
          cout << "card limit reached. restart game.";
      }
      else{
        value = val;
        setSuit();
        value = value % 13 + 1;
        TOTALCARDSCREATED++;
      }
    }
    Card(int suit, int value){
      if(TOTALCARDSCREATED >= 10000){
          cout << "error occured. restart game.";
          return;
      }
      TOTALCARDSCREATED++;

    }
    void setSuit(){
      if(value>=0 && value<13){
        suit = "spades";
      }
      else if(value >= 13 && value < 26){
        suit = "clubs";
      }
      else if(value >= 26 && value < 39){
        suit = "diamonds";
      }
      else{
        suit = "hearts";
      }
    }

    friend class Deck;

};

class CardContainer{
    //add a card
    //remove a card
    //get count of cards
};

class Hand : public CardContainer{
    //total of hand (over 21?)
    //view hand
    private:
      int total;
    protected:
      vector < Card* > hand;
    public:
      Hand(){
        
      }
      int getTotal(){
        return total;
      }
};

//Linked list of cards to make up deck
class Deck : public CardContainer{
  private: 
    Card* current;
  protected:
    Card* deckTop;
    Card* deckBottom;
    Card* deckMiddle;

  public:
///////////////////////////  
//Deck Constructor
//
//Adds 52 unique nodes (cards) to the 
//deck in a linked list fashion
    Deck(){
      for(int i=0; i<52; i++){
        if(!deckBottom){
          deckBottom = new Card(i);
          current = deckBottom;
          current->next = NULL;
          current->prev = NULL;
        }
        else if(i == 25){
            current->next = new Card(i);
            current->next->prev = current;
            current = current->next;
            deckMiddle = current;
            current->next = NULL;
            
        }
        else if(i == 51){
            current->next = new Card(i);
            current->next->prev = current;
            current = current->next;
            deckTop = current;
            current->next = NULL;       
        }
        else{
            current->next = new Card(i);
            current->next->prev = current;
            current = current->next;
            current->next = NULL;
        }
        //cout << "card "<< i+1 << " created"<< endl;
      }
    }

    void printDeck(){
      Card* temp = deckBottom;

      while(temp){
        cout << temp->suit << endl;
        cout << temp->value << endl << endl;
        temp = temp->next;
        
      }
    }
/*
    Deck shuffle(){
  //split list in half, create new deck and alternate inserting cards into new deck, randomly place 2 or 3 cards at a time to simulate a real shuffle. repeat 4-7 times to ensure its random
    }

    Deck resetDeck(){
      
    }
*/
};

class BlackJack{
    private:
        Player* player;
        Dealer* dealer;
        Deck* deck;
    public:
        BlackJack(){
            deck = new Deck();
            player = new Player();
            dealer = new Dealer();

            deck->printDeck();
        } 
};

int main() {
    //Create game
    BlackJack mainGame;



    //cout << TOTALCARDSCREATED;

}