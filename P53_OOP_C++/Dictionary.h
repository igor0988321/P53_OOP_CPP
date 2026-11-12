#pragma once
#include <iostream>
#include <fstream>
#include <cctype>
#include <windows.h>
#include <string>
#include <map>

using namespace std;

void dictionary();
string cleanWord(const string& Word);
bool File(const string& file, map<string, int>& word);
void printAll(const map<string, int>& word);
string Frequent(const map<string, int>& wordFrequency);
void saveFile(const string& file, const map<string, int>& wordFrequency, const string& mostFrequent);

string cleanWord(const string& Word)
{
	string cleaned;
	for (unsigned char ch : Word)
	{
		if (isalnum(ch) || ch >= 128)
		{
			cleaned += static_cast<char>(tolower(ch));
		}
	}
	return cleaned;
}

bool File(const string& file, map<string, int>& wordFrequency)
{
	ifstream inFile(file);
	if (!inFile.is_open())
	{
		cerr << "Не вдалося відкрити файл " << file << endl;
		return false;
	}

	string Word;
	while (inFile >> Word)
	{
		string word = cleanWord(Word);
		if (!word.empty())
		{
			wordFrequency[word]++;
		}
	}
	inFile.close();
	return true;
}

void printAll(const map<string, int>& wordFrequency)
{
	cout << "Словник" << endl;
	for (const auto& pair : wordFrequency)
	{
		cout << pair.first << " : " << pair.second << endl;
	}
}

string Frequent(const map<string, int>& wordFrequency)
{
	string mostFrequent;
	int count = 0;

	for (const auto& pair : wordFrequency)
	{
		if (pair.second > count)
		{
			count = pair.second;
			mostFrequent = pair.first;
		}
	}
	return mostFrequent;
}

void saveFile(const string& file, const map<string, int>& wordFrequency, const string& mostFrequent)
{
	ofstream outFile(file);
	if (!outFile.is_open())
	{
		cerr << "Не вдалося створити файл " << file << endl;
		return;
	}

	outFile << "Словник\n";
	for (const auto& pair : wordFrequency)
	{
		outFile << pair.first << " : " << pair.second << "\n";
	}

	outFile << "Слово: " << mostFrequent << " зустрічається " << wordFrequency.at(mostFrequent) << " разів";

	outFile.close();
	cout << "Результат збережено у файл " << file << endl;
}

void dictionary()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const string input = "input.txt";
	const string output = "output.txt";
	map<string, int> wordFrequency;

	if (!File(input, wordFrequency))
	{
		return;
	}

	if (wordFrequency.empty())
	{
		cout << "Файл порожній" << endl;
		return;
	}

	printAll(wordFrequency);

	string mostFrequent = Frequent(wordFrequency);
	cout << mostFrequent << " зустрічається " << wordFrequency[mostFrequent] << " разів" << endl;

	saveFile(output, wordFrequency, mostFrequent);
}