#include <vector>

using namespace std;

#define BLACK 'X'
#define WHITE '.'

typedef vector<unsigned char> PixelRow;
typedef vector<PixelRow> Map;

Map MakePixelMap(unsigned char* image, int width, int height);
void PrintMap(Map map);
Map MakeInflatedMap(Map sourceMap, int factor);
Map AlterMapByScale(Map sourceMap, double scale);
