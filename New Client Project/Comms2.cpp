#include "Comms2.h"

Comms2::Comms2()
{
	int port = 55555;
	WORD wVersionRequested = MAKEWORD(2, 2);
	
}

int Comms2::initializeWSA()
{
	wsaerr = WSAStartup(wVersionRequested, &wsaData);
	if (wsaerr != 0) {
		throw WSAException();
	}
	else {
		cout << "The Winsock dll found!" << endl;
		cout << "The status: " << wsaData.szSystemStatus << endl;
	}
}
void Comms2::createSocket(SOCKET *SocketName) 
{

	*SocketName = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (*SocketName == INVALID_SOCKET) {
		throw SocketExection();
	}
	else {
		cout << "socket() is OK!" << endl;

	}

}

int Comms2::SendData(SOCKET* AcceptSocket)
{
	cout << "Please Type Message :" << endl;
	//waiting for message to be sent
	cin.getline(buffer, 200);
	
	//reply to message 

	int byteCount = send(*AcceptSocket, buffer, 200, 0);

	if (byteCount == 0)
	{
		throw SendDataException();
	}
	else
	{
		cout << "Bytes sent : " << byteCount << endl;
	}

}


int Comms2::ReceiveData(SOCKET* AcceptSocket)
{
	//waiting for the reply
	int bytesRecived = recv(*AcceptSocket, buffer, 200, 0);
	
	if (bytesRecived == 0)
	{
		throw ReciveDataException();
	}
	else
	{
		cout << "Message : " << buffer << endl;
	}


}

int Comms2::Disconnect()
{
	system("pause");
	WSACleanup();
	exit(0);
}
