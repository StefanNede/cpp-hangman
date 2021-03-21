#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// used to display the hangman
void displayCurrentCorrect(int numberIncorrect)
{
	// hangman :
	// "----\n
	// |   |\n
	// |   O\n
	// |  -|-\n
	// |   |\n
	// |  | |\n
	// ---------"
	// string array to store the hangmen
	string hangmen[6] = {
		"----\n|   |\n|   O\n|  -|-\n|   |\n|  | |\n---------",
		"----\n|   |\n|   O\n|  -|-\n|   |\n|\n---------",
		"----\n|   |\n|   O\n|  -|-\n|\n|\n---------",
		"----\n|   |\n|   O\n|   |\n|\n|\n---------",
		"----\n|   |\n|   O\n|\n|\n|\n---------",
		"----\n|   |\n|\n|\n|\n|\n---------",
	};
	int correspondingHangman = 6 - numberIncorrect;
	cout << hangmen[correspondingHangman] << endl;
}

// getting the random number
int generateRandomNumber(int length)
{
	int randomNumber;
	// seed for random number
	srand(time(NULL));
	// gets random number from 0 to the length passed
	randomNumber = rand() % length;
	return randomNumber;
}

// returns the word that has been picked using the random number
string generateWords()
{
	string possibleWords[6] = {"name", "word", "java", "python", "cpp", "typescript"};
	int length = 6;
	int randomNumber = generateRandomNumber(length);
	return possibleWords[randomNumber];
}

bool getGuess(string correctWord)
{
	int length = correctWord.length();
	char letters[length];
	for (int i = 0; i < length; i++)
	{
		letters[i] = correctWord[i];
	}
	cout << "Enter your guess: ";
	char guess;
	cin >> guess;
	for (int i = 0; i < length; i++)
	{
		if (guess == letters[i])
		{
			return true;
		}
	}
	return false;
}

int main()
{
	cout << "Enter your name: ";
	string name;
	cin >> name;
	// welcoming the user to the game
	cout << "Welcome to the game " << name << endl;
	cout << "You have 6 lives" << endl;
	// loop to start the game (generate the word)
	while (true)
	{
		// variable to store the amount incorrect
		int totalIncorrect = 0;
		string word = generateWords();
		cout << word << endl;
		// main game loop (getting the guess from the user and so on)
		while (true)
		{
			if (totalIncorrect == 6)
			{
				cout << "You have lost :(" << endl;
				return 0;
			}
			else
			{
				// if the boolean is true then it will result in a 1, 0 if it is false
				bool result = getGuess(word);
				if (result == 1)
				{
					cout << "correct" << endl;
				}
				else
				{
					cout << "incorrect" << endl;
					totalIncorrect++;
					displayCurrentCorrect(totalIncorrect);
				}
			}
		}
	}
}
