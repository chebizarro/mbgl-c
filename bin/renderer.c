#include <stdio.h>
#include <core.h>

int main(int argc, char *argv[]) {

	MbglRunLoop *loop = mbgl_run_loop_new();
	
	//MbglOnlineFileSource *fileSource = mbgl_online_file_source_new();

	MbglDefaultFileSource *fileSource = mbgl_default_file_source_new(argv[argc-1],".");
	
	const char *token = "pk.eyJ1IjoiY2FzY2FkaWF0bSIsImEiOiJjamZ0enI4MGwzczljMnhxb3VuZGRkNDVyIn0.KhAJn5M1T6IWbnFS1xnrwA";
	
	mbgl_default_file_source_set_access_token(fileSource, token);
	
	//mbgl_online_file_source_set_api_base_url(fileSource, "https://osm.tegola.io/");
		
	MbglThreadPool *threadPool = mbgl_thread_pool_new(4);
	
	MbglSize size = { 1024, 1024 };
		
	MbglHeadlessFrontend *frontend = mbgl_headless_frontend_new(size, 1, fileSource, threadPool);
		
	MbglMapObserver *observer = mbgl_map_observer_null_observer();
	
	MbglMap *map = mbgl_map_new(frontend, observer, size, 1, fileSource, threadPool, STATIC, HEIGHT_ONLY, DEFAULT);
	
	//MbglMap *map = mbgl_map_new_headless(size, 0, fileSource, threadPool, STATIC, 0, 0);
	
	MbglStyle *style = mbgl_map_get_style(map);
	
	mbgl_style_load_url(style, "mapbox://styles/mapbox/satellite-v9");
	
	mbgl_map_set_lat_lng_zoom(map, mbgl_lat_long_new(0,0), 0);
	
	mbgl_map_set_bearing(map, 0);
	
	mbgl_map_set_pitch(map, 0);
	
	//FILE *filefd = fopen("out.png", "wb");
	//fwrite(mbgl_headless_frontend_render(frontend, map), 4, 90000, filefd);
	//fprintf(filefd, "%s", mbgl_headless_frontend_render(frontend, map));
	//fflush(filefd);
	//fclose(filefd);

	mbgl_headless_frontend_render_to_file(frontend, map, "out.png");

	mbgl_map_destroy(map);
	mbgl_headless_frontend_destroy(frontend);
	mbgl_thread_pool_destroy(threadPool);
	//mbgl_online_file_source_destroy(fileSource);
	mbgl_default_file_source_destroy(fileSource);
	mbgl_run_loop_destroy(loop);
	
	return 0;

}
