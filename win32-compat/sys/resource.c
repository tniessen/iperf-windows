
#include <stdio.h>
#include "resource.h"
#include <errno.h>

int getrusage(int who, struct rusage *usage) {
	if (who != RUSAGE_SELF) {
		errno = EINVAL;
		return -1;
	}

	FILETIME ftCreation, ftExit;
	FILETIME ftSTime, ftUTime;
	if (!GetProcessTimes(GetCurrentProcess(), &ftCreation, &ftExit, &ftSTime, &ftUTime)) {
		errno = GetLastError();
		return -1;
	}

	uint64_t stime = 0, utime = 0;
	stime |= ftSTime.dwHighDateTime;
	stime <<= 32;
	stime |= ftSTime.dwLowDateTime;
	utime |= ftUTime.dwHighDateTime;
	utime <<= 32;
	utime |= ftUTime.dwLowDateTime;

	usage->ru_stime.tv_sec = stime / 10000000;
	usage->ru_stime.tv_usec = (stime % 10000000) / 10;
	usage->ru_utime.tv_sec = utime / 10000000;
	usage->ru_utime.tv_usec = (utime % 10000000) / 10;

	return 0;
}
