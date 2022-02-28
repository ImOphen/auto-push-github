#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>

void file_updated(void)
{
	std::string input;
	std::cout << "\n\033[1;33m╭────Auto-push\n╰─$ \033[0mEnter file to track and push \033[1;33m: \033[0m";
	std::getline (std::cin,input);
	if (!std::cin.good())
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	std::fstream fileStream;
	fileStream.open("../" + input, std::ios::in);
	if (!fileStream.is_open())
	{
		std::cout << "Invalid file" << std::endl;
		exit(1);
	}
	std::string fileBase;
	std::string fileCompare;
	std::getline(fileStream, fileBase, '\0');
	fileStream.close();
	std::cout << "\n\033[1;33m$───Auto-push" << std::endl << "\033[1;33mWaiting for file change\033[0m\n";
	while(1)
	{
		fileStream.open("../" + input, std::ios::in);
		if (!fileStream.is_open())
		{
			std::cout << "Invalid file" << std::endl;
			exit(1);
		}
		std::getline(fileStream, fileCompare, '\0');
		if (fileBase != fileCompare)
		{
			std::system(("cd ..; git add " + input + "; git commit -m \"$(curl -s http://whatthecommit.com/index.txt)\"; git push").c_str());
			fileBase = fileCompare;
			std::cout << "\n\033[1;33m$───Auto-push" << std::endl << "\033[1;33mWaiting for file change\033[0m\n";
		}
		fileStream.close();
		sleep(2);
	}
}

void auto_push(void)
{
	int minutes;
	std::string input;
	try
	{
		std::cout << "Enter number of minutes for between each Push : ";
		std::getline(std::cin, input);
		minutes = std::stoi(input);
	}
	catch (...)
	{
		std::cout << "invalid input" << std::endl;
		exit (1);
	}
	while(1)
	{
		std::cout << "\n\033[1;33m $────Auto-push\033[0m\n";
		std::system("cd ..; git add *; git commit -m \"$(curl -s http://whatthecommit.com/index.txt)\"; git push;");
		sleep(minutes * 60);
	}
}

void push_with_commit(void)
{
	std::string input;
	while(std::cin.good())
	{
		std::cout << "\n\033[1;33m╭────Auto-push\n╰─$ \033[0mEnter commit message \033[1;33m: \033[0m";
		std::getline (std::cin,input);
		if (!std::cin.good())
		{
			std::cout << "Error" << std::endl;
			exit (1);
		}
		std::system(("cd ..; git add *; git commit -m \"" + input + "\"; git push").c_str());
	}
}

int main(void)
{
	std::string type;
	std::cout << "\033[1;33m╭────Auto-push\n╰─$ \033[0m\
	 [1] - Manual push, only enter commit\n\
	 [2] - Automatic push every N minute(s) with random commit messages\n    \
     [3] - Automatic push of the tracked file when a change occurs, with random commits\n\n pick type of auto github push : ";
	std::getline (std::cin,type);
	if (type[0] == '1')
		push_with_commit();
	else if (type[0] == '2')
		auto_push();
	else if (type[0] == '3')
		file_updated();
	else
		std::cout << "Error" << std::endl;
}
