//mouse.cpp

#include "Mouse.h"

 sf::SoundBuffer buffer, bsd;
 sf::Sound sound, ondax;
char playsound[]= "Recursos/Audios/gun.wav";
char playsoundasc[]= "Recursos/Audios/nobalas.wav";

int Mouse::act_diana=0;

            float Mouse::sensividad = 1.0;
            int Mouse::currentX = 0;
			int Mouse::currentY =0;
			int Mouse::lastX = 0;
			int Mouse::lastY = 0;
			int Mouse::deltaX = 0;
			int Mouse::deltaY = 0;
			int Mouse::active = 0;
			int Mouse::click = 0;
			int Mouse::screen_capture_avalaible=0;
			int Mouse::get_sc=0;
			int Mouse::gaming = 0;

			double Mouse::objx = 0, Mouse::objy = 0, Mouse::objz = 0;
			double Mouse::Motionobjx = 0, Mouse::Motionobjy = 0, Mouse::Motionobjz = 0;

			int Mouse::h=0;
			int Mouse::w=0;

void Mouse::clicksound(){
	                      if (!buffer.loadFromFile(playsound))
                              return;
						  
					     sound.setBuffer(buffer); 
			}

void Mouse::clicksound2(){
	                      if (!bsd.loadFromFile(playsoundasc))
                              return;
						  
					     ondax.setBuffer(bsd); 

			}


void Mouse::move(int x, int y) {
									currentX = x;
									currentY = y;

									double modview[16], project[16];
									int v_port[4];
								    float zx = 1;

									glGetDoublev( GL_PROJECTION_MATRIX, project);
									glGetDoublev( GL_MODELVIEW_MATRIX, modview);
									glGetIntegerv( GL_VIEWPORT, v_port );
                                    glReadPixels( x, v_port[3]-y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &zx );	
                                    gluUnProject( x, v_port[3]-y, zx, modview, project, v_port, &Mouse::Motionobjx, &Mouse::Motionobjy, &Mouse::Motionobjz );
									Dianas::circle(Mouse::Motionobjx, Mouse::Motionobjy, Mouse::Motionobjz, 3, 20);
									//cout<<Mouse::Motionobjx<<" "<<Mouse::Motionobjy<<" "<<Mouse::Motionobjz<<endl;
									
} 

void Mouse::update() {
                                    deltaX = currentX - lastX;
									deltaY = currentY - lastY;

									lastX = currentX;
									lastY = currentY;

							

}

void Mouse::mouse(int btn, int state, int x, int y){

	                                              if (btn == GLUT_LEFT_BUTTON){
												                 if (state == GLUT_DOWN) {
																	                                Mouse::active= 1;
																	                                Mouse::click = 1;
																	                                double modelview[16], projection[16];
																									int viewport[4];
																									float z = 1;
																							if (Mouse::gaming==1){
																									if (Dianas::vidas > 0 ){
																											
																												   Dianas::disparos--;
																															 if (Dianas::disparos>0){
																																				   sound.play();
																															 }
																															 else{
																																 cout<<"Recargar"; 
																																 ondax.play();
																															 }
																															 if(Dianas::disparos<0 || Dianas::vidas<=0){
																															                          Dianas::disparos=0;
																															 }
																									}
																									if (Dianas::vidas<=0){
																									                      Dianas::disparos=0; Dianas::vidas=0;
																									}
																                       }
																									 glGetDoublev( GL_PROJECTION_MATRIX, projection );
																									 glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
																									 glGetIntegerv( GL_VIEWPORT, viewport );

																									glReadPixels( x, viewport[3]-y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z );	

	                                                                                                gluUnProject( x, viewport[3]-y, z, modelview, projection, viewport, &Mouse::objx, &Mouse::objy, &Mouse::objz );

																									if(Mouse::screen_capture_avalaible==1){

																														if(Mouse::objz<-10){
																																			Dianas::alta(Mouse::objx, Mouse::objy, Mouse::objz, Dianas::D_Dyn_Radio);
																														 }
																														  else{
																																			Dianas::alta(Mouse::objx, Mouse::objy, -10, Dianas::D_Dyn_Radio);
																														}
																									}

                                                                                                    //if(Mouse::get_sc==1){
																									                                // cout<<Mouse::objx<<" "<< Mouse::objy<<" "<<Mouse::objz<<endl;
																									if (Dianas::disparos>0){
																																	 Dianas::getScore(Mouse::objx, Mouse::objy,Mouse::objz, Mouse::act_diana);
																									}
																									//}

                                                                                                    


																 }
																
																 else if (state == GLUT_UP){
																	                  Mouse::click = 0;
																	                 
																 }
					
												  }

												  if (btn == GLUT_RIGHT_BUTTON){
												                                if(Mouse::click == 1){
																										                  Mouse::click=0;

																									 }
												  }
}
