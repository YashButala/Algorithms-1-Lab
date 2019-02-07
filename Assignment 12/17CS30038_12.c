#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node_
{
	int vno;
	struct node_* next;
}node;
typedef struct _vertex 
{
	node *adjlist; 
} vertex;
typedef vertex *graph;
void printlist(graph G,int v)
{
	node* tmp;
	for(int i=0;i<v;i++)
	{
		printf("vertex %d:",i);
		tmp=G[i].adjlist;
		while(tmp!=NULL)
		{
			printf("%d ",tmp->vno);
			tmp=tmp->next;	
		}
		printf("\n");
	}	
	return ;
}
void dfsvisit(graph G,int *visit,int i,int rem)
{
	visit[i]=1;
	node* tmp=G[i].adjlist;
	while(tmp!=NULL)
	{
		if(tmp->vno==rem)
		{
			tmp=tmp->next;
		}
		else
		{
			if(!visit[tmp->vno])
			dfsvisit(G,visit,tmp->vno,rem);
			tmp=tmp->next;
		}
	}	
}

int DFSComp (graph G,int v, int rem)
{
	int *visit=(int*)malloc(v*sizeof(int));
	for(int i=0;i<v;i++)
		visit[i]=0;
	int t=0;
	for(int i=0;i<v;i++)
	{
		if(i==rem)
			continue;
		else
		{
			if(visit[i]==0)
			{
				dfsvisit(G,visit,i,rem);
				t++;
			}
		}
	}
	return t;	
}
void findCritical (graph G,int v)
{
	printf("Critical junctions using the simple algorithm:\n");
	for(int i=0;i<v;i++)
	{
		int k=DFSComp (G,v, i);
		if(k>1)
		{
			printf("vertex %d : %d components\n",i,k);
			
		}
	}
	return ;
}
int dfsvisit2(graph G,int *visit,int* low,int* d,int* P,int i,int* time)
{
	int t=INT_MAX;;
	visit[i]=1;
	d[i]=*time;
	(*time)++;
	node* tmp=G[i].adjlist,*tmp2;
	tmp2=tmp;
	while(tmp2!=NULL)
	{
		if(low[tmp2->vno]>d[i])
			low[tmp2->vno]=d[i];
		tmp2=tmp2->next;
	}
	while(tmp!=NULL)
	{
		
		if(!visit[tmp->vno])
		{	
			P[tmp->vno]=i;
			t=dfsvisit2(G,visit,low,d,P,tmp->vno,time);
			if(t<low[i])
				low[i]=t;		
		}
		tmp=tmp->next;
		
	}
	return low[i];
}
void findCriticalFast (graph G,int v)
{
	int *visit=(int*)malloc(v*sizeof(int));
	int *low=(int*)malloc(v*sizeof(int));
	int* d=(int*)malloc(v*sizeof(int)); 
	int* P=(int*)malloc(v*sizeof(int)); 
	for(int i=0;i<v;i++)
	{	
		d[i]=INT_MAX;
		low[i]=INT_MAX;			
		visit[i]=0;
		P[i]=-1;
	}
	int time=1;
	for(int i=0;i<v;i++)
	{
	
		if(visit[i]==0)
		{
			dfsvisit2(G,visit,low,d,P,i,&time);
			
		}
	
	}
	int t=0;
	for(int i=1;i<v;i++)
	{
		if(low[i]<d[P[i]])
		printf("%d\t",i);
	}
	printf("\n");
	return ;
}
int main()
{
	int v,e,deg;
	node *tmp;
	printf("Enter the number of vertices and edges\n");
	scanf("%d%d",&v,&e);
	graph A=(graph)malloc(v*sizeof(vertex));
	for(int i=0;i<v;i++)	
	{
		A[i].adjlist=NULL;
	}
	printf("Enter the neighbors for each of the vertex\n");
	for(int i=0;i<v;i++)
	{
		printf("enter the degree of vertex %d :\n",i);
		scanf("%d",&deg);		
		printf("enter neighbours\n");
		for(int j=0;j<deg;j++)
		{
			tmp=(node*)malloc(sizeof(node));
			scanf("%d",&tmp->vno);
			tmp->next=A[i].adjlist;
			A[i].adjlist=tmp;
		}
		
	}
	printlist(A,v);
	findCritical (A, v);
	findCriticalFast (A, v);
	
}
