#include<stdio.h>

int main()
{
	char str[100][1000];
	int size;
	printf("Enter the number of strings: ");
	scanf("%d", &size);

	int i,j, k;
	for(k=0; k<size; k++)
	{
		printf("Input String_%d: ", k+1);
		scanf("%s", str[k]);
	}


	printf("\n\n");
	for(k=0; k<size; k++)
	{
		int len = strlen(str[k]);
		int flag=0;
		for(i=0, j=len-1; i<len; i++, j--)
		{
			if(str[k][i]!=str[k][j])
			{
				flag = 1;
				break;
			}
			else if(str[k][i] == str[k][j])
			{
				char ch = str[k][i];
				if(ch=='A' || ch=='H' || ch=='I' || ch=='M' || ch=='O' || ch=='T' || ch=='U'
				|| ch=='V' || ch=='W'|| ch=='X'|| ch=='Y' )
				{
					flag=0;
				}
				else
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==0)
		{
			printf("\n%s: Mirror word \n", str[k]);
		}
	}
	return 0;
}
