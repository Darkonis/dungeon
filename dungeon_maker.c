#include <stdio.h>
#include "dungeon.h"
int width=80;
int height=21;
char dungeon[21][80];
int main()
{
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
