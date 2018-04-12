#include <mbgl-c/map/map_observer.h>
#include <mbgl/map/map_observer.hpp>
using namespace mbgl;

#ifdef __cplusplus
extern "C"{
#endif

MbglMapObserver* mbgl_map_observer_null_observer() {
	return reinterpret_cast<MbglMapObserver*>(&MapObserver::nullObserver());
}

void mbgl_map_observer_destroy(MbglMapObserver* self) {
	delete reinterpret_cast<MapObserver*>(self);
}

#ifdef __cplusplus
}
#endif
