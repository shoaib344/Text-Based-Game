#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include"puzzle1_s.h"
using namespace std;

std::string shuffleWords(std::string name) {
	// Initialize two empty strings: one to hold the current word and the other to hold the phrase after it has been shuffled
    std::string result = ""; 
    std::string word = ""; 
    // Iterate over each character in the input name
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == ' ') { 
		// A space indicates that a word has been completed.
            std::random_shuffle(word.begin(), word.end()); //the remaining letters in the word are then jumbled
            result += word + " "; //The word is then appended to the output phrase, followed by a space.
            word = ""; 
        }
        else { // Add the current character to the current word if we haven't reached a space yet.
            word += name[i];
        }
    }
    std::random_shuffle(word.begin(), word.end()); // Shuffle the final word
    // adding the final shuffled word to the output name
    result += word; 
    return result; // Return the shuffled name
}

void puzzle_d(){
std::srand(std::time(nullptr)); // Seed the random number generator
	std::srand(std::time(0)); // Seed the random number generator with the current time
    std::string City_Name[] = {"manchester", "liverpool", "new castle", "birmingham", "coventry", "london", "leichester"};
    int numCity_Name = sizeof(City_Name) / sizeof(City_Name[0]); //Track the amount of City Names that are in the list.
    for (int i = 0; i < 3; i++) { // Play three rounds of the game
        std::string name = City_Name[std::rand() % numCity_Name]; // Select a random name from the list
        std::string shuffled = shuffleWords(name); // rearrange the words in the name
        
        std::cout << "Decode the following name:" << std::endl;
        std::cout << shuffled << std::endl; // Print the shuffled name
        std::string guess;
        bool solved = false;
        while (!solved) { //until the player correctly guesses the name, keep looping
            std::cout << "Enter your guess: ";
            std::getline(std::cin, guess); // getting player's guess
            if(guess == name) { // If the guess is correct, break the loop
                std::cout << "Congratulations, you solved the puzzle!" << std::endl;
                solved = true;
            }
            else{ // If the guess is incorrect, prompt the player to try again
                std::cout << "Sorry, that is not the correct answer. Please try again." <<std::endl;
            }
        }
    }
}
