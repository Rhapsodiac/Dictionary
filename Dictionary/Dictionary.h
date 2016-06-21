#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include "WordList.h"
#include "Word.h"

using namespace std;

class Dictionary {	
private:
	string fileName = "dictionary.txt";
	ifstream inFile;
	ofstream outFile;
	vector<Word> dict;
	const int NUM_LANGS = 4;
	const int NUM_PARTS = 7;
	const string arrLang[4] = { "German", "French", "Latin", "Hebrew" };
	const string arrSpeech[6] = { "Noun", "Verb", "Preposition", "Cardinal Number", "Adverb", "Adjective" };
	const string arrGen[3] = { "Neuter", "Male", "Female" };

public:
	
	Dictionary();
	void setFileName(string);
	bool loadDictionary();
	void writeDictionary();
	void storeWord(int);
	void loadWordList();
	bool checkDict();
	void printToOther(int, int);
	void printToEnglish(int, int);
	void printWordSearch();
	string printWordGender();
	string printWordType();
	void sortDict(bool);
	void recSortDict(int, int, bool);
	int dictPartition(int, int, Word, bool);
	void swap(int, int);
	int getIntInRange(int, int);
	void printWord(Word, bool);
	string getString();
	char getLetter();
	void printSpecialChars();
	string getSpecialCharWord(string);
	string getNormalWord(string);
	string getLower(string);
	bool isDupe(string, string);
};
#endif