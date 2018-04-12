#ifndef __MAP_H
#define __MAP_H

#include <mbgl-c/map/mode.h>
#include <mbgl-c/util/size.h>
#include <mbgl-c/util/geo.h>
#include <mbgl-c/storage/file_source.h>
#include <mbgl-c/actor/scheduler.h>
#include <mbgl-c/style/style.h>

#ifdef __cplusplus
extern "C"{
#endif

struct MbglMap;
typedef struct MbglMap MbglMap;

typedef void MbglRendererFrontend;
typedef void MbglMapObserver;

MbglMap* mbgl_map_new(
	MbglRendererFrontend* renderer,
	MbglMapObserver* observer,
	MbglSize size,
	float pixelRatio,
	MbglFileSource* source,
	MbglScheduler* scheduler,
	MbglMapMode mapMode,
	MbglConstrainMode constrainMode,
	MbglViewportMode viewportMode);

void mbgl_map_destroy(MbglMap* self);

MbglStyle* mbgl_map_get_style(MbglMap* self);

void mbgl_map_set_lat_lng_zoom(MbglMap* self, const MbglLatLng* latLng, double zoom);

void mbgl_map_set_bearing(MbglMap* self, double degrees);

void mbgl_map_set_pitch(MbglMap* self, double pitch);

void mbgl_map_set_debug(MbglMap* self, MbglMapDebugOptions debugOptions);

#ifdef __cplusplus
}
#endif
#endif
