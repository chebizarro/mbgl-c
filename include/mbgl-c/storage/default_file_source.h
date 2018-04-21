#ifndef __DEFAULT_FILE_SOURCE_H
#define __DEFAULT_FILE_SOURCE_H

#ifdef __cplusplus
extern "C"{
#endif

struct MbglDefaultFileSource;
typedef struct MbglDefaultFileSource MbglDefaultFileSource;

MbglDefaultFileSource* mbgl_default_file_source_new(const char* cache_path, const char* asset_root);
void mbgl_default_file_source_destroy(MbglDefaultFileSource* self);

#ifdef __cplusplus
}
#endif
#endif
