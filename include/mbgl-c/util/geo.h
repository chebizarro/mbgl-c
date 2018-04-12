#ifndef __GEO_H
#define __GEO_H

#ifdef __cplusplus
extern "C"{
#endif

struct MbglLatLng;
typedef struct MbglLatLng MbglLatLng;

MbglLatLng* mbgl_lat_long_new(double lat, double lon);

void mbgl_lat_long_destroy(MbglLatLng* self);

#ifdef __cplusplus
}
#endif
#endif

