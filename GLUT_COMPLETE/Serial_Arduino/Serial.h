#ifndef SERIALCLASS_H_INCLUDED
#define SERIALCLASS_H_INCLUDED
#define ARDUINO_WAIT_TIME 2000

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

class Serial {
                     private:
								HANDLE hSerial;  //Serial comm handler
								bool connected;  //Connection status
								COMSTAT status;  //Get various information about the connection
								DWORD errors;    //Keep track of last error

					public:  //Initialize Serial communication with the given COM port
						
						Serial(char *portName); //Close the connection
						//NOTA: for some reason you can't connect again before exiting the program and running it again
						
						~Serial(); //Read data in a buffer, if nbChar is greater than the maximum number of bytes available, it will return only the bytes available. The function return -1 when nothing could be read, the number of bytes actually read.
						int ReadData(char *buffer, unsigned int nbChar);
						//Writes data from a buffer through the Serial connection
						//return true on success.
						bool WriteData(char *buffer, unsigned int nbChar);
						//Check if we are actually connected
						bool IsConnected();

                       HANDLE& getHandle();
};

#endif // SERIALCLASS_H_INCLUDED