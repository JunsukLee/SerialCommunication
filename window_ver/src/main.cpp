#include <stdio.h>
#include <iostream>
#include <string>
#include "serialcomm.h"

using namespace std;

int main()
{
	char buffer; 
	CSerialComm serialComm; //SerialComm 객체 생성


	if(!serialComm.connect("COM25")) //COM25번의 포트를 오픈한다. 실패할 경우 -1을 반환한다.
	{
		cout << "connect faliled" << endl;
		return -1;
	}
	else
		cout << "connect successed" << endl;


	while(1) { //오픈에 성공한 경우 sendCommand()를 통해 계속적으로 데이터를 전송한다. 전송에 실패 할 경우 failed 메시지를 출력한다.
		cin >> buffer;

		if(!serialComm.sendCommand(buffer))
		{	
			cout << "send command failed"<< endl;
		}
		else
			cout << "send Command success" << endl;
	}


	serialComm.disconnect(); //작업이 끝나면 포트를 닫는다

	cout << "end connect" << endl;
		return 0;

}
