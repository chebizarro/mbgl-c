#include <mbgl-c/map/map.h>
#include <mbgl-c/util/default_thread_pool.h>
#include <mbgl-c/util/run_loop.h>
#include <mbgl-c/storage/default_file_source.h>
#include <mbgl-c/gl/headless_frontend.h>
#include <mbgl-c/map/mode.h>
#include <mbgl-c/util/size.h>


int main(int argc, char *argv[]) {

	mbgl_run_loop_new();
	
	MbglDefaultFileSource *fileSource = mbgl_default_file_source_new(argv[argc-1],argv[argc]);
	
	MbglThreadPool *threadPool = mbgl_thread_pool_new(4);
	
	MbglSize size;
	
	MbglHeadlessFrontend *frontend = mbgl_headless_frontend_new(size, 0, fileSource, threadPool);
	
	MbglMap *map = mbgl_map_new(frontend, mbgl_map_observer_null_observer(), size, 0, fileSource, threadPool, STATIC, 0, 0);
	
	mbgl_map_get_style(map);
	
	return 0;

}
