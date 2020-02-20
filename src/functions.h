#pragma once

/*=== Function Headers =======================================================*/

/**
 * Converts a byteArray of a given size into an integral number type. The size
 * of the provided byteArray must equal sizeof(T).
 */
template <typename T>
bool byteToIntegral(const char *byteArray, const size_t size, T &integral);

/*=== Function Defintions ====================================================*/

template <typename T>
bool byteToIntegral(const char *byteArray, const size_t size, T &resultInt)
{
   if (size != sizeof(T))
      return false;

   resultInt = 0;
   for (unsigned short i = 0; i < size; ++i)
   {
      resultInt += *(byteArray + i) << (8 * i);
   }

   return true;
}
