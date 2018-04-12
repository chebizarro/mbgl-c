#ifndef __DEFAULT_THREAD_POOL_H
#define __DEFAULT_THREAD_POOL_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C"{
#endif

struct MbglThreadPool;
typedef struct MbglThreadPool MbglThreadPool;

MbglThreadPool* mbgl_thread_pool_new(size_t count);
void mbgl_thread_pool_destroy(MbglThreadPool* self);

#ifdef __cplusplus
}
#endif
#endif
