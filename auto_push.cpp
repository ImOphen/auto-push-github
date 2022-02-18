#include <iostream>

int main(void)
{
    std::string input;
    while(std::cin.good())
    {
        std::cout << "\033[1;33m╭────Auto-push\n╰─$ \033[0mEnter commit message \033[1;33m: \033[0m";
        std::cin >> input;
        std::system(("git add *; git commit -m \"" + input + "\"; git push").c_str());
    }
}