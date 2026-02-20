#include <machine/endian.h>

//
// <endian.h> - POSIX header which, in particular, defines BYTE_ORDER,
//              BIG_ENDIAN, and LITTLE_ENDIAN. Available on Linux, FreeBSD,
//              but not on MacOS.


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
