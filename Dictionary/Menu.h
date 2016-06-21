#ifndef MENU_H
#define MENU_H

#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <vector>

using namespace std;

class Menu {
private:
	const int NUM_LANGS = 4;
	const int NUM_PARTS = 7;
	const string arrLang[4] = { "German", "French", "Latin", "Hebrew" };
	const string arrSpeech[7] = { "Noun", "Verb", "Preposition", "Cardinal Number", "Adverb", "Adjective", "All" };

public:
int printPrelimMenu();
int printDictMenu();
int printLangMenu();
int printPartsMenuToOther(int);
int printPartsMenuToEng(int);
int getIntInRange(int, int);
};


#endif