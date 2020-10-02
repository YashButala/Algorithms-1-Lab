#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct node
{
	
	int data;
	struct node *xor;
	
};//End of structure


struct node *xor( struct node *a , struct node *b )
{
	
    return ( struct node* ) ( ( uintptr_t ) a ^ ( uintptr_t ) b );
	
}//End of function


void trafte( struct node *head )
{
	
	int i;
	struct node* temp = NULL , *prev = NULL , *temp2;
	temp = head;
	printf( "front to end traversal\n" );
	printf( "%d\t" , temp->data );
	temp = ( temp->xor );
	prev = head;
	
	while( xor( temp->xor , prev ) )
	{
		
		printf( "%d\t" , ( temp->data ) );
		temp2 = prev;
		prev = temp;
		temp = xor( ( temp->xor ) , temp2 );
		
	}//End of while

	printf( "%d\n" , ( temp->data ) );	
	
}//End of function


int main()
{
	
	int n;
	scanf( "%d" , &n );
	struct node * front = NULL , *end , *move , *temp , *prev , *temp2;
	
	int i = 0;
	while( i < n )
	{
		
		move = ( struct node* )malloc( sizeof( struct node* ) );//Allocate free space in the memory
		( move->data ) = ( rand() % 100 );
		( move->xor ) = NULL;
		
		if( front == NULL )
		{
			front = move;
		}
		else
		{
			( prev->xor ) = move;
			
		}//End of if
		
		prev = move;
		i = ( i + 1 );
		
	}//End of while
	
	end = move;
	move = front;
	prev = NULL;
	
	i = 0;
	while( i < ( n - 1 ) )
	{
		
		temp = ( move->xor );
		temp2 = move;
		( move->xor ) = ( xor( prev , temp ) );
		move = temp;
		prev = temp2;
		i = ( i + 1 )
			
	}//End of while
	
	( move->xor ) = prev;
	trafte( front );
	return 0;
	
}//End of main
