#include <mbgl-c/storage/default_file_source.h>
#include <mbgl/storage/default_file_source.hpp>
using namespace mbgl;

#ifdef __cplusplus
extern "C"{
#endif

MbglDefaultFileSource* mbgl_default_file_source_new(const char* cache_path, const char* asset_root) {
	return reinterpret_cast<MbglDefaultFileSource*>(new DefaultFileSource(std::string(cache_path), std::string(asset_root)));
}

void mbgl_default_file_source_destroy(MbglDefaultFileSource* self) {
	delete reinterpret_cast<DefaultFileSource*>(self);
}

#ifdef __cplusplus
}
#endif
