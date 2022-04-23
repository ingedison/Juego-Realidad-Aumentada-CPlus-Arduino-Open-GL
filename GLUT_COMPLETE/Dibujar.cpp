#include "Dibujar.h"

const float Dibujar::WALKING_SPEED = 3.2; 
bool Dibujar::gamemode = false;
int Ani_move = 0, G_back=1, hj = 0;
sf::Font Dibujar::font;
unsigned int Dibujar::g_persp=0;
unsigned int Dibujar::g_ortho=0;
unsigned int Dibujar::g_ortho2D=0;
string Result; 
int hcx=0;

 char music[]= "Recursos/Audios/GTA.ogg";
 sf::Music musicx;
 void Musica(char playmusic[]);

char quote[6][80];
char *hola;
int numberOfQuotes=0,i;
int Menu_State=1;
int Menu_Config_State=1;
int cv=0;
int Menu_Enter=0, hg=0;
int change_screen = 0, Select_quad=1, Select_quad_modify=1, modify_enter=0, fgv=0;
int sd=0;
int Level_select=0;
int get_Time_Dianas = 0;
int g=0;
int gamenter = 0;
int arduino_Color = 1, band = 0;

 sf::SoundBuffer buf, bf, bug, frog, endsx;
 sf::Sound sonido, snd, sndx, csndx, lastpl;

char playso[]= "Recursos/Audios/Menu_Move.wav";
char pls[]= "Recursos/Audios/error.wav";
char plsx[]= "Recursos/Audios/Menu_Enter.wav";
char plsxd[]= "Recursos/Audios/Save.wav";
char aok[]= "Recursos/Audios/END.wav";

void Dibujar::sound(){
	                                if (!buf.loadFromFile(playso))
                                     return;
						  
					             sonido.setBuffer(buf); 
			}

void Dibujar::snderror(){
                                  if (!bf.loadFromFile(pls))
                                     return;
						             snd.setBuffer(bf); 
   }

void Dibujar::Men_Ent_Snd(){
	                     if (!bug.loadFromFile(plsx))
                                     return;
						             sndx.setBuffer(bug); 
}

void Dibujar::Men_Save_Snd(){
	                     if (!frog.loadFromFile(plsxd))
                                     return;
						             csndx.setBuffer(frog); 
}

void Dibujar::end_sound(){
	                     if (!endsx.loadFromFile(aok))
                                     return;
						             lastpl.setBuffer(endsx); 
}

void Musica(char playmusic[]){
								
								if (!musicx.openFromFile(playmusic))
									 return;
								     
								      musicx.setVolume(20);			
                                      std::cout << std::endl;
}

