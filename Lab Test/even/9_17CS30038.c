//Yash Parag Butala	
//17CS30038
//PC No-9
/*
subproblem: max probabilty with P persons in completing the project will be max of prob by p persons(n<=p<P) and multiplying by probability ratios of changing number of persons in any one of the component
let dp(n,p) be person on each component with total persons=p;
let maxp(p) store max prob by p persons
dp(n,p)=0 	...for all nXp where (p<N)
maxp(p)=0	...for all nXp where (p<N)
dp(n,p)=1	...when p=N as only one possible way of distributing min 1 perswon to a component
maxp(p)=prod(p[i][1])	...when p=N 
maxp(p)=max(max(maxp(p_i)*(p[i][dp(p_i)+p-p_i])/(p[i][p_i])    for(i=1 to n))for(N<=p_i<p))
let p_i_max and i_max be corresponding obtained values
dp(n,p)=dp(n,p_i_max) for(n !=i )
dp(n,p)=dp(n,p_i_max)+p_i-p_i_max for(n==i)		  

*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N,P;
	scanf("%d%d",&N,&P);
	double **p;	
	p=(double**)malloc((N+1)*sizeof(double*));
	for(int i=0;i<=N;i++)
	{
		p[i]=(double*)malloc((P+1)*sizeof(double));
	}
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=P;j++)
		{
			if(i==0||j==0)
				p[i][j]=0;
			else
				scanf("%lf",&p[i][j]);
		}
	}
	int **dp;
	dp=(int**)malloc((N+1)*sizeof(int*));
	for(int i=0;i<=N;i++)
	{
		dp[i]=(int*)malloc((P+1)*sizeof(int));
	}

	double *maxp;
	maxp=(double*)malloc((P+1)*sizeof(double));
	for(int i=0;i<P;i++)
		maxp[i]=1.0;

	for(int i=1;i<=N;i++)
	{
		dp[i][N]=1;
		maxp[N]=p[i][1]*maxp[N];
	}
	double max,tmp;
	int indi,indk;	
	for(int j=N+1;j<=P;j++)
	{
		max=0;
		for(int k=N;k<j;k++)
		{
			for(int i=1;i<=N;i++)
			{
				tmp=maxp[k]*(p[i][dp[i][k]+j-k])/(p[i][dp[i][k]]);
				if(tmp>max)
				{
					max=tmp;
					indi=i;
					indk=k;
				}
			}
		}
		maxp[j]=max;
		for(int i=1;i<=N;i++)
		{
			dp[i][j]=dp[i][indk];
		}	
		dp[indi][j]+=j-indk;
		
		
	}
	printf("max success probability is:%lf\n",maxp[P]);
	printf("assignment of people for max success probability:\n");
	for(int i=1;i<=N;i++)
	{
		printf("counter %d::%d\n",i,dp[i][P]);
	}
	return 0;	
		
	
}
