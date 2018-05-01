#include <mbgl-c/map/map.h>
#include <mbgl-c/util/default_thread_pool.h>
#include <mbgl-c/util/run_loop.h>
#include <mbgl-c/storage/online_file_source.h>
#include <mbgl-c/gl/headless_frontend.h>
#include <mbgl-c/map/mode.h>
#include <mbgl-c/util/size.h>

int main() {

	MbglRunLoop *loop = mbgl_run_loop_new();
	
	MbglOnlineFileSource *fileSource = mbgl_online_file_source_new();
	
	mbgl_online_file_source_set_api_base_url(fileSource, "https://osm.tegola.io/");
		
	MbglThreadPool *threadPool = mbgl_thread_pool_new(4);
	
	MbglSize size = { 256, 256 };
	
	MbglHeadlessFrontend *frontend = mbgl_headless_frontend_new(size, 0, fileSource, threadPool);
		
	MbglMapObserver *observer = mbgl_map_observer_null_observer();
	
	MbglMap *map = mbgl_map_new(frontend, observer, size, 0, fileSource, threadPool, STATIC, 0, 0);
	
	//MbglMap *map = mbgl_map_new_headless(size, 0, fileSource, threadPool, STATIC, 0, 0);
	
	mbgl_map_get_style(map);
	
	mbgl_frontend_render(frontend, map);

	mbgl_map_destroy(map);
	mbgl_headless_frontend_destroy(frontend);
	mbgl_thread_pool_destroy(threadPool);
	mbgl_online_file_source_destroy(fileSource);
	mbgl_run_loop_destroy(loop);
	
	return 0;

}
