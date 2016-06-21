
#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <fcntl.h>
#include <io.h>
#include "Dictionary.h"
#include "Menu.h"
#include "WordList.h"
#include "Word.h"

using namespace std;

void quit();
int badEntry();

int main(int argc, char** argv) {

	Dictionary myDict;	
	Menu myMenu;
	WordList wordList;
	bool dictHasWords;
	int choice, choice2, choice3, n;

	//load dictionary from file
	myDict.setFileName("dictionary.txt");
	myDict.loadDictionary();
	dictHasWords = myDict.checkDict();

	//ONLY IF TEXT FILE HAS NOT HAD WORDLIST LOADED ONCE
	if (!dictHasWords) {
		myDict.loadWordList();
		myDict.writeDictionary();
		myDict.loadDictionary();
	}

	dictHasWords = myDict.checkDict();

	//preliminary if dictionary has no words
	while(dictHasWords == false){
		system("cls");
		choice = myMenu.printPrelimMenu();
		switch (choice) {
		case 1: 
			choice3 = myMenu.printLangMenu();
			myDict.storeWord(choice3 - 1);
			myDict.writeDictionary();
			break;
		case 2:quit();
			break;
		default: choice = badEntry();
			break;
		}
		dictHasWords = myDict.checkDict();
	}	

	//otherwise if dictionary has at least one word
	while (true) {
		system("cls");
		choice = myMenu.printDictMenu();
		switch (choice) {
		case 1: //add a word
			choice3 = myMenu.printLangMenu();
			myDict.storeWord(choice3-1);
			myDict.writeDictionary();
			break;
		case 2: //other to english
			choice = myMenu.printLangMenu();
			choice2 = myMenu.printPartsMenuToEng(choice-1);
			myDict.printToEnglish(choice-1, choice2-1);
			n = _getch();
			break;
		case 3: //english to other
			choice = myMenu.printLangMenu();
			choice2 = myMenu.printPartsMenuToOther(choice-1);
			myDict.printToOther(choice-1, choice2-1);
			n = _getch();
			break;
		case 4: //search for a word		
			myDict.printWordSearch();
			n = _getch();
			break;
		case 5: //quit
			quit();
		default: choice = badEntry();
			break;
		}
	}
}

void quit() {
	cout << "\nNow quitting\nPress any key...\n";
	_getch();
	exit(0);
}
int badEntry() {
	cout << "\nTry again.";
	return (_getch() - 48);
}
	

