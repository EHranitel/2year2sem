#include <iostream>
#include <array>
#include <string>
#include <list>
#include <fstream>

int standartHash(std::string word)
{
    return abs(std::hash<std::string>{}(word));
}

int hash1(std::string word)
{
    return (word[0] + word[word.length() - 1]) / 2;
}

int hash2(std::string word)
{
    int hash = word[0] * 997;

    int len = word.length();

    for (int i = 1; i < len; i++)
    {
        hash = ((hash + word[i]) * 997) % 26;
    }

    return hash;
}

class hashTable
{
    private:
        std::array<std::list<std::string>, 26> table;
        int tableLens[26];

    public:
        int (*hash) (std::string word);

        hashTable(){}

        int* get()
        {          
            for (int i = 0; i < 26; i++)
            {
                tableLens[i] = table[i].size();
            }

            return tableLens;
        }        

        void add(std::string word)
        {
            table[hash(word) % 26].push_front(word);
        }

        void fillFromFile(const char* Name)
        {
            std::string line;
        
            std::ifstream in(Name); 

            if (in.is_open())
            {
                while (getline(in, line))
                {
                    int lineLen = line.length();

                    int strLen = 0;

                    for (int i = 0; i < lineLen; i++)
                    {
                        if (strLen > 0 && (line[i] < 65 || (line[i] < 97 && line[i] > 90) || line[i] > 122))
                        {
                            std::string word = line.substr (i - strLen, strLen);
                            add(word);

                            strLen = 0;
                        }

                        else
                        {
                            strLen++;
                        }
                    }
                }
            }

            in.close();    
        }

        ~hashTable(){}
};

 
