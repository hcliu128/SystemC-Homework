// gcc pointer.c -o pointer
// ./pointer 100

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please provide memory size as argument.\n");
        return 1;
    }
    int size = atoi(argv[1]);
    char *block = (char *)malloc(size * 1);
    if (block == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    char ch = 'A'; // first character
    for (int i = 0; i < size; i++)
    {
        block[i] = ch;
        if (ch == 'Z')
        {
            ch = '1';
        }
        else if (ch == '9')
        {
            ch = 'A';
        }
        else
        {
            ch++;
        }
    }
    printf("Generated string: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%c", block[i]);
    }
    printf("\n");
    int *intPtr = (int *)block;
    int intCount = size / sizeof(int);
    int index = 0;
    printf("Memory content (int) and (int - 1): \n");
    while (index < intCount)
    {
        int current_value = intPtr[index];
        printf("%d : %d\n", current_value, current_value - 1);
        index++;
    }
    free(block);
    return 0;
}