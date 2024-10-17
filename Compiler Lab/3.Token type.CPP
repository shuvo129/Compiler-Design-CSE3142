/* Write a program which converts a word to its equivalent token. */

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int isLetter(char ch)
{
	if (ch>='a' && ch<='z')
	   return 1;
	if (ch>='A' && ch<='Z')
	   return 1;
	if (ch=='_')
	   return 1;

   return 0;
}

int isDigit(char ch)
{
	if (ch>='0' && ch<='9')
		return 1;

	return 0;
}

int allDigit(char st[])
{
	int i,l;

    l=strlen(st);
    for (i=0; i<l; i++)
		if (st[i]<'0' || st[i]>'9')
			return 0;

		return 1;
}

int onePoint(char st[])
{
	int i,l,p=0;

    l=strlen(st);
    for (i=0; i<l; i++)
    {
		if (st[i]=='.')
           p++;
        else if (st[i]<'0' || st[i]>'9')
           return 0;
    }

   if (p==1)
       return 1;
   else
       return 0;
}

int isOperator(char st[])
{
	if ( (st[0]=='+' || st[0]=='-' || st[0]=='*' || st[0]=='/' || st[0]=='%')
        && st[1]=='\0')
        return 1;
   return 0;
}


int main()
{
	char *key[]={
	             "asm", "auto", "break", "case", "cdecl", "char",
                 "class", "const", "continue", "_cs", "default", "delete",
                 "do", "double", "_ds", "else", "enum", "_es",
                 "extern", "_export", "far", "_fastcall", "float", "for",
                 "friend", "goto", "huge", "if", "inline", "int",
                 "interrupt", "_loadds", "long", "near", "new", "operator",
                 "pascal", "private", "protected", "public", "register", "return",
                 "_saveregs", "_seg", "short", "signed", "sizeof", "_ss",
                 "static", "struct", "switch", "template", "this", "typedef",
                 "union", "unsigned", "virtual", "void", "volatile", "while"
				};

	char *function[]={"main","clrscr","printf","scanf","gets","puts",
						"fopen","fprintf","fscanf","getch"
					};

    char st[30];
    int i,l,flag,found;
	for(;;)
	{
    //printf("Enter type: ");
    scanf("%s",st);
	
    l=strlen(st);
    if (isLetter(st[0]))
    {
		flag=1;
        for (i=1; i<l; i++)
             if (isLetter(st[i])==0 && isDigit(st[i])==0)
                 flag=0;

             if (flag==1)
			{
	             found=0;
	             for (i=0; i<60; i++)
	                 if (strcmp(key[i],st)==0)
	                     found=1;

	                 if (found==1)
					 {
	                        printf("Keyword.\n");
							//exit(1);
							continue;
						//	break;
						//	goto up;
					 }

						int found2=0;
					for(i=0;i<10;i++)
					{
						if(strcmp(function[i],st)==0)
							found2=1;
					}
						
				
					if(found2==1)
						printf("Function\n");
	                 else
	                      printf("Identifier.\n");
		}
             else
                  printf("Undefined.\n");
    }
    else if (allDigit(st))
		printf("Integer.\n");
    else if (onePoint(st))
        printf("Float.\n");
    else if (isOperator(st))
		printf("Arithmetic Operator.\n");
    else if (strcmp(st,"++")==0)
		printf("Increment operator.\n");
    else if (strcmp(st,"--")==0)
		printf("Decrement operator.\n");
	else 
		printf("Undefined.\n");
	}	
	return 0;
}


