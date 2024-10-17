/* This is the program for justifing a expression is valid or invalid */



#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
	char st[100];

	cout<<"Enter any Expression: "<<endl;
	gets(st);

	int l=strlen(st);

	int fast=0,last=0;

	if(st[0]=='+' || st[0]=='*' || st[0]=='/' || st[0]=='^' ||st[0]==')')
	{
		fast=1;  // true
	}

	if(st[l-1]=='+' || st[l-1]=='-' || st[l-1]=='*' || st[l-1]=='/' || st[l-1]=='^' || st[l-1]=='(')
	{
		last=1;  //true
	}

	int many=0;  //for false
	for(int i=0;i<l;i++)
	{
		if(st[i]=='+' || st[i]=='-' || st[i]=='*' || st[i]=='/' || st[i]=='^')
			if(st[i+1]=='+' || st[i+1]=='-' || st[i+1]=='*' || st[i+1]=='/' || st[i+1]=='^')
				many=1;
	}

	int count_fast=0,count_last=0;
	for(i=1;i<l;i++)
	{
		if(st[i-1]=='(')
		{
			count_fast++;
		}

		if(st[i]==')')
		{
			count_last++;
		}
	}

	int equal=0;
	if(count_fast!=count_last)
		equal=1; // if brakets are equal

	int before=0;

	for(i=0;i<l;i++)
	{
		if(st[i]=='(')
			before++;
		if(before)
		{
			if(st[i]==')')
				before--;
		}
	}

	int sequence=0;
	for(i=0;i<l;i++)
	{
		if(st[i]=='(' && st[i+1]==')')
			sequence=1;
	}

	if(fast==1 || last==1 || many==1 || equal==1 || sequence==1 || before!=0)
		cout<<"Invalid expression."<<endl;
	else
		cout<<"Valid expression."<<endl;


	return 0;
}

