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
				returnMap[i][j] = WHITE;
			}
			else
			{
				returnMap[i][j] = BLACK;
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
			returnMap[i][j] = WHITE;
		}
	}



	for (int i=0;i<sourceMap.size();i++)
	{
	  for (int j=0;j<sourceMap[0].size();j++)
	  {
		  if(sourceMap[i][j] == BLACK)
		  {
			  for(int a = 0;a<2*factor+1;a++)
			  {
				  for(int b = 0; b < 2*factor+1; b++)
				  {
					  returnMap[i+a][j+b] = BLACK;
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

Map AlterMapByScale(Map sourceMap, double scale)
{
	Map returnMap;
	if(scale < 1)
	{
		double nScale = 1 / scale;
		int height = sourceMap.size() * scale;
		int width = sourceMap[0].size() * scale;
		int i, j, a, b;
		bool isBlack = false;

		// Initialize the new map
		returnMap.resize(height);
		for (i=0; i < height; i++)
		{
			returnMap[i].resize(width);
			for (j=0; j < width; j++)
			{
				returnMap[i][j] = WHITE;
			}
		}

		// Fill the new Grid according to the original map
		for (i=0;i<(sourceMap.size() - nScale);i+=nScale)
		{
			for (j=0;j<(sourceMap[0].size() - nScale);j+=nScale)
			{
				isBlack = false;
				for(a = 0;a<nScale;a++)
				{
					for(b = 0; b < nScale; b++)
					{
						if (sourceMap[i+a][j+b] == BLACK)
							isBlack = true;
					}
				}
				if (isBlack)
					returnMap[i/nScale][j/nScale] = BLACK;
			}
		}
	}

	return returnMap;
}