void Dibujar::pre_eventos(){
	
							Tiempo::current = ((float) glutGet(GLUT_ELAPSED_TIME)) / 1000;
							Tiempo::delta = Tiempo::current - Tiempo::last;
							Tiempo::last = Tiempo::current;

							//cout <<MOUSE_LAST_X <<", "<<MOUSE_LAST_Y<<endl;
    
							Mouse::update();

							//process Mouse

							//Camera::rotation.y += (float)Mouse::deltaX*Mouse::sensividad;
							//Camera::rotation.x += (float)Mouse::deltaY*Mouse::sensividad;

							if(Camera::rotation.y > Camera::maxtilt){
								Camera::rotation.y= Camera::maxtilt;
								}
								if(Camera::rotation.y < (-Camera::maxtilt)){
								   Camera::rotation.y= -Camera::maxtilt;
								}

	
								if(Camera::rotation.x > Camera::maxtiltx){
									Camera::rotation.x= Camera::maxtiltx;
								}
								if(Camera::rotation.x < (-Camera::maxtiltx)){
								   Camera::rotation.x= -Camera::maxtiltx;
								}


	//procesar teclas
								if(Keyboard::key['A'] || Keyboard::key['a']){

									if(change_screen==0){
									                                    if(Menu_Enter==0){
																				if(Menu_State>1){
									                                                              Menu_State -= 1;
																								  sonido.play();
																				}
																				else{
																				                 snd.play();
																				}
																		}	

																		if(Menu_State==1 && Menu_Enter==1){
																			                              if(Select_quad>1){
																			                               Select_quad -= 1;
																										   sonido.play();
																		                                   }
																										  else{
																															 snd.play();
																											}

																		}

																		if(Menu_State==2 && Menu_Enter==1){
																			                              if(Select_quad_modify>1){
																			                               Select_quad_modify -= 1;
																										   sonido.play();
																		                                   }
																										  else{
																															 snd.play();
																											}

																		}

																		if(Menu_State==3 && Menu_Enter==1){
																		                                   if(Menu_Config_State>1){
									                                                                                                Menu_Config_State -= 1;
																								                                    sonido.play();
																				                          }
																											else{
																															 snd.play();
																											}
																		
																		}
									}

									if(change_screen==1){
															if(modify_enter==1){
										                                       
																				 if(Dianas::D_Dyn_Radio > 0.4 && Dianas::D_Dyn_Radio < 3.2){
																											 Dianas::D_Dyn_Radio +=0.02;
																				 }
															}

									}
									                                            Keyboard::key['A']=false;
																				Keyboard::key['a']=false;
								}

								if(Keyboard::key['B'] || Keyboard::key['b']){
									if(change_screen==0){
									                                       if(Menu_Enter==0){
										                                        if(Menu_State<5){
									                                                              Menu_State += 1;
																								  sonido.play();
																				}
																				else{
																				                 snd.play();
																				}
																		   }	             

																		   if(Menu_State==1 && Menu_Enter==1){
																		                                     if(Select_quad<4){
																											   Select_quad += 1;
																											   sonido.play();
																											  }
																											 
																											   else{
																																	 snd.play();
																													}
																		   }

																		    if(Menu_State==2 && Menu_Enter==1){
																		                                     if(Select_quad_modify<4){
																											       Select_quad_modify += 1;
																											       sonido.play();
																											  }
																											 
																											   else{
																																	 snd.play();
																													}
																		   }

																		   if(Menu_State==3 && Menu_Enter==1){
																			    if(Menu_Config_State<3){
									                                                              Menu_Config_State += 1;
																								  sonido.play();
																				}
																				else{
																				                 snd.play();
																				}
                                                                             }
									                                           
									}

									if(change_screen==1){
															if(modify_enter==1){
										                                       
																				 if(Dianas::D_Dyn_Radio > 0.8 && Dianas::D_Dyn_Radio < 3.5) {
																											 Dianas::D_Dyn_Radio -=0.02;
																				 }
															}

									}


									 Keyboard::key['b']=false;
									 Keyboard::key['B']=false;	                                        
								}

								if(Keyboard::key['C'] || Keyboard::key['c']){

									                if(change_screen==1){
														                  
																		  if(modify_enter==1){
																			                  Dianas::Guardar();
																							  Dianas::create_scene=0;
																		  }
													}

									                if(change_screen==0){
														                    if(Menu_State==1 && Menu_Enter==1){
																					              if(Select_quad==1){
																			                               // Menu_State=1;
																										           change_screen=1;
																		                                           Ani_move = 1;
																										           Dianas::create_scene=0;
																										           Mouse::get_sc=1;
																													hcx=0; g=0;
																													Mouse::gaming=1;
																										            Dianas::cargar_desde_archivo();

																										   if(get_Time_Dianas == 0){
																						                           Tiempo::Tiempo_actual = ((float) glutGet(GLUT_ELAPSED_TIME));
																												   Tiempo::T_total = Tiempo::Tiempo_actual + Tiempo::Time_On_Screen;
																												   Tiempo::Remainig = Tiempo::Time_On_Screen - Tiempo::Tiempo_actual;

																												   Tiempo::Time_for_each = Tiempo::Time_On_Screen/Dianas::filesize;
                                                                                                                   get_Time_Dianas = 1;
																												   gamenter=1;
																										  }
																										 
																									    
																					   }

																		    }

																			if(Menu_State==2 && Menu_Enter==1){
																					   if(Select_quad_modify==1){
																			                             // Menu_State=1;
																										  change_screen=1;
																										  modify_enter=1;
																			                              Mouse::screen_capture_avalaible=1;
																										  Dianas::create_scene = Mouse::screen_capture_avalaible;
																										  Ani_move=0;
																					  }
																					   else{
																					                      Mouse::screen_capture_avalaible=0;
																					   }

																		    }
																			 
									                                         
									                                         if (hg==0){
									                                                    Menu_Enter=1;
																						sndx.play();
																			 }
																			 if (hg==1){
																			           if(Menu_Enter=1){
																			                            Menu_Enter=0;
																										csndx.play();
																			            }
																			 }
													}

													
																			 Keyboard::key['c']=false;
																			 Keyboard::key['C']=false;
										  
								}

								if(Keyboard::key['D'] || Keyboard::key['d']){
										  
								}

								if(Keyboard::key['M'] || Keyboard::key['m']){
										  FullScreen::habilitar_FULL();
								}
								
								if(Keyboard::key['N'] || Keyboard::key['n']){
										 FullScreen::deshabilitar_FULL();
								}

								if(Keyboard::key[' ']){
	
								}

								if(Keyboard::key['s'] || Keyboard::key['S']){
								
								}

								if(Keyboard::key['Z'] || Keyboard::key['z']){
														                    change_screen=0;
																			modify_enter=0;
																			get_Time_Dianas == 0;
																			gamenter=0;
																			hj=0;
																			hcx=0;
																			Mouse::gaming=0;
								}


}

