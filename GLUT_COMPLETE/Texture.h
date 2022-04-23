#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define checkImageWidth 64
#define checkImageHeight 64

using namespace std;

struct Images {
				unsigned long sizeX;
				unsigned long sizeY;
				char *data;

};

typedef struct Images Imagex;




class Texture{
	        
		        public:
							 unsigned int textureID;
							 static GLuint texture[5];
							 static GLubyte checkImage[checkImageWidth][checkImageHeight][3];

							 //	M M
							 static void makeCheckImage(void); // done
							 static int ImageLoad(char *filename, Imagex *imageg); //done
							 static Imagex * loadTexture();
							 static Imagex * loadTexture2();
							 static Imagex * loadTexture3();
							 static void gen_Textures();

			 // M C
	         //Texture(void* data, int w, int h, int format);
			 //static Texture* loadBMP(const char* filename);
	 
};

