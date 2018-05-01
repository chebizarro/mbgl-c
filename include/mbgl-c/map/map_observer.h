#ifndef __MAP_OBSERVER_H
#define __MAP_OBSERVER_H

#ifdef __cplusplus
extern "C"{
#endif

//struct MbglMapObserver;
typedef struct MbglMapObserver MbglMapObserver;

MbglMapObserver* mbgl_map_observer_null_observer();

void mbgl_map_observer_destroy(MbglMapObserver* self);

#ifdef __cplusplus
}
#endif
#endif
