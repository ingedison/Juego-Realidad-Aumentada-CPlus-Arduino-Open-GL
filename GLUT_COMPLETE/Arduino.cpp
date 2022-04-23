#include "Arduino.h"

          int Arduino::x=2; // 2
          char Arduino::EntradaDeDatos[256] =" "; //creamos un vector de datos de tipo char en la cual cargaremos el texto que se envia desde el arduino con la funcion SERIAL.WRITE
          string Arduino::Data_Recibido;
          int Arduino::dataLength = 1; //1
          int Arduino::readResult = 0; //0
          int Arduino::u = 1;  //1

		   Serial* Arduino::ENTRADA = new Serial("\\\\.\\COM5");  // Hacemos uso de la clase Serial y creamos un nuevo objeto de conexion 
		//Debemos indicar el purto COM donde esta conectado nuestro arduino


void Arduino::Conexion_Arduino_IN(){          //CONEXION PARA ENTRADA DE DATOS DEL ARDUINO EN TIEMPO REAL
	                      cout<<"|||| |||| |||| |||| ||  EJECUCION DE LA CONEXION SERIAL  |||| |||| |||| |||| ||"<<endl;   
						  cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;

	                      if (Arduino::ENTRADA->IsConnected()) {   cout<<"El dispositivo se ha conectado correctamente a traves de COM5 :D"<<endl<<endl; }
                          cout<<"********************************************************************************"<<endl;
						  cout<<"MONITOR SERIAL DE ARDUINO -> CAPTURANDO DATOS DE ENTRADA" <<endl<<endl;
} 

void Arduino::Conexion_Arduino_OUT(){

}

