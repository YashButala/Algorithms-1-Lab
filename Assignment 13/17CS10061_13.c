#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef int** graph;
typedef struct queue
{
	int n;
	struct queue* next;
}que;
typedef struct Edge 
{ 
    int src, dest,weight; 
}edge;
void merge(edge a[],int low ,int mid,int high)
{
    int i=low,j=mid+1;
    int k=0;
    edge b[high-low+1];
    while(i<=mid&&j<=high)
    {
        if(a[i].weight<a[j].weight)
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
void mergesort(edge a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
que* enqueue(que *front,int n)
{
	que* move=(que*)malloc(sizeof(que)),*temp;
	move->n=n;
	move->next=NULL;
	if(front==NULL)
	{
		front =move;
		return front ;
	}
	else
	{
		temp=front;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=move;
		return front;	
	}		
}
int first(que* front)
{
	if(front!=NULL)
		return front->n;
}	
que* dequeue(que* front)
{
	if(front!=NULL)	
		return front->next;	
}
int isempty(que* front)
{
	if(front==NULL)
		return 0;
	return 1;
}
int isConnectedUsingBFS(graph G,int n)
{
	int *v=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		v[i]=0;
	v[0]=1;
	que* Q=NULL;
	Q=enqueue(Q,0);
	while(isempty(Q))
	{
		int u=first(Q);
		Q=dequeue(Q);
		for(int j=0;j<n;j++)
		{
			if(G[u][j]>0 && v[j]==0)
			{
				Q=enqueue(Q,j);	
				v[j]=1;
			}	
		}
	}
	for(int i=0;i<n;i++)
		if(v[i]==0)		
		{	free(v);
			return 0;
		}
	free(v);
	return 1;


}
	
void findMST(graph G, int numberOfNodes)
{
	int v=numberOfNodes,e=0;
	edge ed[10000];
	for(int i=0;i<v;i++)
	{
		for(int j=i;j<v;j++)
		{
			if(G[i][j]>0)
			{
				
				ed[e].src=i;
				ed[e].dest=j;
				ed[e].weight=G[i][j];
				e++;
				
			}	
		}
	}
	mergesort(ed,0,e-1);
	for(int i=0;i<e;i++)
	{
		int t=G[ed[i].src][ed[i].dest];
		G[ed[i].src][ed[i].dest]=0;
		G[ed[i].dest][ed[i].src]=0;
		if( isConnectedUsingBFS( G,v))
			continue;
		else
		{
			G[ed[i].src][ed[i].dest]=t;
			G[ed[i].dest][ed[i].src]=t;
		}
			
	}
	for(int i=0;i<v;i++)
	{	
		printf("vertex %d : ",i);
		for(int j=0;j<v ;j++)
			if(G[i][j]>0)
				printf("%d %d ",j,G[i][j]);
		printf("\n");
			
	}
			
}
int main()
{
	int n,m,a,b,deg;
	printf("Enter the number of nodes and edges\n");
	scanf("%d%d",&n,&m);
	graph A=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<n;i++)
	{
		A[i]=(int*)malloc(n*sizeof(int));
	}
	printf("Enter the neighbors for each of the vertex\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			A[i][j]=0;
		printf("enter the degree of vertex %d :\n",i);
		scanf("%d",&deg);		
		printf("enter neighbours\n");
		for(int j=0;j<deg;j++)
		{
			
			scanf("%d%d",&a,&b);
			A[i][a]=b;
		}
	}
	for(int i=0;i<n;i++)
	{	
		printf("vertex %d : ",i);
		for(int j=0;j<n ;j++)
			if(A[i][j]>0)
				printf("%d %d ",j,A[i][j]);
		printf("\n");
			
	}	
	printf("neughbours of required mst\n");	
	findMST( A, n)	;
	for(int i=0;i<n;i++)
		free(A[i]);
	return 0;
}	
