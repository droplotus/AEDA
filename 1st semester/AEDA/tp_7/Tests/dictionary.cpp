#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"
#include "bst.h"

using namespace std;

BST<WordMeaning> Dictionary::getWords() const {
    return words;
}

bool WordMeaning::operator < (const WordMeaning &wm1) const {
    return word < wm1.word;
}

bool WordMeaning::operator == (const WordMeaning &wm1) const {
    return word == wm1.word;
}

void Dictionary::readDictionary(ifstream &f)
{
    string word;
    string meaning;
    while(!f.eof()){
        getline(f, word);
        getline(f, meaning);
        WordMeaning wm(word, meaning);
        words.insert(wm);
    }

    return;
}

string Dictionary::searchFor(string word) const
{
    WordMeaning wm1(word,"");
    WordMeaning wmx = words.find(wm1);
    WordMeaning wmNotFound("","");

    if(wmx == wmNotFound){
        BSTItrIn<WordMeaning> it(words);
        string wordBefore, meaningBefore;
        while(!it.isAtEnd() && it.retrieve()<wm1){
            wordBefore = it.retrieve().getWord();
            meaningBefore = it.retrieve().getMeaning();
            it.advance();
        }
        string wordAfter, meaningAfter;
        if(!it.isAtEnd()){
            wordAfter = it.retrieve().getWord();
            meaningAfter = it.retrieve().getMeaning();
        }
        throw WordInexistent(wordBefore, meaningBefore, wordAfter, meaningAfter);
    }

    return wmx.getMeaning();
}

//TODO
bool Dictionary::correct(string word, string newMeaning)
{
    WordMeaning wm1(word, newMeaning);
    WordMeaning wmx = words.find(wm1);
    WordMeaning wmNotFound("", "");

    if(wmx == wmNotFound){
        words.insert(wm1);
        return false;
    }

    words.remove(wmx);
    words.insert(wm1);
    return true;
}

void Dictionary::print() const
{
    BSTItrIn<WordMeaning> it(words);
    while(!it.isAtEnd()) {
        std::cout << "Word: " << it.retrieve().getWord() << std::endl;
        std::cout << "Meaning: "<< it.retrieve().getMeaning() << std::endl;
        it.advance();
    }

    return;
}

