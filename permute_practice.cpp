#include <iostream>
#include <string>

/*This is practice for my Microsoft interview*/

/*Begin linked list practice: 10/22/2011 3:54*/
int tracker(0);
void doPermute(std::string word, char* newWord, bool* truth, int index, int length)
{
	using namespace std;
	if(index == length)
	{
		cout << newWord << "\n";
		++tracker;
	}
	else
	{
		for(int i = 0; i < length; ++i)
		{
		if(truth[i])
				continue;
		newWord[i] = word[i];
		truth[i] = 1;
		doPermute(word, newWord, truth, index+1, length);
		truth[i] = 0;
		}
	}
}

int counter(0);
void doCombine(std::string word, std::string newWord, int index, int length)
{
	if(index == length)
		;
	else
	{
		for(int i(index); i < length; ++i)
		{
		newWord[i] = word[i];
		++counter;
		std::cout << newWord << "\n";
		doCombine(word, newWord, ++index, length);
		}
	}
}

void permute(std::string word)
{
	int length(word.length());
	bool truth[length];
	for(int i(0); i < length; ++i)
	{
		truth[i] = 0;
	}
	char newWord[length];
	doPermute(word, newWord, truth, 0, length);
}

void combine(std::string word)
{
	int length = word.length();
	char newWord[length];
	doCombine(word, newWord, 0, length);
}

int main()
{
	std::string sent("Katie");
	permute(sent);
	std::cout << tracker << "\n";
	combine(sent);
	std::cout << counter;
}