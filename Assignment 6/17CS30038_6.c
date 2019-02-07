#include<stdio.h>
#include<stdlib.h>
void combine(int A[], int left, int middle, int right)
{
	int i=left,j=middle+1,k=0;
	int *b;
	b=(int*)malloc(sizeof(int)*(right-left+1));
	while(i<=middle&&j<=right)
	{
		if(A[i]<=A[j])
		{
			b[k]=A[i];
			i++;
			k++;
			
		}
		else
		{
			b[k]=A[j];
			k++;
			j++;
		}
	}
	while(i<=middle)
	{
		b[k]=A[i];
		i++;
		k++;
			
	}
	while(j<=right)
	{
		b[k]=A[j];
		k++;
		j++;
	}	
	for(i=left,k=0;i<=right;k++,i++)
	{
		A[i]=b[k];
	}	
	free(b);
	return;
}
void superbSorting(int A[], int sizeOfA)
{
	int block=1;
	int i,left,middle,right;
	for(block=1;block<=sizeOfA;block*=2)
	{
		for(i=0;i<sizeOfA;i+=block*2)
		{
			left=i;
			right=i+2*block-1;
			if(right>=sizeOfA)
				right=sizeOfA-1;
			middle=left+block-1;
			combine(A, left,  middle, right);
		}
	}
}
int compare1(int X[],int sizeOfX,int x,int y)
{
	int i,x_pos,y_pos;
	for(i=0;i<sizeOfX;i++)
	{
		if(X[i]==x)
			x_pos=i;
		if(X[i]==y)
			y_pos=i;
	}
	if(x_pos<y_pos)
		return 1;	
	
	else
		return -1;

}
void combine1(int A[], int left, int middle, int right, int B[], int sizeOfB)
{
	int i=left,j=middle+1,k=0;
	int *b;
	b=(int*)malloc(sizeof(int)*(right-left+1));
	while(i<=middle&&j<=right)
	{
		if(compare1(B,sizeOfB,A[i],A[j])==1)
		{
			b[k]=A[i];
			i++;
			k++;
			
		}
		else
		{
			b[k]=A[j];
			k++;
			j++;
		}
	}
	while(i<=middle)
	{
		b[k]=A[i];
		i++;
		k++;
			
	}
	while(j<=right)
	{
		b[k]=A[j];
		k++;
		j++;
	}	
	for(i=left,k=0;i<=right;k++,i++)
	{
		A[i]=b[k];
	}	
	free(b);
	return;
}
void superbSorting1(int A [], int sizeOfA, int B[], int sizeOfB)
{
	int block=1;
	int i,left,middle,right;
	for(block=1;block<=sizeOfA;block*=2)
	{
		for(i=0;i<sizeOfA;i+=block*2)
		{
			left=i;
			right=i+2*block-1;
			if(right>=sizeOfA)
				right=sizeOfA-1;
			middle=left+block-1;
			combine1(A, left,  middle, right,B,sizeOfB);
		}
	}
}
void F_combine(int A[], int left, int middle, int right,int B[])
{
	int i=left,j=middle+1,k=0;
	int *b;
	b=(int*)malloc(sizeof(int)*(right-left+1));
	while(i<=middle&&j<=right)
	{
		if(B[A[i]]<B[A[j]])
		{
			b[k]=A[i];
			i++;
			k++;
			
		}
		else
		{
			b[k]=A[j];
			k++;
			j++;
		}
	}
	while(i<=middle)
	{
		b[k]=A[i];
		i++;
		k++;
			
	}
	while(j<=right)
	{
		b[k]=A[j];
		k++;
		j++;
	}	
	for(i=left,k=0;i<=right;k++,i++)
	{
		A[i]=b[k];
	}	
	free(b);
	return;
}
void F_sort(int A [], int sizeOfA, int B[])
{
	int block=1;
	int i,left,middle,right;
	for(block=1;block<=sizeOfA;block*=2)
	{
		for(i=0;i<sizeOfA;i+=block*2)
		{
			left=i;
			right=i+2*block-1;
			if(right>=sizeOfA)
				right=sizeOfA-1;
			middle=left+block-1;
			F_combine(A, left,  middle, right,B);
		}
	}
}
int main()
{
	int i,n,*A;
	printf("Enter number of numbers in the array A :\n");
	scanf("%d",&n);
	printf("\n");
	A=(int*)malloc(n*sizeof(int));
	printf("Enter numbers in the arrayA:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}  
	printf("\nnon decreasing order\n");
	superbSorting(A,n);
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");



 	printf("\nArray conversion+++++++\n");
	int n1,*A1,*B;
	A1=(int*)malloc(n*sizeof(int));
	printf("Enter numbers in the arrayA1:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A1[i]);
	}
	printf("Enter number of numbers in the array B:\n");
	scanf("%d",&n1);
	printf("\nenter elements of B:\n");
	B=(int*)malloc(n1*sizeof(int));  
	for(i=0;i<n1;i++)
	{
		scanf("%d",&B[i]);
	} 
	printf("\nrearranged order\n");
	superbSorting1(A1,n,B, n1);
	for(i=0;i<n;i++)
	{
		printf("%d\t",A1[i]);
	}
	printf("\n");
	free(A1);
	free(B);



	printf("\nFaster Algo++++++++++++++\n");
	int *B1,tmp,m;
	B1=(int*)malloc(sizeof(int)*10*n);
	printf("re-enter A for faster algo:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("Re-enter number of numbers in the array B for fast algo:\n");
	scanf("%d",&m);
	printf("\nenter elements of B:\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&tmp);
		B1[tmp]=i;
		
	}
	F_sort(A, n, B1);
	printf("reaaranged A using faster algorithm:\n"); 
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
	free(A);
	free(B1); 
	return 0;
}
