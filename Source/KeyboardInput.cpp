#include "../Headers/KeyboardInput.h"
#include <unistd.h>
#include <cstring>

cKeyboard::cKeyboard() {
	active = false;
	keyboard_fd = 0;
	keyboard_ev = new input_event();
	keyboard_st = new keyboard_state();
	keyboard_fd = open(KEYBOARD_DEV, O_RDONLY | O_NONBLOCK);
	if (keyboard_fd > 0) {
		ioctl(keyboard_fd, EVIOCGNAME(256), name);
		std::cout << "   Name: " << name << std::endl;
		active = true;
		pthread_create(&thread, 0, &cKeyboard::loop, this);
	}
}

void* cKeyboard::loop(void *obj) {
	while (reinterpret_cast<cKeyboard *>(obj)->active) reinterpret_cast<cKeyboard *>(obj)->readEv();
}

void cKeyboard::readEv() {
	read(keyboard_fd, &keyboard_ev, sizeof(keyboard_ev));

	if (keyboard_ev->type == 1 && keyboard_ev->value == 1) 
	{
		std::cout << keyboard_ev->code << std::endl;
		keyboard_st->keys[keyboard_ev->code] = keyboard_ev->value;
	}
}

short cKeyboard::getKeyState(short key) {
	return keyboard_st->keys[key];
}

cKeyboard::~cKeyboard() {
	if (keyboard_fd > 0) {
		active = false;
		pthread_join(thread, 0);
		close(keyboard_fd);
	}
	delete keyboard_st;
	delete keyboard_ev;
	keyboard_fd = 0;
}