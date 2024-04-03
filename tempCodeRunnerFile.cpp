#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Hangman {
private:
    vector<string> words;
    string selectedWord;
    string guessedWord;
    int attemptsLeft;
    string playerName;

    // Function to display hangman state
    void displayHangman(int state) {
        // Display hangman state
        switch (state) {
            case 1:
                cout << "  +---+" << endl;
                cout << "  |   |" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "=========" << endl;
                break;
            case 2:
                cout << "  +---+" << endl;
                cout << "  |   |" << endl;
                cout << "  O   |" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "=========" << endl;
                break;
            case 3:
                cout << "  +---+" << endl;
                cout << "  |   |" << endl;
                cout << "  O   |" << endl;
                cout << "  |   |" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "=========" << endl;
                break;
            case 4:
                cout << "  +---+" << endl;
                cout << "  |   |" << endl;
                cout << "  O   |" << endl;
                cout << " /|   |" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "=========" << endl;
                break;
            case 5:
                cout << "  +---+" << endl;
                cout << "  |   |" << endl;
                cout << "  O   |" << endl;
                cout << " /|\\  |" << endl;
                cout << "      |" << endl;
                cout << "      |" << endl;
                cout << "=========" << endl;
                break;
            case 6:
                cout << "  +---+" << endl;
                cout << "  |   |" << endl;
                cout << "  O   |" << endl;
                cout << " /|\\  |" << endl;
                cout << " /    |" << endl;
                cout << "      |" << endl;
                cout << "=========" << endl;
                break;
            case 7:
                cout << "  +---+" << endl;
                cout << "  |   |" << endl;
                cout << "  O   |" << endl;
                cout << " /|\\  |" << endl;
                cout << " / \\  |" << endl;
                cout << "      |" << endl;
                cout << "=========" << endl;
                break;
        }
    }

    // Function to check if the guessed letter is present in the word
    bool isPresent(char letter) {
        bool found = false;
        for (int i = 0; i < selectedWord.length(); ++i) {
            if (selectedWord[i] == letter) {
                guessedWord[i] = letter;
                found = true;
            }
        }
        return found;
    }

    // Function to generate a random word from a list
    string getRandomWord() {
        int index = rand() % words.size();
        return words[index];
    }

    // Function to get the remaining available letters from the alphabet
    string getAvailableLetters() {
        string available = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < guessedWord.length(); ++i) {
            char letter = guessedWord[i];
            available.erase(remove(available.begin(), available.end(), letter), available.end());
        }
        return available;
    }

public:
    Hangman(const vector<string>& wordList) : words(wordList) {}

    // Function to set player name
    void setPlayerName(const string& name) {
        playerName = name;
    }

    // Function to start the game
    void start() {
        selectedWord = getRandomWord();
        guessedWord = string(selectedWord.length(), '_');
        attemptsLeft = 7;
        playGame();
    }

    // Function to play the game
    void playGame() {
        while (attemptsLeft > 0) {
            displayHangman(7 - attemptsLeft);
            cout << "Guessed Word: " << guessedWord << endl;

            char guess;
            cout << "Available letters: " << getAvailableLetters() << endl;
            cout << "Guess a letter: ";
            cin >> guess;

            if (isPresent(guess)) {
                cout << "Correct guess!" << endl;
                if (guessedWord == selectedWord) {
                    cout << "Congratulations, " << playerName << "! You guessed the word: " << selectedWord << endl;
                    return;
                }
            } else {
                cout << "Incorrect guess!" << endl;
                attemptsLeft--;
            }
        }
        displayHangman(7 - attemptsLeft);
        cout << "Sorry, " << playerName << ", you couldn't guess the word. It was: " << selectedWord << endl;
    }
};

int main() {
    // Words for different levels
    vector<string> easyWords;
    vector<string> mediumWords;
    vector<string> hardWords;

    // Reading words from text files
    ifstream easyFile("easy_words.txt");
    ifstream mediumFile("medium_words.txt");
    ifstream hardFile("hard_words.txt");
    string word;

    while (easyFile >> word) {
        easyWords.push_back(word);
    }
    while (mediumFile >> word) {
        mediumWords.push_back(word);
    }
    while (hardFile >> word) {
        hardWords.push_back(word);
    }

    // Setting up random seed
    srand(time(0));

    // Menu
    char level;
    string playerName;
    cout << "Welcome to Hangman!" << endl;
    cout << "Enter your name: ";
    cin >> playerName;
    cout << "Select level (E for Easy, M for Medium, H for Hard): ";
    cin >> level;

    // Selecting words based on level
    vector<string> words;
    if (level == 'E' || level == 'e')
        words = easyWords;
    else if (level == 'M' || level == 'm')
        words = mediumWords;
    else if (level == 'H' || level == 'h')
        words = hardWords;
    else {
        cout << "Invalid level selection!" << endl;
        return 1;
    }

    Hangman game(words);
    game.setPlayerName(playerName);
    game.start();

    return 0;
}
