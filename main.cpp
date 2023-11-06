#include <iostream>
#include <set>
#include <fstream>
// I've read that 'using namespace std' is considered bad practice so from here
// onward I will be omitting any uses of it in my code.

int main(){
    std::ifstream inFile("TheRaven.txt");

    if(inFile)
        std::cout << "File exists, continuing operation." << std::endl;
    else{
        std::cout << "File not found, exiting program." << std::endl;
        exit(0);
    }

    while(inFile){

    }
}