#include<stdio.h>
#include<string.h>

int main()
{
    char a[10];
    printf("\nEnter a Subject Code in Upper Case with no space: ");
    scanf("%s",&a);

    if(strcmp(a, "CSE3141")==0)
    {
        printf("Compiler Design\n");
    }
    else if(strcmp(a, "CSE3111")==0)
    {
        printf("System analysis and Design\n");
    }
    else if(strcmp(a, "CSE3131")==0)
    {
        printf("Digital Signal Processing\n");
    }
    else if(strcmp(a, "CSE3121")==0)
    {
       printf("Database Management\n");
    }


    else if(strcmp(a, "CSE3151")==0)
    {
        printf("Computer Networks\n");
    }
    else if(strcmp(a, "CSE3152")==0)
    {
        printf("Computer Networks Lab\n");
    }
    else if(strcmp(a, "CSE3122")==0)
    {
       printf("Database Management Lab\n");
    }



    else if(strcmp(a, "CSE3132")==0)
    {
        printf("Digital Signal Processing Lab\n");
    }
    else if(strcmp(a, "CSE3142")==0)
    {
       printf("Compiler Design Lab\n");
    }


    else
    {
        printf("Wrong Input\n");
    }


    return 0;
}
