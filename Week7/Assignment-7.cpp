#include <iostream>
#include <fstream>
#include <string>
int main() {
    
std::string fileName, word, newWord;
std::cout << "Please enter the input file name: ";
std::cin >> fileName;

std::cout << "Enter the word you want to count ";
std::cin >> word;

std::cout << "Enter the replacement word: ";
std::cin >> newWord;

std::ifstream inFile(fileName);
if (!inFile.is_open()) {
    std::cout << "CAUTION:" << fileName << " could not be found!" << std::endl;
    return 0;
}

std::ofstream outFile("output.txt");

int count = 0;
std::string currentWord;

while (inFile >> currentWord) {
    if (currentWord == word){
        outFile << newWord << " ";
        count++;
    }else {
        outFile << currentWord << " ";
    }
}
std::cout << "The word " << word << " was found " << count << " times" << std::endl;
std::cout << "The text has been saved";

inFile.close();
outFile.close();

return 0;
}