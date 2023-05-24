#include <stdio.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 
#include <stdbool.h>
#include <time.h> 
#include "API.h"

card** deckBuilder (){
    card **deckFinal = (card **) malloc ((sizeof (card *)) * DECK);
    for (int i = 0; i < DECK; i++){
        deckFinal[i] = NULL; 
    }
    card **tmp[4]; 
    char suits[SUIT_NUM][SIZE_SUIT_CHAR] = {"♣", "♤", "♥", "♦"};
    char *symbol[DISTINCT] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}; 
    int i, j; 
    for (i = 0; i < SUIT_NUM; i++){
        tmp[i] = helper(suits[i]); //return a double array with cards in a certain suit 
        for (j = 0; j < DISTINCT; j++){ //adds symbol and val to each card in the suit being worked with 
            tmp[i][j]->val = j + 1; 
            strcpy (tmp[i][j]->symbol, symbol[j]); 
            addToDeck (deckFinal, tmp[i][j]); //tmp[i][j] is malloced
        }
        free (tmp[i]); //freeing current double array (not the cards within them because these pointers are added to deckFinal)
    }
    return deckFinal; 
}

void addToDeck (card **deck, card *toAdd){
    int i = 0; 
    while (deck[i] != NULL){
        i++; 
    }
    deck[i] = toAdd; 
}



//doesn't account for an existing hand fully 
//-> would have to decide what card to discard and save that somewhere to be freed 
void draw (card **deck, card **hand, int num){ //assume deck/hand passed in is fully initialized (i.e. NULL or Val)
    int randomNumber, i, j; 
    srand (time(0)); 

    for (i = 0; i < num; i++){
        randomNumber = rand() % 52; 
        
        for (j = 0; j < HAND_SIZE; j++){ //checks for duplicate
            if (hand[j] == deck[randomNumber]){
                printf ("duplicate found!\n"); 
                j = -1; 
                break; 
            }
        }
        if (j != -1){ //if no duplicate, add card to hand and remove from deck
            hand[i] = deck[randomNumber]; 
            deck[randomNumber] = NULL; 
            printCard (hand[i]); 
        }
    }
}

void printCard (card *toPrint){
    printf ("[%s|%s]\n", toPrint->symbol, toPrint->suit);
}

card** helper (char *suit){
    card ** suitList = (card **) malloc ((sizeof (card *)) * DISTINCT);
    for (int i = 0; i < DISTINCT; i++){ //copies all 13 cards for current suit 
        card *temp = (card *) malloc (sizeof (card)); 
        strcpy (temp->suit, suit);
        suitList[i] = temp; 
    }
    return suitList;
}

void freeDeck (card **toFree, card **handtoFree){
    for (int i = 0; i < DECK; i++){//check for null? 
        if (toFree[i] != NULL){
            free(toFree[i]); 
        }
    }
    for (int i = 0; i < 7; i++){
        if (handtoFree[i] != NULL){
            free (handtoFree[i]); 
        }
    }
    free (toFree); 
    free (handtoFree); //malloc in main 
}