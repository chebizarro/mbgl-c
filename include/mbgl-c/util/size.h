#ifndef __SIZE_H
#define __SIZE_H

#include <cstdint>

#ifdef __cplusplus
extern "C"{
#endif

struct MbglSize {
	uint32_t width;
	uint32_t height;
};

typedef struct MbglSize MbglSize;

//const MbglSize mbgl_size_new(const uint32_t width, const uint32_t height);

//void mbgl_size_destroy(MbglSize* self);

#ifdef __cplusplus
}
#endif
#endif
