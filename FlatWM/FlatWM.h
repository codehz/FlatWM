#pragma once
extern "C" {
#include <X11\Xlib-xcb.h>
}
#include <memory>
#include <forward_list>
#include <fstream>

#include "SimpleDeletor.h"
#include "Utils.h"
#include "Desktop.h"

class FlatWM {
public:
	static FlatWM &get();

	void Run();
private:
	FlatWM();
	void EventLoop();

	static void OnQuit(int);

	static const char *pipe_f;

	const CustomUniquePtr<xcb_connection_t> conn;
	const CustomUniquePtr<xcb_screen_t> screen;
	Rect<> screen_dimension;
	::std::forward_list<Desktop> desktop_list;
};