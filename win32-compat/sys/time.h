
#ifndef SYS_TIME_H
#define SYS_TIME_H

#include "socket.h"
#include "stdint.h"

#include <time.h>

#ifndef HAVE_STRUCT_TIMESPEC
#define HAVE_STRUCT_TIMESPEC
#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
struct timespec {
	time_t tv_sec;
	long tv_nsec;
};
#endif /* _TIMESPEC_DEFINED */
#endif /* HAVE_STRUCT_TIMESPEC */

#ifndef HAVE_STRUCT_TIMEZONE
#define HAVE_STRUCT_TIMEZONE
#ifndef _TIMEZONE_DEFINED
#define _TIMEZONE_DEFINED
struct timezone {
	int tz_minuteswest;     /* minutes west of Greenwich */
	int tz_dsttime;         /* type of DST correction */
};
#endif /* _TIMEZONE_DEFINED */
#endif /* HAVE_STRUCT_TIMEZONE */

int gettimeofday(struct timeval *tv, struct timezone *tz);

#endif /* SYS_TIME_H */
