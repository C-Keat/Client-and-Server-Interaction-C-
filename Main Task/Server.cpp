#include "Server.h"



Server::Server() 
{
	serverSocket = INVALID_SOCKET;
	service.sin_family = AF_INET;//configuring for the family of service socket
	fromlen = sizeof(from);
	
}


int Server::Bind() 
{
	InetPton(AF_INET, _T("127.0.0.1"), &service.sin_addr.s_addr); //formating the IP address into a way windows can read, using the call back address
	service.sin_port = htons(port);//assign the port number and formating it using the htons function
	if (bind(serverSocket, (SOCKADDR*)& service, sizeof(service)) == SOCKET_ERROR) { //binding the socket used to port num and IP
		throw BindException();
	}
	else {
		cout << "bind() is OK!" << endl;
	}
}
void Server::Listen() 
{
	//makes the socket go into a lissening mode 
	if (listen(serverSocket, 1) == SOCKET_ERROR) 
	{
		throw ListenException();
	}
	else
		cout << "listen() is OK, I'm waiting for connections..." << endl;
}
int Server::AcceptConection() 
{
	
	//waiting for a connection to take place
	acceptSocket = accept(serverSocket, (SOCKADDR*)& from, &fromlen); //also grabs information on the socket that it connected to

	//if the socket failed to connect
	if (acceptSocket == INVALID_SOCKET) {
		
		throw AcceptConnectionException();

	}

	//gets and stores information on the client that connected
	retval = getnameinfo((SOCKADDR*)& from,	fromlen,hoststr,NI_MAXHOST,servstr,NI_MAXSERV,NI_NUMERICHOST | NI_NUMERICSERV);
	
	if (retval != 0) {

		cout << retval << endl;
		throw GetInfoException();
	}
	cout << "Accepted connection from host " << hoststr << " and port " << servstr << endl;

	cout << "Accepted connection" << endl;

}

int Server::ReceiveData(SOCKET* AcceptSocket)
{
	Comms::ReceiveData(AcceptSocket);
	
	if (strcmp(buffer, "QUIT") == 0)
	{
		closesocket(*AcceptSocket);//closes the use of the socket incase other programs need to use it 

		Disconnect();
	}
	return 0;
	
}
	
