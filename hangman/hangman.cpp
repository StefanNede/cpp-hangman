#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// used to display the hangman
void displayHangman(int numberIncorrect)
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

int displayWord(string word, string guessedLetters)
{
	int wordLength = word.length();
	int guessedLength = guessedLetters.length();
	char result[wordLength];
	for (int i = 0; i < wordLength; i++)
	{
		result[i] = '_';
	}
	string attempt = "";
	for (int j = 0; j < guessedLength; j++)
	{
		for (int i = 0; i < wordLength; i++)
		{
			if (guessedLetters[j] == word[i])
			{
				result[i] = guessedLetters[j];
			}
		}
	}

	for (int i = 0; i < wordLength; i++)
	{
		attempt += result[i];
	}
	cout << result << endl;
	if (result == word)
	{
		cout << "You have won!" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
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
	// a very creative array of possible words
	string possibleWords[5] = {"name", "word", "java", "python", "cpp"};
	int length = 5;
	int randomNumber = generateRandomNumber(length);
	return possibleWords[randomNumber];
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
		string correctLetters = "";
		// to help the user
		cout << "the word has length: " << word.length() << endl;
		// main game loop (getting the guess from the user and so on)
		while (true)
		{
			// checks if the user has lost all of their lives
			if (totalIncorrect == 6)
			{
				cout << "You have lost :(" << endl;
				cout << "The correct word was: " << word << endl;
				return 0;
			}
			else
			{
				// used to check if the guess is in the word. I now realise you could have just done:
				// word.find(guess), which returns the index, and then see if the index is less than
				// the length of the word, but this is what I first did
				bool inWord = false;
				int length = word.length();
				cout << "Enter your guess: ";
				char guess;
				cin >> guess;
				for (int i = 0; i < length; i++)
				{
					if (guess == word[i])
					{
						correctLetters += word[i];
						inWord = true;
					}
				}
				if (inWord == false)
				{
					totalIncorrect++;
					displayHangman(totalIncorrect);
				}
				int hasWon = displayWord(word, correctLetters);
				// the method returns a 1 if the user wins, in which case we stop the game
				if (hasWon == 1)
				{
					cout << "Do you want to play again? (y for yes or n for no)" << endl;
					string userResponse;
					cin >> userResponse;
					// some error checking to only check the first letter entered
					char response = userResponse[0];
					if (response == 'n' || response != 'y')
					{
						cout << "Thanks for playing!" << endl;
						return 0;
					}
					// if the user wants to play again, then it breaks to the outer while loop to generate a new word
					else if (response == 'y')
					{
						break;
					}
				}
			}
		}
	}
}
