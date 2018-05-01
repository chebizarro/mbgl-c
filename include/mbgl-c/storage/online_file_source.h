#ifndef __ONLINE_FILE_SOURCE_H
#define __ONLINE_FILE_SOURCE_H

#include <mbgl-c/storage/file_source.h>

#ifdef __cplusplus
extern "C"{
#endif

//struct MbglOnlineFileSource;
typedef struct MbglFileSource MbglOnlineFileSource;
//typedef struct MbglOnlineFileSource MbglOnlineFileSource;

MbglOnlineFileSource* mbgl_online_file_source_new();

void mbgl_online_file_source_set_api_base_url(MbglOnlineFileSource* self, const char* url);

void mbgl_online_file_source_destroy(MbglOnlineFileSource* self);

#ifdef __cplusplus
}
#endif
#endif
