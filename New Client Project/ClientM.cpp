#include "ClientM.h"


ClientM::ClientM()
{
	clientService.sin_family = AF_INET;
	clientSocket = INVALID_SOCKET;
}


int ClientM::ConnectToServer()
{

	InetPton(AF_INET, _T("127.0.0.1"), &clientService.sin_addr.s_addr);
	clientService.sin_port = htons(port);
	if (connect(clientSocket, (SOCKADDR*)& clientService, sizeof(clientService)) == SOCKET_ERROR) {//pass the structure 
		throw ConnectToServerException();
	}
	else {
		cout << "Client: connect() is OK." << endl;
		cout << "Client: Can start sending and receiving data..." << endl;
	}

}

int ClientM::SendData(SOCKET *AcceptSocket)
{
	Comms2::SendData(AcceptSocket);

	if (strcmp(buffer, "QUIT") == 0)
	{
		closesocket(clientSocket);
		Disconnect();

	}

	return 0;
}
