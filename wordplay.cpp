/*More Microsoft Practice, only 1 week away!*/

#include <iostream>
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
}