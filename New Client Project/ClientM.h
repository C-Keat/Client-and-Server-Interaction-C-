#pragma once
#include "Comms2.h"


class ClientM :

	public Comms2
{

public:

	ClientM();

	void CreateSocket();

	int ConnectToServer();

	int SendData(SOCKET* AcceptSocket);

	SOCKET clientSocket;

private:
	
	sockaddr_in clientService;//storing who the client has connected to
};

