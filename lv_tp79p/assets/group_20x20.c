#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_GROUP_20X20
#define LV_ATTRIBUTE_IMG_GROUP_20X20
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_GROUP_20X20 uint8_t group_20x20_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Blue: 2 bit, Green: 3 bit, Red: 3 bit*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x6e, 0x25, 0x26, 0x4a, 0x93, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0x26, 0x26, 0x26, 0x26, 0x06, 0x26, 0x6e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x73, 0x06, 0x26, 0x06, 0x06, 0x26, 0x26, 0x25, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x4a, 0x06, 0x06, 0x06, 0x26, 0x26, 0x26, 0x26, 0x93, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x06, 0x26, 0x73, 0x93, 0x4e, 0xb7, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x6e, 0x26, 0x26, 0x06, 0x26, 0x26, 0x26, 0x26, 0xb7, 0x6e, 0x26, 0x26, 0xdb, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xdb, 0x26, 0x26, 0x26, 0x06, 0x26, 0x26, 0x4a, 0xff, 0x2a, 0x26, 0x26, 0x6f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0x2a, 0x05, 0x26, 0x26, 0x4e, 0xdf, 0x4a, 0x26, 0x26, 0x06, 0x72, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xbb, 0xb7, 0xdb, 0xff, 0xbb, 0x93, 0x4a, 0x26, 0x26, 0xb7, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0x93, 0x2a, 0x26, 0x26, 0x26, 0x26, 0x26, 0x4a, 0x93, 0xdf, 0x97, 0x93, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x2a, 0x26, 0x26, 0x26, 0x06, 0x26, 0x26, 0x26, 0x06, 0x26, 0x2a, 0xff, 0x4e, 0x93, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0x93, 0x26, 0x26, 0x26, 0x06, 0x26, 0x26, 0x06, 0x26, 0x26, 0x26, 0x26, 0x73, 0xb7, 0x25, 0x72, 0xff, 0xff, 
  0xff, 0xbb, 0x26, 0x06, 0x06, 0x06, 0x06, 0x26, 0x06, 0x26, 0x26, 0x26, 0x06, 0x26, 0x26, 0xdb, 0x6f, 0x26, 0x93, 0xff, 
  0xff, 0x93, 0x26, 0x06, 0x26, 0x06, 0x26, 0x26, 0x25, 0x06, 0x06, 0x06, 0x26, 0x26, 0x26, 0x93, 0x6f, 0x26, 0x6f, 0xff, 
  0xff, 0x6e, 0x26, 0x26, 0x06, 0x06, 0x06, 0x06, 0x06, 0x26, 0x26, 0x06, 0x26, 0x26, 0x26, 0x4e, 0x93, 0x26, 0xb7, 0xff, 
  0xff, 0xdb, 0x6f, 0x26, 0x26, 0x26, 0x06, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x6e, 0xdb, 0xdf, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xdb, 0xdb, 0xdb, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xbf, 0xf7, 0xde, 0xd6, 0xff, 0xff, 0xbf, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xbe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7e, 0xce, 0x32, 0x5b, 0x4c, 0x21, 0x0e, 0x19, 0x31, 0x42, 0x36, 0x84, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xde, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xde, 0x8d, 0x29, 0x2e, 0x11, 0x2f, 0x11, 0x31, 0x19, 0xcf, 0x10, 0xed, 0x10, 0x12, 0x5b, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xdf, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xdf, 0xf7, 0xb4, 0x73, 0xed, 0x10, 0x31, 0x11, 0x11, 0x09, 0xcf, 0x08, 0x71, 0x21, 0x71, 0x21, 0xec, 0x10, 0xfc, 0xbd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xde, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x3a, 0xce, 0x10, 0x11, 0x11, 0x10, 0x09, 0x4f, 0x11, 0x30, 0x11, 0xf0, 0x10, 0x2e, 0x19, 0x57, 0x84, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 
  0xbf, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0x2c, 0x21, 0x30, 0x21, 0x31, 0x19, 0x50, 0x11, 0x0e, 0x11, 0x91, 0x21, 0xcf, 0x08, 0x0e, 0x11, 0xb5, 0x6b, 0x14, 0x74, 0xd0, 0x4a, 0x1b, 0x9d, 0xdf, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xd3, 0x5a, 0xcf, 0x10, 0x30, 0x19, 0x2e, 0x11, 0x0f, 0x11, 0x10, 0x11, 0x30, 0x19, 0x4e, 0x19, 0x5b, 0x9d, 0x33, 0x53, 0xed, 0x10, 0xf0, 0x18, 0xb7, 0xb5, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xff, 0xff, 0x3d, 0xce, 0xed, 0x18, 0xf0, 0x18, 0x32, 0x19, 0xf0, 0x10, 0x51, 0x21, 0xef, 0x10, 0x30, 0x3a, 0xff, 0xf7, 0xf0, 0x31, 0x11, 0x11, 0x31, 0x11, 0x56, 0x63, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x18, 0x9d, 0xee, 0x31, 0x0b, 0x11, 0x0f, 0x11, 0x10, 0x19, 0xb1, 0x4a, 0xdf, 0xce, 0x92, 0x4a, 0xed, 0x10, 0x2d, 0x19, 0xee, 0x08, 0x93, 0x73, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 
  0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x9e, 0xc6, 0x3d, 0xb6, 0x5a, 0x9d, 0x9c, 0xbe, 0x7f, 0xdf, 0xfc, 0xb5, 0xf8, 0x7b, 0xd1, 0x31, 0xcf, 0x10, 0x31, 0x19, 0x56, 0xa5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xf7, 0xf5, 0x7b, 0xcf, 0x31, 0x4e, 0x19, 0x2e, 0x11, 0x30, 0x21, 0x0d, 0x19, 0x0e, 0x19, 0x13, 0x3a, 0x36, 0x7c, 0x1f, 0xd7, 0xb6, 0x84, 0x96, 0x84, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xae, 0x31, 0x0e, 0x19, 0x0f, 0x11, 0x31, 0x19, 0xf1, 0x10, 0xee, 0x10, 0x51, 0x21, 0x30, 0x19, 0xae, 0x10, 0x30, 0x21, 0xcd, 0x31, 0xbf, 0xef, 0xb1, 0x52, 0x36, 0x7c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xdf, 0xf7, 0xf6, 0x7b, 0x0d, 0x19, 0x4f, 0x19, 0x50, 0x19, 0xef, 0x08, 0x30, 0x11, 0x31, 0x19, 0xce, 0x08, 0x2f, 0x11, 0x51, 0x19, 0x52, 0x19, 0x0e, 0x19, 0xb6, 0x6b, 0xd9, 0x94, 0xec, 0x10, 0x94, 0x6b, 0xff, 0xff, 0xff, 0xff, 
  0xdf, 0xff, 0xbb, 0xb5, 0x2d, 0x19, 0xef, 0x10, 0x10, 0x11, 0x0f, 0x11, 0x2e, 0x11, 0x2e, 0x11, 0x0f, 0x11, 0x6f, 0x19, 0x30, 0x11, 0x31, 0x11, 0xee, 0x08, 0x30, 0x19, 0xee, 0x18, 0xdc, 0xb5, 0x15, 0x53, 0xec, 0x10, 0x97, 0x8c, 0xff, 0xff, 
  0xff, 0xff, 0x15, 0x84, 0x0d, 0x19, 0xf0, 0x10, 0x72, 0x19, 0xcf, 0x08, 0x50, 0x11, 0x2f, 0x11, 0x6c, 0x19, 0xf0, 0x08, 0xf1, 0x08, 0x50, 0x11, 0x4f, 0x11, 0x2f, 0x11, 0x2d, 0x19, 0xf7, 0x7b, 0x95, 0x63, 0x0f, 0x19, 0x14, 0x5b, 0xff, 0xf7, 
  0xff, 0xff, 0xf2, 0x5a, 0xcf, 0x18, 0x12, 0x19, 0x10, 0x11, 0x2f, 0x11, 0x30, 0x11, 0x11, 0x11, 0x2e, 0x11, 0x2f, 0x11, 0x30, 0x19, 0xf0, 0x10, 0x30, 0x19, 0x0f, 0x11, 0x2e, 0x11, 0xf4, 0x4a, 0x17, 0x7c, 0x0d, 0x21, 0x3b, 0xa5, 0xff, 0xff, 
  0xff, 0xff, 0xfd, 0xc5, 0xf5, 0x5a, 0xef, 0x18, 0x0e, 0x19, 0x4e, 0x19, 0xed, 0x10, 0x30, 0x19, 0x10, 0x19, 0xf0, 0x18, 0x10, 0x19, 0x0f, 0x19, 0xee, 0x18, 0x2d, 0x19, 0xf3, 0x52, 0x1e, 0xbe, 0xbe, 0xd6, 0x5f, 0xe7, 0xff, 0xff, 0xff, 0xff, 
  0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xf7, 0x7f, 0xef, 0xfd, 0xd6, 0x7b, 0xce, 0x7b, 0xce, 0x3b, 0xc6, 0x5b, 0xc6, 0x9c, 0xce, 0xfd, 0xde, 0x7e, 0xef, 0xdf, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xdf, 0xff, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit BUT the 2 bytes are swapped*/
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xf7, 0xbf, 0xd6, 0xde, 0xff, 0xff, 0xf7, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xbe, 0xff, 0xff, 0xff, 0xff, 0xce, 0x7e, 0x5b, 0x32, 0x21, 0x4c, 0x19, 0x0e, 0x42, 0x31, 0x84, 0x36, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xde, 0xff, 0xff, 0xff, 0xff, 0xde, 0xff, 0x29, 0x8d, 0x11, 0x2e, 0x11, 0x2f, 0x19, 0x31, 0x10, 0xcf, 0x10, 0xed, 0x5b, 0x12, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xdf, 0xff, 0xff, 0xff, 0xfe, 0xf7, 0xdf, 0x73, 0xb4, 0x10, 0xed, 0x11, 0x31, 0x09, 0x11, 0x08, 0xcf, 0x21, 0x71, 0x21, 0x71, 0x10, 0xec, 0xbd, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xde, 0xff, 0xff, 0xff, 0xff, 0x3a, 0x0f, 0x10, 0xce, 0x11, 0x11, 0x09, 0x10, 0x11, 0x4f, 0x11, 0x30, 0x10, 0xf0, 0x19, 0x2e, 0x84, 0x57, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 
  0xff, 0xbf, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0x21, 0x2c, 0x21, 0x30, 0x19, 0x31, 0x11, 0x50, 0x11, 0x0e, 0x21, 0x91, 0x08, 0xcf, 0x11, 0x0e, 0x6b, 0xb5, 0x74, 0x14, 0x4a, 0xd0, 0x9d, 0x1b, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x5a, 0xd3, 0x10, 0xcf, 0x19, 0x30, 0x11, 0x2e, 0x11, 0x0f, 0x11, 0x10, 0x19, 0x30, 0x19, 0x4e, 0x9d, 0x5b, 0x53, 0x33, 0x10, 0xed, 0x18, 0xf0, 0xb5, 0xb7, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xff, 0xce, 0x3d, 0x18, 0xed, 0x18, 0xf0, 0x19, 0x32, 0x10, 0xf0, 0x21, 0x51, 0x10, 0xef, 0x3a, 0x30, 0xf7, 0xff, 0x31, 0xf0, 0x11, 0x11, 0x11, 0x31, 0x63, 0x56, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x9d, 0x18, 0x31, 0xee, 0x11, 0x0b, 0x11, 0x0f, 0x19, 0x10, 0x4a, 0xb1, 0xce, 0xdf, 0x4a, 0x92, 0x10, 0xed, 0x19, 0x2d, 0x08, 0xee, 0x73, 0x93, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
  0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xc6, 0x9e, 0xb6, 0x3d, 0x9d, 0x5a, 0xbe, 0x9c, 0xdf, 0x7f, 0xb5, 0xfc, 0x7b, 0xf8, 0x31, 0xd1, 0x10, 0xcf, 0x19, 0x31, 0xa5, 0x56, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xdf, 0x7b, 0xf5, 0x31, 0xcf, 0x19, 0x4e, 0x11, 0x2e, 0x21, 0x30, 0x19, 0x0d, 0x19, 0x0e, 0x3a, 0x13, 0x7c, 0x36, 0xd7, 0x1f, 0x84, 0xb6, 0x84, 0x96, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x31, 0xae, 0x19, 0x0e, 0x11, 0x0f, 0x19, 0x31, 0x10, 0xf1, 0x10, 0xee, 0x21, 0x51, 0x19, 0x30, 0x10, 0xae, 0x21, 0x30, 0x31, 0xcd, 0xef, 0xbf, 0x52, 0xb1, 0x7c, 0x36, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf7, 0xdf, 0x7b, 0xf6, 0x19, 0x0d, 0x19, 0x4f, 0x19, 0x50, 0x08, 0xef, 0x11, 0x30, 0x19, 0x31, 0x08, 0xce, 0x11, 0x2f, 0x19, 0x51, 0x19, 0x52, 0x19, 0x0e, 0x6b, 0xb6, 0x94, 0xd9, 0x10, 0xec, 0x6b, 0x94, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xdf, 0xb5, 0xbb, 0x19, 0x2d, 0x10, 0xef, 0x11, 0x10, 0x11, 0x0f, 0x11, 0x2e, 0x11, 0x2e, 0x11, 0x0f, 0x19, 0x6f, 0x11, 0x30, 0x11, 0x31, 0x08, 0xee, 0x19, 0x30, 0x18, 0xee, 0xb5, 0xdc, 0x53, 0x15, 0x10, 0xec, 0x8c, 0x97, 0xff, 0xff, 
  0xff, 0xff, 0x84, 0x15, 0x19, 0x0d, 0x10, 0xf0, 0x19, 0x72, 0x08, 0xcf, 0x11, 0x50, 0x11, 0x2f, 0x19, 0x6c, 0x08, 0xf0, 0x08, 0xf1, 0x11, 0x50, 0x11, 0x4f, 0x11, 0x2f, 0x19, 0x2d, 0x7b, 0xf7, 0x63, 0x95, 0x19, 0x0f, 0x5b, 0x14, 0xf7, 0xff, 
  0xff, 0xff, 0x5a, 0xf2, 0x18, 0xcf, 0x19, 0x12, 0x11, 0x10, 0x11, 0x2f, 0x11, 0x30, 0x11, 0x11, 0x11, 0x2e, 0x11, 0x2f, 0x19, 0x30, 0x10, 0xf0, 0x19, 0x30, 0x11, 0x0f, 0x11, 0x2e, 0x4a, 0xf4, 0x7c, 0x17, 0x21, 0x0d, 0xa5, 0x3b, 0xff, 0xff, 
  0xff, 0xff, 0xc5, 0xfd, 0x5a, 0xf5, 0x18, 0xef, 0x19, 0x0e, 0x19, 0x4e, 0x10, 0xed, 0x19, 0x30, 0x19, 0x10, 0x18, 0xf0, 0x19, 0x10, 0x19, 0x0f, 0x18, 0xee, 0x19, 0x2d, 0x52, 0xf3, 0xbe, 0x1e, 0xd6, 0xbe, 0xe7, 0x5f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xdf, 0xef, 0x7f, 0xd6, 0xfd, 0xce, 0x7b, 0xce, 0x7b, 0xc6, 0x3b, 0xc6, 0x5b, 0xce, 0x9c, 0xde, 0xfd, 0xef, 0x7e, 0xf7, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xdf, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Blue: 8 bit, Green: 8 bit, Red: 8 bit, Fix 0xFF: 8 bit, */
  0xfd, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xfd, 0xfd, 0xff, 0xfa, 0xfa, 0xff, 0xff, 0xf6, 0xfc, 0xff, 0xff, 0xf4, 0xfc, 0xff, 0xff, 0xfb, 0xfe, 0xff, 0xff, 0xfc, 0xf8, 0xfe, 0xff, 0xed, 0xff, 0xfc, 0xff, 0xf0, 0xff, 0xf9, 0xff, 0xfa, 0xff, 0xfc, 0xff, 0xf6, 0xf9, 0xf7, 0xff, 0xfd, 0xff, 0xfe, 0xff, 0xf6, 0xfc, 0xfb, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xf4, 0xff, 0xfd, 0xff, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xf8, 0xfc, 0xf6, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xf8, 0xfc, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xf7, 0xf8, 0xff, 0xff, 0xf3, 0xf3, 0xff, 0xf2, 0xd8, 0xd2, 0xff, 0xff, 0xfe, 0xf8, 0xff, 0xff, 0xf5, 0xef, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xfa, 0xfd, 0xfb, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xf8, 0xfa, 0xfb, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xf1, 0xf6, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xff, 0xed, 0xcd, 0xc8, 0xff, 0x92, 0x63, 0x5b, 0xff, 0x60, 0x28, 0x1d, 0xff, 0x73, 0x22, 0x1b, 0xff, 0x8c, 0x46, 0x3f, 0xff, 0xb3, 0x83, 0x7d, 0xff, 0xff, 0xfb, 0xf5, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xf6, 0xfb, 0xfa, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xfd, 0xfd, 0xfd, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 
  0xff, 0xfe, 0xff, 0xff, 0xf4, 0xf8, 0xf9, 0xff, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xfc, 0xde, 0xd9, 0xff, 0x6b, 0x30, 0x26, 0xff, 0x70, 0x23, 0x13, 0xff, 0x7c, 0x24, 0x13, 0xff, 0x8c, 0x23, 0x18, 0xff, 0x7a, 0x19, 0x0f, 0xff, 0x69, 0x1c, 0x13, 0xff, 0x8f, 0x61, 0x5a, 0xff, 0xff, 0xfd, 0xf7, 0xff, 0xfd, 0xff, 0xfe, 0xff, 0xf6, 0xfa, 0xfb, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfd, 0xff, 
  0xff, 0xfa, 0xfd, 0xff, 0xfa, 0xff, 0xff, 0xff, 0xf4, 0xfc, 0xfb, 0xff, 0xff, 0xf7, 0xf3, 0xff, 0xa4, 0x76, 0x6f, 0xff, 0x6a, 0x1b, 0x10, 0xff, 0x87, 0x25, 0x13, 0xff, 0x87, 0x21, 0x0a, 0xff, 0x76, 0x18, 0x05, 0xff, 0x8c, 0x2b, 0x1d, 0xff, 0x87, 0x2b, 0x20, 0xff, 0x60, 0x1d, 0x14, 0xff, 0xdd, 0xbe, 0xb5, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xfa, 0xff, 0xfe, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xfd, 0xff, 0xff, 0xf3, 0xf8, 0xf9, 0xff, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfa, 0xff, 0x77, 0x3f, 0x3a, 0xff, 0x73, 0x19, 0x0e, 0xff, 0x87, 0x21, 0x0f, 0xff, 0x83, 0x1f, 0x07, 0xff, 0x77, 0x28, 0x13, 0xff, 0x7e, 0x24, 0x13, 0xff, 0x7e, 0x1e, 0x11, 0xff, 0x73, 0x24, 0x19, 0xff, 0xb7, 0x89, 0x7e, 0xff, 0xff, 0xfe, 0xf3, 0xff, 0xff, 0xff, 0xf6, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xfc, 0xf7, 0xf8, 0xff, 0xff, 0xfe, 0xff, 0xff, 
  0xff, 0xf5, 0xf8, 0xff, 0xfa, 0xff, 0xff, 0xff, 0xf4, 0xff, 0xfd, 0xff, 0xff, 0xfe, 0xfb, 0xff, 0x64, 0x24, 0x23, 0xff, 0x83, 0x23, 0x1d, 0xff, 0x86, 0x23, 0x15, 0xff, 0x81, 0x28, 0x13, 0xff, 0x72, 0x22, 0x11, 0xff, 0x8a, 0x2f, 0x20, 0xff, 0x77, 0x19, 0x0c, 0xff, 0x6d, 0x1f, 0x12, 0xff, 0xa8, 0x74, 0x67, 0xff, 0xa4, 0x7f, 0x71, 0xff, 0x84, 0x57, 0x4c, 0xff, 0xd8, 0x9f, 0x96, 0xff, 0xfe, 0xf9, 0xfa, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xfe, 0xf9, 0xfa, 0xff, 0xff, 0xfc, 0xfd, 0xff, 
  0xff, 0xfd, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xfe, 0xff, 0xff, 0xf8, 0xf7, 0xff, 0x9c, 0x5a, 0x5b, 0xff, 0x78, 0x17, 0x13, 0xff, 0x83, 0x25, 0x18, 0xff, 0x72, 0x23, 0x10, 0xff, 0x7b, 0x22, 0x14, 0xff, 0x80, 0x20, 0x13, 0xff, 0x81, 0x23, 0x16, 0xff, 0x73, 0x2a, 0x1c, 0xff, 0xdb, 0xa7, 0x96, 0xff, 0x97, 0x63, 0x53, 0xff, 0x69, 0x1d, 0x11, 0xff, 0x83, 0x1e, 0x16, 0xff, 0xb8, 0xb3, 0xb4, 0xff, 0xfc, 0xf7, 0xf8, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xfd, 0xfe, 0xff, 
  0xf7, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0xef, 0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xe9, 0xc4, 0xc8, 0xff, 0x65, 0x1b, 0x1b, 0xff, 0x80, 0x1c, 0x17, 0xff, 0x94, 0x23, 0x19, 0xff, 0x81, 0x1e, 0x10, 0xff, 0x89, 0x27, 0x1d, 0xff, 0x75, 0x1b, 0x14, 0xff, 0x7e, 0x45, 0x3c, 0xff, 0xff, 0xfc, 0xed, 0xff, 0x7e, 0x3d, 0x2e, 0xff, 0x87, 0x20, 0x11, 0xff, 0x88, 0x25, 0x11, 0xff, 0xae, 0x67, 0x64, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xed, 0xff, 0xfe, 0xff, 0xff, 0xfe, 0xff, 0xff, 
  0xff, 0xfd, 0xfe, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xf7, 0xfb, 0xfc, 0xff, 0xff, 0xfe, 0xfc, 0xff, 0xc3, 0x9f, 0x97, 0xff, 0x71, 0x3d, 0x30, 0xff, 0x58, 0x20, 0x0d, 0xff, 0x77, 0x22, 0x13, 0xff, 0x7d, 0x22, 0x19, 0xff, 0x88, 0x54, 0x48, 0xff, 0xf6, 0xd9, 0xcb, 0xff, 0x8e, 0x50, 0x48, 0xff, 0x68, 0x1e, 0x12, 0xff, 0x6c, 0x26, 0x15, 0xff, 0x72, 0x1e, 0x0c, 0xff, 0x9a, 0x72, 0x6d, 0xff, 0xff, 0xfe, 0xf7, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xf9, 0xf5, 0xfa, 0xff, 
  0xff, 0xfe, 0xff, 0xff, 0xf8, 0xf6, 0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xfd, 0xf1, 0xff, 0xf1, 0xd0, 0xbd, 0xff, 0xeb, 0xc6, 0xb0, 0xff, 0xcd, 0xa9, 0x97, 0xff, 0xe0, 0xcf, 0xbc, 0xff, 0xff, 0xed, 0xdc, 0xff, 0xe3, 0xbb, 0xaf, 0xff, 0xbd, 0x7e, 0x76, 0xff, 0x8a, 0x39, 0x32, 0xff, 0x7b, 0x19, 0x11, 0xff, 0x8c, 0x25, 0x1c, 0xff, 0xb3, 0xa9, 0x9f, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xfc, 0xfd, 0xff, 0xff, 0xfd, 0xff, 0xff, 
  0xf8, 0xfd, 0xfc, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xfb, 0xf9, 0xff, 0xff, 0xf9, 0xf4, 0xff, 0xac, 0x7e, 0x76, 0xff, 0x76, 0x38, 0x2d, 0xff, 0x72, 0x29, 0x1b, 0xff, 0x72, 0x26, 0x14, 0xff, 0x84, 0x24, 0x1e, 0xff, 0x65, 0x20, 0x16, 0xff, 0x72, 0x22, 0x1b, 0xff, 0x99, 0x40, 0x3c, 0xff, 0xb4, 0x83, 0x79, 0xff, 0xf6, 0xdf, 0xd0, 0xff, 0xb2, 0x93, 0x84, 0xff, 0xb3, 0x90, 0x82, 0xff, 0xff, 0xfe, 0xf4, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xfc, 0xfd, 0xff, 0xf9, 0xfd, 0xff, 0xff, 
  0xf5, 0xfc, 0xf9, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xfd, 0xf8, 0xff, 0x6d, 0x36, 0x2f, 0xff, 0x6e, 0x21, 0x18, 0xff, 0x7b, 0x1f, 0x14, 0xff, 0x8b, 0x25, 0x18, 0xff, 0x86, 0x1d, 0x10, 0xff, 0x6e, 0x1b, 0x13, 0xff, 0x87, 0x28, 0x1f, 0xff, 0x7e, 0x25, 0x1b, 0xff, 0x6f, 0x14, 0x0d, 0xff, 0x7d, 0x25, 0x1e, 0xff, 0x67, 0x3a, 0x2d, 0xff, 0xff, 0xf6, 0xe7, 0xff, 0x8b, 0x54, 0x4d, 0xff, 0xaf, 0x83, 0x7c, 0xff, 0xff, 0xfb, 0xf5, 0xff, 0xfe, 0xfc, 0xfb, 0xff, 0xf6, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0xff, 0xff, 0xf7, 0xf3, 0xff, 0xaf, 0x7b, 0x75, 0xff, 0x6a, 0x1f, 0x16, 0xff, 0x7c, 0x27, 0x18, 0xff, 0x7f, 0x27, 0x16, 0xff, 0x75, 0x1d, 0x0c, 0xff, 0x7f, 0x25, 0x14, 0xff, 0x85, 0x24, 0x1a, 0xff, 0x72, 0x19, 0x0b, 0xff, 0x7a, 0x23, 0x13, 0xff, 0x89, 0x28, 0x1a, 0xff, 0x8d, 0x27, 0x1b, 0xff, 0x74, 0x21, 0x19, 0xff, 0xae, 0x75, 0x6c, 0xff, 0xca, 0x9a, 0x94, 0xff, 0x60, 0x1b, 0x12, 0xff, 0xa0, 0x72, 0x6b, 0xff, 0xff, 0xfd, 0xf7, 0xff, 0xf7, 0xff, 0xfd, 0xff, 
  0xff, 0xfa, 0xf8, 0xff, 0xd9, 0xb3, 0xaf, 0xff, 0x67, 0x23, 0x1c, 0xff, 0x75, 0x1d, 0x0f, 0xff, 0x7d, 0x21, 0x0e, 0xff, 0x78, 0x22, 0x0e, 0xff, 0x73, 0x24, 0x0f, 0xff, 0x72, 0x25, 0x12, 0xff, 0x78, 0x20, 0x10, 0xff, 0x7a, 0x2e, 0x1b, 0xff, 0x82, 0x26, 0x13, 0xff, 0x8a, 0x24, 0x11, 0xff, 0x73, 0x1b, 0x0a, 0xff, 0x84, 0x25, 0x1b, 0xff, 0x71, 0x1b, 0x15, 0xff, 0xe4, 0xba, 0xb3, 0xff, 0xa6, 0x61, 0x52, 0xff, 0x64, 0x1c, 0x14, 0xff, 0xba, 0x90, 0x89, 0xff, 0xff, 0xff, 0xf9, 0xff, 
  0xff, 0xfe, 0xfc, 0xff, 0xa9, 0x80, 0x7d, 0xff, 0x6c, 0x21, 0x19, 0xff, 0x81, 0x1e, 0x10, 0xff, 0x92, 0x2b, 0x18, 0xff, 0x7b, 0x1a, 0x06, 0xff, 0x81, 0x28, 0x14, 0xff, 0x7b, 0x23, 0x12, 0xff, 0x60, 0x2c, 0x15, 0xff, 0x7d, 0x1e, 0x0a, 0xff, 0x87, 0x1e, 0x09, 0xff, 0x7d, 0x28, 0x0e, 0xff, 0x7c, 0x27, 0x11, 0xff, 0x77, 0x25, 0x14, 0xff, 0x68, 0x23, 0x19, 0xff, 0xbc, 0x7c, 0x77, 0xff, 0xab, 0x70, 0x5d, 0xff, 0x7a, 0x21, 0x17, 0xff, 0xa4, 0x60, 0x5b, 0xff, 0xff, 0xff, 0xf4, 0xff, 
  0xff, 0xfb, 0xf6, 0xff, 0x8d, 0x5d, 0x5b, 0xff, 0x76, 0x19, 0x16, 0xff, 0x8f, 0x22, 0x1a, 0xff, 0x80, 0x20, 0x10, 0xff, 0x77, 0x24, 0x0e, 0xff, 0x7d, 0x24, 0x0f, 0xff, 0x87, 0x20, 0x0d, 0xff, 0x72, 0x23, 0x0e, 0xff, 0x7b, 0x25, 0x11, 0xff, 0x82, 0x26, 0x15, 0xff, 0x7e, 0x1e, 0x0e, 0xff, 0x83, 0x26, 0x17, 0xff, 0x76, 0x21, 0x11, 0xff, 0x6f, 0x24, 0x14, 0xff, 0x9e, 0x5c, 0x4a, 0xff, 0xb7, 0x80, 0x79, 0xff, 0x67, 0x22, 0x1f, 0xff, 0xd5, 0xa5, 0xa3, 0xff, 0xff, 0xff, 0xf9, 0xff, 
  0xff, 0xfd, 0xfe, 0xff, 0xe9, 0xbd, 0xbe, 0xff, 0xa9, 0x5c, 0x5a, 0xff, 0x76, 0x1b, 0x16, 0xff, 0x73, 0x21, 0x16, 0xff, 0x73, 0x2a, 0x1c, 0xff, 0x6a, 0x1b, 0x10, 0xff, 0x7d, 0x26, 0x1c, 0xff, 0x83, 0x21, 0x19, 0xff, 0x7f, 0x1d, 0x15, 0xff, 0x81, 0x21, 0x1b, 0xff, 0x7b, 0x20, 0x19, 0xff, 0x71, 0x1d, 0x17, 0xff, 0x6b, 0x23, 0x1b, 0xff, 0x98, 0x5d, 0x53, 0xff, 0xf4, 0xc1, 0xb7, 0xff, 0xf3, 0xd6, 0xcf, 0xff, 0xf8, 0xea, 0xe4, 0xff, 0xff, 0xfe, 0xf9, 0xff, 0xff, 0xff, 0xfe, 0xff, 
  0xf3, 0xff, 0xff, 0xff, 0xfa, 0xff, 0xfd, 0xff, 0xff, 0xfd, 0xf8, 0xff, 0xff, 0xf7, 0xef, 0xff, 0xfd, 0xee, 0xe5, 0xff, 0xec, 0xdd, 0xd4, 0xff, 0xdc, 0xcc, 0xc6, 0xff, 0xdb, 0xcb, 0xc5, 0xff, 0xd7, 0xc4, 0xbd, 0xff, 0xdb, 0xc8, 0xc3, 0xff, 0xe1, 0xd1, 0xcb, 0xff, 0xe6, 0xdc, 0xd5, 0xff, 0xf1, 0xed, 0xe8, 0xff, 0xf8, 0xfa, 0xf4, 0xff, 0xf5, 0xfc, 0xf7, 0xff, 0xf6, 0xff, 0xfc, 0xff, 0xff, 0xfe, 0xfb, 0xff, 0xf3, 0xff, 0xfe, 0xff, 0xf2, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 
  0xfb, 0xfe, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xfe, 0xff, 0xfb, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xfc, 0xfb, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xfd, 0xfe, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xfd, 0xfe, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 
#endif
};

const lv_img_dsc_t group_20x20 = {
  .header.always_zero = 0,
  .header.w = 20,
  .header.h = 20,
  .data_size = 400 * LV_COLOR_SIZE / 8,
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .data = group_20x20_map,
};
