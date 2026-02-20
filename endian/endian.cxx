#include <sys/param.h>

//
// <endian.h> - POSIX header which, in particular, defines BYTE_ORDER,
//              BIG_ENDIAN, and LITTLE_ENDIAN. Available on Linux, FreeBSD,
//              but not MacOS.
//
// <machine/endian.h> - not a POSIX header. Typically available on BSD-derived
//                      systems, in particular, on FreeBSD and MacOS.
//
// <sys/endian.h>     - not a POSIX header. Typically available on BSD-derived
//                      systems, in particular, on FreeBSD but not MacOS.
//
int main ()
{
#if !defined(BYTE_ORDER) || !defined(BIG_ENDIAN) || !defined(LITTLE_ENDIAN)
  return 3;
#endif

#if BYTE_ORDER == LITTLE_ENDIAN
  return 0;
#elif BYTE_ORDER == BIG_ENDIAN
  return 1;
#else
  return 2;
#endif
}
