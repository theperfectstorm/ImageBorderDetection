#include<stdio.h>
#include<math.h>
#define RIGHT 0
#define BOTTOM_RIGHT 7
#define BOTTOM 6
#define BOTTOM_LEFT 5
#define LEFT 4
#define TOP_LEFT 3
#define TOP 2
#define TOP_RIGHT 1

int flag=1;
struct coord
{
	int x;
	int y;
}coordinate;


int main()
{
	int matrix[100][100];
	int processed[100][100]={0};
	struct coord top,current;
	
	current.x=-1;
	current.y=-1; //assign invalid position initially
	int size; //size of the matrix;
	int i,j,k;
	int count1=0; //total no. of 1s in the matrix
	int count=0; //total no. of 1s encountered yet
	int arr[100]; //to store position value
	int it=0; //1D array iterator
	int m,n;
	printf("Enter size of matrix m*n: ");
	scanf("%d %d",&m,&n);
	//matrix=(int*)malloc(m*n*sizeof(int));
	printf("Enter elements in the matrix :");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&matrix[i][j]);
			


	//Display the matrix 
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{	if(matrix[i][j]==1)
				count1++;   //finding total no. of 1s in the matrix
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	
	
	//TRAVERSING AND FINDING TOP LEFT ELEMENT
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(matrix[i][j])
			{
				top.x=i;
				top.y=j;
				current.x=top.x;
				current.y=top.y;
				break;
			}
		}
	}
	//Finding the second one to initialize the initial current value
	/*for(i=top.x;i<m;i++)
	{	
		for(j=top.y+1;j<n;j++)
		{
			if(matrix[i][j]==1)
			{
				current.x=i;
				current.y=j;
				break;
			}
		}
	}*/ //It did'nt work
	
	//Main work done here
	
	//while((top.x!=current.x || top.y!=current.y )&& count1!=count)   //previous while loop
	while((abs(count1-count))>=3)
	{	
		flag=0; //loop executed at least one time
		
		//if right
	   if(matrix[current.x][current.y+1]==1 && !processed[current.x][current.y] && current.y!=n-1)   //not the rightmost one 
	   {
		   arr[it++]=RIGHT;
		   current.y++;
		   count++;
		   processed[current.x][current.y]=1;
		  // current.y=top.y;
	   }
	   //if bottom
	   else  if(matrix[current.x+1][current.y]==1 && !processed[current.x][current.y] && current.x!=m-1)   //not the bottom_most one 
	   {
		   arr[it++]=BOTTOM;
		   current.x++;
		   count++;
		   processed[current.x][current.y]=1;
		  // current.y=top.y;
	   }
	   
	   //BOTTOM RIGHT
	   else  if(matrix[current.x+1][current.y+1]==1 && !processed[current.x][current.y] && current.x!=m-1)   //not the bottom_most one 
	   {
		   arr[it++]=BOTTOM_RIGHT;
		   current.x++;
		   current.y++;
		   count++;
		   processed[current.x][current.y]=1;
		  // current.y=top.y;
	   }
	   //BOTTOM LEFT
	  else  if(matrix[current.x+1][current.y-1]==1 && !processed[current.x][current.y] && current.y!=0)   //not the bottom_most one 
	   {
		   arr[it++]=BOTTOM_RIGHT;
		   current.x++;
		   current.y--;
		   count++;
		   processed[current.x][current.y]=1;
		  // current.y=top.y;
	   }
	   //LEFT
	  else  if(matrix[current.x][current.y-1]==1 && !processed[current.x][current.y] && current.y!=0)   //not the bottom_most one 
	   {
		   arr[it++]=LEFT;
		    //current.x++;
		   current.y--;
		   count++;
		   processed[current.x][current.y]=1;
		  // current.y=top.y;
	   }
	   
	   //UP
	  else  if(matrix[current.x-1][current.y]==1 && !processed[current.x][current.y] && current.x!=0)   //not the bottom_most one 
	   {
		   arr[it++]=TOP;
		    current.x--;
		   //current.y--;
		   count++;
		   processed[current.x][current.y]=1;
		  // current.y=top.y;
	   }
	   //UP_LEFT
	   
	  else  if(matrix[current.x-1][current.y-1]==1 && !processed[current.x][current.y] && current.y!=0)   //not the bottom_most one 
	   {
		   arr[it++]=TOP_LEFT;
		   current.x--;
		   current.y--;
		   count++;
		   processed[current.x][current.y]=1;
		  // current.y=top.y;
	   }
	   //TOP_RIGHT
	  else  if(matrix[current.x-1][current.y+1]==1 && !processed[current.x][current.y] && current.y!=n-1)   //not the bottom_most one 
	   {
		   arr[it++]=TOP_RIGHT;
		   current.x--;
		   current.y++;
		   count++;
		   processed[current.x][current.y]=1;
		  // current.y=top.y;
	   }
	   
	}
	
	
for(i=0;i<=it;i++)
{
		printf("%d\t",arr[i]);
}
	
return 0;
}
	
