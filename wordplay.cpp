/*More Microsoft Practice, only 1 week away!*/

#include <iostream>
#include <string>
/*Finding the first non repeating letter!*/

char find(char* word) //I'd like to use string library so I can utilize length... bah owell, We'll hardcode for this example
{
	bool* truths = new bool[256];
	for(int i(0); word[i]; ++i) //General case is i < word.length
	{
		int hash = word[i];
		if(truths[hash] == 1)
		{
			return word[i];
		}
		truths[hash] = 1;
	}
	return ' ';
}

int wordToInt(char* word)
{
	int counter = 0;
	//std::cout << "WORD TO INT\n";
	for(int i(0); word[i]; ++i)
	{
	counter *= 10;
	//std::cout << word[i] << " word \n";
	//std::cout << counter << " counter \n";
	counter += word[i] - '0';
	}
	return counter;
}

void intToWord(int number)
{
	//ex. 325%10 = 5 ... 325/10
	char test[4];
	//Read the first number in...This won't be the general case but is easily applicable
	for(int pos(3); pos > 0; --pos)
	{
		int value = number%10;
		test[pos] = value + '0';
		number -= value;
		number /= 10;
	}
	for(int i(1); i <= 3; ++i) //Some hairy indexing but owell it works okay!
	{
	std::cout << test[i];
	}
}



int main()
{
	char word[] = "this is fun";
	char word2[] = "apple";
	char word3[] = "ThIS IS weird";
	char word4[] = "Hello Mark";
	std::cout << find(word) << "\n";
	std::cout << find(word2) << "\n";
	std::cout << find(word3) << "\n";
	std::cout << find(word4) << "\n";
	char words[] = "325";
	std::cout << wordToInt(words) << "\n";
	intToWord(325);
}