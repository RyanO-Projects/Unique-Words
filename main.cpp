#include <iostream>
#include <set>
#include <fstream>
// I've read that 'using namespace std' is considered bad practice so from here
// onward I will be omitting any uses of it in my code.

// Function prototype for handling strings with '-' in them
void hyphenatedWords(std::string, std::set<std::string>*);

int main(){
    std::ifstream inFile("TheRaven.txt");
    std::set<std::string> words;
    std::string line;

    // Ensure file exists
    if(inFile)
        std::cout << "File exists, continuing operation." << std::endl;
    else{
        std::cout << "File not found, exiting program." << std::endl;
        exit(0);
    }


    std::string word;    
    // While there are words in the file
    while(inFile >> word){
        std::string charWord = "";
        bool hyphen = false;

        // Find if the current word is hyphenated, pass to hyphenatedWords() if true.
        for(char letter : word){
            if((letter == '-' || letter == '!') && hyphen == false){
                hyphenatedWords(word, &words);
                hyphen = true;
            }
        }


        // If current word is not hyphenated, nothing else needs to be done.
        if(!hyphen){
            for(char letter : word){
                if(isalnum(letter))
                    charWord += letter;
            }
        }
        
        words.insert(charWord);
    }

    // Display words in the set
    for(std::string element : words){
        std::cout << element << std::endl;
    }
}

// Function that takes hyphenated words, splits them into individual words, adds them to the set.
void hyphenatedWords(std::string wordString, std::set<std::string> *wordSet){
    std::string newWord;

    // Iterate through each character in wordString
    for(char letter : wordString){
        if(isalpha(letter)){
            newWord += letter;
        }
        else if(letter == '-'){
            wordSet->insert(newWord);
            newWord = "";
        }
    }

    // To catch last word in string
    if(!newWord.empty())
        wordSet->insert(newWord);
}