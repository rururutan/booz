/* booz.h */
/* this file is public domain */

#include <stdio.h>

typedef unsigned char uchar;    /* 8 bits or more */
typedef unsigned int   uint;    /* 16 bits or more */
typedef unsigned short ushort;  /* 16 bits or more */
typedef unsigned long  ulong;   /* 32 bits or more */

/* T_UINT16 must be an unsigned data type of exactly 16 bits */
#define T_UINT16     unsigned short

/* Define FIXFNAME to activate the fixfname() function that converts
filename syntax to be acceptable to the host system */
/* #define FIXFNAME */

/*
OPEN(x)     open file x for read
CREATE(x)   create file x for read/write

Files opened by OPEN() and CREATE() must be opened in
binary mode (not involving any newline translation).
*/

#define NEED_B

/* Conventional stdio, using "b" suffix for binary open */
#ifdef NEED_B
#define  CREATE(x)	fopen(x, "wb")
#define  OPEN(x)	fopen(x, "rb")

#else
/* some systems (e.g. Ultrix) don't like a trailinb "b" */
#define  CREATE(x)	fopen(x, "w")
#define  OPEN(x) 	fopen(x, "r")
#endif

/* don't change the rest of this file */
#define MEM_BLOCK_SIZE	8192

/* Functions defined by Booz */
struct zoo_header;
struct direntry;

int getfile (FILE*, FILE*, long);
int lzd (FILE*, FILE*);
int rd_zooh (struct zoo_header*, FILE*);
int rd_dir (struct direntry*, FILE*);
int addbfcrc (char *buffer, unsigned);
int prterror (int, char*, char*, char*);
int oozext (char*, char*, int, char *argv[]);
void putstr (char*);
char *itoan (char, long, char*, int);
int fixfname (char*);
int memerr ();
int gentab ();
int match (char*, char*);
int cfactor (long, long);
int lzh_decode (FILE*, FILE*);
int fillbuf (int);
int make_table (int, uchar[], int, ushort[]);
int init_getbits();
int huf_decode_start();
int fwrite_crc (uchar *, int, FILE*);
