//////////////////////////////////////////////////
// Author/s:			Chris Murphy
// Date created:		18/12/17
// Date last edited:	20/12/17
//////////////////////////////////////////////////
#include <algorithm>
#include <exception>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>

unsigned int GetMaxPalindromeLength()
{
	return 256;
}

bool GetIfValidPalindrome(std::string str)
{
	if (str.length() < 2 || str.length() > GetMaxPalindromeLength())
	{
		std::ostringstream error_msg;
		error_msg << "Error - the length of the palindrome string must be greater than 1 character and less than " << GetMaxPalindromeLength() << " characters.";
		throw std::invalid_argument(error_msg.str());
	}
	
	// Removes all spaces from the string.
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

	// The two halves of the string to be checked - if the length of the string is an odd number, the middle character is omitted from both substrings because it doesn't affect whether the full string is a valid palindrome.
	const std::string str_first_half = str.substr(0, str.length() / 2);
	std::string str_second_half = str.substr((str.length() / 2) + ((str.length() % 2 == 0) ? 0 : 1), std::string::npos);

	std::reverse(str_second_half.begin(), str_second_half.end());

	return (str_first_half == str_second_half);
}

int main()
{
	while (true)
	{
		std::cout << "Enter palindrome to be checked or 'N' to exit the program: ";

		std::string user_input;
		std::getline(std::cin, user_input);

		if (std::tolower(user_input[0], std::locale()) == 'n')
			break;

		try
		{
			if (GetIfValidPalindrome(user_input))
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