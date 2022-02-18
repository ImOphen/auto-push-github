#include <iostream>
#include <unistd.h>

int main(void)
{
    char *input;
    std::string str1= "git add *; git commit -m \"";
    std::string str2= "\"; git push";
    char type[1];
    std::cout << "\033[1;33m╭────Auto-push\n╰─$ \033[0m [1] - Manual push, only enter commit\n     [2] - Automatic push every minute\n\n pick type of auto github push : ";
    std::cin.get(type, 2);
    if (type[0] == '1')
    {
        while(std::cin.good())
        {
            std::cout << "\n\033[1;33m╭────Auto-push\n╰─$ \033[0mEnter commit message \033[1;33m: \033[0m";
             scanf("%s", input);
            std::system((str1 + input + str2).c_str());
        }
    }
    else if (type[0] == '2')
    {
        while(1)
        {
            std::cout << "\n\033[1;33m $────Auto-push\033[0m\n";
            std::system("git add *; git commit -m \" Automatic push \"; git push");
            sleep(60);
        }
    }
    else
        std::cout << "Error";
}