void Dibujar::Menu(){

	                                                  glEnable(GL_TEXTURE_2D);
												      glBindTexture(GL_TEXTURE_2D, Texture::texture[0]);

												      glPushMatrix();

												       //glRotatef(Camera::rotation.x, 1, 0, 0);
												      // glTranslatef(-Camera::rotation.y, Camera::rotation.x, 0);


												       glBegin(GL_POLYGON);


													   glTexCoord2f(0.0, 1.0);
													   glVertex3f(100.0, 50.0, -120.0);

													   glTexCoord2f(1.0, 1.0);
													   glVertex3f(-100.0, 50.0, -120.0);

													   glTexCoord2f(1.0, -0.0);
													   glVertex3f(-100, -50.0, -120);

													   glTexCoord2f(0.0, -0.0);
													   glVertex3f(100, -50.0, -120);

													   glEnd();

													   glDisable(GL_TEXTURE_2D);

												    
													   glPopMatrix();

													   glPushMatrix();
													   
													   glTranslatef(-Camera::position.x, -27, Camera::position.z);
														glColor3f(0.545098, 0.270588, 0.0745098);
														Terreno::drawScene();
													glPopMatrix();
}

void Dibujar::Escenario(){
	                             
												   glEnable(GL_TEXTURE_2D);
												   glBindTexture(GL_TEXTURE_2D, Texture::texture[3]);

												   glPushMatrix();

												   glRotatef(Camera::rotation.x, 1, 0, 0);
												   glTranslatef(-Camera::rotation.y, Camera::rotation.x, 0);


												  glBegin(GL_POLYGON);

												  
													glTexCoord2f(1, 1);
													glVertex3f(200.0, 80.0, -120.0);

													glTexCoord2f(0, 1);
													glVertex3f(-200.0, 80.0, -120.0);

													glTexCoord2f(0, -0.8);
													glVertex3f(-200, -100.0, -120);

													glTexCoord2f(1, -0.8);
													glVertex3f(200, -100.0, -120);

													glEnd();

													glDisable(GL_TEXTURE_2D);

												    
													glPopMatrix();

							
													glPushMatrix();

													   glRotatef(Camera::rotation.x, 1, 0, 0);
													   glRotatef(Camera::rotation.y, 0, 1, 0);
													   glRotatef(Camera::rotation.z, 0, 0, 1);
													   glTranslatef(-Camera::position.x, -Camera::position.y, Camera::position.z);

													 //glColor3f(0.854902, 0.647059, 0.12549);
													    if (arduino_Color == 1){
														glColor3f(0.839216, 0.839216, 0.839216);
														}
														if (arduino_Color == 2){
                                                        glColor3f(1, 0.54902, 0); //
														}
														if (arduino_Color == 3){
                                                        glColor3f(0.133333, 0.545098, 0.133333);
														}
														if (arduino_Color == 4){
                                                        glColor3f(0, 0, 0.545098);
														}
													   
														Terreno::drawScene();

													//glColor3f(1, 0.54902, 0);	  
                                                     
												   glPopMatrix();


}

