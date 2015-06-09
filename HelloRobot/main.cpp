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
	//ReadConfigFile();
	robotSize.width = 1;

	unsigned error;
	unsigned char* image;

	unsigned width, height;

	error = lodepng_decode24_file(&image, &width, &height, "Resources/Images/1.png");

	Map readMap = MakePixelMap(image, width, height);

	cout<<"read map:"<<endl;
	PrintMap(readMap);

	Map inflatedMap = MakeInflatedMap(readMap, robotSize.width);

	cout<<"inflated map:"<<endl;
	PrintMap(inflatedMap);

	cout<<"hello";
	// free(image);


	PlayerClient pc("localhost", 6665);
	SonarProxy lp(&pc);
	Position2dProxy pp(&pc);

	pp.SetMotorEnable(true);

	//pp.SetSpeed(0.0, 0.0);

	while (true) {
		pc.Read();

		if (lp[2] < 0.802) {

			//if(lp[0] < 0.9 || lp[1] < 0.9) {
				pp.SetSpeed(0.0, 0.3);
			//} else if(lp[4] < 0.9 || lp[3] < 0.9) {
				//pp.SetSpeed(0.0,-0.3);
			//}

			//pp.SetSpeed(0.0, 0.3);
		}
		else
			pp.SetSpeed(1, 0.0);
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
