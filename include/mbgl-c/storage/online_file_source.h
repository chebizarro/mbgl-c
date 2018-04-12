#ifndef __ONLINE_FILE_SOURCE_H
#define __ONLINE_FILE_SOURCE_H

#ifdef __cplusplus
extern "C"{
#endif

struct MbglOnlineFileSource;
typedef struct MbglOnlineFileSource MbglOnlineFileSource;

MbglOnlineFileSource* mbgl_online_file_source_new();
void mbgl_online_file_source_destroy(MbglOnlineFileSource* self);

#ifdef __cplusplus
}
#endif
#endif
