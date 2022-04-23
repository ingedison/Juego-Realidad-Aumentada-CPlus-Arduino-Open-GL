#include "Texto.h"

font g_TheFont = GLUT_BITMAP_HELVETICA_10;


void SetFont(font f) {
	g_TheFont = f;
}

void DrawFont(const char* text,int x,int y) {

	int i=0;

	// set position for text
	glRasterPos2i(x,y);

	// draw each character in the text string
	while(text[i]) {
		glutBitmapCharacter(g_TheFont,text[i]);
		++i;
	}
}


unsigned int FontWidth(const char* text) {
	return glutBitmapLength(g_TheFont,(unsigned char*)text);
}

unsigned int FontHeight() {

	if(g_TheFont==GLUT_BITMAP_9_BY_15)
		return 15;
	if(g_TheFont==GLUT_BITMAP_8_BY_13)
		return 13;
	if(g_TheFont==GLUT_BITMAP_TIMES_ROMAN_10)
		return 10;
	if(g_TheFont==GLUT_BITMAP_TIMES_ROMAN_24)
		return 24;
	if(g_TheFont==GLUT_BITMAP_HELVETICA_10)
		return 10;
	if(g_TheFont==GLUT_BITMAP_HELVETICA_12)
		return 12;
	if(g_TheFont==GLUT_BITMAP_HELVETICA_18)
		return 18;
	return 0;
}

