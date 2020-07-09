// Theodore Lewitt
// ITP 165, Summer 2020
// Lab practical 4
// lewitt@usc.edu

#include <iostream>
#include <string>
#include <fstream>
std::string encrypt(std::string cipher, std::string toEncrypt);
int main()
{
	std::string cipher{ "LKDJFHAGZXBCVNMQWERIOPSTY" };
	std::string filename;
	//Get filename to write top
	std::cout << "Enter file name to encrypt to:  ";
	std::cin >> filename;
	//Create output stream
	std::ofstream fObj(filename);
	bool adding = true;
	//Loop until user is done writing
	while (adding) {
		std::string templine;
		std::cout << "Enter a line of text or \"done\" to quit:";
		std::cin.clear();
		//Get user line, unencrypted
		std::getline(std::cin, templine);
		//Check if the user is done
		if (templine == "done") {
			adding = false;
		}
		else {
			//Write the encrypted string to the file
			fObj << encrypt(cipher, templine) << "\n";
		}
	}
	//Close the file
	fObj.close();
}
std::string encrypt(std::string cipher, std::string toEncrypt)
{
	for (int i = 0; i < toEncrypt.length(); i++)
	{
		if (toEncrypt[i] >= 'A' && toEncrypt[i] <= 'Z')
		{
			toEncrypt[i] = cipher[toEncrypt[i] - 'A'];
		}
		else if (toEncrypt[i] >= 'a' && toEncrypt[i] <= 'z')
		{
			toEncrypt[i] = cipher[toEncrypt[i] - 'a'];
		}
	}
	return toEncrypt;
}