#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <termios.h>
#include <fcntl.h>
#include <iostream>

//#define BUF_MAX 512

class SerialPort
{
public:
	bool OpenPort();
	bool ConfigurePort(int BUF_MAX);
	bool serialData_write(char *data);
	char* serialData_read();
	bool closePort();
private:
	int fd;
	int BUF_MAX;
	char *buf;
	struct termios newtio;		
};
