#include <winsock2.h>
#include <ws2tcpip.h>
#include <tchar.h>
#include "iostream"
#include "Comms.h"
#include "Client.h"
#include "Server.h"
#include <exception>


//defining code will run within main.
#define ServerConfig
//#define ClientConfig

using namespace std;

int main()
{
#ifdef ServerConfig
	try {
		Server SerObj1;

		SerObj1.initializeWSA();

		SerObj1.createSocket(&SerObj1.serverSocket);//passing the serverSocket variable 

		SerObj1.Bind();

		SerObj1.Listen();

		SerObj1.AcceptConection();


		while (true)
		{
			SerObj1.ReceiveData(&SerObj1.acceptSocket);

			SerObj1.SendData(&SerObj1.acceptSocket);
		}

	
#endif
	
	

#ifdef ClientConfig
		
		ClientM ClObj;

		ClObj.initializeWSA();

		ClObj.createSocket(&ClObj.clientSocket);

		ClObj.ConnectToServer();

		while (true)
		{
			ClObj.SendData(&ClObj.clientSocket);

			ClObj.ReceiveData(&ClObj.clientSocket);
		}
	

#endif // ClientConfig
	}
	//when the functions throws are used, if an error was generated, they will be catched depending on where the error was created.  
	catch (SocketExection& e) {
		cout << e.what() << WSAGetLastError() << endl; //prints the what message and get the last error message
		WSACleanup(); //unloading the DLL after somthing has caused and error
		system ("pause");
		exit(0);
	}
	catch (WSAException& e) {
		cout << e.what() << endl;
		WSACleanup();
		system("pause");
		exit(0);
	}
	catch (SendDataException& e) {
		cout << e.what() << endl;
		WSACleanup();
		system("pause");
		exit(0);
	}
	catch (ReciveDataException e) {
		cout << e.what() << endl;
		WSACleanup();
		system("pause");
		exit(0);
	}
	catch (BindException& e) {
		cout << e.what() << endl;
		WSACleanup();
		system("pause");
		exit(0);
	}
	catch (ListenException& e) {
		cout << e.what() << WSAGetLastError() << endl;
		WSACleanup();
		system("pause");
		exit(0);
	}
	catch (AcceptConnectionException& e) {
		cout << e.what() << WSAGetLastError() << endl;
		WSACleanup();
		system("pause");
		exit(0);
	}
	catch (GetInfoException& e) {
		cout << e.what() << endl;
		WSACleanup();
		system("pause");
		exit(0);

	} 


	//below is a rough guide on the logic of the programme

	//server object created
	//client obkject created
	//call paraent function inialize WSA
	//use exeption to check status of program
	//call paraent function createsockets - call for each of the objs? do they both need inderviual ones
	//server binds socket
	//checks to see if binded with execption class
	//listens for server socket
	//checks to see if sockets found with sockets execption class
	//client connects to server
	//checks to see if messages can be sent
	//accepts connection of client - grabbing the info of the client
	//checks to see if connection was succesful via execption class
	//loop while (1)	
		//client tpyes a message
		//if QUIT was typed Break out of loop
		//checks num of bytes sent if 0 throw an exception
		//Server reives message
		//server sends message back saying message recived
	//Disconnect/shutdown

	
}


