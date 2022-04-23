//Mouse.h
#include <GL/glut.h>
#include <iostream>
#include <SFML/Audio.hpp>
#include <GL/glu.h>
#include <GL/gl.h>
#include "Dianas.h"
using namespace std;

class Mouse{
           
	        public:
            static float sensividad;
	        static int currentX;
			static int currentY;
			static int lastX;
			static int lastY;
			static int deltaX;
			static int deltaY;
			static int active;
			static int leftButton;
			static int rightButton;
			static int middlebutton;
			static int screen_capture_avalaible;
			static int h, w;
			static int get_sc;
			static int act_diana;
			static int click;
			static int gaming;
			static double objx, objy, objz;
			static double Motionobjx, Motionobjy, Motionobjz;

	        static void move(int x, int y);

			static void update();

			static void mouse(int btn, int state, int x, int y);

			static void clicksound();
			static void clicksound2();

};