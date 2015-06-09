#include <vector>

using namespace std;

// Struct definition
struct position
{
	int x;
	int y;
};

struct size
{
	int width;
	int height;
};

// Globals declaration
const char* filePath = "Resources/config.txt";
string mapFilePath = "";
position startPostion;
int startYaw;
position destination;
size robotSize;
int mapResolution;
int gridSize;

// Fucntions declerations
void ReadConfigFile();
