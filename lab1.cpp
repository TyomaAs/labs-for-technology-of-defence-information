#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StringVectorEncryptor
{
private:
	const int firsASCICharCode = int('a');
	uint8_t step;
	string encryptString(string word)
	{
		string encryptedString = "";
		for (int i = 0; i < word.length(); i++)
		{
			char symbolASCICode = int(word[i]);
			encryptedString += char((symbolASCICode + this->step - firsASCICharCode) % 26 + firsASCICharCode);
		}
		return encryptedString;
	}

	string decryptString(string word)
	{
		string encryptedString = "";
		for (int i = 0; i < word.length(); i++)
		{
			char symbolASCICode = int(word[i]);
			encryptedString += char(((symbolASCICode - this->step + 26 - 97) % 26) + firsASCICharCode);
		}
		return encryptedString;
	}

public:
	StringVectorEncryptor(uint8_t step)
	{
		this->step = step;
	}

	vector<string> _split(string &str, char separator)
	{
		vector<string> words;
		string word = "";

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == separator)
			{
				words.push_back(word);
				word = "";
				continue;
			}

			word += str[i];
		}

		words.push_back(word);

		return words;
	}

	vector<string> decryptVectorStrings(vector<string> &encryptWords)
	{
		vector<string> decryptWords;

		for (string encryptWord : encryptWords)
		{
			decryptWords.push_back(this->decryptString(encryptWord));
		}

		return decryptWords;
	}

	vector<string> encryptVectorStrings(vector<string> &words)
	{
		vector<string> encryptWords;

		for (string word : words)
		{
			encryptWords.push_back(this->encryptString(word));
		}

		return encryptWords;
	}
};

ostream &operator<<(ostream &out, const vector<string> &words)
{
	for (string word : words)
	{
		out << word << " ";
	}

	return out;
}
int main()
{
	vector<string> words;
	string str;
	int step;

	cout << "Input step: ";
	cin >> step;
	std::cin.ignore(1);

	StringVectorEncryptor stringVectorEncryptor = StringVectorEncryptor(step);

	while (getline(cin, str, '\n'))
	{
		words = stringVectorEncryptor._split(str, ' ');
		vector<string> encryptedWords = stringVectorEncryptor.encryptVectorStrings(words);
		cout << encryptedWords << '\n';

		vector<string> decryptedWords = stringVectorEncryptor.decryptVectorStrings(encryptedWords);
		cout << decryptedWords << '\n';
	}

	return 0;
}
