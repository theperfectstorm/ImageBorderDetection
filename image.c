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
int loopcount=0;
int flag=1;
int flag1=0;
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
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&matrix[i][j]);
			}
		}
	
	//Display the matrix and count total no. of 1s 
	/*for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{if(matrix[i][j]==1)
		count1++;   //finding total no. of 1s in the matrix
		//	printf("%d\t",matrix[i][j]);
		}
		//printf("\n");
	}*/
	
	
	//TRAVERSING AND FINDING TOP LEFT ELEMENT


	i=0;
	while(i<m && flag1==0)
	{
		j=0;
		while(j<n && flag1==0)
		{
			if(matrix[i][j]==1)
			{
				flag1=1;
				top.x=i;
				top.y=j;
			}
				if(flag1==0)
				{
					j++;
				}
		}
		i++;
	}

		

	printf("TOP x: %d   y %d  \n\n",top.x,top.y);
	current.x=top.x;
	current.y=top.y;
	//Main work done here
	
	do
	{	
		flag=0; //loop executed at least one time
		loopcount++;
		//if right
	   if( current.y!=n-1 && matrix[current.x][current.y+1]==1 && !processed[current.x][current.y] )   //not the rightmost one 
	   {
		   arr[it++]=RIGHT;
		   
		   count++;
		   processed[current.x][current.y]=1;
			current.y+=1;
		  // current.y=top.y;
	   }
	   //if bottom
	   else  if( current.x!=m-1 && matrix[current.x+1][current.y]==1 && !processed[current.x][current.y])   //not the bottom_most one 
	   {
		   arr[it++]=BOTTOM;
				   processed[current.x][current.y]=1;
		   current.x+=1;
		   count++;

		  // current.y=top.y;
	   }
	   
	   //BOTTOM RIGHT
	   else  if(current.x!=m-1 && current.y!=n-1 && matrix[current.x+1][current.y+1]==1 && !processed[current.x][current.y])   //not the bottom_most one 
	   {
		   arr[it++]=BOTTOM_RIGHT;
					   processed[current.x][current.y]=1;
		   current.x+=1;
		   current.y+=1;
		   count++;

		  // current.y=top.y;
	   }
	   //BOTTOM LEFT
	  else  if(current.y!=0 && current.x!= m-1 && matrix[current.x+1][current.y-1]==1 && !processed[current.x][current.y])   //not the bottom_most one 
	   {
		   arr[it++]=BOTTOM_LEFT;
					   processed[current.x][current.y]=1;
		   current.x+=1;
		   current.y-=1;
		   count++;

		  // current.y=top.y;
	   }
	   //LEFT
	  else  if( current.y!=0 && matrix[current.x][current.y-1]==1 && !processed[current.x][current.y] )   //not the bottom_most one 
	   {
		   arr[it++]=LEFT;
		   processed[current.x][current.y]=1;
		    //current.x++;
		   current.y-=1;
		   count++;

		  // current.y=top.y;
	   }
	   
	   //UP
	  else  if( current.x!=0 && matrix[current.x-1][current.y]==1 && !processed[current.x][current.y])   //not the bottom_most one 
	   {
		   arr[it++]=TOP;
		   processed[current.x][current.y]=1;
		    current.x-=1;
		   //current.y--;
		   count++;

		  // current.y=top.y;
	   }
	   //UP_LEFT
	   
	  else  if(current.y!=0 && current.x!=0 && matrix[current.x-1][current.y-1]==1 && !processed[current.x][current.y] )   //not the bottom_most one 
	   {
		   arr[it++]=TOP_LEFT;
		   processed[current.x][current.y]=1;
		   current.x-=1;
		   current.y-=1;
		   count++;

		  // current.y=top.y;
	   }
	   //TOP_RIGHT
	  else  if(current.y!=n-1 && current.x!=m-1 && matrix[current.x-1][current.y+1]==1 && !processed[current.x][current.y])   //not the bottom_most one 
	   {
		   arr[it++]=TOP_RIGHT;

		   processed[current.x][current.y]=1;
		   current.x-=1;
		   current.y+=1;
		   count++;

		  // current.y=top.y;
	   }
	   
	}while(count!=9);
	
	
for(i=0;i<=it;i++)
{
		printf("%d\t",arr[i]);
}
	
printf("\n\nCount of loop : %d\n",loopcount);
printf("\nTOP x: %d   y: %d\n",top.x,top.y);
printf("Current x:%d  y:%d",current.x,current.y);
return 0;
}
	
