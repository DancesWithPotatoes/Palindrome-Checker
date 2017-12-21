//////////////////////////////////////////////////
// Author/s:			Chris Murphy
// Date created:		18/12/17
// Date last edited:	21/12/17
//////////////////////////////////////////////////
#include <algorithm>
#include <exception>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>

unsigned int get_max_palindrome_length()
{
	return 256;
}

bool get_if_valid_palindrome(std::string mString)
{
	if (mString.length() < 2 || mString.length() > get_max_palindrome_length())
	{
		std::ostringstream errorMsg;
		errorMsg << "Error - the length of the palindrome string must be greater than 1 character and less than " << get_max_palindrome_length() << " characters.";
		throw std::invalid_argument(errorMsg.str());
	}
	
	// Removes all spaces from the string.
	mString.erase(std::remove(mString.begin(), mString.end(), ' '), mString.end());

	// The two halves of the string to be checked - if the length of the string is an odd number, the middle character is omitted from both substrings because it doesn't affect whether the full string is a valid palindrome.
	const std::string stringFirstHalf = mString.substr(0, mString.length() / 2);
	std::string stringSecondHalf = mString.substr((mString.length() / 2) + ((mString.length() % 2 == 0) ? 0 : 1), std::string::npos);

	std::reverse(stringSecondHalf.begin(), stringSecondHalf.end());

	return (stringFirstHalf == stringSecondHalf);
}

int main()
{
	while (true)
	{
		std::cout << "Enter palindrome to be checked or 'N' to exit the program: ";

		std::string userInput;
		std::getline(std::cin, userInput);

		if (std::tolower(userInput[0], std::locale()) == 'n')
			break;

		try
		{
			if (get_if_valid_palindrome(userInput))
				std::cout << "The inputted string is a valid palindrome.";
			else
				std::cout << "The inputted string is not a valid palindrome.";
		}
		catch (std::invalid_argument& e)
		{
			std::cout << e.what();
		}

		std::cout << std::endl << std::endl;
	}

	return 0;
}