#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <tchar.h>
#include "iostream"
#include "SocketExection.h"
#include "WSAException.h"
#include "SendDataException.h"
#include "ReciveDataException.h"
#include "BindException.h"
#include "ListenException.h"
#include "AcceptConnectionException.h"
#include "GetInfoException.h"

using namespace std;

class Comms
{
public:

	int port;

	Comms();

	int initializeWSA();
	void createSocket(SOCKET *SocketName);

	virtual int SendData(SOCKET* SocketName);
	virtual int ReceiveData(SOCKET *SocketName);

	int Disconnect();

	

protected:
	char buffer[200]; //protected character arrary allowing the child objects to access it
	
private:
	

	WSADATA wsaData;

	int wsaerr;
	
	WORD wVersionRequested;

};

