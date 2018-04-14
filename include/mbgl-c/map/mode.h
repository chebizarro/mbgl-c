#ifndef __MODE_H
#define __MODE_H


#ifdef __cplusplus
extern "C"{
#endif

typedef enum MbglMapMode {
	CONTINUOUS, // continually updating map
	STATIC, // a once-off still image of an arbitrary viewport
	TILE // a once-off still image of a single tile
} MbglMapMode;

typedef enum MbglConstrainMode {
	NONE,
	HEIGHT_ONLY,
	WIDTH_AND_HEIGHT
} MbglConstrainMode;

typedef enum MbglViewportMode {
	DEFAULT,
	FLIPPED_Y
} MbglViewportMode;

typedef enum MbglMapDebugOptions {
	NO_DEBUG     = 0,
	TILE_BORDERS = 1 << 1,
	PARSE_STATUS = 1 << 2,
	TIMESTAMPS   = 1 << 3,
	COLLISION    = 1 << 4,
	OVERDRAW     = 1 << 5
} MbglMapDebugOptions;

#ifdef __cplusplus
}
#endif
#endif
