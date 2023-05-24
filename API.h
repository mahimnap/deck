#ifndef _CW_API_
#define _CW_API_

#define DECK 52
#define DISTINCT 13
#define SUIT_NUM 4 
#define SIZE_SUIT_CHAR 4 
#define HAND_SIZE 7
typedef struct card {
    char symbol[3]; 
    char suit[4]; 
    int val; 
}card; 

card ** deckBuilder (); 
card** helper (char *suit);
void addToDeck (card **deck, card *toAdd); 
void printCard (card *toPrint); 
void freeDeck (card **toFree, card **handtoFree); 
void draw (card **deck, card **hand, int num);


#endif 

//♣
//♤
//♥
//♦