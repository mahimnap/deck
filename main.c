#include <stdio.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 
#include <stdbool.h>
#include <time.h> 

#include "API.h"

int main (int argc, char *argv[]){
    card **myDeck; 
    card **myHand = (card **) malloc ((sizeof(card*)) * 7);
    myDeck = deckBuilder(); 
    int i;

    for (i = 0; i < 7; i++) {
        myHand[i] = NULL; //initialize hand add to player function later 
    }

    printf ("Full Deck:\n"); 
    for (i = 0; i < DECK; i++){
        printCard (myDeck[i]); 
    }

    printf ("Random 7 Card Deck:\n");
    draw (myDeck, myHand, 7);

    freeDeck (myDeck, myHand); 
    return 0; 
}