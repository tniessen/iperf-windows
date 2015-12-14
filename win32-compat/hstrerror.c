
#include "sys\socket.h"

#define _(a) (a)

static const char *wsa_strerror(int error_code);

#ifndef HAVE_HSTRERROR
#define HAVE_HSTRERROR
const char *hstrerror(int e)
{
	switch (e)
	{
	case HOST_NOT_FOUND:
		return _("host not found (authoritative)");

	case TRY_AGAIN:
		return _("host not found (nonauthoritative) or server failure");

	case NO_RECOVERY:
		return _("nonrecoverable error");

	case NO_DATA:
		return _("valid name, but no data record of requested type");

	default:
		return wsa_strerror(e);
	}
}
#endif

static const char *wsa_strerror(int error_code)
{
	switch (error_code)
	{
	case WSA_NOT_ENOUGH_MEMORY:
		return _("not enough memory");

	case WSAEINTR:
		return _("operation aborted");

	case WSAEINVAL:
		return _("invalid argument");

	case WSATYPE_NOT_FOUND:
		return _("class type not found");

	case WSAENETDOWN:
		return _("the network subsystem has failed");

	case WSAHOST_NOT_FOUND:
		return _("host not found (authoritative)");

	case WSATRY_AGAIN:
		return _("host not found (nonauthoritative) or server failure");

	case WSANO_RECOVERY:
		return _("nonrecoverable error");

	case WSANO_DATA:
		return _("valid name, but no data record of requested type");

	case WSAEAFNOSUPPORT:
		return _("address family not supported");

	case WSAEMFILE:
		return _("no socket descriptors available");

	case WSAENOBUFS:
		return _("no buffer space available");

	case WSAEPROTONOSUPPORT:
		return _("protocol not supported");

	case WSAEPROTOTYPE:
		return _("wrong protocol type for this socket");

	case WSAESOCKTNOSUPPORT:
		return _("socket type is not supported in this address family");

	case WSAEADDRNOTAVAIL:
		return _("remote address is not valid");

	case WSAECONNREFUSED:
		return _("connection refused");

	case WSAENETUNREACH:
		return _("network unreachable");

	case WSAETIMEDOUT:
		return _("timeout");

	case WSAENOTCONN:
		return _("socket not connected");

	case WSAESHUTDOWN:
		return _("the socket was shut down");

	case WSAEHOSTUNREACH:
		return _("host unreachable");

	case WSAECONNRESET:
		return _("connection reset by peer");

	case WSASYSNOTREADY:
		return _("the underlying network subsystem is not ready");

	case WSAVERNOTSUPPORTED:
		return _("the requested version is not available");

	case WSAEINPROGRESS:
		return _("a blocking operation is in progress");

	case WSAEPROCLIM:
		return _("limit on the number of tasks has been reached");

	case WSAEFAULT:
		return _("invalid request");

	default:
		return _("unknown error");
	}
}
