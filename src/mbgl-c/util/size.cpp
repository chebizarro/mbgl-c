#include <mbgl-c/util/size.h>
#include <mbgl/util/size.hpp>
using namespace mbgl;

#ifdef __cplusplus
extern "C"{
#endif

/*
const MbglSize mbgl_size_new(const uint32_t width, const uint32_t height) {
	return reinterpret_cast<const MbglSize>(new Size(width, height));
}

void mbgl_size_destroy(MbglSize* self) {
	delete reinterpret_cast<Size*>(self);
}*/

#ifdef __cplusplus
}
#endif