void Dibujar::output(GLfloat x, GLfloat y, char *text) {
														   char *p;
														   glPushMatrix();
														   glTranslatef(x, y, 0);
														   for (p = text; *p; p++){
																				   glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
														   }
														   glPopMatrix();
}

void Screen_Change_Event(){
	                                                if(Mouse::screen_capture_avalaible == 1 && change_screen==1){ 
																		glPushMatrix();
																						Dianas::Dib_dianas();
																		glPopMatrix();
													}

													if(Mouse::screen_capture_avalaible == 1 && change_screen==1 && Dianas::create_scene==1){
																								glPushMatrix();
																								if(Mouse::Motionobjz<-10){
																								glTranslatef(Mouse::Motionobjx, Mouse::Motionobjy, Mouse::Motionobjz);
																								}else{
																								glTranslatef(Mouse::Motionobjx, Mouse::Motionobjy, -10);
																								}

																								Dianas::circle_vect(0,0,0,Dianas::D_Dyn_Radio,20);
																								glPopMatrix();

													}

													if(change_screen==0){
													                     Dibujar::Menu();
																		 get_Time_Dianas == 1;

													}

													if(change_screen==1){
													                    Dibujar::Escenario();
																		Menu_State=1;
																		Menu_Config_State=1;
																		if (Mouse::screen_capture_avalaible==0){
																			                            
																			                            if(g==0){
																											      Tiempo::Dia_t_ini = ((float) glutGet(GLUT_ELAPSED_TIME));
																												  Tiempo::Dia_t_fin = Tiempo::Dia_t_ini + Tiempo::Time_for_each;
																												  g=1;
																										}

																										Tiempo::compare = ((float) glutGet(GLUT_ELAPSED_TIME));

																										if(Tiempo::compare >= Tiempo::Dia_t_fin-200 && Tiempo::compare <= Tiempo::Dia_t_fin+200){
																										     hcx++;
																										     g=0;
																										}
																									Mouse::act_diana = hcx;
																									   Dianas::draw_from_file(hcx);

																		     }

																		if(Menu_State==1 && Menu_Enter==1){
																					   if(Select_quad==1){
																						                Dianas::create_scene=0;
																						   
																					   }
																		}

													}

}

void Movement(){
	            if(Ani_move==1){

														if(G_back==1){
																		Camera::rotation.y +=0.5;
																		 if(Camera::rotation.y >= 80){
																									  G_back=0;
																									  Dianas::go_and_back=0;
																		}
														}

														if (G_back==0){
															        Camera::rotation.y -=0.5;

														            if (Camera::rotation.y <= -80){
                                                                                                       G_back=1;
																									   Dianas::go_and_back=1;
																	}
														 }

                                                    }
}

void Indicators(){
	                                                                                    
																						SetFont(GLUT_BITMAP_HELVETICA_18);
																						DrawFont("A = Arriba",550,-700);
																						DrawFont("B = Abajo",700,-700);
																						DrawFont("C = Entrar",840,-700);
																						DrawFont("A",80,-600);
																						DrawFont("B",120,-700);
																						DrawFont("D",40,-700);
																						DrawFont("C",80,-800);

}

void Indicators_on_crating(){
	                                                                                    
																						SetFont(GLUT_BITMAP_HELVETICA_18);

																						DrawFont("A = Aumentar",450,-900);
																						DrawFont("B = Reducir ",600,-900);
																						DrawFont("C = Guardar ",730,-900);
																						DrawFont("D = Cancelar",870,-900);

																						DrawFont("A",80,-600);
																						DrawFont("B",120,-700);
																						DrawFont("D",40,-700);
																						DrawFont("C",80,-800);

}

void Indicators_Return(){
	                                                                                    
																						SetFont(GLUT_BITMAP_HELVETICA_18);
																						DrawFont("A = Arriba",550,-700);
																						DrawFont("B = Abajo",700,-700);
																						DrawFont("C = Guardar",840,-700);
																						DrawFont("A",80,-600);
																						DrawFont("B",120,-700);
																						DrawFont("D",40,-700);
																						DrawFont("C",80,-800);

}

