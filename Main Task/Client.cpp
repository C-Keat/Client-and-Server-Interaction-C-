#include "Client.h"

Client::Client() 
{
	clientService.sin_family = AF_INET;
	clientSocket = INVALID_SOCKET;
}


int Client::ConnectToServer() 
{
	
	
	InetPton(AF_INET, _T("127.0.0.1"), &clientService.sin_addr.s_addr);
	clientService.sin_port = htons(port);
	if (connect(clientSocket, (SOCKADDR*)& clientService, sizeof(clientService)) == SOCKET_ERROR) {
		cout << "Client: connect() - Failed to connect." << endl;
		WSACleanup();
		return 0;
	}
	else {
		cout << "Client: connect() is OK." << endl;
		cout << "Client: Can start sending and receiving data..." << endl;
	}

}

int Client::SendData()
{
	char buffer[200];
	cout << "Please Type Message :" << endl;
	//waiting for message to be sent
	cin.getline(buffer, 200);
	//message sent 
	int byteCount = send(clientSocket, buffer, 200, 0);

	if (byteCount == SOCKET_ERROR)
	{
		cout << "ERROR" << endl;
		return -1;
	}
	else
	{
		cout << "Bytes sent : " << byteCount << endl;

		if (strcmp(buffer, "QUIT") == 0)
		{
			return -1;
		}

	}
}

void Client::CreateSocket() 
{
	try
	{
		
		clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (clientSocket == INVALID_SOCKET) {
			throw 1;
		}
		else {
			cout << "socket() is OK!" << endl;
		}
	}
	catch (int error)
	{
		cout << "Exception: " << error << endl;
		cout << "Error at socket(): " << WSAGetLastError() << endl;
		WSACleanup();
	}
}

int Client::Recive() 
{
	char bufferSE[200];
	//waiting for the reply
	int bytesRecived = recv(clientSocket, bufferSE, 200, 0);

	if (bytesRecived == 0)
	{
		cout << "ERROR" << endl;
		return -1;
	}
	else
	{
		cout << "Message : " << bufferSE << endl;
	}

}