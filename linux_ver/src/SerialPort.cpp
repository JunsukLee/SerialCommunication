#include "SerialPort.h"
bool SerialPort::OpenPort()
{
    fd = open( "/dev/ttyACM2", O_RDWR | O_NOCTTY );
    if(fd >= 0){ // OpenPort success
	memset( &newtio, 0, sizeof(newtio) );
	return true;
    }else{       // OpenPort fail
	return false;
    }    
}

bool SerialPort::ConfigurePort(int BUF_SIZE)
{
    bool result = false;
    try{
	BUF_MAX = BUF_SIZE;
	buf = new char[BUF_MAX];
	memset(buf, '\0', BUF_MAX);

	newtio.c_cflag = B115200;    
	newtio.c_cflag |= CS8;    
	newtio.c_cflag |= CLOCAL;    
	newtio.c_cflag |= CREAD;
	newtio.c_iflag = IGNPAR;    
	newtio.c_oflag = 0;
	newtio.c_lflag = 0;
	newtio.c_cc[VTIME] = 0;  
	newtio.c_cc[VMIN] = 1;  

	tcflush (fd, TCIFLUSH );
	tcsetattr(fd, TCSANOW, &newtio );

	sleep(2);
	result = true;
    }catch(...){
	result = false;
    }
    
    return result;
}

bool SerialPort::serialData_write(std::string data)
{
    write(fd, "write_aaa", BUF_MAX);
    return true;
/*
    if(write(fd, "write_aaa", BUF_MAX) != -1)
	return true;
    else
	return false;
*/
}

char* SerialPort::serialData_read()
{

    read(fd, buf, BUF_MAX);
//    printf("Arduino : %s\n", buf);
    return buf;
/*    if(read(fd, buf, BUF_MAX) != -1){
	printf("Arduino : %s\n", buf);
	return true;
       //return buf;
    }else
	return false;
*/
}

bool SerialPort::closePort()
{
    close(fd);
}
