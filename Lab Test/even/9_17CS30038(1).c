//Yash Parag Butala
//17CS30038
//PC no=9
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b)(a>b?a:b)
int main()
{
	char input1[100],input2[100],output[100];
	int DP[100][100];
	int i,j;
	int m,n;
	printf("enter m:");
	scanf("%d",&m);
	printf("enter n:");
	scanf("%d",&n);
	printf("enter A:");
	scanf(" %s",input1);
	printf("enter B:");
	scanf(" %s",input2);
	for(i=0;i<=strlen(input1);i++)
		for(j=0;j<=strlen(input2);j++)
		{
			if(i==0 || j==0)
				DP[i][j]=0;
			else if(input1[i-1]==input2[j-1])
				DP[i][j]=DP[i-1][j-1]+1;
			else
				DP[i][j]=max(DP[i][j-1],DP[i-1][j]);
		}
	int temp=DP[strlen(input1)][strlen(input2)];
	printf("\nLength of LCS is %d",DP[strlen(input1)][strlen(input2)]);
	
	return 0;
}


