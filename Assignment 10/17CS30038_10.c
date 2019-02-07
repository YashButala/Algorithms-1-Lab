#include<stdio.h>
#include<stdlib.h>
typedef struct _rwd
{
	int start_time;
	int service_time;
}reqWD;	
typedef struct _rwd1
{
	int start_time;
	int service_time;
	int id;	
}reqWD1;
typedef struct _rsd 
{
	int service_time;
	int target_time;
} reqSD;
typedef struct _rsd1 
{
	int service_time;
	int target_time;
	int id;
} reqSD1;

void merge1(reqWD1 a[],int low ,int mid,int high)
{
    int i=low,j=mid+1;
    int k=0;
    reqWD1 *b=(reqWD1*)malloc((high-low+1)*sizeof(reqWD));
    while(i<=mid&&j<=high)
    {
        if(a[i].start_time>a[j].start_time)
        {
            b[k]=a[j];
            j++;
            k++;
        }
        else
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for(i=low,k=0;i<=high;i++,k++)
    {
        a[i]=b[k];
    }
    return ;
}
void sort1(reqWD1 a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        sort1(a,low,mid);
        sort1(a,mid+1,high);
        merge1(a,low,mid,high);
    }
}
void fun1(reqWD1* A,int n)
{
	reqWD1* B=(reqWD1*)malloc(sizeof(reqWD1)*n);
	int *keeper=(int* )malloc(n*sizeof(int));//stores counter no of ith index
	int i,j,index,max_count=1;
	B[0]=A[0];
	keeper[0]=0;
	for(i=1;i<n;i++)
	{
		for(j=0;j<max_count;j++)
		{
			if(B[j].start_time+B[j].service_time<=A[i].start_time)
			{
				B[j]=A[i];
				keeper[i]=j;
			//	count+++;
			//	maxcount++;
				break;
			}
			else
				continue;
			
		}
		if(j==max_count)
		{
			B[j]=A[i];
			keeper[i]=max_count;
	//		count++;
			max_count++;
		}	
	}
/*	for(int i=0;i<n;i++)
		printf("%d\n",keeper[i]);*/
	for(i=0;i<max_count;i++)
	{
		printf("counter %d::\n",i);
		for(j=0;j<n;j++)
		{
			if(keeper[j]==i)
			{
				printf("%d\t%d\t%d\n",A[j].id,A[j].start_time,A[j].start_time+A[j].service_time);
			}	
		}
	}
	return ;
}
void merge2(reqSD1 a[],int low ,int mid,int high)
{
    int i=low,j=mid+1;
    int k=0;
    reqSD1 *b=(reqSD1*)malloc((high-low+1)*sizeof(reqWD));
    while(i<=mid&&j<=high)
    {
        if(a[i].target_time>a[j].target_time)
        {
            b[k]=a[j];
            j++;
            k++;
        }
        else
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for(i=low,k=0;i<=high;i++,k++)
    {
        a[i]=b[k];
    }
    return ;
}
void sort2(reqSD1 a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        sort2(a,low,mid);
        sort2(a,mid+1,high);
        merge2(a,low,mid,high);
    }
}
void fun2(reqSD1* A,int n)
{
	int start_time=0;
	int end_time=0;

	for(int i=0;i<n;i++)
	{
		start_time=end_time;
		end_time=start_time+A[i].service_time;
		printf("request %d::  ",A[i].id);
		printf("%d  %d\n",start_time,end_time);	
		
	}
	return ;
}
int main()
{
	int n;
	printf("Enter the number of requests over weekday:\n");
	scanf("%d",&n);
	reqWD *rw=(reqWD*)malloc(n*sizeof(reqWD));
	reqWD1* RW=(reqWD1*)malloc(n*sizeof(reqWD1));
	printf("Enter the start time and length for each of the requests\n");
	for(int i=0;i<n;i++)
	{	
		printf("request no %d::",i);
		scanf("%d%d",&RW[i].start_time,&RW[i].service_time);
		RW[i].id=i;
		rw[i].start_time=RW[i].start_time;
		rw[i].service_time=RW[i].service_time;
		
	}			
	sort1(RW,0,n-1);
/*	for(int i=0;i<n;i++)
	{
		printf("%d: %d :: %d\n",RW[i].id,RW[i].start_time,RW[i].service_time);	
	}*/
	fun1(RW,n);



	int m;
	printf("Enter the number of requests over Saturday:\n");
	scanf("%d",&m);
	reqSD *sw=(reqSD*)malloc(m*sizeof(reqSD));
	reqSD1* SW=(reqSD1*)malloc(m*sizeof(reqSD1));
	printf("Enter the length and target time for each of the requests\n");
	for(int i=0;i<m;i++)
	{	
		printf("request no %d::",i);
		scanf("%d%d",&SW[i].service_time,&SW[i].target_time);
		SW[i].id=i;
		sw[i].service_time=SW[i].service_time;
		sw[i].target_time=SW[i].target_time;
		
	}
	sort2(SW,0,m-1);
	fun2(SW,m); 
	return 0;
}

