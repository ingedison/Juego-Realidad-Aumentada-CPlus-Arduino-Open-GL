#include "Keyboard.h"

bool Keyboard::key[256];

void Keyboard::keyDown(unsigned char k, int x, int y){

	key[k] = true;

} 

void Keyboard::keyUp(unsigned char k, int x, int y){

	key[k] = false;

}