/*
CSERIES.H
*/

#ifndef __CSERIES_H
#define __CSERIES_H
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* ---------- constants */

#ifndef TRUE
	#define TRUE 1
#endif
#ifndef FALSE
	#define FALSE 0
#endif

enum
{
	UNSIGNED_LONG_MAX= 4294967295,
	LONG_MAX= 2147483647L,
	LONG_MIN= (-2147483648L),
	LONG_BITS= 32,
	LONG_BITS_BITS= 5,

	UNSIGNED_SHORT_MAX= 65535,
	SHORT_MAX= 32767,
	SHORT_MIN= (-32768),
	SHORT_BITS= 16,
	SHORT_BITS_BITS= 4,

	UNSIGNED_CHAR_MAX= 255,
	CHAR_MAX= 127,
	CHAR_MIN= (-128),
	CHAR_BITS= 8,
	CHAR_BITS_BITS= 3
};

#define NONE -1

/* ---------- macros */

#define STRINGIFY_DETAIL(x) #x
#define STRINGIFY(x) STRINGIFY_DETAIL(x)

/* on non-matching builds give actual source line info for assertions */
#ifdef NON_MATCHING
	#define MATCH_FILE(file) __FILE__
	#define MATCH_LINE(line) __LINE__
#else
	#define MATCH_FILE(file) file
	#define MATCH_LINE(line) line
#endif

#define match_halt(file, line) do { display_assert(NULL, MATCH_FILE(file), MATCH_LINE(line), TRUE); halt_and_catch_fire(); } while (FALSE);
#define match_vhalt(file, line, string) do { display_assert(string, MATCH_FILE(file), MATCH_LINE(line), TRUE); halt_and_catch_fire(); } while (FALSE);
#define match_assert(file, line, expr) if (!(expr)) { display_assert(#expr, MATCH_FILE(file), MATCH_LINE(line), TRUE); system_exit(-1); }
#define match_vassert(file, line, expr, string) if (!(expr)) { display_assert(string, MATCH_FILE(file), MATCH_LINE(line), TRUE); system_exit(-1); }
#define match_warn(file, line, expr) if (!(expr)) { display_assert(#expr, MATCH_FILE(file), MATCH_LINE(line), FALSE); }
#define match_vwarn(file, line, expr, string) if (!(expr)) { display_assert(string, MATCH_FILE(file), MATCH_LINE(line), FALSE); }

#define halt() match_halt(__FILE__, __LINE__)
#define vhalt(string) match_vhalt(__FILE__, __LINE__, string)
#define assert(expr) match_assert(__FILE__, __LINE__, expr)
#define vassert(expr, string) match_vassert(__FILE__, __LINE__, expr, string)
#define warn(expr) match_warn(__FILE__, __LINE__, expr)
#define vwarn(expr, string) match_vwarn(__FILE__, __LINE__, expr, string)

#define ABS(x) ((x>=0) ? (x) : -(x))

#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX(a,b) ((a)>(b)?(a):(b))

#define FLOOR(n,floor) ((n)<(floor)?(floor):(n))
#define CEILING(n,ceiling) ((n)>(ceiling)?(ceiling):(n))
#define PIN(n,floor,ceiling) ((n)<(floor) ? (floor) : CEILING(n,ceiling))

#define FLAG(b) (1<<(b))
#define TEST_FLAG(flags, bit) ((flags)&(unsigned)FLAG(bit))
#define SET_FLAG(f, b, v) ((v) ? ((f)|=(unsigned)FLAG(b)) : ((f)&=(unsigned)~FLAG(b)))

#define NUMBEROF(array) (sizeof(array) / sizeof(array[0]))

/* ---------- types */

typedef unsigned char byte;
typedef unsigned short word;

typedef byte boolean;

typedef unsigned long tag;

typedef float real;

/* ---------- prototypes/CSERIES.C */

void display_assert(char *information, char *file, long line, boolean fatal);

/* ---------- prototypes/CSERIES_WINDOWS.C */

void system_exit(long code);

/* ---------- prototypes/MAIN.C */

void halt_and_catch_fire(void);

#endif // __CSERIES_H
