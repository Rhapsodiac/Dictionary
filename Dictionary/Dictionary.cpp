#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <iomanip>
#include <locale>
#include "Dictionary.h"
#include "WordList.h"
#include "Word.h"

using namespace std;


Dictionary::Dictionary() {}

void Dictionary::setFileName(string name) {
	fileName = name;
}
bool Dictionary::loadDictionary() {
	try {
		inFile.open(fileName, ios::in | ios::binary);
		if (inFile.fail())
			throw 1;
	}
	catch (int e) {
		cout << "\nFile Failed to Open. Error: " << e;
		system("pause");
		inFile.clear();
		return false;
	}

	while (!inFile.eof()) {
		Word tempWord;
		inFile.read(reinterpret_cast<char *>(&tempWord), sizeof(Word));
		if (!inFile.eof())
			dict.push_back(tempWord);
	}
	if (dict.empty())
		cout << "Dictionary Loaded and empty!\n";
	else 
		cout << "Dictionary loaded and full!\n";

	cout << "\nPress any key to continue...";
	char c = _getch();
	return true;
}

void Dictionary::writeDictionary() {
	outFile.open(fileName, ios::out | ios::binary);
	Word tempWord;
	for (int count = 0; count < dict.size(); count++) {
		tempWord = (dict)[count];
		outFile.write(reinterpret_cast<char *>(&tempWord), sizeof(Word));
	}
	outFile.close();
}

void Dictionary::storeWord(int langIndex) {
	string language, foreign, english, defArt, type, gender;

	printSpecialChars();
	cout << "\nEnter word without articles: ";
	foreign = getString();
	cout << "\nEnter article, or press enter if there is none: ";
	defArt = getString();
	cout << "\nEnter English meaning: ";
	english = getString();
	cout << endl;
	if (!isDupe(english, arrLang[langIndex])) {
		type = printWordType();
		gender = printWordGender();
		dict.push_back({ arrLang[langIndex], foreign, english, defArt, type, gender });
	}	
	else {
		cout << "\nDuplicate found, word not added\n";
		char c = _getch();
	}


}

void Dictionary::loadWordList() {
	WordList list;
	int j;
	for (j = 0; j < list.SIZE_ARR; j++) {
		dict.push_back((Word)list.gerArr[j]);
	}
	
	for (j = 0; j < list.SIZE_ARR; j++) {
		dict.push_back((Word)list.freArr[j]);
	}
	for (j = 0; j < list.SIZE_ARR; j++) {
		dict.push_back((Word)list.latArr[j]);
	}
	for (j = 0; j < list.SIZE_ARR; j++) {
		dict.push_back((Word)list.hebArr[j]);
	}
}

bool Dictionary::isDupe(string english, string language) {

	for (int c = 0; c < dict.size(); c++) {
		if (dict[c].language.compare(language) == 0 && dict[c].english.compare(english) == 0)
			return true;
	}
	return false;

}

bool Dictionary::checkDict() {
	if (dict.empty()) {
		return false;
	}
	else
		return true;
}

string Dictionary::printWordType() {
	int num;
	cout << "\nEnter word type: \n1. " + arrSpeech[0] + "\t2. " + arrSpeech[1] + "\t3. " + arrSpeech[2] + "\n4. " + arrSpeech[3] + "\t5. " + arrSpeech[4] + "\t6. " + arrSpeech[5] + "\n";
	switch (num = getIntInRange(1, 6)) {
	case 1: return arrSpeech[0];
	case 2: return arrSpeech[1];
	case 3: return arrSpeech[2];
	case 4: return arrSpeech[3];
	case 5: return arrSpeech[4];
	case 6: return arrSpeech[5];
	default:return "";
	}
}

string Dictionary::printWordGender() {
	int num;
	cout << "\nEnter word gender: \n1. " + arrGen[0] + "\n2. " + arrGen[1] + "\n3. " + arrGen[2] + "\n";
	switch (num = getIntInRange(1, 3)) {
	case 1: return arrGen[0];
	case 2: return arrGen[1];
	case 3: return arrGen[2];
	default: return "";
	}
}

void Dictionary::printToOther(int langInd, int speechInd) {
	sortDict(true);
	for (int count = 0; count < dict.size(); count++) {
		if (arrLang[langInd].compare(dict[count].language) == 0 && speechInd == 6)
			printWord(dict[count], true);
		else if (arrLang[langInd].compare(dict[count].language) == 0 && arrSpeech[speechInd].compare(dict[count].type) == 0)
			printWord(dict[count], true);
	}
	cout << "\nPress any key...\n";
}
void Dictionary::printToEnglish(int langInd, int speechInd) {
	//printing in ascending order of english words
	sortDict(false);
	for (int count = 0; count < dict.size(); count++) {
		if(arrLang[langInd].compare(dict[count].language) == 0 && speechInd == 6)
			printWord(dict[count], false);
		else if (arrLang[langInd].compare(dict[count].language) == 0 && arrSpeech[speechInd].compare(dict[count].type) == 0)
			printWord(dict[count], false);
	}
	cout << "\nPress any key...\n";
}

void Dictionary::printWordSearch() {
	string word;
	bool found = false;
	printSpecialChars();
	cout << "\nEnter the word to search in the desired language: ";
	word = getString();
	cout << endl;
	for (int count = 0; count < dict.size(); count++) {		
		if (dict[count].english.compare(word) == 0) {
			cout << "\n" + dict[count].language + "\n";
			printWord(dict[count], true);
			found = true;
		}
		else if (getSpecialCharWord(dict[count].foreign).compare(word) == 0) {
			cout << "\n" + dict[count].language + "\n";
			printWord(dict[count], false);
			found = true;
		}
		else if ((dict[count].defArt + ' ' + getSpecialCharWord(dict[count].foreign)).compare(word) == 0) {	
			cout << "\n" + dict[count].language + "\n";
			printWord(dict[count], false);
			found = true;
		}
	}
	if (!found)
		cout << "Your entry \"" << word << "\" was not found.";
	cout << "\nPress any key...\n";
}

