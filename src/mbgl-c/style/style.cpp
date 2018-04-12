#include <mbgl-c/style/style.h>
#include <mbgl/style/style.hpp>
using namespace mbgl;

#ifdef __cplusplus
extern "C"{
#endif

MbglStyle* mbgl_style_new(
	MbglScheduler* scheduler,
	MbglFileSource* fileSource,
	float pixelRatio) {
	
	return reinterpret_cast<MbglStyle*>(
		new style::Style(
			reinterpret_cast<Scheduler&>(scheduler),
			reinterpret_cast<FileSource&>(fileSource),
			pixelRatio
		)
	);

}

void mbgl_style_destroy(MbglStyle* self) {
	delete reinterpret_cast<style::Style*>(self);
}

#ifdef __cplusplus
}
#endif
