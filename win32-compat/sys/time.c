
// Important: <windows.h> must never be imported before socket.h (time.h)!

#include "time.h"

#include <windows.h>
#include <VersionHelpers.h>

/*
 * This implementation is based on the MSDN document "Acquiring high-resolution time stamps"
 * http://msdn.microsoft.com/en-us/library/windows/desktop/dn553408%28v=vs.85%29.aspx
 */

static const unsigned __int64 epoch = (uint64_t) 116444736000000000;

int gettimeofday(struct timeval *tv, struct timezone *tz) {

#ifdef _GETTIMEOFDAY_USE_FILETIME
	FILETIME ft;

	if (IsWindows8OrGreater()) {
		// Guaranteed microsecond resolution
		GetSystemTimePreciseAsFileTime(&ft);
	}
	else {
		// Millisecond resolution only
		GetSystemTimeAsFileTime(&ft);
	}

	// Convert to timeval
	ULARGE_INTEGER ularge;

	ularge.HighPart = ft.dwHighDateTime;
	ularge.LowPart = ft.dwLowDateTime;

	// ularge.QuadPart is now "a 64-bit value representing the number of
	// 100-nanosecond intervals since January 1, 1601 (UTC)"

	tv->tv_sec = (long)((ularge.QuadPart - epoch) / 10000000L);
	tv->tv_usec = (long)(((ularge.QuadPart - epoch) / 10) % 1000000);
#else
	LARGE_INTEGER counter, freq;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&counter);

	counter.QuadPart *= 1000000;
	counter.QuadPart /= freq.QuadPart;

	tv->tv_sec = counter.QuadPart / 1000000;
	tv->tv_usec = counter.QuadPart % 1000000;
#endif

	return 0;
}
