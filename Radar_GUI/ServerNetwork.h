/*
 -------------------------------------------------------------------------------------------------------------------------------------------
 Author			:	Simar Mann Singh
 Department		:	High Frequency Department, TF
 Date			:	28/08/2018
 -------------------------------------------------------------------------------------------------------------------------------------------
*/
#pragma once
#include <winsock2.h>
#include <Windows.h>
#include "NetworkServices.h"
#include <ws2tcpip.h>
#include <map>
#include "NetworkData.h"

using namespace std; 
#pragma comment (lib, "Ws2_32.lib")

//#define DEFAULT_BUFLEN 512
//#define DEFAULT_PORT "5050"

class ServerNetwork
{

public:

    ServerNetwork(void);
    ~ServerNetwork(void);

    // Socket to listen for new connections
	SOCKET ListenSocket ;

    // Socket to give to the clients
    SOCKET ClientSocket;

    // for error checking return values
    int iResult;

    // table to keep track of each client's socket
    std::map<unsigned int, SOCKET> sessions; 

	// accept new connections
	bool acceptNewClient(const unsigned int & id);

	// receive incoming data
	int receiveData(unsigned int client_id, char * recvbuf);

	// send data to all clients
	void sendToAll(char * packets, int totalSize);


};