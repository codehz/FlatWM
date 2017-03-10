#include "FlatWM.h"
#include "Fetcher.hpp"
#include <iostream>
#include <sys/stat.h>
#include <signal.h>

using std::ofstream;

FlatWM &FlatWM::get()
{
	static FlatWM single;
	return single;
}

void FlatWM::Run()
{
	EventLoop();
}

const char *FlatWM::pipe_f = "/tmp/FlatWM";

FlatWM::FlatWM() 
	:conn(xcb_connect(NULL, NULL)),
	screen(xcb_setup_roots_iterator(xcb_get_setup(conn.get())).data) {
	screen_dimension.w = screen->width_in_pixels;
	screen_dimension.h = screen->height_in_pixels;
	//TODO: first desktop
	std::uint32_t mask[] = { XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY | XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT };
	xcb_change_window_attributes(conn.get(), screen->root, XCB_CW_EVENT_MASK, mask);

	xcb_flush(conn.get());

	signal(SIGINT, FlatWM::OnQuit);
}

void FlatWM::EventLoop()
{

}

void FlatWM::OnQuit(int)
{
	xcb_disconnect(FlatWM::get().conn.get());
	exit(0);
}
