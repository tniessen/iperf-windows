
#ifndef SYS_SOCKET_H
#define SYS_SOCKET_H

#pragma comment(lib, "Ws2_32.lib")

#include <WinSock2.h>
#include <Ws2tcpip.h>

// A POSIX compliant wrapper around closesocket
int _posix_closesocket(int s);

#endif /* SYS_SOCKET_H */
