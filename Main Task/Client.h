#pragma once
#include "Comms.h"
class Client :
	public Comms
{

public:

	Client();

	void CreateSocket();
	int ConnectToServer();
	int SendData();
	int Recive();


private:
	SOCKET clientSocket;
	sockaddr_in clientService;
};

