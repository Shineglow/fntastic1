#include <iostream>
#include <string>
#include <map>
#include "StringToBrackets.h"
#include <cctype>

int main()
{
	std::string str[] = {"din", "recede", "Success", "(( @" };

	for (auto s : str)
	{
		ToBrackets(s);
		std::cout << s << std::endl;
	}

	system("PAUSE");
}

void ToBrackets(std::string& str)
{
	std::map<char, char*>* charsDictionary = new std::map<char, char*>();
	for (auto it = str.begin(); it != str.end(); ++it) {
		auto c = tolower(*it);
		if (charsDictionary->find(c) == charsDictionary->end()) {
			charsDictionary->insert({ c, (char*)(it._Ptr) });
			*it = '(';
			continue;
		}

		*((*charsDictionary)[*it]) = ')';
		*it = ')';
	}
	delete(charsDictionary);
}

