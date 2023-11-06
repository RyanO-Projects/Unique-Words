#include <iostream>
#include <set>
#include <fstream>
// I've read that 'using namespace std' is considered bad practice so from here
// onward I will be omitting any uses of it in my code.

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
        for(int i = 0; i < word.size(); i++){
            if(isalnum(word[i]))
                charWord += word[i];
        }
        words.insert(charWord);
    }

    for(std::string element : words){
        std::cout << element << std::endl;
    }
}