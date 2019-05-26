#ifndef INCLUDE_TYPES_H_
#define INCLUDE_TYPES_H_

#define NULL ((void*)0)
#define bool int
#define true 1
#define false 0
#define DIV_ROUND_UP(X, STEP) ((X + STEP - 1) / (STEP))
/*自定义数据类型*/
typedef unsigned int   uint32_t;
typedef          int   int32_t;
typedef unsigned short uint16_t;
typedef          short int16_t;
typedef unsigned char  uint8_t;
typedef          char  int8_t;

typedef unsigned int   u32;
typedef          int   s32;
typedef unsigned short u16;
typedef          short s16;
typedef unsigned char  u8;
typedef          char  s8;


typedef void (*irq_handler_t) (int irq);
typedef void* sys_call_t;
typedef	char *	va_list;
typedef void* application_t;

typedef int GLenum;
typedef int GLsizei;
typedef int GLbitfield;
typedef unsigned char GLclampf;
typedef int GLint;


#endif  // INCLUDE_TYPES_H_