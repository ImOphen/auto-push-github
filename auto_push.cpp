#include <iostream>
#include <unistd.h>

int main(void)
{
    std::string input;
    int type;
    std::cout << "\033[1;33m╭────Auto-push\n╰─$ \033[0m [1] - Manual push, only enter commit\n     [2] - Automatic push every minute\n pick type of auto github push : ";
    std::cin >> type;
    if (type == 1)
    {
        while(std::cin.good())
        {
            std::cout << "\033[1;33m╭────Auto-push\n╰─$ \033[0mEnter commit message \033[1;33m: \033[0m";
            std::cin >> input;
            std::system(("git add *; git commit -m \"" + input + "\"; git push").c_str());
        }
    }
    else if (type == 2)
    {
        while(std::cin.good())
        {
            std::system("git add *; git commit -m \" Automatic push \"; git push");
            std::cout << std::cout << "\033[1;33m $ ────Auto-push\033[0m";
            sleep(60);
        }
    }
    else
        std::cout << "Error";
}