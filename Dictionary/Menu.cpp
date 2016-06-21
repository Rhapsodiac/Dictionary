#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <vector>
#include "Menu.h"


using namespace std;

int Menu::printPrelimMenu() {
	int num;
	cout << "1. Add Words.\n2. Quit\n";
	return (num = getIntInRange(1, 2));
}

int Menu::printDictMenu() {
	int num;
	cout << "1. Add Words.\n2. Other to English.\n3. English to Other.\n4. Search for a word.\n5. Quit\n";
	return (num = getIntInRange(1, 5));
}

int Menu::printLangMenu() {
	int count;
	int num;

	for (count = 0; count < NUM_LANGS; count++) {
		cout << "\n" << count + 1 << ". " << arrLang[count];
	}
	cout << "\n";
	return (num = getIntInRange(1, 7));
}

int Menu::printPartsMenuToOther(int langIndex) {
	int count;
	int num;

	for (count = 0; count < NUM_PARTS; count++) {
		cout << "\n " << count + 1 << ". " << " English to " << arrLang[langIndex] << " " << arrSpeech[count];
	}
	cout << "\n\n";
	return (num = getIntInRange(1, 7));

}
int Menu::printPartsMenuToEng(int langIndex) {
	int count;
	int num;

	for (count = 0; count < NUM_PARTS; count++) {
		cout << "\n " << count + 1 << ". " << arrLang[langIndex] << " to English " << arrSpeech[count];
	}
	cout << "\n\n";
	return (num = getIntInRange(1, 7));

}
int Menu::getIntInRange(int low, int high) {
	int num = (int)(_getch() - 48);
	while (num < low || num > high) {
		cout << "\n" << num << " is an Invalid Entry.\nTry again.\n";
		num = _getch() - 48;
	}
	return num;
}
