#ifndef __IMAGE_H
#define __IMAGE_H

#ifdef __cplusplus
extern "C"{
#endif

enum MbglImageAlphaMode {
	UNASSOCIATED,
	PREMULTIPLIED,
	EXCLUSIVE
};

struct MbglImage;
typedef struct MbglImage MbglImage;
typedef MbglImage MbglPremultipliedImage;

const char* mbgl_encode_png(MbglPremultipliedImage* image);

#ifdef __cplusplus
}
#endif
#endif
