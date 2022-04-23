
#include <iostream>
using namespace std;

class Keyboard{

                public:
			    static bool key[256];
				static void keyDown(unsigned char k, int x, int y);
				static void keyUp(unsigned char k, int x, int y);

};