#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void cleanPos(short* pos);
void testLetter(string& orig, string newLetter, short* pos);
void writeToFile(string fileName, string& edit);
void readFromFile(string fileName, string& data);
void findLetters(string& words, char letter, short* pos);

int main()
{
	string fileName = "atbashEX.txt";
	string words;
	string change;
	short pos[100];
	cleanPos(pos);
	string& wordsRef = words;
	string& changeRef = change;

	//cout << "Input file alteration: ";
	//getline(cin,change);
	//cout << '\n';

	//writeToFile(fileName, changeRef);
	readFromFile(fileName, wordsRef);

	cout << words << endl << endl;

	//findLetters(words, 'r', pos);

	//for (size_t i = 0; i < 100; i++)
	//{
	//	cout << i << " : " << pos[i] << endl;
	//}

	/*for (size_t i = 0; pos[i] > -1; i++)
	{
		words.replace(pos[i], 1, "a");
	}*/

	//testLetter(wordsRef, "a", pos);

	findLetters(words, 'o', pos);
	testLetter(wordsRef, "L", pos);

	findLetters(words, 'r', pos);
	testLetter(wordsRef, "I", pos);

	findLetters(words, 'v', pos);
	testLetter(wordsRef, "E", pos);

	findLetters(words, 'l', pos);
	testLetter(wordsRef, "O", pos);

	findLetters(words, 'g', pos);
	testLetter(wordsRef, "T", pos);

	findLetters(words, 's', pos);
	testLetter(wordsRef, "H", pos);

	findLetters(words, 'e', pos);
	testLetter(wordsRef, "V", pos);

	findLetters(words, 'z', pos);
	testLetter(wordsRef, "A", pos);

	findLetters(words, 'u', pos);
	testLetter(wordsRef, "F", pos);

	findLetters(words, 'm', pos);
	testLetter(wordsRef, "N", pos);

	findLetters(words, 'p', pos);
	testLetter(wordsRef, "K", pos);

	findLetters(words, 'd', pos);
	testLetter(wordsRef, "W", pos);

	findLetters(words, 'b', pos);
	testLetter(wordsRef, "Y", pos);

	findLetters(words, 'f', pos);
	testLetter(wordsRef, "U", pos);

	findLetters(words, 'i', pos);
	testLetter(wordsRef, "R", pos);

	findLetters(words, 'h', pos);
	testLetter(wordsRef, "S", pos);

	findLetters(words, 'x', pos);
	testLetter(wordsRef, "C", pos);

	findLetters(words, 't', pos);
	testLetter(wordsRef, "G", pos);

	findLetters(words, 'n', pos);
	testLetter(wordsRef, "M", pos);

	findLetters(words, 'w', pos);
	testLetter(wordsRef, "D", pos);

	findLetters(words, 'k', pos);
	testLetter(wordsRef, "P", pos);

	findLetters(words, 'q', pos);
	testLetter(wordsRef, "J", pos);

	findLetters(words, 'y', pos);
	testLetter(wordsRef, "B", pos);

	findLetters(words, 'c', pos);
	testLetter(wordsRef, "X", pos);

	cout << words << endl << endl;

	//abcdefghijklmnopqrstuvwxyz

	std::cin.get();
}

void cleanPos(short* pos)
{
	for (size_t i = 0; i < 100; i++)
	{
		pos[i] = -10;
	}
}

void testLetter(string& orig, string newLetter, short* pos)
{
	for (size_t i = 0; pos[i] > -1; i++)
	{
		orig.replace(pos[i], 1, newLetter);
	}
	cleanPos(pos);
}

void writeToFile(string fileName, string& edit)
{
	ofstream outFile;
	outFile.open("Item.txt", ofstream::out | ofstream::trunc);
	outFile << edit;
	outFile.close();
}

void readFromFile(string fileName, string& data)
{
	ifstream inFile;
	inFile.open(fileName);
	getline(inFile, data, '\0');
	inFile.close();
}

void findLetters(string& words, char letter, short* pos)
{
	size_t step = 0;
	short temp = 0;
	for (size_t i = 0; temp != -1; i++)
	{
		temp = words.find(letter, step);
		if (temp == -1)
		{
			break;
		}
		else
		{
			pos[i] = temp;
			step = temp + 1;
		}
	}
}