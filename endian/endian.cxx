#include <stdio.h>

#    if defined(__GLIBC__) || defined(__OpenBSD__)
      /* POSIX header. Available on Linux, FreeBSD, but not MacOS.
       */
#      include <endian.h>
#    elif defined(__FreeBSD__) || defined(__NetBSD__)
       /* Not a POSIX header. Typically available on BSD-derived systems, in
        * particular, on FreeBSD but not MacOS.
        */
#      include <sys/endian.h>
#    elif defined(__APPLE__)
       /* Not a POSIX header. Typically available on BSD-derived systems, in
        * particular, on FreeBSD and MacOS.
        */
#      include <machine/endian.h>
#    elif !defined(_WIN32)
       /* Not a POSIX header. Historically available on POSIX systems, in
        * particular, on Linux, FreeBSD, and MacOS.
        */
#      include <sys/param.h>
#    endif

int main ()
{
  int r (0);

#if defined(BYTE_ORDER) && defined(BIG_ENDIAN) && defined(LITTLE_ENDIAN)
#  if BYTE_ORDER == LITTLE_ENDIAN
     r += 1;
#  elif BYTE_ORDER == BIG_ENDIAN
     r += 2;
#  else
     r += 3;

     printf ("BYTE_ORDER %d, "
             "LITTLE_ENDIAN %d, "
             "BIG_ENDIAN %d\n",
             BYTE_ORDER, LITTLE_ENDIAN, BIG_ENDIAN);
#  endif
#endif

#if defined(__BYTE_ORDER) && defined(__BIG_ENDIAN) && defined(__LITTLE_ENDIAN)
#  if __BYTE_ORDER == __LITTLE_ENDIAN
     r += 10;
#  elif __BYTE_ORDER == __BIG_ENDIAN
     r += 20;
#  else
     r += 30;

     printf ("__BYTE_ORDER %d, "
             "__LITTLE_ENDIAN %d, "
             "__BIG_ENDIAN %d\n",
             __BYTE_ORDER, __LITTLE_ENDIAN, __BIG_ENDIAN);
#  endif
#endif

#if defined(_BYTE_ORDER) && defined(_BIG_ENDIAN) && defined(_LITTLE_ENDIAN)
#  if _BYTE_ORDER == _LITTLE_ENDIAN
     r += 100;
#  elif _BYTE_ORDER == _BIG_ENDIAN
     r += 200;
#  else
     r += 300;

     printf ("_BYTE_ORDER %d, "
             "_LITTLE_ENDIAN %d, "
             "_BIG_ENDIAN %d\n",
             _BYTE_ORDER, _LITTLE_ENDIAN, _BIG_ENDIAN);
#  endif
#endif

#if defined(__DARWIN_BYTE_ORDER) && defined(__DARWIN_BIG_ENDIAN) && defined(__DARWIN_LITTLE_ENDIAN)
#  if __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN
     r += 1000;
#  elif __DARWIN_BYTE_ORDER == __DARWIN_BIG_ENDIAN
     r += 2000;
#  else
     r += 3000;

     printf ("__DARWIN_BYTE_ORDER %d, "
             "__DARWIN_LITTLE_ENDIAN %d, "
             "__DARWIN_BIG_ENDIAN %d\n",
             __DARWIN_BYTE_ORDER, __DARWIN_LITTLE_ENDIAN, __DARWIN_BIG_ENDIAN);
#  endif
#endif

#if defined(__BYTE_ORDER__) && defined(__BIG_ENDIAN__) && defined(__LITTLE_ENDIAN__)
#  if __BYTE_ORDER__ == __LITTLE_ENDIAN__
     r += 10000;
#  elif __BYTE_ORDER__ == __BIG_ENDIAN__
     r += 20000;
#  else
     r += 30000;

     printf ("__BYTE_ORDER__ %d, "
             "__LITTLE_ENDIAN__ %d, "
             "__BIG_ENDIAN__ %d\n",
             __BYTE_ORDER__, __LITTLE_ENDIAN__, __BIG_ENDIAN__);
#  endif
#endif

  printf ("RESULT: %d\n", r);
  return 0;
}
