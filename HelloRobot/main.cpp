/*
 * main.cpp
 *
 *  Created on: Jan 10, 2015
 *      Author: colman
 */

#include <libplayerc++/playerc++.h>
#include <iostream>

using namespace PlayerCc;


int main() {

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