void Menu_Set(){
	           SetFont(GLUT_BITMAP_TIMES_ROMAN_24);
																						if(Menu_State==1){
																					                      glColor3f(0.854902, 0.647059, 0.12549);                 
																						}
																						DrawFont("* Jugar ",550,250);
																						glColor3f(1, 1, 1); 
																						if(Menu_State==2){
																					                      glColor3f(0.854902, 0.647059, 0.12549);                 
																						}
																						DrawFont("* Crear Escenario ",550,150);
																						glColor3f(1, 1, 1); 
																						if(Menu_State==3){
																					                      glColor3f(0.854902, 0.647059, 0.12549);                 
																						}
																						DrawFont("* Configuracion",550,50);
																						glColor3f(1, 1, 1); 

																						if(Menu_State==4){
																					                      glColor3f(0.854902, 0.647059, 0.12549);                 
																						}
																						DrawFont("* Instrucciones",550,-50);
																						glColor3f(1, 1, 1); 

																						if(Menu_State==5){
																					                      glColor3f(0.854902, 0.647059, 0.12549);                 
																						}
																						DrawFont("* Creditos",550,-150);
																						glColor3f(1, 1, 1); 
}

void Game_Confing(){
	                SetFont(GLUT_BITMAP_TIMES_ROMAN_24);
					                                                                    if(Menu_Config_State==1){
																					                      glColor3f(0.854902, 0.647059, 0.12549);                 
																						}
																						DrawFont("Vidas:",550,250);
																						DrawFont("/// ",550,150);
																						DrawFont("x3 ",800,150);
																						glColor3f(1, 1, 1); 

																						if(Menu_Config_State==2){
																					                      glColor3f(0.854902, 0.647059, 0.12549);                 
																						}
																						DrawFont("Disparos ",550, 20);
																						DrawFont("/// ",550,-80);
																						DrawFont("x3 ",800,-80);
																						glColor3f(1, 1, 1); 

																						if(Menu_Config_State==3){
																					                      glColor3f(0.854902, 0.647059, 0.12549);                 
																						}
																						DrawFont("Tiempo ",550,-210);
																						DrawFont("/// ",550,-310);
																						DrawFont("x3 ",800,-310);
																						glColor3f(1, 1, 1); 


}

void  Select_Scene(){
	                                     glPushMatrix();
	                			         glBegin(GL_QUADS);
					                     glVertex3f(-40.0, 16.0, -80);
					                     glVertex3f(0.0, 16.0, -80);
					                     glVertex3f(0.0, -14.0, -80);
					                     glVertex3f(-40.0, -14.0, -80);
	                                     glEnd();
										 glPopMatrix();

										 glPushMatrix();
										 glColor3f(1.0f, 1.0f, 1.0f);
										 glTranslatef(40, 0, 0);

										            glBegin(GL_QUADS);
													 glVertex3f(-35.0, 13.0, -80);
													 glVertex3f(0.0, 13.0, -80);
													 glVertex3f(0.0, -11.0, -80);
													 glVertex3f(-35.0, -11.0, -80);
													 glEnd();
                                         glPopMatrix();

										 glPushMatrix();
										 glColor3f(0.0f, 1.0f, 1.0f);
										 glTranslatef(80, 0, 0);
										             glBegin(GL_QUADS);
													 glVertex3f(-35.0, 13.0, -80);
													 glVertex3f(0.0, 13.0, -80);
													 glVertex3f(0.0, -11.0, -80);
													 glVertex3f(-35.0, -11.0, -80);
													 glEnd();
                                         glPopMatrix();

										 glPushMatrix();
										 glColor3f(0.0f, 1.0f, 1.0f);
										 glTranslatef(120, 0, 0);
										             glBegin(GL_QUADS);
													 glVertex3f(-35.0, 13.0, -80);
													 glVertex3f(0.0, 13.0, -80);
													 glVertex3f(0.0, -11.0, -80);
													 glVertex3f(-35.0, -11.0, -80);
													 glEnd();
                                         glPopMatrix();



										 

}

