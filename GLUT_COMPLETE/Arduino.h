#pragma once
#include "Serial_Arduino/SerialClass.h"
#include  <iostream>
using namespace std;

class Arduino{

         public:
         
		  static int x; // 2
          static char EntradaDeDatos[256]; //creamos un vector de datos de tipo char en la cual cargaremos el texto que se envia desde el arduino con la funcion SERIAL.WRITE
          static string Data_Recibido;
          static int dataLength; //1
          static int readResult; //0
          static int u;  //1

	      static Serial* ENTRADA;
	      static void Arduino_ini();
	      static void Conexion_Arduino_IN();
		  static void Conexion_Arduino_OUT();

};

