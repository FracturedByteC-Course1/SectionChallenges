#pragma once
#include <iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<string>
#include<map>
#include<set>

void display_words(std::map<std::string, int>& words)
{
	std::cout << std::setw(12) << std::left << "\nWord" << std::setw(7) << std::right << "Count" << std::endl;
	std::cout << "==================================" << std::endl;
	for (auto pair : words)
		std::cout << std::setw(12) << std::left << pair.first << std::setw(7) << std::right << pair.second << std::endl;
}

void display_words(std::map<std::string, std::set<int>>& words)
{
	std::cout << std::setw(12) << std::left << "\nWord" << std::setw(7) << std::right << "Occurrences" << std::endl;
	std::cout << "================================================================================================================================================================" << std::endl;
	for (auto pair : words) {
		std::cout << std::setw(12) << std::left << pair.first << std::left << "[ ";
		for (auto i : pair.second)
			std::cout << i << ' ';
		std::cout << ']' << std::endl;
	}
}

std::string clean_string(const std::string& s)
{
	std::string result;
	for (char c : s)
	{
		if (c == '.' || c == ',' || c == ';' || c == ':')
			continue;
		else
			result += c;
	}
	return result;
}

void part1()
{
	std::map<std::string, int> words;
	std::string line;
	std::string word;
	std::ifstream in_file{ "words.txt" };

	if (in_file)
	{
		while (std::getline(in_file, line))
		{
			std::stringstream ss(line);
			while (ss >> word)
			{
				word = clean_string(word);
				words[word]++;
			}
		}
		in_file.close();
		display_words(words);
	}
	else
		std::cerr << "Error opening input file" << std::endl;
}

void part2()
{
	std::map<std::string, std::set<int>> words;
	std::string line;
	std::string word;
	std::ifstream in_file{ "words.txt" };

	if (in_file)
	{
		int line_number = 0;
		while (std::getline(in_file, line))
		{
			line_number++;
			std::stringstream ss(line);
			while (ss >> word)
			{
				word = clean_string(word);
				words[word].insert(line_number);
			}
		}
		in_file.close();
		display_words(words);
	}
	else
		std::cerr << "Error opening input file" << std::endl;
}

int main()
{
	part1();
	part2();
	return 0;
}