#include "stdafx.h"
#include "sciter-x-window.hpp"

static RECT wrc = { GetSystemMetrics(SM_CXSCREEN) / 2 - 400,
					GetSystemMetrics(SM_CYSCREEN) / 2 - 300,
					GetSystemMetrics(SM_CXSCREEN) / 2 + 400,
					GetSystemMetrics(SM_CYSCREEN) / 2 + 300 };

class frame : public sciter::window {
public:
	frame() : window(SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN | SW_ENABLE_DEBUG, wrc) {}
};

#include "resources.cpp"

int uimain(std::function<int()> run) {

	//sciter::debug_output_console console; - uncomment it if you will need console window

	sciter::archive::instance().open(aux::elements_of(resources)); // bind resources[] (defined in "resources.cpp") with the archive

	frame* pwin = new frame();

	// note: this:://app URL is dedicated to the sciter::archive content associated with the application
	pwin->load(WSTR("this://app/main.html"));

	pwin->expand();

	return run();
}