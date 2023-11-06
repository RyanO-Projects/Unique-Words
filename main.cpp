#include <iostream>
#include <set>
#include <fstream>
// I've read that 'using namespace std' is considered bad practice so from here
// onward I will be omitting any uses of it in my code.

// Function prototype for handling strings with '-' in them
std::string splitWords(std::string, std::set<std::string>);

int main(){
    std::ifstream inFile("TheRaven.txt");
    std::set<std::string> words;
    std::string line;

    if(inFile)
        std::cout << "File exists, continuing operation." << std::endl;
    else{
        std::cout << "File not found, exiting program." << std::endl;
        exit(0);
    }

    std::string word;    
    std::string charWord;
    while(inFile >> word){
        charWord = "";
        bool hyphen = false;

        for(int i = 0; i < word.size(); i++){
            if(word[i] == '-')
                splitWords(word, words);
                hyphen = true;
        }

        if(!hyphen){
            for(int i = 0; i < word.size(); i++){
                if(isalnum(word[i]))
                    charWord += word[i];
            }
        }
        
        words.insert(charWord);
    }

    for(std::string element : words){
        std::cout << element << std::endl;
    }
}


std::string splitWords(std::string wordString, std::set<std::string> *wordSet){
    int hyphenCount = 1;
    
    for(int i = 0; i < wordString.size(); i++)
    {
        if(wordString[i] == '-')
            hyphenCount += 1;
    }
}