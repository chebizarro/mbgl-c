#include <mbgl-c/map/map.h>
#include <mbgl/map/map.hpp>
#include <mbgl/style/style.hpp>
#include <mbgl/util/geometry.hpp>

using namespace mbgl;

#ifdef __cplusplus
extern "C"{
#endif

MbglMap* mbgl_map_new(
	MbglRendererFrontend* renderer,
	MbglMapObserver* observer,
	MbglSize size,
	float pixelRatio,
	MbglFileSource* source,
	MbglScheduler* scheduler,
	MbglMapMode mapMode,
	MbglConstrainMode constrainMode,
	MbglViewportMode viewportMode) {

	return reinterpret_cast<MbglMap*>(
		new Map(
			reinterpret_cast<RendererFrontend&>(renderer),
			reinterpret_cast<MapObserver&>(observer),
			{size.width, size.height},
			pixelRatio,
			reinterpret_cast<FileSource&>(source),
			reinterpret_cast<Scheduler&>(scheduler),
			static_cast<MapMode>(mapMode),
			static_cast<ConstrainMode>(constrainMode),
			static_cast<ViewportMode>(viewportMode))
		);
}

void mbgl_map_destroy(MbglMap* self) {
	delete reinterpret_cast<Map*>(self);
}

MbglStyle* mbgl_map_get_style(MbglMap* self) {
	style::Style& style = (reinterpret_cast<Map*>(self))->getStyle();
	return reinterpret_cast<MbglStyle*>(&style);
}

void mbgl_map_set_lat_lng_zoom(MbglMap* self, const MbglLatLng* latLng, double zoom) {
	(reinterpret_cast<Map*>(self))->setLatLngZoom(
		reinterpret_cast<const LatLng&>(latLng),
		zoom);		
}

void mbgl_map_set_bearing(MbglMap* self, double degrees) {
	(reinterpret_cast<Map*>(self))->setBearing(degrees);	
}

void mbgl_map_set_pitch(MbglMap* self, double pitch) {
	(reinterpret_cast<Map*>(self))->setPitch(pitch);
}

void mbgl_map_set_debug(MbglMap* self, MbglMapDebugOptions debugOptions) {
	(reinterpret_cast<Map*>(self))->setDebug(
		static_cast<MapDebugOptions>(debugOptions)
	);		
}

#ifdef __cplusplus
}
#endif
