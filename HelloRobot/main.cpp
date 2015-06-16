/*
 * main.cpp
 *
 *  Created on: Jan 10, 2015
 *      Author: colman
 */

#include <iostream>
#include <libplayerc++/playerc++.h>
#include <fstream>
#include "Resources/ThirdParty/lodepng.h"
#include "Resources/ThirdParty/pngUtil.h"
#include "MapUtils.h"
#include "Main.h"
using namespace std;
using namespace PlayerCc;

int main() {

	// Read the config file and init
	ReadConfigFile();
	//robotSize.width = 1;

	unsigned error;
	unsigned char* image;
	unsigned width, height;

	// TODO: change to map path from the file
	error = lodepng_decode24_file(&image, &width, &height, "Resources/Images/3.png");

	Map readMap = MakePixelMap(image, width, height);

	cout<<"read map:"<<endl;
	PrintMap(readMap);

	Map scaled = AlterMapByScale(readMap, mapResolution / gridSize);
	cout<<"after scaling:"<<endl;

	PrintMap(scaled);

	// TODO: change the factor to robotsize
	Map inflatedMap = MakeInflatedMap(readMap, robotSize.width);

	cout<<"inflated map:"<<endl;
	//PrintMap(inflatedMap);

	cout<<"hello";
	// free(image);


	PlayerClient pc("localhost", 6665);
	SonarProxy sp(&pc);
	LaserProxy lp(&pc);
	Position2dProxy pp(&pc);

	pp.SetMotorEnable(true);

	//pp.SetSpeed(0.0, 0.0);

	pp.SetSpeed(1, 0.0);

	while (true) {
		pc.Read();

		for(int i=0;i<730;i+=30)
		{
			cout<<i<<" : "<<lp[i]<<endl;
		}


		//

		//if (lp[2] < 0.802) {

			//if(lp[0] < 0.9 || lp[1] < 0.9) {
				pp.SetSpeed(0.0, 0.1);
			//} else if(lp[4] < 0.9 || lp[3] < 0.9) {
				//pp.SetSpeed(0.0,-0.3);
			//}

			//pp.SetSpeed(0.0, 0.3);
		//}
		//else
		//	pp.SetSpeed(1, 0.0);
	}
	return 0;

}



void ReadConfigFile()
{
	ifstream configFile(filePath);
	if(!configFile.is_open())
	{
		cout << " the file wasnt opened" << endl;
	}
	else
	{
		// Readign the map file
		configFile >> mapFilePath;

		// Start position
		configFile >> startPostion.x;
		configFile >> startPostion.y;
		configFile >> startYaw;

		// destination
		configFile >> destination.x;
		configFile >> destination.y;

		// size
		configFile >> robotSize.width;
		configFile >> robotSize.height;

		// Resolution
		configFile >> mapResolution;

		// grid size
		configFile >> gridSize;

		configFile.close();
	}

}
