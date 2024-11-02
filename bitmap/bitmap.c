#include <stdio.h>
#include <stdlib.h>

#define INVALID_BITMAP_SIZE 0
typedef unsigned char bitmap_t;
typedef unsigned char u8;

/*
 * The create_bitmap function allocates a memory block large enough to represent n bits, 
 * with some space at the beginning to store the n value itself. This allows for efficient storage of bit arrays,
 * 
 */
bitmap_t *create_bitmap(const size_t n)
{
  if (!n) return NULL;
  // n >> 3 == n / 8 calculate the byte required to store n bit
  // n & 0x07 checks if there is a remainder when dividing by 8
  // if there is remainder an extra byte is added 
  size_t bitmap_size = sizeof(size_t) + (n >> 3) + ((n & 0x07) ? 1 : 0);
  bitmap_t *ptr_bitmap = (bitmap_t *)calloc(bitmap_size, sizeof(bitmap_t));
  if (ptr_bitmap == NULL) return NULL;
  /*
   *   Bytes: 0x12  0x34  0x56  0x78
       Index:   3     2     1     0
      Iteration (i)	Shift Amount (i * 8)	n >> (i * 8)	   Masked Byte (& 0xFF)	Stored in ptr_bitmap[i]
      i = 0	        0	                    0x12345678 >> 0	  0x78	                0x78
      i = 1	        8	                    0x12345678 >> 8	  0x56	                0x56
      i = 2	        16	                  0x12345678 >> 16	0x34	                0x34
      i = 3	        24	                  0x12345678 >> 24	0x12	                0x12
  */
  for (u8 i = 0; i < sizeof(size_t); ++i) {
    ptr_bitmap[i] = (n >> (i << 3)) & 0xFF;
  }
  return ptr_bitmap;
}

// extract the size of bitmap, the size of the bitmap is stored at the header of bitmap array
size_t get_bitmap_size(const bitmap_t *ptr_bitmap)
{
  if (!ptr_bitmap) return INVALID_BITMAP_SIZE;
  size_t n = 0x00;
  for(u8 i = 0; i < sizeof(size_t); ++i) {
    n |= (size_t)ptr_bitmap[i] << (i << 3);
  }
  return n;
}

int precheck_sn_size(const size_t sn, const bitmap_t *ptr_bitmap)
{
  size_t bitmap_size = get_bitmap_size(ptr_bitmap);
  if (bitmap_size == INVALID_BITMAP_SIZE) {
    return -3; // invalid
  }
  if (sn >= bitmap_size) {
    return -1; //invalid serial number
  }
  return 0;
}

/*
 * const bitmap_t *head = ptr_bitmap + sizeof(size_t)
 * 
 *
 * For any power of 2 (like 4, which is 2^2), you can use number & (divisor - 1) to get the same result as number % divisor
 * */
int sn_check(const size_t sn, const bitmap_t *ptr_bitmap)
{
  int check = precheck_sn_size(sn, ptr_bitmap);
  if (check < 0)
    return check;
  // head point to the start position of the bitmap, remember the layout, first section of the array is the size of bitmap
  const bitmap_t *head = ptr_bitmap + sizeof(size_t);
  // because each element in the array is a byte that has 8 bit, each bit represent a slot of the number
  // so sn >> 3 is just devide the number by 8 the locate the number in which element  
  // eg: 
  //
  // 0        1
  // 10111000 10001100 
  // so 
  // number 0 - 7 is in the 0 index
  // number 8 - 15 is in the 1 index
  //
  // after get the index of element, calculate the exact bit within the byte
  //
  // 0x80 = 10000000
  // sn & 0x07 == sn % 8 (For any power of 2 (like 4, which is 2^2), you can use number & (divisor - 1) to get the same result as number % divisor)
  // calculate the remainder after number devide 8 which is the slot number of the number within byte
  // then shift 0x80 to the right slot
  return (head[sn >> 3] & ((u8)0x80 >> (sn & 0x07))) ? 1 : 0;
}

int sn_update(const size_t sn, bitmap_t *ptr_bitmap)
{
  int check = precheck_sn_size(sn, ptr_bitmap);
  if (check < 0)
    return check;
  bitmap_t *head = ptr_bitmap + sizeof(size_t);
  head[sn >> 3] |= ((u8)0x80 >> (sn & 0x07));
  return 1;
}

size_t all_check(const bitmap_t *ptr_bitmap)
{
  size_t bitmap_size = get_bitmap_size(ptr_bitmap);
  for (size_t i = 0; i < bitmap_size; ++i) {
    if (!sn_check(i, ptr_bitmap)) {
      return i;
    }
  }
  return 0;
}

void free_bitmap(bitmap_t **ptr_bitmap)
{
  free(*ptr_bitmap);
  *ptr_bitmap = NULL;
}

int main(int argc, char **argv) {
  bitmap_t *p = create_bitmap(16);
  size_t map_size = get_bitmap_size(p);
  printf("the size of map is %lu\n", map_size);

  sn_update(15, p);
  sn_update(14, p);

  printf("15 is %d 14 is %d, 12 is %d\n", sn_check(15, p), sn_check(14, p), sn_check(12, p));

  return 0;
}
