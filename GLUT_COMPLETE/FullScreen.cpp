#include "FullScreen.h"

bool FullScreen::gamemode = false;


void FullScreen::habilitar_FULL(){
	if(!gamemode){
	             int w = glutGet(GLUT_SCREEN_WIDTH);
				 int h = glutGet(GLUT_SCREEN_HEIGHT);
				 int pixelDepth = glutGameModeGet( GLUT_GAME_MODE_PIXEL_DEPTH );
				 int refreshRate = glutGameModeGet( GLUT_GAME_MODE_REFRESH_RATE );
				 char temp[64];
				 sprintf( temp, "%dx%d:%d@%d", w, h, pixelDepth, refreshRate );
                   gamemode=true;
					    glutFullScreen();

				 
	
	}
	
}

void FullScreen::deshabilitar_FULL(){
								if(gamemode){
											gamemode=false;
											glutReshapeWindow(800, 540);        /* Restore us */
											glutPositionWindow(7,29);
								}

}