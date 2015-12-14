
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <Windows.h>
#include <fcntl.h>
#include <stdint.h>

#include "stdlib_extras.h"

int mkstemp(char *_tmpl) {
    // Preserve a copy for retries
    char tmpl[MAX_PATH];
    strcpy(tmpl, _tmpl);

    // Find dynamic part of template
    char *dynPart = tmpl + strlen(tmpl) - 6;
    if (strcmp(dynPart, "XXXXXX")) {
	errno = EINVAL;
	return -1;
    }

    // Hexadecimal chars
    const char *chars = "0123456789ABCDEF";
    assert(strlen(chars) == (1 << 4));

    // Reduces the number of attempts necessary to find an unused name
    // during one execution
    static uint32_t num = 0;

    // Find an unused name
    do {
	// Try the next number
	num++;
	// Replace the dynamic part with a hexadecimal representation of
	// our counter
	for (int i = 0; i < 6; i++) {
	    int c = (num & (0x0f << (i * 4))) >> (i * 4);
	dynPart[5 - i] = chars[c];
	}
    } while (GetFileAttributes(tmpl) != INVALID_FILE_ATTRIBUTES);

    // Open the file
    int fd = open(tmpl, O_RDWR | O_CREAT | O_EXCL);
    if (fd < 0) {
	if (errno == EEXIST) {
	    // Really lazy way to handle race condition between multiple
	    // processes on the same machine
	    return mkstemp(_tmpl);
	}
	errno = EIO;
	return -1;
    }

    // Copy generated name to template
    strcpy(_tmpl, tmpl);

    return fd;
}
