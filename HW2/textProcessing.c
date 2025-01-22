// gcc textProcessing.c -o run
// ./run ./test.txt
// or ./run ./textfile1.txt

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void processing(FILE *, int);
void toUpper(FILE *);

int main(int argc, char *argv[])
{
    char *fname = NULL;
    fname = argv[1];
    FILE *fp = NULL;
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("Error in opening a file...\n");
    }
    fseek(fp, 0, SEEK_END);
    int len = ftell(fp);
    // text processing functions
    fseek(fp, 0, SEEK_SET);
    processing(fp, len);
    // to upper case letters
    fseek(fp, 0, SEEK_SET);
    toUpper(fp);
    fclose(fp);
    return 0;
}

void processing(FILE *fp, int len)
{
    char ch;
    int lines = 0, characters = 0, upperLetters = 0, words = 0;
    int wordFlag = 0; // flag to represent whether the current character is in a word.
    if (len == 0)
        return;
    else
    {
        lines = 1;
        while ((ch = fgetc(fp)) != EOF)
        {
            if (ch == '\n')
            {
                lines++;
            }
            if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z'))
            {
                characters++;
            }
            if ((ch >= 'A' && ch <= 'Z'))
            {
                characters++;
                upperLetters++;
            }
            if (isalnum(ch)) // check if ch is a number or an alphabet
            {
                if (!wordFlag)
                {
                    words++;
                    wordFlag = 1;
                }
            }
            else if (ch == ' ' || ch == '\n' || ch == '\t')
            {
                wordFlag = 0;
            }
        }
        printf("lines = %d\tchar = %d\tupper = %d\twords = %d\n", lines, characters, upperLetters, words);
        return;
    }
}

void toUpper(FILE *fp)
{
    char ch;
    FILE *outFile = fopen("UPPER.txt", "w");
    if (outFile == NULL)
    {
        printf("Error in creating the file 'UPPER.txt'\n");
        return;
    }
    fseek(fp, 0, SEEK_SET);
    while ((ch = fgetc(fp)) != EOF)
    {
        fputc(toupper(ch), outFile);
    }
    fclose(outFile);
}