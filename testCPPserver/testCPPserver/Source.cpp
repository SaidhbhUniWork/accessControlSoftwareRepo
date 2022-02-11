
// https://www.youtube.com/watch?v=WDn-htpBlnU

#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

//void message()
//{
//
//}

void main()
{
	//initialise winsock
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0)
	{
		cerr << "Cant initialise Winsock" << endl;
		return;
	}

	//create a socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << "Cant create socket, quitting" << endl;
		return;
	}
	
	//bind an ip address and port to a socket
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(54000);
	addr.sin_addr.S_un.S_addr = INADDR_ANY; // could also use inet_pton...

	//want to bind any address "innadr_any" to our port 54000
	bind(listening, (sockaddr*)&addr, sizeof(addr));

	//tell winsock the socket is for listening
	listen(listening, SOMAXCONN);

	//wait for a connection
	sockaddr_in client;
	int clientsize = sizeof(client);

	SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientsize); //connected socket
	if (clientSocket == INVALID_SOCKET)
	{
		cerr << "Invalid socket" << endl;
		return;
	}

	char host[NI_MAXHOST];		// client's remote name
	char service[NI_MAXHOST];	// service (i.e. port) the client is connected on

	ZeroMemory(host, NI_MAXHOST);	// same as memset(host, 0, NI_MAXHOST) in Linux
	ZeroMemory(service, NI_MAXHOST);

			//try to lookup the host name of the client we're connected to...
	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
	{
		cout << host << " connected on port " << service << endl;
	}
	else
	{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		cout << host << " connected on port " << ntohs(client.sin_port) << endl;
	}

	//close listening socket
	closesocket(listening);

	//while loop: accept and echo message back to client
	char buf[4096];

	while (true)
	{
		ZeroMemory(buf, 4096);

		// wait for client to send data
		int bytesReceived = recv(clientSocket, buf, 4096, 0);
		cout << buf << endl;
		if (bytesReceived == SOCKET_ERROR) //error of -1
		{
			cerr << "Error in recv(). Quitting" << endl;
			break;
		}

		if (bytesReceived == 0)
		{
			cout << "Client disconnected " << endl;
			break;
		}

		//echo message back to client if necessary
		send(clientSocket, buf, bytesReceived + 1, 0);
	}

	//close the socket
	closesocket(clientSocket);

	//clean up winsock
	WSACleanup();
}

