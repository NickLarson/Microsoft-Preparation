/*Some more practice... here we go!!!*/

#include <iostream>
#include <algorithm>

void reverseSentence(char* sentence, int length)
{
	int startWord = 0;
	int endWord = 0;
	if(length == 1 or length == 0)
		std::cout << "Bad input"; //Special case
	while(endWord <= length)
	{
		if(endWord == length)
		{
			for(; startWord <= endWord; ++startWord, --endWord)
			{
				std::swap(sentence[startWord], sentence[endWord]);
			}
			break;
		}
		if(sentence[endWord] == ' ') //Hit a delimiter, so reverse the word...
		{
			int newEnd = endWord+1;
			for(int temp(endWord-1); startWord < temp; ++startWord, --temp)
			{
				std::swap(sentence[startWord], sentence[temp]);
			}
			endWord = newEnd;
			startWord = newEnd;
		}
		else
		++endWord;
	}
	//Now we've reversed all the words... so go ahead and reverse the string...
	for(int start(0), end(length); start <= end; ++start, --end)
	{
	std::swap(sentence[start], sentence[end]);
	}
	//Now we can return...
	std::cout << "Finished...\n";
}

int main()
{
	char y[] = "This is wordplay yes I am.";
	reverseSentence(y, 25);
	std::cout << y;
}
		
		