#ifndef __MBGL_C_TYPES_H
#define __MBGL_C_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

typedef struct MbglScheduler *MbglScheduler;

typedef struct MbglRendererFrontend *MbglRendererFrontend;

typedef struct MbglRendererFrontend *MbglHeadlessFrontend;

typedef struct MbglMap *MbglMap;

typedef struct MbglMapObserver *MbglMapObserver;

typedef struct MbglFileSource *MbglFileSource;

typedef struct MbglFileSource *MbglDefaultFileSource;

typedef struct MbglFileSource *MbglOnlineFileSource;

typedef struct MbglScheduler *MbglThreadPool;

typedef struct MbglLatLng *MbglLatLng;

typedef struct MbglImage *MbglImage;
typedef struct MbglImage *MbglPremultipliedImage;

typedef struct MbglRunLoop *MbglRunLoop;

struct MbglSize {
	uint32_t width;
	uint32_t height;
};

typedef struct MbglSize MbglSize;




#ifdef __cplusplus
}
#endif
#endif /* __MBGL_C_TYPES_H */
