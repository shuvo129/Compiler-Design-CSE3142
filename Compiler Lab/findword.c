/**
 * C program to count total number of alphabets, digits
 * and special characters in a string
 */

#include <stdio.h>
#define MAX_SIZE 100 // Maximum string size


int main()
{
    char str[MAX_SIZE];
    int alphabets, digits, others, i;

    alphabets = digits = others = i = 0;


    /* Input string from user */
    printf("Enter any string : ");
    gets(str);

    /*
     * Check each character of string for alphabet, digit or special character
     */
    while(str[i]!='\0')
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
        {
            alphabets++;
        }
        else if(str[i]>='0' && str[i]<='9')
        {
            digits++;
        }
        else
        {
            others++;
        }

        i++;
    }

    printf("Alphabets = %d\n", alphabets);
    printf("Digits = %d\n", digits);
    printf("Special characters = %d", others);

    return 0;
}
