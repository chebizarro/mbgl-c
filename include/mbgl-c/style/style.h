#ifndef __STYLE_H
#define __STYLE_H

#include <mbgl-c/actor/scheduler.h>
#include <mbgl-c/storage/file_source.h>

#ifdef __cplusplus
extern "C"{
#endif

struct MbglStyle;
typedef struct MbglStyle MbglStyle;

MbglStyle* mbgl_style_new(MbglScheduler* scheduler, MbglFileSource* fileSource, float pixelRatio);

void mbgl_style_destroy(MbglStyle* self);

#ifdef __cplusplus
}
#endif
#endif

