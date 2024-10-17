#include<stdio.h>
#include<conio.h>
int main()
{
    char str[100];
    int i, count=0, countChar=0;
    int countUpper=0, countLower=0, countDigit=0, countVowel=0;
    int countSpace=0, countWord=0, countLine=0, countConsonant=0;
    printf("Enter any string: ");
    gets(str);
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]>=65 && str[i]<=90)
        {
            countUpper++;

        }
        else if(str[i]>=97 && str[i]<=122)
        {
            countLower++;
        }
        else if(str[i]>=48 && str[i]<=57)
            countDigit++;
        else if(str[i]==' ')
            countSpace++;
        else if(str[i]=='\n')
            countLine++;
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' ||
           str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' ||
           str[i]=='O' || str[i]=='U')
            countVowel++;
        if(str[i]!=' ')
            count++;
        else
        {
            if(count!=0 && str[i+1]!='\0')
                countWord++;
            count = 0;
        }
        countChar++;
    }
    countConsonant = (countUpper+countLower) - countVowel;
    printf("\nTotal Character = %d", countChar);
    printf("\nTotal Uppercase Character = %d", countUpper);
    printf("\nTotal Lowercase Character = %d", countLower);
    printf("\nTotal Vowel = %d", countVowel);
    printf("\nTotal Consonant = %d", countConsonant);
    printf("\nTotal Digit = %d", countDigit);
    printf("\nTotal Space = %d", countSpace);
    printf("\nTotal Word = %d", countWord+1);
    printf("\nTotal Line = %d", countLine);
    getch();
    return 0;
}
