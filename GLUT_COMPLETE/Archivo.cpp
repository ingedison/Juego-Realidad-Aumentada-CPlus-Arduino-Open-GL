#include "Archivo.h"

                 int Archivo::modoretornar;   
				 FILE *Archivo::data;
				 FILE *Archivo::Index;
				 FILE *Archivo::aux;
				 int Archivo::file_size=0;
				 float Archivo::xc=0; float Archivo::yc=0; float Archivo::zc=0; float Archivo::rd=0;
				 struct registro nuevo, borrado;
				 struct index indexado;

                void Archivo::insertar(){                
                                         data=fopen("Recursos/Files/data.txt","at+");
                                         Index=fopen("Recursos/Files/index.txt","a+");
										 aux=fopen("Recursos/Files/Auxi.txt","a+");

				                         char add;
										 nuevo.nrr = Archivo::file_size;
										 nuevo.xcoord = Archivo::xc;
										 nuevo.ycoord  = Archivo::yc;
										 nuevo.zcoord  = Archivo::zc;
										 nuevo.radio  = Archivo::rd;

                                             fwrite(&nuevo, sizeof(struct registro), 1, data);
                                             
                                           fclose(data);
                                           fclose(Index);
                                    
                }

				void Archivo::consultar(){

					                          data=fopen("Recursos/Files/data.txt", "at+");
                                                       while(fread(&nuevo, sizeof(struct registro),1,data) !=0){
																							   cout<<nuevo.nrr<<" ";
																							   cout<<nuevo.xcoord<<" ";
																							   cout<<nuevo.ycoord <<" ";
																							   cout<<nuevo.zcoord <<" ";
																							   cout<<nuevo.radio<<" "<<endl;
                                                       }      
                                            fclose(data);
				                          
				
				}