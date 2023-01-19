/*
 * The MIT License
 *
 * Copyright 2020 Michael Brinkmeier, AG Didaktik der Informatik.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef ALGOVIZ_HPP
#define ALGOVIZ_HPP

// #include "Version.hpp"

#include <string>
#include <iostream>
#include <unistd.h>
#include <map>
#include <chrono>
// #include "xcpp/xdisplay.hpp"
// #include "xeus/xcomm.hpp"
// #include "xeus/xinterpreter.hpp"
// #include "xeus/xinput.hpp"
// #include "nlohmann/json.hpp"

using namespace std;

class MouseState {

protected:
	int _x;
	int _y;
	int _screenX;
	int _screenY;
	int _buttons;
	bool _legal;

public:

	MouseState() {
		this->_x = -1;
		this->_y = -1;
		this->_screenX = -1;
		this->_screenY = -1;
		this->_buttons = -1;
		this->_legal = false;
	}

	std::string m_content;

	inline int x() {
		return this->_x;
	}

	inline int y() {
		return this->_y;
	}

	inline int screenX() {
		return this->_screenX;
	}

	inline int screenY() {
		return this->_screenY;
	}

	inline int buttons() {
		return this->_buttons;
	}

	inline bool left() {
		return (this->_buttons == 0);
	}

	inline bool right() {
		return (this->_buttons == 2);
	}

	inline bool middle() {
		return (this->_buttons == 1);
	}

	inline bool isLegal() {
		return this->_legal;
	}

};

// ===============================================================================

class AlgoViz {

public:
	static std::chrono::time_point<std::chrono::steady_clock> lastMessageTime;

	static bool queueing;

	static int queueSize;

	static double sendDelay;

	static std::string version();

	static void init();

	static void clear();

	static void show();

	static void hide();

	static void sendText(const std::string &msg);

	static inline void sleep(int msec);

	static void collectMessages();

	static void flushMessages(bool queueing);

	static void html(const std::string &content);

	static void sendCode(const std::string code);

	static void slideshow(const std::string &content,
			const std::string &server =
					"https://abbozza.informatik.uos.de/aud/slideshows/html/viewer.html",
			const std::string &width = "100%", const std::string &height =
					"700px");

	static std::string getColor(int red, int green, int blue,
			float alpha = 1.0);

	static void _slideshow(const std::string &id, const std::string &title,
			const std::string &content, const double ratio);

	inline static std::string lastMessage();

	static std::string getMouse();
};

// =====================================================================================

class AlgoVizView {

public:
	static map<int, AlgoVizView*> views;
	static int nextViewID;

protected:
	int id;
	string type;
	int rowHeight = 80;
	int colWidth = 80;

public:

	virtual ~AlgoVizView() {
	}

	void create(int width, int height, std::string title = "") {

	}

	void hide() {

	}

	void show() {

	}

	virtual void clear() {

	}

	static AlgoVizView* getView(int id) {

		return nullptr;
	}

	inline std::string toString() {
		return "View " + std::to_string(this->id);
	}

	std::string waitForKey() {
		return "#ALGOVIZ#";
	}

	std::string lastKey() {
		return "#ALGOVIZ#";
	}

	MouseState getMouseState() {
		MouseState data;

		return data;
	}

	MouseState lastClick() {
		MouseState data = MouseState();

		return data;
	}

	MouseState waitForClick() {
		MouseState data = MouseState();

		return data;
	}

	void waitForClick(MouseState &data) {

	}

	inline int getId() {
		return this->id;
	}

	void setStatusMsg(string status) {

	}

	void clearStatusMsg() {

	}

};
// class AlgoVizView

// =================================================================================

map<int, AlgoVizView*> AlgoVizView::views = map<int, AlgoVizView*>();

int AlgoVizView::nextViewID = 0;

// =================================================================================

namespace algoviz {

class CommHandler;

algoviz::CommHandler *comm = nullptr;

int nextViewID = 0;
int nextScriptID = 0;

struct html {
	inline html(const std::string &content) {
		m_content = content;
	}
	std::string m_content;
};

struct script_t {
	inline script_t(const std::string &content) {
		m_content = content;
	}
	std::string m_content;
};

class CommHandler {

private:

public:
	CommHandler() {

	}

	inline std::string lastReceived() {

		return "";
	}

};

}
;
// namespace algoviz

// ====================================================================================

std::chrono::time_point<std::chrono::steady_clock> AlgoViz::lastMessageTime;
int AlgoViz::queueSize = 100;
double AlgoViz::sendDelay = 1500.0;
bool AlgoViz::queueing = false;

std::string AlgoViz::version() {
	return "";
}

void AlgoViz::init() {

}

void AlgoViz::clear() {

}

void AlgoViz::show() {

}

void AlgoViz::hide() {

}

void AlgoViz::sendText(const std::string &text) {

}

inline void AlgoViz::sleep(int msec) {

}

void AlgoViz::collectMessages() {
	AlgoViz::queueing = true;
}

void AlgoViz::flushMessages(bool queueing = false) {

}

void AlgoViz::sendCode(string code) {

}

void AlgoViz::html(const std::string &content) {

}

void AlgoViz::slideshow(const std::string &content, const std::string &server,
		const std::string &width, const std::string &height) {

}

std::string AlgoViz::getColor(int red, int green, int blue, float alpha) {
	return "rgba()";
}

void AlgoViz::_slideshow(const std::string &id, const std::string &title,
		const std::string &content, const double ratio) {

}

std::string AlgoViz::lastMessage() {
	return "";
}

#endif
