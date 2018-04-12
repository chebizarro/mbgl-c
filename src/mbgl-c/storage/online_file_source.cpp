#include <mbgl-c/storage/online_file_source.h>
#include <mbgl/storage/online_file_source.hpp>
using namespace mbgl;

#ifdef __cplusplus
extern "C"{
#endif

MbglOnlineFileSource* mbgl_online_file_source_new() {
	return reinterpret_cast<MbglOnlineFileSource*>(new OnlineFileSource());
}

void mbgl_online_file_source_destroy(MbglOnlineFileSource* self) {
	delete reinterpret_cast<OnlineFileSource*>(self);
}

#ifdef __cplusplus
}
#endif
