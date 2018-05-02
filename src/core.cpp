#include <mbgl-c/core.h>
#include <mbgl/gl/headless_frontend.hpp>
#include <mbgl/map/map.hpp>
#include <mbgl/map/map_observer.hpp>
#include <mbgl/storage/default_file_source.hpp>
#include <mbgl/storage/online_file_source.hpp>
#include <mbgl/style/style.hpp>
#include <mbgl/util/default_thread_pool.hpp>
#include <mbgl/util/geo.hpp>
#include <mbgl/util/geometry.hpp>
#include <mbgl/util/image.hpp>
#include <mbgl/util/run_loop.hpp>
#include <mbgl/util/size.hpp>



MbglLatLng mbgl_lat_long_new(double lat, double lon) {
	return reinterpret_cast<MbglLatLng>(new LatLng(lat, lon));
}

void mbgl_style_destroy(MbglLatLng self) {
	delete reinterpret_cast<LatLng*>(self);
}


MbglHeadlessFrontend mbgl_headless_frontend_new(
	const MbglSize size,
	float pixelRatio,
	MbglFileSource fileSource,
	MbglScheduler scheduler) {
		
	return reinterpret_cast<MbglHeadlessFrontend>(
		new HeadlessFrontend(
			{size.width, size.height},
			pixelRatio,
			reinterpret_cast<FileSource&>(*fileSource),
			reinterpret_cast<Scheduler&>(*scheduler)
		)
	);
}

void mbgl_headless_frontend_destroy(MbglHeadlessFrontend self) {
	delete reinterpret_cast<HeadlessFrontend*>(self);
}

MbglPremultipliedImage mbgl_headless_frontend_render(MbglHeadlessFrontend self, MbglMap map) {
	return reinterpret_cast<MbglPremultipliedImage>(
		reinterpret_cast<HeadlessFrontend*>(self)->render(
		reinterpret_cast<Map&>(*map)));
}


MbglDefaultFileSource mbgl_default_file_source_new(const char* cache_path, const char* asset_root) {
	return reinterpret_cast<MbglDefaultFileSource>(new DefaultFileSource(std::string(cache_path), std::string(asset_root)));
}

void mbgl_default_file_source_destroy(MbglDefaultFileSource self) {
	delete reinterpret_cast<DefaultFileSource*>(self);
}

MbglOnlineFileSource mbgl_online_file_source_new() {
	return reinterpret_cast<MbglOnlineFileSource>(new OnlineFileSource());
}

void mbgl_online_file_source_set_api_base_url(MbglOnlineFileSource self, const char* url) {
	OnlineFileSource fs = reinterpret_cast<OnlineFileSource*>(self);
	fs->setAPIBaseURL(std::string(url));
}

void mbgl_online_file_source_destroy(MbglOnlineFileSource self) {
	delete reinterpret_cast<OnlineFileSource*>(self);
}



MbglMap mbgl_map_new(
	MbglRendererFrontend renderer,
	MbglMapObserver observer,
	MbglSize size,
	float pixelRatio,
	MbglFileSource source,
	MbglScheduler scheduler,
	MbglMapMode mapMode,
	MbglConstrainMode constrainMode,
	MbglViewportMode viewportMode) {

	return reinterpret_cast<MbglMap>(
		new Map(
			reinterpret_cast<RendererFrontend&>(*renderer),
			reinterpret_cast<MapObserver&>(*observer),
			{size.width, size.height},
			pixelRatio,
			reinterpret_cast<FileSource&>(*source),
			reinterpret_cast<Scheduler&>(*scheduler),
			static_cast<MapMode>(mapMode),
			static_cast<ConstrainMode>(constrainMode),
			static_cast<ViewportMode>(viewportMode))
		);
}

void mbgl_map_destroy(MbglMap self) {
	delete reinterpret_cast<Map*>(self);
}

MbglStyle mbgl_map_get_style(MbglMap self) {
	style::Style& style = (reinterpret_cast<Map*>(self))->getStyle();
	return reinterpret_cast<MbglStyle*>(&style);
}

void mbgl_map_set_lat_lng_zoom(MbglMap self, const MbglLatLng latLng, double zoom) {
	(reinterpret_cast<Map*>(self))->setLatLngZoom(
		reinterpret_cast<const LatLng&>(latLng),
		zoom);		
}

void mbgl_map_set_bearing(MbglMap self, double degrees) {
	(reinterpret_cast<Map*>(self))->setBearing(degrees);	
}

void mbgl_map_set_pitch(MbglMap self, double pitch) {
	(reinterpret_cast<Map*>(self))->setPitch(pitch);
}

void mbgl_map_set_debug(MbglMap self, MbglMapDebugOptions debugOptions) {
	(reinterpret_cast<Map*>(self))->setDebug(
		static_cast<MapDebugOptions>(debugOptions)
	);		
}

MbglMapObserver mbgl_map_observer_null_observer() {
	return reinterpret_cast<MbglMapObserver>(&MapObserver::nullObserver());
}

void mbgl_map_observer_destroy(MbglMapObserver self) {
	delete reinterpret_cast<MapObserver*>(self);
}



MbglThreadPool mbgl_thread_pool_new(size_t count) {
	return reinterpret_cast<MbglThreadPool>(new ThreadPool(count));
}

void mbgl_thread_pool_destroy(MbglThreadPool self) {
	delete reinterpret_cast<ThreadPool*>(self);
}


const char* mbgl_encode_png(MbglPremultipliedImage image) {
	return encodePNG(reinterpret_cast<const PremultipliedImage&>(image)).c_str();
}


MbglRunLoop mbgl_run_loop_new() {
	return reinterpret_cast<MbglRunLoop>(new util::RunLoop());
}

void mbgl_run_loop_destroy(MbglRunLoop self) {
	delete reinterpret_cast<util::RunLoop*>(self);
}
