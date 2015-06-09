#include "MapUtils.h"
#include <iostream>
using namespace std;

Map MakePixelMap(unsigned char* image, int width, int height)
{
	Map returnMap;
	returnMap.resize(height);

	int i,j;

	for (i=0;i<height;i++){

		// Allocate the row vector
		returnMap[i].resize(width);

		for(j=0;j<width;j++){

			if (image[(i * width * 3) + (j*3)] == 255)
			{
				returnMap[i][j] = '_';
			}
			else
			{
				returnMap[i][j] = 'X';
			}
		}
	}

	return returnMap;
}


Map MakeInflatedMap(Map sourceMap, int factor)
{
	Map returnMap;
	int height = sourceMap.size() + factor * 2;
	int width = sourceMap[0].size() + factor * 2;
	returnMap.resize(height);

	for (int i=0;i<height;i++)
	{
		returnMap[i].resize(width);
		for (int j=0; j < width; j++)
		{
			returnMap[i][j] = '_';
		}
	}



	for (int i=0;i<sourceMap.size();i++)
	{
	  for (int j=0;j<sourceMap[0].size();j++)
	  {
		  if(sourceMap[i][j] == 'X')
		  {
			  for(int a = 0;a<2*factor+1;a++)
			  {
				  for(int b = 0; b < 2*factor+1; b++)
				  {
					  returnMap[i+a][j+b] = 'X';
				  }
			  }
		  }
	  }
	}

	return returnMap;
}


void PrintMap(Map map)
{
	for (int i=0;i<map.size();i++)
	{
		for (int j=0;j<map[0].size();j++)
		{
		  cout<<map[i][j];
		}
		cout<<endl;
	}
}
