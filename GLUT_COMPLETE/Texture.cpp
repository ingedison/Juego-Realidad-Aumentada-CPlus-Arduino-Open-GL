#include <stdio.h>
#include <stdlib.h>

#include "Texture.h"

GLuint Texture::texture[5];
GLubyte Texture::checkImage[checkImageWidth][checkImageHeight][3];

void Texture::makeCheckImage(void){
    int i, j, c;

							for (i = 0; i < checkImageWidth; i++) {
											for (j = 0; j < checkImageHeight; j++) {
												c = ((((i&0x8)==0)^((j&0x8)==0)))*255;
												checkImage[i][j][0] = (GLubyte) c;
												checkImage[i][j][1] = (GLubyte) c;
												checkImage[i][j][2] = (GLubyte) c;
											}
							}
}


int Texture::ImageLoad(char *filename, Imagex *image) {

														FILE *file;
														unsigned long size; // size of the image in bytes.
														unsigned long i; // standard counter.
														unsigned short int planes; // number of planes in image (must be 1)
														unsigned short int bpp; // number of bits per pixel (must be 24)
														char temp; // temporary color storage for bgr-rgb conversion.

    
														if ((file = fopen(filename, "rb"))==NULL){ // make sure the file is there.
																									printf("File Not Found : %s\n",filename);
																									return 0;
														}

															// seek through the bmp header, up to the width/height:

														 fseek(file, 18, SEEK_CUR);

														// read the width

														if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
															printf("Error reading width from %s.\n", filename);
															return 0;
														}

														//printf("Width of %s: %lu\n", filename, image->sizeX);

														// read the height

														if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
																										printf("Error reading height from %s.\n", filename);
																										return 0;
                                                        }

														//printf("Height of %s: %lu\n", filename, image->sizeY);

														// calculate the size (assuming 24 bits or 3 bytes per pixel).

														size = image->sizeX * image->sizeY * 3;

														// read the planes

														if ((fread(&planes, 2, 1, file)) != 1) {
															printf("Error reading planes from %s.\n", filename);
															return 0;
														}

														if (planes != 1) {
															printf("Planes from %s is not 1: %u\n", filename, planes);
															return 0;
														}

														// read the bitsperpixel

														if ((i = fread(&bpp, 2, 1, file)) != 1) {
															printf("Error reading bpp from %s.\n", filename);
															return 0;

														}

														if (bpp != 24) {
															printf("Bpp from %s is not 24: %u\n", filename, bpp);
															return 0;

														}

														// seek past the rest of the bitmap header.

														fseek(file, 24, SEEK_CUR);

														// read the data.

														image->data = (char *) malloc(size);

														if (image->data == NULL) {
															printf("Error allocating memory for color-corrected image data");
															return 0;
														}

														if ((i = fread(image->data, size, 1, file)) != 1) {
															printf("Error reading image data from %s.\n", filename);
															return 0;
														}

														for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)
															temp = image->data[i];
															image->data[i] = image->data[i+2];
															image->data[i+2] = temp;
														}

															// we're done.

															return 1;
}


Imagex * Texture::loadTexture(){
	                           Imagex *image1;  // allocate space for texture
                               image1 = (Imagex *) malloc(sizeof(Imagex));
							    
							   if (image1 == NULL) {
									printf("Error allocating space for image");
									exit(0);
								}

								if (!ImageLoad("Recursos/Menu.bmp", image1)) {
									exit(1);
								}

							 return image1;

}

Imagex * Texture::loadTexture2(){
	                           Imagex *image2;  // allocate space for texture
                               image2 = (Imagex *) malloc(sizeof(Imagex));
							    
							   if (image2 == NULL) {
									printf("Error allocating space for image");
									exit(0);
								}

								if (!ImageLoad("Recursos/cel.bmp", image2)) {
									exit(1);
								}

							 return image2;

}

Imagex * Texture::loadTexture3(){
	                           Imagex *image3;  // allocate space for texture
                               image3 = (Imagex *) malloc(sizeof(Imagex));
							    
							   if (image3 == NULL) {
									printf("Error allocating space for image");
									exit(0);
								}

								if (!ImageLoad("Recursos/snows.bmp", image3)) {
									exit(1);
								}

							 return image3;

}

void Texture::gen_Textures(){

							Imagex *image1 = loadTexture();
							Imagex *image2 = loadTexture2();
							Imagex *image3 = loadTexture3();

							if(image1 == NULL){
								printf("NO SE ENCONTRO LA TEXTURA . ERROR FATAL\n");
								//exit(0);
							}

							if(image2 == NULL){
								printf("NO SE ENCONTRO LA TEXTURA . ERROR FATAL\n");
								//exit(0);
							}
							if(image3 == NULL){
								printf("NO SE ENCONTRO LA TEXTURA . ERROR FATAL\n");
								//exit(0);
							}

							Texture::makeCheckImage();
							glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

							glGenTextures(2, texture); //cuadro
							glBindTexture(GL_TEXTURE_2D, texture[2]);
							glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture
							glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture
							glTexImage2D(GL_TEXTURE_2D, 0, 3, image2->sizeX, image2->sizeY, 0,
							GL_RGB, GL_UNSIGNED_BYTE, image2->data);
							glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

							//Texture Menu
							
							glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

							glBindTexture(GL_TEXTURE_2D, texture[0]);
							glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture
							glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture
							glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0,
							GL_RGB, GL_UNSIGNED_BYTE, image1->data);
							glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

							//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

							glBindTexture(GL_TEXTURE_2D, texture[4]);
							glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture
							glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture
							glTexImage2D(GL_TEXTURE_2D, 0, 3, image3->sizeX, image3->sizeY, 0,
							GL_RGB, GL_UNSIGNED_BYTE, image3->data);
							glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);


							//tetera
							glBindTexture(GL_TEXTURE_2D, texture[1]);
							glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
							glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
							glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
							glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
							glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
							glTexImage2D(GL_TEXTURE_2D, 0, 3, checkImageWidth,
							checkImageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE,&checkImage[0][0][0]);

							//glEnable(GL_TEXTURE_2D);

							glShadeModel(GL_FLAT);


}
