#include<stdio.h>
#include<stdlib.h>
 #include<stdint.h>
struct node
{
	int data;
	struct node *xor;
};

struct node *xor(struct node *a,struct node *b)
{
    return (struct node*) ((uintptr_t) a ^ (uintptr_t) b);
}
void trafte(struct node *head)
{
	int i;
	struct node* temp=NULL,*prev=NULL,*temp2;
	temp=head;
	printf("front to end traversal\n");
	printf("%d\t",temp->data);
	temp=temp->xor;
	prev=head;
	while(xor(temp->xor,prev))
	{
		printf("%d\t",temp->data);
		temp2=prev;
		prev=temp;
		temp=xor(temp->xor,temp2);
	}

	printf("%d\n",temp->data);	
}
int main()
{
	int n;
	scanf("%d",&n);
	struct node * front=NULL,*end,*move,*temp,*prev,*temp2;	;
	int i=0;
	for(i=0;i<n;i++)
	{
		move=(struct node*)malloc(sizeof(struct node*));
		move->data=rand()%100;
		move->xor=NULL;
		if(front==NULL)
		{
			front=move;
		}
		else
		{
			prev->xor=move;
			
		}
		prev=move;
	}
	end=move;
	move=front;
	prev=NULL;
	for(int i=0;i<n-1;i++)
	{
		temp=move->xor;
		temp2=move;
		move->xor=xor(prev,temp);
		move=temp;
		prev=temp2;
			
	}
	move->xor=prev;
	trafte(front);
	return 0;
	
}
