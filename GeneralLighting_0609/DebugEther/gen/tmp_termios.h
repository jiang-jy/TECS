/*  1 "./gen/tmp_C_src.c" */
/*  1 "<built-in>" */
/*  1 "<command-line>" */
/*  1 "./gen/tmp_C_src.c" */
/*  34 "./gen/tmp_C_src.c" */
typedef struct { int dummy; } va_list;

/*  1 "../../musl-1.1.18/include/termios.h" 1 */







/*  1 "../../musl-1.1.18/include/features.h" 1 */
/*  9 "../../musl-1.1.18/include/termios.h" 2 */



/*  1 "../../musl-1.1.18/include/bits/alltypes.h" 1 */
/*  263 "../../musl-1.1.18/include/bits/alltypes.h" */
typedef int pid_t;
/*  13 "../../musl-1.1.18/include/termios.h" 2 */

typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;



/*  1 "../../musl-1.1.18/include/bits/termios.h" 1 */
struct termios {
 tcflag_t c_iflag;
 tcflag_t c_oflag;
 tcflag_t c_cflag;
 tcflag_t c_lflag;
 cc_t c_line;
 cc_t c_cc[32];
 speed_t __c_ispeed;
 speed_t __c_ospeed;
};
/*  21 "../../musl-1.1.18/include/termios.h" 2 */

speed_t cfgetospeed (const struct termios *);
speed_t cfgetispeed (const struct termios *);
int cfsetospeed (struct termios *, speed_t);
int cfsetispeed (struct termios *, speed_t);

int tcgetattr (int, struct termios *);
int tcsetattr (int, int, const struct termios *);

int tcsendbreak (int, int);
int tcdrain (int);
int tcflush (int, int);
int tcflow (int, int);

pid_t tcgetsid (int);


void cfmakeraw(struct termios *);
int cfsetspeed(struct termios *, speed_t);
/*  36 "./gen/tmp_C_src.c" 2 */
