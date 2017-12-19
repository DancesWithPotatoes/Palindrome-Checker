//////////////////////////////////////////////////
// Author/s:			Chris Murphy
// Date created:		18/12/17
// Date last edited:	19/12/17
//////////////////////////////////////////////////
#define MAX_PALINDROME_LENGTH 256
#include <iostream>
#include <exception>
#include <sstream>
#include <string>

using namespace std;

// Returns whether or not the provided string is a valid palindrome.
bool GetIfValidPalindrome(const string& str)
{
	// Ensures that the length of the provided string is valid.
	if (str.length() < 2 || str.length() > MAX_PALINDROME_LENGTH)
	{
		// The string stream used to create the error message of the exception to throw.
		ostringstream errorMsg;
		errorMsg << "Error - the length of the palindrome string must be greater than 1 character and less than " << MAX_PALINDROME_LENGTH << " characters.";
		throw invalid_argument(errorMsg.str());
	}

	return false;
}

// The entry point of the program.
int main()
{
	while (true)
	{
		cout << "Enter palindrome to be checked: ";

		// The string used to store the input of the user.
		string input;
		getline(cin, input);

		try
		{
			GetIfValidPalindrome(input);
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
		}	

		cout << endl; 
	}

	// TODO - add valid exit input which breaks the while loop.

	return 0;
}