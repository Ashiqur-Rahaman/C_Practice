/*
The program takes the file path as input, reads the content of the file, and prints it to the console.
Then it reads each word in the file, converts it to lowercase, removes any trailing punctuation, and counts the number of occurrences of each unique word.
Finally, the program prints the total number of unique words and the number of new lines in the file.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS   1000
#define LSIZ 128
#define RSIZ 10

int main()
{
    // Declare variables and arrays
    char line[RSIZ][LSIZ], x[1000][1000];
    char ch;
    FILE *fptr;
    int i = 0;
    int tot = 0,y=0;
    char path[100];
    int len, index, isUnique;
    char words[MAX_WORDS][50];
    char word[50];
    int count[MAX_WORDS];

    // Prompt the user to enter the file path
    printf("Enter file path: ");
    scanf("%s", path);

    // Open the file for reading
    fptr = fopen(path, "r");

    // Read each line of the file and store it in the line array
    while(fgets(line[i], LSIZ, fptr))
    {
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
    printf("\nThe content of the file %s  are : \n", path);

    // Print the content of the file
    for(i = 0; i < tot; ++i)
    {
        printf(" %s\n", line[i]);
    }
    printf("\n");

    // Re-open the file for reading
    fptr = fopen(path, "r");

    // Check if the file was opened successfully
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read privileges.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the count array to 0
    for (i=0; i<MAX_WORDS; i++)
        count[i] = 0;

    // Read each word in the file and count the number of occurrences of each unique word
    index = 0;
    while (fscanf(fptr, "%s", word) != EOF)
    {
        // Convert word to lowercase and remove any trailing punctuation
        strlwr(word);
        len = strlen(word);
        if (ispunct(word[len - 1]))
            word[len - 1] = '\0';

        // Check if the word is unique, and if so, add it to the words array
        // Otherwise, increment the count for the existing word
        isUnique = 1;
        for (i=0; i<index && isUnique; i++)
        {
            if (strcmp(words[i], word) == 0)
                isUnique = 0;
        }
        if (isUnique)
        {
            strcpy(words[index], word);
            count[index]++;
            index++;
        }
        else
        {
            count[i - 1]++;
        }
    }

    // Close the file
    fclose(fptr);

    // Calculate and print the total number of unique words in the file
    int size = sizeof line / sizeof line[0];
    printf("Total number of unique word : %u", size);

    // Count and print the number of new lines in the file
    for (ch = getc(fptr); ch != EOF; ch = getc(fptr))
        if (ch == '\n')
            y = y + 1;
    printf("\nnumber of new line : %d", y);

    // Exit the program
    return 0;
}
