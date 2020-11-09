#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "stack.h"

using namespace std;
string readFile();

int main()
{
    string str = readFile(); // read the input file to a string
    cout << "\n\t\t\t\t\t\tQ6\n\nold strings : " << str << endl;
    string str_reversed = "";
    Stack word = Stack();
    // loop on all string chars
    for (int i = 0; i < str.length(); i++) {
        // if the string is alpha or a (') push it into the stack
        if (isalpha(str[i]) || str[i] == '\'') {
            word.push(str[i]);
        }
        // else = the word is done : pop all items from the stack to the reversed string.
        else {
            while (!word.isEmpty()) {
                str_reversed += word.pop();
            }
            str_reversed += str[i];
        }
    }
    cout << "\nnew strings : " << str_reversed << endl;
}

string readFile() {
    ifstream inFile;
    inFile.open("input.txt"); // open the file input.txt
    stringstream strStream;
    strStream << inFile.rdbuf(); // read the file
    return strStream.str(); // return it as string
}
