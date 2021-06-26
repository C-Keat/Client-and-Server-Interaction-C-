#include "Comms.h"


Comms::Comms() 
{
	int port = 55555;
	WORD wVersionRequested = MAKEWORD(2, 2);
	//formatting the version to use in WSA STARTUP
	
}

int Comms::initializeWSA() 
{
	//This loads the  DLL passing the version, and getting empty structure so that information can be grabbed about the DLL
	wsaerr = WSAStartup(wVersionRequested, &wsaData);
	if (wsaerr != 0) {
		//checking for an error and if so it will throw and exception back to main
		throw WSAException();
	}
	else {
		cout << "The Winsock dll found!" << endl; 
		cout << "The status: " << wsaData.szSystemStatus << endl; //printing information on the DLL and the systems status
	}
}
void Comms::createSocket(SOCKET *SocketName) //classes socket passed as paramater 
{
		
	*SocketName = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//configering the socket via the 3 constant arguments 
	if (*SocketName == INVALID_SOCKET) {
		//checking for an error and throwing exception of it returns an invalid socket
		throw SocketExection();
	}
	else {
		cout << "socket() is OK!" << endl;
			
	}
	
}

int Comms::SendData(SOCKET *AcceptSocket)
{
	cout << "Please Type Message :" << endl;
	//waiting for message to be sent
	cin.getline(buffer, 200); //populates the array "buffer"


	int byteCount = send(*AcceptSocket, buffer, 200, 0);//sends the contence of buffer and the socket to what ever it is connected to 

	if (byteCount == 0)
	{
		throw SendDataException();
	}
	else
	{ 
		cout << "Bytes sent : " << byteCount << endl;
	}

}



int Comms::ReceiveData(SOCKET *AcceptSocket)
{
	//waiting for the reply
	int bytesRecived = recv(*AcceptSocket, buffer, 200, 0); //populates the buffer with the information that has just been recived
//also a blocking function, waiting for information to be sent 
	if (bytesRecived == 0)
	{
		throw ReciveDataException();
	}
	else
	{
		cout << "Message : " << buffer << endl;
	}

}

int Comms::Disconnect() 
{
	system("pause");
	WSACleanup();
	exit(0);
}
