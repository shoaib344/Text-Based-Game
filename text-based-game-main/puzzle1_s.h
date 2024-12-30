#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include<ctime>
#include "inventory_s.h"
using namespace std;
class Hangman {
private:
    vector<string> words; 
    string word; 
    string guessed; 
    int num_guesses;
    vector<char> incorrect_guesses; 
    bool correct;
public:
    Hangman() {
        words = {"die","key","run","gun","win","hero","hide","ammo","kill","game","safe","exit","loss","heal","word","fight","enemy","armor","knife","escape","weapon","health","damage","puzzle","villain"};
        num_guesses = 6;
        selectWord();
    }

    void selectWord() {
        srand(time(NULL));
        int index = rand() % words.size();
        word = words[index];
        guessed = string(word.length(), '-');
        // incorrect_guesses.clear();
    }

    void showWords() {
        cout << "List of words:" << endl;
        for (int i = 0; i < words.size(); i++) {
        cout << words[i] << endl;
    }       
    }

    char updateGuessed(char guess) {    
        correct = false;
    for (int j = 0; j < word.length(); j++) {
        if (word[j] == guess) {
            guessed[j] = guess;
            correct = true;
        }
    }
   
    if (correct==true) {
        return guess;
    } 
    else {
        num_guesses--;
        incorrect_guesses.push_back(guess);
    }
    }
  
    void printGame() {   
        cout<< "=================="<<endl;
        cout << "Guessed word: " << guessed << endl;
        cout << "Incorrect guesses: ";
        for (int k = 0; k < incorrect_guesses.size(); k++) {
        cout << incorrect_guesses[k];
        }
        cout << endl;
        cout << "Attempts left: " << num_guesses << endl;
        cout << endl;
    }

    bool GameOver() {   
        if (guessed == word) {
            cout << "Congratulations! You have passed the puzzle."<<endl; 
            cout<<"The word was " <<"'"<<word<<"'"<< endl;
            cout<< "Reward Earned! :) "<<endl;
            cout << endl;
            increase_resource();
            increase_weapon();            
            return true;
        }
        else if (num_guesses == 0) {
            cout << "You have run out of attempts. "<<endl; 
            cout<<"The word was " << "'"<<word <<"'"<< endl;
            cout << "No Reward Earned :( "<<endl;
            cout << endl;          
            return true;
        }
        return false;    
    }
};

void puzzle_s(){    
Hangman puzzle1;  
    puzzle1.showWords();
    cout << "----------------"<<endl;
    cout << "Try to guess the word letter by letter"<<endl; 
    while (!puzzle1.GameOver()) {    
        puzzle1.printGame();
        char guess;
        cout << "Enter a letter: ";
        cin >> guess;
        puzzle1.updateGuessed(guess);   
    }
}
