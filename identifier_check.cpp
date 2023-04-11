//This code is for identifying whether the given input is an identifier or not.


#include<iostream>
using namespace std;

int main()
{
    char a[100];
    int flag=0, i=1;

    // Prompt the user to enter a value
    cout<<"Enter the value"<<endl;
    cin>>a;

    // Check if the first character is a letter
    if(isalpha(a[0]))
        flag = 1;
    else
        cout<<"it is not an identifier"<<endl;

    // Loop through the rest of the characters in the string
    while(a[i]!= '\0')
    {
        // If the character is not a digit or a letter, it's not an identifier
        if(!isdigit(a[i])&&!isalpha(a[i]))
            flag=0;
        break;
    }

    // If flag is still 1, then it's an identifier, otherwise it's not
    if(flag==1)
        cout<<"Its an identifier"<<endl;
}
