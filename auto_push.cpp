#include <iostream>
#include <unistd.h>
#include <string>

int main(void)
{
	std::string input;
	int minutes;
	std::string type;
	std::cout << "\033[1;33m╭────Auto-push\n╰─$ \033[0m [1] - Manual push, only enter commit\n     [2] - Automatic push every N minute(s) with random commit messages\n\n pick type of auto github push : ";
	std::getline (std::cin,type);
	if (type[0] == '1')
	{
		while(std::cin.good())
		{
			std::cout << "\n\033[1;33m╭────Auto-push\n╰─$ \033[0mEnter commit message \033[1;33m: \033[0m";
			std::getline (std::cin,input);
			if (!std::cin.good())
			{
				std::cout << "Error" << std::endl;
				return 1;
			}
			std::system(("cd ..; git add *; git commit -m \"" + input + "\"; git push").c_str());
		}
	}
	else if (type[0] == '2')
	{
		try
		{
			std::cout << "Enter number of minutes for between each Push : ";
			std::getline(std::cin, input);
			minutes = std::stoi(input);
		}
		catch (...)
		{
			std::cout << "invalid input" << std::endl;
			return 1;
		}
		while(1)
		{
			std::cout << "\n\033[1;33m $────Auto-push\033[0m\n";
			std::system("cd ..; git add *; git commit -m \"$(curl -s http://whatthecommit.com/index.txt)\"; git push;");
			sleep(minutes * 60);
		}
	}
	else
		std::cout << "Error" << std::endl;
}
