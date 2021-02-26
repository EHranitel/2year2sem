#include <fstream>
#include "Hash-Table.hpp"

void createAndFillFileWithHashTable(std::string name, int* tableLens)
{
    std::ofstream file(name);

    for (int i = 0; i < 26; i++)
    {
        file << (tableLens[i]) << std::endl;
    }
    
    file.close();  
}

int main()
{
    hashTable table0;
    hashTable table1;
    hashTable table2;

    table0.hash = &standartHash;
    table1.hash = &hash1;
    table2.hash = &hash2;

    table0.fillFromFile("Text.txt");
    table1.fillFromFile("Text.txt");
    table2.fillFromFile("Text.txt");

    createAndFillFileWithHashTable("standartHash", table0.get());
    createAndFillFileWithHashTable("hash1", table1.get());
    createAndFillFileWithHashTable("hash2", table2.get());
}   