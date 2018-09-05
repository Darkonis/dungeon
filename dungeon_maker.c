#include <stdio.h>
#include "dungeon_maker.h"
#include <stdlib.h>
#include <time.h>
int width=80;
int height=21;
char dungeon[21][80];
int main(int argc, char **argv)
{
  //int i;
  int seed;

  seed = time(NULL);

  printf("argv[0] is %s\n", argv[0]);

  if (argc == 2) {
    seed = atoi(argv[1]);
  }
  printf("Seed is %d\n", seed);

  srand(seed);
  sweep();
  mkBounds();
  
  printDungeon();
  return 0;
}


void sweep()
{
  for(int i=0;i<height;i++)
    {
      for(int k=0;k<width;k++)
        {
          dungeon[i][k]=' ';//clears and initalizes all dungeon squares    
        }
    }
}
void mkBounds()
{
  
  for(int i=0;i<width;i++)
    {
      dungeon[0][i]='-'; //define the upper bounds                    
    }
  for(int i=0;i<width;i++)
    {
      dungeon[height-1][i]='-'; //define the lower bounds                          
    }
  for(int i=1; i<height-1;i++)
    {
      dungeon[i][0]='|';//define left bounds                           
    }
  for(int i=1; i<height-1;i++)
    {
      dungeon[i][width-1]='|';//define right bounds
    }
}
void printDungeon()
{
  for(int i=0;i<height;i++)
    {
      for(int k=0;k<width;k++)
	{
	  printf("%c",dungeon[i][k]);
	}
      printf("\n");
    }
}
typedef struct
{
  int x,y;
  int height,width;

}room;


void makeRooms()
{
  int numRooms =rand()%5+5;//howmany random rooms will be genrated between 5-10
  room rooms[numRooms];
  
  for(int i=0;i<numRooms;i++)
    {
      //int loopCounter=0;
      int isSafe=0;
      while(!isSafe)
	{
	  // loopCounter++;
	  // if(loopCounter==30)//locks at 30 tries // this might need to be changed
	  room* temp = malloc(sizeof(room));
	  temp->width = rand()%5+3;
	  temp->x=rand()%(80-temp->width);
	  temp->height=rand()%5+3;
	  temp->y=rand()%(21-temp->height);
	  isSafe=1;
	  for(int k=0;k<i;k++)//yes this is horrendous for big o time
	    {
	      if(!(rooms[k].x>(temp->x+temp->width)||!(temp->x>rooms[k].x+rooms[k].width)))//if the new room is with in the bounds of the x values
		{
		  if(!(rooms[k].y>(temp->y+temp->height))||!(temp->y>rooms[k].y+rooms[k].height)) //if the new room is in the y bounds of the y values
		    {
		      isSafe=0;
		    }
		}    
	      if(isSafe==1)
		{
		  rooms[i]=*temp;
		}
	    }
	}
    }
  for(int i =0;i<numRooms;i++)
    {
      for(int k=rooms[i].x;k<(rooms[i].x+rooms[i].width);k++)
	{
	   for(int j=rooms[i].y;j<(rooms[i].y+rooms[i].height);j++)
	     {
	       dungeon[k][j]='*';
	     }
	}
    }
}
