//============================================================================
// Name        : image.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstdio>
#define MAX 5
using namespace std;

int main()
{
	int border[MAX][MAX]= {0};
	int i=0, j=0, r1, c1, r0, c0;
	int x[8]= {0}, y[8]= {0};
	int points[3][2]= {0}, prevx = 0, prevy = 0;
	int flag=0, count= 0;
	char ch= 'y';
	printf("Enter the border matrix: \n");
	while( ch == 'y')
	{
		printf("Point %d: ", k++);
		scanf("%d%d", &i, &j);
		border[i][j]=1;

		printf("continue (y/n)? ");
		cin>>ch;

		if( ch != 'y')
		{
			break;
		}

	}


	//printing border matrix

	printf("\n");
	for(int i=0; i<MAX; i++)
	{
		for(int j=0; j<MAX; j++)
		{
			printf("%d ", border[i][j]);
		}

		printf("\n");
	}

	//searching for first point in border matrix

	for(int i=0; i<MAX; i++)
	{
		for(int j=0; j<MAX; j++)
		{
			if( border[i][j] == 1)
			{
				flag = 1;
				break;		//breaking from inner for( int j...) loop
			}
		}

		if( flag == 1)
		{
			break;		//breaking from outer for( int i...) loop
		}
	}
	r1 = i; c1 = j;

	//searching the first zero point in border matrix

	flag=0;
	for(int i=0; i<MAX; i++)
	{
		for(int j=0; j<MAX ; j++)
		{
			if( border[i][j] == 0)
			{
				flag = 1;
				break;
			}
		}

		if( flag == 1)
		{
			break;
		}
	}
	r0 = i; c0 = j;

	//starting traversal from given first point in anti-clockwise direction
	i = r1; j = c1;
	do
	{
		x[0]= i-1;	y[0]= j-1;
		x[1]= i-1;	y[1]= j;
		x[2]= i-1;	y[2]= j+1;		//considering current point to be middle point
		x[3]= i; 	y[3]= j+1;		//calculating 8 points surrounding current point
		x[4]= i+1;	y[4]= j+1;
		x[5]= i+1;	y[5]= j;
		x[6]= i+1;	y[6]= j-1;
		x[7]= i;	y[7]= j-1;

		//if the calculated points are out of bounds, initialize them with
		//previously found zero sample point ie r0, c0

		for( int i=0; i<8; i++)
		{
			if( (x[i]<0 || x[i]>MAX-1) || (y[i]<0 || y[i]>MAX-1) )
			{
				x[i]= r0; y[i]=c0;
			}
		}
		
		count= 0;
		point[3][2]= {0};

		for( int i=0; i<8; i++)
		{
			for( j=0; j<8; j++)
			{
				if( border[x[i]][y[j]] == 1 )
				{
					point[i][j] = 1;
					count++;
				}
			}
		}

		if( count == 2)
		{


	}while( (i != r1) && (j != c1) ); //terminate loop when current point is equal to initial
									  //point
	return 0;
}
