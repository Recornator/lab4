#include <iostream>
#include "FileReader.h"
#include "PushdownAutomaton.h"
#include <string>
#include <fstream>

//void main(){ int a = 3; }
//void main(){ if (a < b) return 5; }
//void main(){ if ((a < b) or (c < d)) return 5; }
//void main(){ for (int a = 0;10 < a;) return 5; }
//void main(){ while (a < b) return 5; }
//void main(){ if (a < b) {return 5;} else {return 2;} } 
//void main(){ if (a < b) return 5; else }

int main()
{
    FileReader fr;
    std::string filename;
    std::string input;
 //   setlocale(LC_ALL, "Russian");
 //   SetConsoleCP(65001);
    bool isFileOk = false;

    /*while (!isFileOk)
    {
        std::cout << "Write filename:" << std::endl;
        try
        {
            std::getline(std::cin, filename);
            fr.getData(filename);
            isFileOk = true;

        }
        catch (std::string err)
        {
            std::cout << err << std::endl;
            std::cout << std::endl;
        }
    }*/




    fr.getData("fix.txt");
    
    isFileOk = true;
    std::cout << std::endl;

    fr.printRawRules();
    fr.printInputAlphabet();
    fr.printNonterminalsAlphabet();
    fr.printAlphabet();
    fr.printCommands();

    while (1)
    {
        void(*ptr(void(*(int))));
        std::cout << "Write str:" << std::endl;
        std::getline(std::cin, input);
        char ch = '&&';
        char ch2 = '||';

     
        int indexOfChar = input.find(ch);
        if (indexOfChar != -1)
            input.replace(indexOfChar, 2, "or");
        int indexOfChar3 = input.find(ch2);
        if (indexOfChar3 != -1)
            input.replace(indexOfChar3, 2, "and");
        const std::vector<ConfigCommand> commands = fr.getCommands();
        std::vector<std::string> terminals = fr.getTerminals();
        std::vector<std::string> nonTerminals = fr.getNonTerminals();
        PushdownAutomaton pa(input, commands, terminals, nonTerminals);
        if (pa.checkStr(input))
        {
            if (pa.getErrorCount() > 0)
            {
                std::cout << "Str not OK :(" << std::endl;
                std::cout << "Count errors: " << pa.getErrorCount() << std::endl;
            }
            else
            {
                std::cout << "Str OK :)" << std::endl;
                for (std::string str : pa.getChainConfigurations())
                {
                    std::cout << str << std::endl;
                }
            }
        }
        else
        {
            std::cout << "Str not OK :(" << std::endl;
            std::cout << "Count errors: " << pa.getErrorCount() << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