void Dictionary::printWord(Word word, bool englishToOther) {
	string foreign = getSpecialCharWord(word.foreign);
	if (englishToOther) {
		cout << left << setw(15) << word.english << setw(15) << (word.defArt == "" ? "":word.defArt + " ") + foreign;
	}
	else {
		cout << left << setw(15) << (word.defArt == "" ? "" : word.defArt + " ") + foreign << setw(15) << word.english;
	}
		cout << endl;
}

string Dictionary::getSpecialCharWord(string foreign) {
	string tempWord = "";
	for (int c = 0; c < foreign.size(); c++) {
		switch (foreign[c]) {
		case 'Ä': tempWord += (char)142; break;
		case 'ä': tempWord += (char)132; break;
		case 'Ö': tempWord += (char)153; break;
		case 'ö': tempWord += (char)148; break;
		case 'Ü': tempWord += (char)154; break;
		case 'ü': tempWord += (char)129; break;
		case 'ç': tempWord += (char)135; break;
		case 'é': tempWord += (char)130; break;
		case 'ê': tempWord += (char)136; break;
		case 'è': tempWord += (char)138; break;
		default: tempWord += foreign[c];
		}
	}
	return tempWord;
}

string Dictionary::getNormalWord(string foreign) {
	string tempWord = "";
	for (int c = 0; c < foreign.size(); c++) {
		switch (foreign[c]) {
		case 'Ä': 
		case 'ä': tempWord += 'a'; break;
		case 'Ö': 
		case 'ö': tempWord += 'o'; break;
		case 'Ü': 
		case 'ü': tempWord += 'u'; break;
		case 'ç': tempWord += 'c'; break;
		case 'é':
		case 'ê': 
		case 'è': tempWord += 'c'; break;
		default: tempWord += tolower(foreign[c]);
		}
	}
	return tempWord;
}

void Dictionary::sortDict(bool englishToForeign) {
	
	recSortDict(0, dict.size() - 1, englishToForeign);
}

string Dictionary::getLower(string word) {
	string tempString = word;
	string to;
	for (int c = 0; c < word.size(); c++) {
		tempString[c] = tolower(word[c]);
	}
	to = tempString.substr(0, 3);
	if (to.compare("to ") == 0)
		tempString = tempString.substr(3, tempString.size() - 3);
	return tempString;
}

void Dictionary::recSortDict(int left, int right, bool englishToForeign) {
	//a < z
	//z > a
	if (right-left <=0) {
		return;
	}
	else {	
		Word pivot = dict[right];
		int partition = dictPartition(left, right, pivot, englishToForeign);
		recSortDict(left, partition - 1, englishToForeign);
		recSortDict(partition + 1, right, englishToForeign);
	}
}

int Dictionary::dictPartition(int left, int right, Word pivot, bool englishToForeign) {
	//if compare returns less than 0, left > right
	//if compare returns greater than zero, left < right 
	int leftMark = left - 1;
	int rightMark = right;
	while (true) {
		if (englishToForeign) {
			while (getLower(dict[++leftMark].english).compare(getLower(pivot.english)) < 0);
			while (rightMark > 0 && getLower(dict[--rightMark].english).compare(getLower(pivot.english)) > 0);
			if (leftMark >= rightMark)
				break;
			else
				swap(leftMark, rightMark);
		}
		else {
			while (getNormalWord(dict[++leftMark].foreign).compare(getNormalWord(pivot.foreign)) < 0);
			while (rightMark > 0 && getNormalWord(dict[--rightMark].foreign).compare(getNormalWord(pivot.foreign)) > 0);
			if (leftMark >= rightMark)
				break;
			else
				swap(leftMark, rightMark);
		}
	}
	swap(leftMark, right);
	return leftMark;
}
void Dictionary::swap(int i, int j) {
	Word temp = dict[i];
	dict[i] = dict[j];
	dict[j] = temp;
}

int Dictionary::getIntInRange(int low, int high) {
	int num = _getch() - 48;
	while (num < low || num > high) {
		cout << "\nInvalid Entry.\nTry again.";
		int num = _getch() - 48;
	}
	return num;
}

string Dictionary::getString() {
	char letter = NULL;
	string word;

	while ((letter = getLetter()) != '\r') {
		if (letter != '\r')
			word += letter;
	}
	return word;
}

void Dictionary::printSpecialChars() {
	cout << "\nTo print special characters: "
		<< "\nF1: " << char(142)
		<< "\tF2: " << char(132)
		<< "\tF3: " << char(153)
		<< "\tF4: " << char(148)
		<< "\tF5: " << char(154)
		<< "\nF6: " << char(129)
		<< "\tF7: " << char(135)
		<< "\tF8: " << char(130)
		<< "\tF9: " << char(136)
		<< "\tF10: " << (char)138 << endl;
}

char Dictionary::getLetter() {
	char key = _getch();
	char key2;
	if (key == 0) {
		key2 = _getch();
		switch (key2) {
		case 59: key = (char)142; break;
		case 60: key = (char)132; break;
		case 61: key = (char)153; break;
		case 62: key = (char)148; break;
		case 63: key = (char)154; break;
		case 64: key = (char)129; break;
		case 65: key = (char)135; break;
		case 66: key = (char)130; break;
		case 67: key = (char)136; break;
		case 68: key = (char)138; break;
		default: break;
		}
	}
	cout << key;
	return key;
}


