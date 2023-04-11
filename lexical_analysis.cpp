/*This C++ code reads a file named "pro.txt" and identifies keywords and identifiers in the file.
It uses an array of C++ keywords and checks each word in the file against that array. 
If the word is a C++ keyword, it is identified as a keyword; otherwise, it is identified as an identifier.
The code also identifies basic arithmetic operators (+,-,*,/,%). Finally, the code prints the result to the console.*/

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

// function to check if a given string is a keyword
int isKeyword(char buffer[]){
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
    "do","double","else","enum","extern","float","for","goto",
    "if","int","long","register","return","short","signed",
    "sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"};
    int i, flag = 0;
    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(){
    char ch, buffer[15], operators[] = "+-*/%="; // operators to be recognized
    ifstream fin("pro.txt"); // input file stream
    int i,j=0;
    if(!fin.is_open()){ // check if file could be opened
        cout<<"error while opening the file\n";
        exit(0);
    }
    while(!fin.eof()){ // while not end of file
        ch = fin.get(); // read one character at a time

        for(i = 0; i < 6; ++i){ // loop through all operators
            if(ch == operators[i])
                cout<<ch<<" is operator\n";
        }

        if(isalnum(ch)){ // if character is alphanumeric
            buffer[j++] = ch; // store it in buffer
        }
        else if((ch == ' ' || ch == '\n') && (j != 0)){ // if space or newline and buffer is not empty
            buffer[j] = '\0'; // add null terminator to end of buffer
            j = 0; // reset buffer index

            if(isKeyword(buffer) == 1) // check if buffer is a keyword
                cout<<buffer<<" is keyword\n";
            else
                cout<<buffer<<" is identifier\n"; // if not keyword, then it's an identifier
        }
    }
    fin.close(); // close file
    return 0;
}
