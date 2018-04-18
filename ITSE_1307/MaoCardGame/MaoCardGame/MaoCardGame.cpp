// MaoCardGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum cardsuite {CLUBS, DIAMONDS, HEARTS, SPADES};

int getFaceValue(int intCard) {
	//Function to get the face value of the card
	return 1 + ((intCard - 1) % 13);
}

int getSuiteValue(int intCard) {
	//Function to geth the suite value of the card
	return (intCard - 1) / 13;
}

string getFaceString(int intCard) {
	//Function to get the face as a string of a card
	int intFace = getFaceValue(intCard);
	string strFace = "";
	switch (intFace) {
		case 1:
			strFace = "Ace";
			break;
		case 11:
			strFace = "Jack";
			break;
		case 12:
			strFace = "Queen";
			break;
		case 13:
			strFace = "King";
			break;
		default:
			strFace += std::to_string(intFace);
	}
	return strFace;
}

string getSuiteString(int intCard) {
	//Returns the suite of the card as a string
	string strSuite = "";
	switch (getSuiteValue(intCard)) {
		case CLUBS:
			strSuite = "Clubs";
			break;
		case DIAMONDS:
			strSuite = "Diamonds";
			break;
		case HEARTS:
			strSuite = "Hearts";
			break;
		default:
			strSuite = "Spades";
			break;
	}
	return strSuite;
}

string getCardString(int intCard) {
	//Returns the full card as a string
	return getFaceString(intCard) + " of " + getSuiteString(intCard);
}

int pickACard() {
	//Lets the user pick a random number
	int intCard = 0;
	do {
		cout << "Please enter a card number between 1 and 52: ";
		cin >> intCard;
	} while (intCard < 1 || intCard > 52);
	return intCard;
}

int getRandomCard() {
	//Generates a random card number
	return rand() % 52 + 1;
}

void printArrayOfCards(int aryDeck[], int intNumberOfCardsInArray = 52) {
	for (int intIndex = 0; intIndex < intNumberOfCardsInArray; intIndex++) {
		cout << getCardString(aryDeck[intIndex]) << endl;
	}
}

void createDeck(int aryDeck[], int intNumberOfDecks = 1) {
	int intDeckIndex = 0;
	for (int intCurrentDeck = 1; intCurrentDeck <= intNumberOfDecks; intCurrentDeck++) {
		for (int intCurrentCard = 1; intCurrentCard <= 52; intCurrentCard++) {
			aryDeck[intDeckIndex] = intCurrentCard;
			//cerr << getCardString(aryDeck[intDeckIndex]) << endl;
			intDeckIndex++;
		}
	}
}

void shuffleDeck(int aryDeck[], int &intDeckLocation, int intNumberOfDecks = 1) {
	int intTempCardStorage = 0;
	int intRandomCardIndex = 0;
	for (int intCardIndex = 0; intCardIndex < intNumberOfDecks * 52; intCardIndex++) {
		intRandomCardIndex = rand() % (intNumberOfDecks * 52);
		intTempCardStorage = aryDeck[intRandomCardIndex];
		aryDeck[intRandomCardIndex] = aryDeck[intCardIndex];
		aryDeck[intCardIndex] = intTempCardStorage;
	}
	intDeckLocation = 0;
}

int getCardFromDeck(int aryDeck[], int &intDeckLocation, int intNumberofDecks = 1) {
	if (intDeckLocation < intNumberofDecks * 52) {
		cerr << "DEBUG: Deck Location = " << intDeckLocation << endl;
		return aryDeck[intDeckLocation++];
	}
	cerr << "ERROR: Invalid deck location." << endl;
	return -1;
}

int main()
{
	srand(time(0)); //Setup the randomness at the beginning of the program
	const int INTNUMBEROFDECKS = 4;
	const int INTPLAYERHANDSIZE = 7;
	int intDeckLocation = 0;
	int aryPlayerHand[2][INTPLAYERHANDSIZE];
	int aryDeck[52 * INTNUMBEROFDECKS];
	createDeck(aryDeck, INTNUMBEROFDECKS);
	shuffleDeck(aryDeck, intDeckLocation, INTNUMBEROFDECKS);
	//cerr << (sizeof(aryDeck) / sizeof(aryDeck[0])) << endl;
	printArrayOfCards(aryDeck, INTNUMBEROFDECKS * 52);
	for (int intHandIndex = 0; intHandIndex < INTPLAYERHANDSIZE; intHandIndex++) {
		aryPlayerHand[0][intHandIndex] = getCardFromDeck(aryDeck, intDeckLocation, INTNUMBEROFDECKS);
		aryPlayerHand[1][intHandIndex] = getCardFromDeck(aryDeck, intDeckLocation, INTNUMBEROFDECKS);
	}
	printArrayOfCards(aryPlayerHand[0], INTPLAYERHANDSIZE);
	printArrayOfCards(aryPlayerHand[1], INTPLAYERHANDSIZE);


	//int intCard = getRandomCard(); //Generates a card
	//cout << getCardString(intCard) << endl; //Displays a card

    return 0;
}

