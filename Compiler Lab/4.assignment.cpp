/*Input a c program and determine the tokens type.
Sample input output:-
1. if,for,void,int	keyword
2. main,printf,scanf	function
3.120			integer
4.123.20		float
5.xyz,abc2xzy		identifier
**************************************************/
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char *keyword[]={
			"asm","auto","break","case","cdecl","char","class",			"const","continue","cs","default","delete","do","double","_ds","else",
			"enum","_es","extern","_export","far","float","for"," friend",
			"goto","huge","if","inline","int","interrupt","_loadds","long"," near",
			"new","operator","pascal","private","protected","public","register",
			"return"," _saveregs","_seg","short","signed","sizeof","_ss","static",
			"struct","switch"," template","this","typedef","union","unsigned",
			"virtual","void","volatile","while"
			};

	char *function[]={
			  "main","clrscr","printf","scanf","gets","puts","fopen",
			  "fprintf","fscanf","getch"};
	FILE *fp,*fout;
	char st[20],ch;
	int func,found,k,isconst;
	//printf("Enter string");
	//gets(st);
	fp=fopen("Input.txt","r");
	fout=fopen("Output.txt","w");
	int i=0;
	while(st[i]!='\0')
	{
		ch=st[i];
		if(i==0)
		{
			if(ch>='0' && ch<='9')
				isconst=1;
			else
				isconst=0;
		}
		if(isconst)
		{
			if(ch>='0' && ch<='9')
			{
				st[i++]=ch;
				continue;
			}
			else
			{
				st[i]=0;
				//printf("Conostant: ");
				fprintf(fout,"\n%-16s-->\tConstant.\n",st);
				i=0;
				isconst=0;
			}
		}
		if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') )
			st[i++]=ch;
		else
		{
			st[i]=0;
			if(i)
			{
				/* Print keyword*/

				found=0;
				for(k=0;k<60;k++)// 60 is the length of keyword

				if(strcmp(st,keyword[k])==0)
					{
						found=1;
						break;
					}
					if(found)
					{
						//printf("Keyword");
						fprintf(fout,"\n%-16s-->\tKeyword.\n",st);
					}
				/* Print function */
				func=0;
				for(k=0;k<10;k++)

					if(strcmp(st,function[k])==0)
					{
						func=1;
						break;
					}
					if(func)
						//printf("function");
						fprintf(fout,"\n%-16s-->\tFunction.\n",st);


				if(found==0 && func==0)
					//printf("Idetifier");

					fprintf(fout,"\n%-16s-->\tIdentifier.\n",st);
			}
			i=0;
		}
	}
	return 0;

}
