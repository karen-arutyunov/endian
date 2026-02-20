#include <endian.h>

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
