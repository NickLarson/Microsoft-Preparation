#include <iostream>
#include <algorithm> //For swap... I could code this but it'd be missing the point
#include <cstring> //Only for using strlen
#include <string> //Passed the test!

/*This is practice for my Microsoft interview*/

/*Begin string practice: 10/20/2011 6:34
We won't begin using the standard string 
library until we write a reverse function using a char array*/

char* reverse(char* string)
{
	if(!sizeof(string))
	{
		std::cout << "EMPTY!\n";
		return string;
	}
	int len = strlen(string);
	for(int i(0); i < len; ++i, --len)
	{
		std::swap(string[i], string[len-1]);
	}
	return string;
}

/*These will use the string library definitions*/

/*Check to see if there's any duplicates*/
bool hasDupes(std::string str)
{
	int table [15];
	for(int i(0); i < str.length(); ++i)
	{
		int hash = (int)str[i];
		if(table[hash] == 1)
		{
			return 1;
		}
		else
			table[hash] = 1;
	}
	return 0;
}

int main()
{
/*Begin tests for reverse*/
 using namespace std;
 char test[] = "tester";
 cout << reverse(test) << "\n";
/*End test for reverse... now we can just use std::string*/
 //Lack of a good unicode hash function forces me to do this...
 std::string text("12345176891034");
 cout << "This has duplicates in it... do you agree?:\n";
 cout << hasDupes(text) << "\n";
 std::string one("1234567");
 cout << "\nThis one doesn't though... you know?:\n" << hasDupes(one);


}

