#include<stdio.h>
#include<stdlib.h>
typedef struct rm {
	int hInd;
	int vInd;
} room;
struct node 
{
	room data;
	struct node *next;
};
typedef struct node node, *list;
typedef struct {
	struct node *head ;
} STACK ;
void init(STACK *s)
{
	s->head=NULL;
}
int isempty(STACK s)
{
	if(s.head==NULL)
		return 1;
	else
		return 0;
}
void push(STACK *s, room data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data.hInd=data.hInd;
	temp->data.vInd=data.vInd;
	temp->next=s->head;
	s->head=temp;
}
void pop(STACK *s);

void printmaze(int H[][20], int V[][21], int n)
{
	int i,j;
	for(i=0;i<4*n+1;i++)
		for(j=0;j<4*n+1;j++)
		{
			if(i%4==0&&j%4==0)
			{
				printf("+");
			}
			if(i%4==0&&j%4!=0)
			{
				if(H[i/4][j/4]==0)
					printf("-");
				else
					printf(" ");
			}
			if(i%4!=0&&j%4==0)
			{
				if(i%4==1||i%4==3)
					printf(" ");
				else
				{	
					if(V[i/4][j/4]==0)
						printf("|");
					else
						printf(" ");
				}
	
			}
			if(i%4!=0&&j%4!=0)
			{ 
				printf(" ");
			}
			if(j==4*n)
				printf("\n");

			
		}
	
}
void createmaze(list maze[][20], int n, int H[][20], int V[][21])
{
	int i,j;
	struct node* temp;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			maze[i][j]=NULL;
			if(H[i][j]==1)
			{
				struct node* t;
				t=(struct node*)malloc(sizeof(struct node));
				t->data.hInd=i-1;
				t->data.vInd=j;
				if(maze[i][j]==NULL)
				{	maze[i][j]=t;temp=t;}
						
				else
				{	
					temp->next=t;
					temp=t;
				}	
			}
			if(H[i+1][j]==1)
			{
				struct node* t;
				t=(struct node*)malloc(sizeof(struct node));
				t->data.hInd=i+1;
				t->data.vInd=j;
				if(maze[i][j]==NULL)
				{	maze[i][j]=t;temp=t;}
				else
				{	
					temp->next=t;
					temp=t;
				}
			}
			if(V[i][j]==1)
			{
				struct node* t;
				t=(struct node*)malloc(sizeof(struct node));
				t->data.hInd=i;
				t->data.vInd=j-1;
				if(maze[i][j]==NULL)
				{	maze[i][j]=t;temp=t;}
				else
				{	
					temp->next=t;
					temp=t;
				}
			}

			if(V[i][j+1]==1)
			{
				struct node* t;
				t=(struct node*)malloc(sizeof(struct node));
				t->data.hInd=i;
				t->data.vInd=j+1;
				if(maze[i][j]==NULL)
				{	maze[i][j]=t;temp=t;}
				else
				{	
					temp->next=t;
					temp=t;
				}
			}
			temp->next=NULL;			
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			printf("(%d,%d)",i,j);
			temp=maze[i][j];
			if(temp!=NULL)
			{printf("::-->");printf("(%d,%d)",temp->data.hInd,temp->data.vInd);}
			while(temp->next!=NULL)
			{
				temp=temp->next;
				printf("-->");	
				printf("(%d,%d)",temp->data.hInd,temp->data.vInd);	
				
			}	printf("\n");
		}
	return;	
}
int main()
{
