#include <mbgl-c/util/run_loop.h>
#include <mbgl/util/run_loop.hpp>
using namespace mbgl;

#ifdef __cplusplus
extern "C"{
#endif

MbglRunLoop* mbgl_run_loop_new() {
	return reinterpret_cast<MbglRunLoop*>(new util::RunLoop());
}

#ifdef __cplusplus
}
#endif
