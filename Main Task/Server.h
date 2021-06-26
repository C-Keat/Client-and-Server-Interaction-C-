#pragma once
#include "Comms.h"
class Server :
	public Comms
{

public:

	Server();

	
	int Bind();
	void Listen();
	int AcceptConection();

	int ReceiveData(SOCKET* AcceptSocket);



	SOCKET serverSocket, acceptSocket;

private:

	int retval, fromlen;
	SOCKADDR_STORAGE from;
	char servstr[NI_MAXSERV], hoststr[NI_MAXHOST];
	sockaddr_in service;
};

