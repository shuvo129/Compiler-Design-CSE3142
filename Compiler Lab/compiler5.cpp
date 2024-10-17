/*Write a program which checks a validaty of expression derived by a
grammar.

RESULT:
~~~~~~~
	Input: 2+3*5
	Output: VALID
	Input:	6++12
	Output:	INVALID
*********************************************/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
   char input[100],stack[100];
   int i,j=0,l;

   //clrscr();
   printf("Enter a string: ");
   gets(input);

   l=strlen(input);
   for (i=0; i<l; i++)
   {
	   stack[j++]=input[i];

      // grammar 6	E-->id
      if ((j>=1 && stack[j-1]>='0' && stack[j-1]<='9')||(j>=1 && stack[j-1]>='a' && stack[j-1]<='z'))
      {
			while((input[i+1]>='0' && input[i+1]<='9')||(j>=1 && input[i+1]>='a' && input[i+1]<='z'))
				i++;
			stack[j-1]='E';
      }
      // grammar 1	E-->E+E
      if (j>=3 && stack[j-1]=='E' && stack[j-2]=='+' && stack[j-3]=='E')
		j-=2;
      // grammar 2	E-->E-E
      if (j>=3 && stack[j-1]=='E' && stack[j-2]=='-' && stack[j-3]=='E')
		j-=2;
      // grammar 3	E-->E*E
      if (j>=3 && stack[j-1]=='E' && stack[j-2]=='*' && stack[j-3]=='E')
      j-=2;
      // grammar 4	E-->E/E
      if (j>=3 && stack[j-1]=='E' && stack[j-2]=='/' && stack[j-3]=='E')
		j-=2;
      // grammar 5	E-->(E)
      if (j>=3 && stack[j-1]==')' && stack[j-2]=='E' && stack[j-3]=='(')
      {
			stack[j-3]='E';
			j-=2;
      }
   }

   if (j==1 && stack[0]=='E')
		printf("VALID\n");
   else
		printf("INVALID\n");
   //getch();
}