void Indicaciones_De_Creado(){
	                           SetFont(GLUT_BITMAP_HELVETICA_18);
							   DrawFont("Mueva El Mouse, Haga click o Dispare En La Pantalla Para   ",30,900);
							   DrawFont("Ubicar Las Dianas, A -> Aumentar B -> Disminuir Tamano.    ",30,830);
							   glColor3f(0.823529, 0.411765, 0.117647);
							   Indicators_on_crating();
}

void Dibujar_Menus(){
	                                                                             glCallList(Dibujar::g_ortho);
																				 glColor3f(1.0, 1.0, 1.0);
																				 glPushAttrib(GL_ENABLE_BIT);
																				 glDisable(GL_LIGHTING);

																				 if(change_screen==0){
																				 glPushMatrix();
																					glTranslatef(85.0, -681.0, 0.0);
																					glScalef(0.8,2.1,0);
																					glColor3f(1.0f, 1.0f, 1.0f);
																					
																		          Dianas::circle_lined(0,0,0,70,80);
																				  glPopMatrix();

																				 }
																			     glPushMatrix();
																					  glRotatef(90, 0.0, 0.0, 1.0);
																					  glLoadIdentity();

																					  glEnable(GL_LINE_SMOOTH);
																					  glLineWidth(10.0);
																					  glDisable(GL_BLEND);

																					  if(change_screen==0){
																									  if(Menu_Enter==0){
																														Dibujar::output(550, 450, "Menu");
																									  }
																									  else{
																											  if(Menu_State==1){
																											  Dibujar::output(130, 650, "Elegir");
	                                                                                                            SetFont(GLUT_BITMAP_TIMES_ROMAN_24);
					                                                                                            DrawFont("Seleccione un escenario para",550,700);
																												DrawFont("Iniciar la partida de tiro",550,600);
																											  }

																											    if(Menu_State==2){
																											  Dibujar::output(130, 650, "Crear");
																											  
	                                                                                                            SetFont(GLUT_BITMAP_TIMES_ROMAN_24);
					                                                                                            DrawFont("Seleccione un escenario para",550,700);
																												DrawFont("Crear dianas de juego",550,600);
																											  }


																											  if(Menu_State==3){
																											  Dibujar::output(550, 450, "Config");
																											  }
																											  
																											  if(Menu_State==4){
																											  Dibujar::output(200, 650, "Instrucciones");
																											  }
																											  if(Menu_State==5){
																											  Dibujar::output(550, 450, "Credits");
																											  }
																									  }

																					  }

																					  glPopAttrib();
													                            glPopMatrix();

																				glPushMatrix();

																				
																				
                                                                            
															 if(change_screen==0){
																				if(Menu_Enter==0){
																						          Menu_Set();
																								  Indicators();
																								  hg=0;
																				}
																				if(Menu_Enter==1){
																					hg=1;
																					if (Menu_State==3){
																						              Game_Confing();
																					}
																					if (Menu_State==4){
																					}
																					Indicators_Return();
																				}	
															 }
																				

																				glPopMatrix();

															
																					   if(modify_enter==1){
																						                        Indicaciones_De_Creado();
																					   }

																					   if(gamenter == 1){
																						                                    if(Mouse::click==0){
																															  stringstream strs;
																															  strs << Dianas::Score;
																															  string temp_str = strs.str();
																															  char* char_type = (char*) temp_str.c_str();
																															  hola = char_type;
																															  DrawFont(char_type,930,800);
																															}
																															Tiempo::Tiempo_actual = ((float) glutGet(GLUT_ELAPSED_TIME));
																												            Tiempo::Remainig = (Tiempo::T_total  - Tiempo::Tiempo_actual) /1000;
																															//cout<<Tiempo::Remainig<<endl;

																															SetFont(GLUT_BITMAP_TIMES_ROMAN_24);
																															stringstream strx;
																															strx << Tiempo::Remainig;
																															string temp_str = strx.str();
																															char* char_types = (char*) temp_str.c_str();
																															if(Tiempo::Remainig>0){		  
																															                       DrawFont(char_types,930,900);
																															}
																															else{
																															                      
																																				   if (hj == 0){
																																				       Sleep(2000);
																																				       musicx.stop();
																																					   Sleep(2000);
                                                                                                                                                       hj = 1;
																																				   }
																																				   
																																				   if(hj==1){
																																					          DrawFont("GAME OVER" , 500,0);
																																							  DrawFont(hola,750,500);

																																							  if(fgv==0){
																																							  lastpl.play();
																																							  fgv=1;
																																							  }
																																				   }
																																				   

																															}

																															DrawFont("Tiempo: ",800,900);
																															DrawFont("Puntaje: ",800,800);
																												            DrawFont("Vidas: ",50,900);
																															DrawFont("Disparos: ",50,800);
																														
																															  stringstream strsd;
																															  strsd << Dianas::disparos;
																															  string temp_str2 = strsd.str();
																															  char* char_type_x = (char*) temp_str2.c_str();
																															  DrawFont(char_type_x,190,800);


																															  stringstream strsdx;
																															  strsdx << Dianas::vidas;
																															  string temp_str2x = strsdx.str();
																															  char* char_type_xs = (char*) temp_str2x.c_str();
																															  DrawFont(char_type_xs,190,900);
																						   
																									    }


}

