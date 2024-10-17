
/*  This is the program for finding the vowels and consotants in a 
given string */


#include<stdio.h>
#include<string.h>

typedef struct
{
	char st[20];
}string;

int vowel(char ch)
{
	if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'
		||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U')
				return 1;
	return 0;
}

int main()
{
	char line[100],v[100],c[100],v2[30],c2[30];
	int n,l,i,j,k,nv=0,nc=0,t;

	printf("Enter the string:\n");
	gets(line);
	n= strlen(line);

	for(i=0; i<n; i++)
	{
		if(line[i]=='&'||line[i]==' ')
			continue;
		else if(vowel(line[i]))
		{
			v[nv]=line[i];
			nv++;
		}
		else
		{
			c[nc]=line[i];
			nc++;
		}
	}

	k=0;
	for(i=0; i<nv; i++)
	{
		int flag=1;
		for(j=i-1; j>=0; j--)
		{
			if(v[j]==v[i]+32||v[j]==v[i]-32||v[j]==v[i])
				flag=0;
		}
		if(flag)
			v2[k++]=v[i];

	}
	v2[k]='\0';

	k=0;
	for(i=0; i<nc; i++)
	{
		int flag=1;
		for(j=i-1; j>=0; j--)
		{
			if(c[j]==c[i]+32||c[j]==c[i]-32||c[j]==c[i])
				flag=0;
		}
		if(flag)
			c2[k++]=c[i];
	}
	c2[k]='\0';

	string word1[100],word2[100],stv[100],stc[100];
	t=0;
	j=0;
	for(i=0; i<=n; i++)
	{
		if(line[i]==' '|| line[i]=='\0')
		{
			word1[t].st[j]='\0';
			t++;
			j=0;
			continue;
		}
		word1[t].st[j]=line[i];
		j++;
	}

	k=0;
	for(i=0; i<t; i++)
	{
		l=strlen(word1[i].st);
		int count=0;
		for(j=0; j<l; j++)
		{
			char ch=word1[i].st[j];
			if(vowel(ch))
				count++;
		}
		if(count>2)
		{
			strcpy(word2[k].st,word1[i].st);
			k++;
		}
	}

	int sv=0,sc=0;
	for(i=0; i<t; i++)
	{
		if(vowel(word1[i].st[0]))
			strcpy(stv[sv++].st,word1[i].st);
		else if(word1[i].st[0]=='&')
			continue;
		else
			strcpy(stc[sc++].st,word1[i].st);
	}

	printf("\nNumber of vowels: %d\n",nv);
	printf("\nNumber of consonents: %d\n",nc);

	printf("\nVowels are: ");
	puts(v2);

	printf("\nConsonents are: ");
	puts(c2);

	printf("\nWords are:\n");
	for(i=0; i<t; i++)
		puts(word1[i].st);
	printf("\nWords having more than two vowels:\n");
	for(i=0; i<k; i++)
		puts(word2[i].st);

	printf("\nWords starts with vowel:\n");
	for(i=0; i<sv; i++)
		printf("%s ",stv[i].st);

	printf("\nWords starts with consonent:\n");
    	for(i=0; i<sc; i++)
		printf("%s ",stc[i].st);
	printf("\n");

	return 0;
}
