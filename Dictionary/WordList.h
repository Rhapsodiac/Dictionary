#ifndef WORDLIST_H
#define WORDLIST_H

#include <string>
#include "Word.h"

using std::string;

class WordList {
public:

	const static int SIZE_ARR = 25;

	Word gerArr[SIZE_ARR] = {
		{"German", "Mann", "man", "der", "Noun", "Male"},
		{"German", "Öl", "oil", "das", "Noun", "Neuter"},
		{"German", "Frau", "woman", "die", "Noun", "Female"},
		{"German", "Fräulein", "Miss", "das", "Noun", "Neuter"},
		{"German", "Mädchen", "girl", "das", "Noun", "Neuter"},
		{"German", "Kind", "child", "das", "Noun", "Neuter"},
		{"German", "Haus", "house", "das", "Noun", "Neuter"},
		{"German", "Schule", "school", "die", "Noun", "Female"},
		{"German", "Tür", "door", "die", "Noun", "Female"},
		{"German", "kommen", "to come", "", "Verb", "Neuter"},
		{"German", "gehen", "to go", "", "Verb", "Neuter"},
		{"German", "sehen", "to see", "", "Verb", "Neuter"},
		{"German", "wollen", "to want", "", "Verb", "Neuter"},
		{"German", "wissen", "to know", "", "Verb", "Neuter"},
		{"German", "können", "to be able", "", "Verb", "Neuter"},
		{"German", "vor", "before", "", "Preposition", "Neuter"},
		{"German", "nach", "after", "", "Preposition", "Neuter"},
		{"German", "zu", "to", "", "Preposition", "Neuter"},
		{"German", "bis", "until", "", "Preposition", "Neuter"},
		{"German", "ohne", "without", "", "Preposition", "Neuter"},
		{"German", "eins", "one", "", "Cardinal Number", "Neuter"},
		{"German", "zwei", "two", "", "Cardinal Number", "Neuter"},
		{"German", "drei", "three", "", "Cardinal Number", "Neuter"},
		{"German", "hoch", "high", "", "adverb", "Neuter"},
		{"German", "gut", "good", "", "adverb", "Neuter"}
	};

	Word freArr[SIZE_ARR] = {
		{"French", "mot", "word", "le", "Noun", "Male"},
		{"French", "garçon", "boy", "le", "Noun", "Male"},
		{"French", "jeune", "young", "", "Adjective", "Neuter"},
		{"French", "boulanger", "baker", "la", "Noun", "Female"},
		{"French", "fille", "girl", "la", "Noun", "Female"},
		{"French", "français", "French", "", "Adjective", "Neuter"},
		{"French", "livre", "book", "le", "Noun", "Male"},
		{"French", "école", "school", "l'", "Noun", "Male"},
		{"French", "maison", "house", "la", "Noun", "Female"},
		{"French", "être", "to be", "", "Verb", "Neuter"},
		{"French", "après", "after", "", "Preposition", "Neuter"},
		{"French", "voir", "to see", "", "Verb", "Neuter"},
		{"French", "dire", "to say", "", "Verb", "Neuter"},
		{"French", "aller", "to go", "", "Verb", "Neuter"},
		{"French", "bon", "good", "", "Adjective", "Neuter"},
		{"French", "mardi", "Tuesday", "le", "Noun", "Neuter"},
		{"French", "salle", "room", "la", "Noun", "Male"},
		{"French", "elle", "she", "", "Pronoun", "Male"},
		{"French", "jour", "day", "le", "Noun", "Male"},
		{"French", "aujourd'hui", "today", "", "Adverb", "Male"},
		{"French", "pluie", "rain", "la", "Noun", "Male"},
		{"French", "cheval", "horse", "le", "Noun", "Male"},
		{"French", "moulin", "mill", "le", "Noun", "Male"},
		{"French", "rouge", "red", "le", "Adjective", "Male"},
		{"French", "neige", "snow", "la", "Noun", "Female"}
	};