void Dibujar::display(){
							                        Dibujar::pre_eventos();
													
													glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

													Dibujar_Menus();

													if (cv == 0){
														 Musica(music);
											             musicx.play();
														cv =1;
													}
													 Tiempo::Tiempo_actual = ((float) glutGet(GLUT_ELAPSED_TIME));
													 cout<<Tiempo::Tiempo_actual<<endl;
													glCallList(Dibujar::g_persp);

																					glMatrixMode(GL_MODELVIEW);
																					glLoadIdentity();
																					glColor3f(0.0, 0.647059, 0.12);
																					glShadeModel(GL_SMOOTH);
																					glEnable(GL_NORMALIZE);
																					glPointSize(15);
																					
																					if(change_screen==0){
																										if(Menu_Enter==1){
																														  if (Menu_State==1 || Menu_State==2){
																																			    Select_Scene();
																																			
																														   }
																										}  
																					}
																					
											
																					Movement();
																					Screen_Change_Event();


																					//cuadro de puntaje 

																					if (hj ==1 && change_screen == 1 && Menu_State == 1){
																						//glEnable(GL_TEXTURE_2D);
												                                              //glBindTexture(GL_TEXTURE_2D, Texture::texture[0]);
																						                 glColor3f(0.823529, 0.411765, 0.117647);
																										  glBegin(GL_QUADS);
																										   //glColor3f(0,0,0);
																										   
																										   glTexCoord2f(1, 1);
																										   glVertex3f(-10,7,-30);
																										   glTexCoord2f(0, 1);
																										   glVertex3f(10,7,-30);
																										   glTexCoord2f(0, -1);
																										   glVertex3f(10,-7,-30);
																										   glTexCoord2f(1, -1);
																										   glVertex3f(-10,-7,-30);
																										   glEnd();

												  
																					  // glDisable(GL_TEXTURE_2D);
																					}


									   Arduino::readResult = Arduino::ENTRADA->ReadData(Arduino::EntradaDeDatos,Arduino::dataLength);

									   std::string test(Arduino::EntradaDeDatos);

									   if(Arduino::readResult!=-1){
														  std::cout<<std::endl<<std::endl;
														  std::cout<<" "<<Arduino::EntradaDeDatos<<std::endl;
														  Arduino::u=Arduino::u+1;

														  if(test=="H"){
															        if (band == 0){
																				   if(arduino_Color > 0 && arduino_Color < 4){
																														   arduino_Color++;
																				   }
																				   else{
																											   band = 1;
																	            }
																	 }
																	   

																	   if (band == 1) {
																								  if(arduino_Color > 0 && arduino_Color < 4){
																														   arduino_Color--;
																				   }
																								  else{
																											   band = 0;
																	                             }
																	   }
														  }

														  if(test=="Y"){
															           Dianas::disparos=8;
														               Dianas::vidas--;
														  }

														  if(test=="C"){
														  
														  }

														 }
											   test = " ";

										//efecto corrido de dianas

										   if(G_back==0){
	   									   Dianas::gj+=10.0;
										   }
										   else{
											Dianas::gj-=10.0;
										   }
								   glutSwapBuffers();

}
