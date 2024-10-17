/* Write a program that will justify a given programm Whether it is 
syntactically correct or incorrect according
to the following grammar:
     S->SUB+PRED
     SUB->N|P|NP
     PRED->V|V+OBJ
     OBJ->N|NP
     NP->ART+N
     ART->a|an|the
     N->Shamim|Hossain|boy|girl|book|rice|cat|football|mango
     P->I|he|you|the|it
     V->am|is|are|read|play|eat

Sample input & output:-

input:  He is taking a book.
output: Valid
input:  A book is taking a cow.
output: Valid (Because the context free grammar does not check 
	the syntactical problem only check the grammartical rule).
input: The Rahim in going.
output: Invalid
***********************************************************/

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<iostream.h>


struct word{
	char name[20];
	char type[10];
};

int main()
{
	int i,j,a,n,p,sub,verb,ob,a_ob,n_ob,check;
	FILE *file;
	struct word w;

	char s[200],temp[10][25];


	a=0;
	n=0;
	p=0;
	sub=0;
	verb=0;
	check=0;
	ob=0;
	a_ob=0;
	n_ob=0;

	printf("Enter a sentance.\n");
	gets(s);
	i=0;
	int k=0;

	//tokenizing
	while(s[i-1]!='\0')
	{
		j=0;
		while(s[i]!=' ')
		{
			if(s[i]=='\0')
				break;
			temp[k][j++]=s[i++];
		}
		i++;
		temp[k][j]='\0';
	//	cout<<endl<<temp[k];
		k++;
	}

	i=0;
	// Subject find
    np:
	file=fopen("name.txt","r");
	while(fscanf(file,"%s %s",w.name,w.type)!=EOF)
	{
		if(sub==0 && i<k)
		{
			if((strcmp(temp[i],w.name)==0) && (strcmp(w.type,"art")==0))
				a=1;
			else if((strcmp(temp[i],w.name)==0) && (strcmp(w.type,"noun")==0))
				n=1;
			else if((strcmp(temp[i],w.name)==0) && (strcmp(w.type,"pro")==0))
				p=1;

			if((a&&n) || n || p)
				sub=1;
		}
	}
	i++;
	fclose(file);

	if(i==1 && a == 1 && sub == 0)
		goto np;

	// find verb

	file=fopen("name.txt","r");
	while(fscanf(file,"%s %s",w.name,w.type)!=EOF)
	{
		if(verb==0 && i<k)
			if(sub==1)
			{
				if((strcmp(temp[i],w.name)==0) && (strcmp(w.type,"verb")==0))
					verb=1;
			}
			else
			{
					printf("Syntactically Incorrect \n");
					return 0;
			}
	}
	i++;

np2:
	file=fopen("name.txt","r");
	while(fscanf(file,"%s %s",w.name,w.type)!=EOF)
	{
		if(ob==0 && i<k)
			if(sub==1 && verb==1)
			{
				if((strcmp(temp[i],w.name)==0) && (strcmp(w.type,"art")==0))
					a_ob=1;
				else if((strcmp(temp[i],w.name)==0) && (strcmp(w.type,"noun")==0))
					n_ob=1;
				if((a_ob*n_ob) || n_ob)
					ob=1;
			}
	}

	fclose(file);

	if(a_ob==1 && ob==0 && i<k)
	{
		i++;
		goto np2;
	}

	if(sub==1 && verb==1 && i==k)
		printf("Syntactically Correct \n");
	else if(sub==1 && verb==1 && ob==1 && i==k-1)
		printf("Syntactically Correct \n");
	else
		printf("Incorrect\n");

	cout<<endl;
	//getch();
	return 0;

}

