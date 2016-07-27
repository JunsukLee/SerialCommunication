#include "SerialPort.h"
#include <stdio.h>

#define BUF_MAX 512

int main()
{
	SerialPort serial;
	char message[BUF_MAX];

	serial.OpenPort();
	serial.ConfigurePort(BUF_MAX);
/*	if(!serial.OpenPort())
		printf("OpenPort fail\n");
	if(!serial.ConfigurePort())
		printf("ConfigurePort fail\n");
*/
	while(1){
		sleep(1);
		serial.serialData_write("testtttttt");
		memset(message, '\0', BUF_MAX);
		strcpy(message, serial.serialData_read());
		printf("arduino : %s\n", message);
	}
	serial.closePort();

	return 0;
}
