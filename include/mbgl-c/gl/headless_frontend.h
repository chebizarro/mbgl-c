#ifndef __HEADLESS_FRONTEND_H
#define __HEADLESS_FRONTEND_H

#include <mbgl-c/util/size.h>
#include <mbgl-c/util/image.h>
#include <mbgl-c/map/map.h>
#include <mbgl-c/actor/scheduler.h>
#include <mbgl-c/storage/file_source.h>

#ifdef __cplusplus
extern "C"{
#endif

struct MbglRendererFrontend;
typedef struct MbglRendererFrontend MbglRendererFrontend;
typedef struct MbglRendererFrontend MbglHeadlessFrontend;

MbglHeadlessFrontend* mbgl_headless_frontend_new(
	const MbglSize size,
	float pixelRatio,
	MbglFileSource* fileSource,
	MbglScheduler* scheduler);

void mbgl_headless_frontend_destroy(MbglHeadlessFrontend* self);

MbglPremultipliedImage* mbgl_headless_frontend_render(MbglHeadlessFrontend* self, MbglMap* map);

#ifdef __cplusplus
}
#endif
#endif

