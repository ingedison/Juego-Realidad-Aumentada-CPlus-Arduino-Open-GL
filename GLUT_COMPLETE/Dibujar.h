#pragma once
//#include <glut.h>

#include "Keyboard.h"
#include "Mouse.h"
#include "Math.h"
#include "Tiempo.h"
#include "Texture.h"

// "Dianas.h"
#include "Texto.h"
#include "colors.h"
#include "Menu.h";
#include "Terreno.h"
#include "Arduino.h"
#include "FullScreen.h"

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class Dibujar{
             public:
				    static const float WALKING_SPEED;
					static bool gamemode;
	                static void pre_eventos();
					static void display();
					static sf::Font font;
					static void output(GLfloat x, GLfloat y, char *text);
					static unsigned int g_persp, g_ortho, g_ortho2D;
					static void Escenario();
					static void Menu();
					static void sound();
					static void snderror();
					static void Men_Ent_Snd();
					static void Men_Save_Snd();
			        static void end_sound();
};




