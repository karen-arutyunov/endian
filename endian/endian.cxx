int main ()
{
#if !defined(__BYTE_ORDER__) || !defined(__ORDER_BIG_ENDIAN__) || !defined(__ORDER_LITTLE_ENDIAN__)
  return 3;
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  return 0;
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  return 1;
#else
  return 2;
#endif
}
