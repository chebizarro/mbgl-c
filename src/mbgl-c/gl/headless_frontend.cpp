#include <mbgl-c/gl/headless_frontend.h>
#include <mbgl/gl/headless_frontend.hpp>
#include <mbgl/util/image.hpp>
using namespace mbgl;

#ifdef __cplusplus
extern "C"{
#endif

MbglHeadlessFrontend* mbgl_headless_frontend_new(
	const MbglSize size,
	float pixelRatio,
	MbglFileSource* fileSource,
	MbglScheduler* scheduler) {
		
	return reinterpret_cast<MbglHeadlessFrontend*>(
		new HeadlessFrontend(
			{size.width, size.height},
			pixelRatio,
			reinterpret_cast<FileSource&>(*fileSource),
			reinterpret_cast<Scheduler&>(*scheduler)
		)
	);
}

void mbgl_headless_frontend_destroy(MbglHeadlessFrontend* self) {
	delete reinterpret_cast<HeadlessFrontend*>(self);
}

MbglPremultipliedImage* mbgl_headless_frontend_render(MbglHeadlessFrontend* self, MbglMap* map) {
	return reinterpret_cast<MbglPremultipliedImage*>(
		reinterpret_cast<HeadlessFrontend*>(self)->render(
		reinterpret_cast<Map&>(*map)));
}


#ifdef __cplusplus
}
#endif
