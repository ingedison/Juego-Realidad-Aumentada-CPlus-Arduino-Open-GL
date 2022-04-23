#include "Serial.h"

Serial::Serial(char *portName) {
         this->connected = false; //¿Esta conectado? - Falso

        //(Intente conectarse al puerto asignado) throuh CreateFile
        this->hSerial = CreateFileA(portName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        if(this->hSerial==INVALID_HANDLE_VALUE) { //chequear si la conexión fue exitosa
        
			   if(GetLastError()==ERROR_FILE_NOT_FOUND){  //Si no es exitoso. Muestre error en pantalla
				      
                        printf("ERROR: El dispositivo no ha sido conectado: El puerto  %s no esta disponible.\n", portName);

                }
                else
                {
                        printf("ERROR!");
                }
        }
        else
        {
                //Si se conecto, establecemos los parametros COMM
                DCB dcbSerialParams = {0};

                //Intente obtener el predeterminado
                if (!GetCommState(this->hSerial, &dcbSerialParams))
                {
                        //Si es posible, muestre un error
                        printf("fallo al obtener los parametros seriales!");
                }
                else
                {
                        //Definir los parametros de conexion serial para la placa arduino
                        dcbSerialParams.BaudRate=CBR_9600;
                        dcbSerialParams.ByteSize=8;
                        dcbSerialParams.StopBits=ONESTOPBIT;
                        dcbSerialParams.Parity=NOPARITY;

						 //establecer los parametros y revisar para su aplicacion apropiada

                         if(!SetCommState(hSerial, &dcbSerialParams))
                         {
                                printf("ALERTA: NO SE PUDO ESTABLECER LOS PARAMETROS DEL PUERTO SERIAL");
                         }
                         else
                         {
                                 //Si todo bien, entonces estamos conectados
                                 this->connected = true;
                                 //esperamos 2 segundos para el reseteo de la board arduino
                                 Sleep(ARDUINO_WAIT_TIME);
                         }
                }
        }

}

Serial::~Serial() {
                                //Check if we are connected before trying to disconnect
						if(this->connected) {
								//We're no longer connected
								this->connected = false;
								//Close the serial handler
								CloseHandle(this->hSerial);
						}
}

int Serial::ReadData(char *buffer, unsigned int nbChar) { //metodo para leer datos 
                                                        DWORD bytesRead; //Numero de bits que hemos leido
                                                        unsigned int toRead; //Numero de bits que realmento preguntamos para leer
        

        //Use the ClearCommError function to get status info on the Serial port
        ClearCommError(this->hSerial, &this->errors, &this->status);

        //Check if there is something to read
        
		if(this->status.cbInQue>0) {
                //If there is we check if there is enough data to read the required number
                //of characters, if not we'll read only the available characters to prevent
                //locking of the application.
                if(this->status.cbInQue>nbChar)
                {
                        toRead = nbChar;
                }
                else
                {
                        toRead = this->status.cbInQue;
                }

                //Try to read the require number of chars, and return the number of read bytes on success
                if(ReadFile(this->hSerial, buffer, toRead, &bytesRead, NULL) && bytesRead != 0)
                {
                        return bytesRead;
                }

        }

        //If nothing has been read, or that an error was detected return -1
        return -1;

}


bool Serial::WriteData(char *buffer, unsigned int nbChar)
{
        DWORD bytesSend;

        //Try to write the buffer on the Serial port
        if(!WriteFile(this->hSerial, (void *)buffer, nbChar, &bytesSend, 0))
        {
                //In case it don't work get comm error and return false
                ClearCommError(this->hSerial, &this->errors, &this->status);

                return false;
        }
        else
                return true;
}

bool Serial::IsConnected()
{
        //Simply return the connection status
        return this->connected;
}

HANDLE& Serial::getHandle()
{
        return hSerial;
}