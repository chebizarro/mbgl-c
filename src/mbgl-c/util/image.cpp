#include <mbgl-c/util/image.h>
#include <mbgl/util/image.hpp>
using namespace mbgl;

#ifdef __cplusplus
extern "C"{
#endif

const char* mbgl_encode_png(MbglPremultipliedImage* image) {
	return encodePNG(reinterpret_cast<const PremultipliedImage&>(image)).c_str();
}

#ifdef __cplusplus
}
#endif