	Word latArr[SIZE_ARR] = {
		{"Latin", "puer", "boy", "", "Noun", "Male"},
		{"Latin", "pistor", "baker", "", "Noun", "Male"},
		{"Latin", "puella", "girl", "", "Noun", "Female"},
		{"Latin", "bonus", "good", "", "Adjective", "Neuter"},
		{"Latin", "liber", "book", "", "Noun", "Male"},
		{"Latin", "schola", "school", "", "Noun", "Female"},
		{"Latin", "domus", "house", "", "Noun", "Female"},
		{"Latin", "esse", "to be", "", "Verb", "Neuter"},
		{"Latin", "post", "after", "", "Preposition", "Neuter"},
		{"Latin", "illa", "she", "", "Pronoun", "Neuter"},
		{"Latin", "conclave", "room", "", "Noun", "Male"},
		{"Latin", "hodie", "today", "", "Adverb", "Neuter"},
		{"Latin", "pluvia", "rain", "", "Noun", "Female"},
		{"Latin", "equus", "horse", "", "Noun", "Male"},
		{"Latin", "mola", "mill", "", "Noun", "Female"},
		{"Latin", "ruber", "red", "", "Adjective", "Neuter"},
		{"Latin", "nix", "snow", "", "Noun", "Female"},
		{"Latin", "ire", "to go", "", "Verb", "Neuter"},
		{"Latin", "oculus", "eye", "", "Noun", "Male"},
		{"Latin", "intro", "within", "", "Adverb", "Neuter"},
		{"Latin", "femina", "woman", "", "Noun", "Female"},
		{"Latin", "homunculus", "little man", "", "Noun", "Male"},
		{"Latin", "malum", "apple", "", "Noun", "Female"},
		{"Latin", "nam", "for", "", "Preposition", "Neuter"},
		{"Latin", "zelus", "zeal", "", "Noun", "Male"},
	};

	Word hebArr[SIZE_ARR] = {
		{"Hebrew","rachok", "far", "", "Adverb", "Male"},
		{"Hebrew","panim", "face", "", "Noun", "Female"},
		{"Hebrew","tapuach", "apple", "", "Noun", "Male"},
		{"Hebrew","ma'afiah", "bakery", "", "Noun", "Female"},
		{"Hebrew","ayin", "eye", "", "Noun", "Female"},
		{"Hebrew","adom", "red", "", "Adjective", "Male"},
		{"Hebrew","sheleg", "snow", "", "Noun", "Male"},
		{"Hebrew","ochel", "food", "", "Noun", "Male"},
		{"Hebrew","bari", "healthy", "", "Adjective", "Male"},
		{"Hebrew","cham", "hot", "", "Adjective", "Male"},
		{"Hebrew","yom shlishi", "Tuesday", "", "Noun", "Male"},
		{"Hebrew","tov", "good", "", "Adjective", "Male"},
		{"Hebrew","latet", "to give", "", "Verb", "Neuter"},
		{"Hebrew","kan", "here", "", "Adverb", "Neuter"},
		{"Hebrew","juke", "bug", "", "Noun", "Male"},
		{"Hebrew","lemala", "up", "", "Adverb", "Neuter"},
		{"Hebrew","mitah", "upbed", "", "Noun", "Female"},
		{"Hebrew","kafa'fa", "glove", "", "Noun", "Female"},
		{"Hebrew","katis ashrei", "credit card", "", "Noun", "Male"},
		{"Hebrew","zol", "inexpensive", "", "Adjective", "Male"},
		{"Hebrew","smartoot", "rain", "", "Noun", "Male"},
		{"Hebrew","sus", "horse", "", "Noun", "Male"},
		{"Hebrew","matai", "when", "", "Adverb", "Neuter"},
		{"Hebrew","chatza'it", "skirt", "", "Noun", "Female"},
		{"Hebrew","chesbon", "bill", "", "Noun", "Male"},
	};
};
#endif