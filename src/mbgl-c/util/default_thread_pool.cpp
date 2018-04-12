#include <mbgl-c/util/default_thread_pool.h>
#include <mbgl/util/default_thread_pool.hpp>
using namespace mbgl;

#ifdef __cplusplus
extern "C"{
#endif

MbglThreadPool* mbgl_thread_pool_new(size_t count) {
	return reinterpret_cast<MbglThreadPool*>(new ThreadPool(count));
}

void mbgl_thread_pool_destroy(MbglThreadPool* self) {
	delete reinterpret_cast<ThreadPool*>(self);
}

#ifdef __cplusplus
}
#endif
