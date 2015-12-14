
#include "socket.h"

int _posix_closesocket(int s) {
	int lastError = WSAGetLastError();
	int closeRet = closesocket(s);
	if (closeRet == 0) {
		// closesocket set the last error code to 0 which is not POSIX compliant
		WSASetLastError(lastError);
	}
	return closeRet;
}
