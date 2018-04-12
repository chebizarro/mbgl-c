#include <mbgl-c/util/geo.h>
#include <mbgl/util/geo.hpp>
using namespace mbgl;

#ifdef __cplusplus
extern "C"{
#endif

MbglLatLng* mbgl_lat_long_new(double lat, double lon) {
	return reinterpret_cast<MbglLatLng*>(new LatLng(lat, lon));
}

void mbgl_style_destroy(MbglLatLng* self) {
	delete reinterpret_cast<LatLng*>(self);
}

#ifdef __cplusplus
}
#endif
