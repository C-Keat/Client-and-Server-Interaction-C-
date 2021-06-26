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
#include "ConnectToServerException.h"

using namespace std;

class Comms2
{

public:

	int port;

	Comms2();

	int initializeWSA();
	void createSocket(SOCKET *SocketName);

	virtual int SendData(SOCKET* AcceptSocket);
	virtual int ReceiveData(SOCKET* AcceptSocket);

	int Disconnect();

protected:
	char buffer[200];

private:


	WSADATA wsaData;

	int wsaerr;

	WORD wVersionRequested;

};

