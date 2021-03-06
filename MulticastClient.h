/**
 * @file   MulticastClient.h
 * @Author Vinod Gopalan (kgvinod@gmail.com)
 * @date   July, 2016
 * @brief  A client for receiving multicast streams
 *
 */

#ifndef MCLIENT_H
#define MCLIENT_H

#include <string>
#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>


const unsigned int MAX_PORT_NUM = 65535;

// MulticastClient class
class MulticastClient {

public:

    // Disallow Default Constructor
    MulticastClient() = delete;

    // Constructor
    MulticastClient(std::string local_ip, std::string multicast_ip, unsigned int multicast_port);

    // Destructor
    ~MulticastClient();

    // Open mcast stream
    int open();

    // Read mcast stream
    int readData(char *buffer, unsigned int size);


private:

    std::string mLocalIp;
    std::string mMulticastIp;
    unsigned int mMulticastPort;
    int mSockFd;
    struct sockaddr_in mLocalSock;
    struct ip_mreq mGroup;
};

#endif //#ifndef FSNODE_H
