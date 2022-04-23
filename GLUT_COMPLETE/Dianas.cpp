#include "Dianas.h"


double Dianas::R_aum=0;
double Dianas::D_Dyn_Radio=1;

const int Dianas::size = 200;
int Dianas::cont = 0;
int Dianas::Score = 0;
int Dianas::vidas = 3;
int Dianas::disparos=8;
int xa=1;
float Dianas::xc[200];

Dianas *arreglo = new Dianas[200];

Dianas *arreglo_alta = new Dianas[200];

int Dianas::clicked=0; int Dianas::filesize=0 ;

GLuint Dianas::list_dianas;

int xcs=0;

int Dianas::create_scene=1;

float Dianas::gj=0;

int Dianas::go_and_back=1;

float MIN_X[200], MAX_X[200], MIN_Y[200], MAX_Y[200], MIN_Z[200], MAX_Z[200];

struct registro nuevox, borradox;
struct index indexadox;

void Dianas::alta(double Pos_x, double Pos_y, double Pos_z, double r){

	                                                               if(create_scene == true){
																	  arreglo_alta[Dianas::cont].clickx = Pos_x;
																	  arreglo_alta[Dianas::cont].clicky = Pos_y;
																	  arreglo_alta[Dianas::cont].clickz = Pos_z;
																	  arreglo_alta[Dianas::cont].rad= r;

																	  Archivo::file_size = Dianas::cont;
																	  Dianas::cont ++;
                                                                      Dianas::clicked = 1;

																	  cout<<Pos_x<<" "<<Pos_y<<" "<<Pos_z<<endl;
																   }
}

void Dianas::Guardar(){

						remove("Recursos/Files/data.txt");

	                   for (int xc=0; xc<Dianas::cont; xc++){
						                                              Archivo::xc = arreglo_alta[xc].clickx;
																	  Archivo::yc = arreglo_alta[xc].clicky;
																	  Archivo::zc = arreglo_alta[xc].clickz;
																	  Archivo::rd= arreglo_alta[xc].rad;
																	  Archivo::file_size = xc;
																	  Archivo::insertar();
					   }

}

void Dianas::Dib_dianas(){
																for (int l=0; l<Dianas::cont; l++){
																	                         glPushMatrix();
																			                 glRotatef(0, 1, 0, 0);
																		                     glRotatef(0, 0, 1, 0);
																							 glTranslatef(arreglo_alta[l].clickx, arreglo_alta[l].clicky, arreglo_alta[l].clickz);
																		                     glRotatef(Dianas::gj,0,0,1);
																							 Dianas::circle_vect(0,0,0, arreglo_alta[l].rad, 20);
														                                     glPopMatrix();
																}
													


}

void Dianas::draw_from_file(int l){
																	                         glPushMatrix();
																			                 glRotatef(0, 1, 0, 0);
																		                     glRotatef(0, 0, 1, 0);
																							 glTranslatef(arreglo[l].clickx, arreglo[l].clicky, arreglo[l].clickz);
																		                     glRotatef(Dianas::gj,0,0,1);
																							 Dianas::circle_vect(0,0,0, arreglo[l].rad, 20);
														                                     glPopMatrix();

}

void Dianas::circle(float x, float y, float z, float r, int segments) {
	                                                                 
																		glBegin( GL_TRIANGLE_FAN );
																			glVertex3f(x, y, z);
																			for( int n = 0; n <= segments; ++n ) {
																				float const t = 2*M_PI*(float)n/(float)segments;
																				glVertex3f(x + sin(t)*r, y + cos(t)*r, z);
																			}
																		glEnd();
}

void Dianas::circle_vect(float x, float y, float z, float r, int segments) {
	                                                                    int h=0;

																		glColor3f(0.854902, 0.647059, 0.12549);
																		
																		glBegin( GL_TRIANGLE_FAN );
																			glVertex3f(x,y,z);
																			for( int n = 0; n <= segments; ++n ) {

																				float const t = 2*M_PI*(float)n/(float)segments;

																				if(h% 2 == 0){
																				        glColor3f(1, 1, 1);
																				}

																				else{
																				        glColor3f(0, 0, 0);
																				}


																				glVertex3f(x + sin(t)*r, y + cos(t)*r, z);
																				h++;
																			}
																		glEnd();
}

void Dianas::circle_lined(float x, float y, float z, float r, int segments) {
	                                                                    int h=0;

																		glBegin(GL_LINE_LOOP);
																			//glVertex3f(x,y,z);
																			for( int n = 0; n <= segments; ++n ) {

																				float const t = 2*M_PI*(float)n/(float)segments;
                                                                                 glVertex3f(x + sin(t)*r, y + cos(t)*r, z);
																				h++;
																			}
																		glEnd();
}

void Dianas::listar(){
	                   glNewList(Dianas::list_dianas, GL_COMPILE);


}

void Dianas::cargar_desde_archivo(){
	                          Dianas::filesize=0;
	                          xcs=0;
					                          Archivo::data=fopen("Recursos/Files/data.txt", "at+");

                                                       while(fread(&nuevox, sizeof(struct registro),1,Archivo::data) !=0){
																							   cout<<nuevox.nrr<<" ";
																							   cout<<nuevox.xcoord<<" ";
																							   cout<<nuevox.ycoord <<" ";
																							   cout<<nuevox.zcoord <<" ";
																							   cout<<nuevox.radio<<" "<<endl;
																							   arreglo[xcs].clickx = nuevox.xcoord;
																							   arreglo[xcs].clicky = nuevox.ycoord;
																							   arreglo[xcs].clickz = nuevox.zcoord;
																							   arreglo[xcs].rad= nuevox.radio;
																							   xcs++;
																							   Dianas::filesize++;
                                                       }      
                              fclose(Archivo::data); 

							   for (int s=0; s<=Dianas::filesize; s++) {
											                                         MIN_X[s] = arreglo[s].clickx-arreglo[s].rad;
                                                                                     MAX_X[s] = arreglo[s].clickx+arreglo[s].rad;

																					 MIN_Y[s] = arreglo[s].clicky-arreglo[s].rad;
                                                                                     MAX_Y[s] = arreglo[s].clicky+arreglo[s].rad;

																					 MIN_Z[s] = arreglo[s].clickz-arreglo[s].rad;
                                                                                     MAX_Z[s] = arreglo[s].clickz+arreglo[s].rad; 
				               }

}

void Dianas::getScore(float x, float y, float z, int c){

	                                                 for (int sx=0; sx<Dianas::filesize; sx++) {

																					 if((x>=MIN_X[sx]&& x<=MAX_X[sx]) && (y>=MIN_Y[sx]&& y<=MAX_Y[sx]) && (z>=MIN_Z[sx]&& z<=MAX_Z[sx])){

																						                                                      cout<<"ME DIERON"<<endl;
																																			  Dianas::Score+=10;
																					 }
																			         

												   }
	                    
													 if((x>=MIN_X[c]&& x<=MAX_X[c]) && (y>=MIN_Y[c]&& y<=MAX_Y[c]) && (z>=MIN_Z[c]&& z<=MAX_Z[c])){

																						                                                      cout<<"ME DIERON"<<endl;
									                 }
													 else{
													     
																																			  //Dianas::Score-=3;
													 }
}
