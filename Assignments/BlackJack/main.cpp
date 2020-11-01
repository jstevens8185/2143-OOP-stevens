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
    int value;

    /**
 * Set Suit.
 * -suit is based on the cards value (0-51)
 * -if value is 0-12 its spades
 * -if "" is 13-25 its clubs
 * ""        26-38 its diamonds
 * else its hearts
**/ 
    void setSuit(){
      if(value>=0 && value<13){
        suit = "Spades";
      }
      else if(value >= 13 && value < 26){
        suit = "Clubs";
      }
      else if(value >= 26 && value < 39){
        suit = "Diamonds";
      }
      else{
        suit = "Hearts";
      }
    }

/**
 * setStringValue
 * sets string value based on int value
**/ 
    void setStringValue(){
      if (value > 1 && value < 11){
        stringValue = to_string(value);
      }
      else if(value == 1){
        stringValue = "Ace";
      }
      else if(value == 11){
        stringValue = "Jack";
      }
      else if(value == 12){
        stringValue = "Queen";
      }
      else if(value == 13){
        stringValue = "King";
      }
      else{
        stringValue = "-1";
      }
    }

  protected:
  /////////////////////////
  //0-12: spades
  //13-25: clubs
  //26-38: diamonds
  //39-51: hearts
  /////////////////////////
    
    string suit;
    string stringValue;
  public:
//Constructors
    Card()
    {
      if(TOTALCARDSCREATED >= 10000){
          cout << "error occured. restart game.";
          return;
      }
      suit = " ";
      stringValue = " ";
      value = -1;
      //cout << "made a card\n";
      TOTALCARDSCREATED++;
    }
/**
 * Make a new card. Pass in a number that represents value (ace 2 3...jack..)
 * -set the value equal to passed in val
 * -set suit based on value. (0-12 is spades. 13-whatever is...)
 * -mod value to get them in sets of 13
 * -set stringValue based on value set in last step
**/

    Card(int val)
    {
/**
 * Stop cards from being made after an absurdly high value in case it 
 * gets into a card making loop
**/
      if(TOTALCARDSCREATED >= 10000){
          cout << "card limit reached. restart game.";
      }
      else{
        value = val;
        setSuit();
        value = value % 13 + 1;
        setStringValue();
        TOTALCARDSCREATED++;
      }
    }
    
    Card(int suit, int value)
    {
      if(TOTALCARDSCREATED >= 10000){
          cout << "error occured. restart game.";
          return;
      }
      TOTALCARDSCREATED++;

    }
    

    string getSuit(){
      return suit;
    }

    string getRank(){
      return stringValue;
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

//doubly linked list of cards to make up deck
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
    Deck()
    {
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

    void printDeck()
    {
      Card* temp = deckBottom;

      while(temp){
        cout << temp->getSuit() << endl;
        cout << temp->getRank() << endl << endl;
        temp = temp->next;
        
      }
    }

    Deck shuffle(){
  //split list in half, randomly place 2 or 3 cards at a time to simulate a real shuffle. repeat 4-7 times to ensure its random
       Card* tempTop = NULL;
       Card* tempMiddle = NULL;
       Card* tempBottom = NULL;
       Card* Current = NULL;
       


  //Split the list by unlinking "middle" and the card before it
      deckMiddle->next->prev = NULL;
      deckMiddle->next = NULL;
  //Deck now is in two parts. Like when you cut it in half
    tempBottom = deckMiddle = Current;
    deckMiddle = deckMiddle->prev;
    tempBottom->prev = NULL;
    Current->next = deckTop;
    deckTop = deckTop->prev;
    Current->next->prev = Current;
    Current = Current->next;
    
    
    }

    Deck resetDeck(){
      
    }

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