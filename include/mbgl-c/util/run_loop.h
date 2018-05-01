#ifndef __RUN_LOOP_H
#define __RUN_LOOP_H

#ifdef __cplusplus
extern "C"{
#endif

struct MbglRunLoop;
typedef struct MbglRunLoop MbglRunLoop;

MbglRunLoop* mbgl_run_loop_new();

void mbgl_run_loop_destroy(MbglRunLoop* self);

#ifdef __cplusplus
}
#endif
#endif
