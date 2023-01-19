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

#ifndef SVG_HPP
#define SVG_HPP

#include <iostream>
#include <string>
// #include "xeus/xjson.hpp"
#include "AlgoViz.hpp"
#include <vector>
#include <map>
using namespace std;

class AlgoViz;
class SVG;

class SVGElement {

protected:
	SVG *svg;
	int x;
	int y;
	int id;
	int alpha;
	void (*clickHandler)(SVGElement*);
	map<std::string, std::string> attributes = map<std::string, std::string>();

	friend class SVG;

	void sendAttributes();

public:
	SVGElement();

	SVGElement(SVG *view);

	SVGElement(const SVGElement &original);

	virtual ~SVGElement();

	virtual void addTo(SVG *svg);

	SVGElement& operator=(const SVGElement &original);

	void copy(const SVGElement &original);

	int getId();

	virtual int getX() {
		return 0;
	}

	virtual int getY() {
		return 0;
	}

	virtual void moveTo(int x, int y) = 0;

	void moveBy(int dx, int dy);

	void setAttribute(std::string attr, int value);

	void setAttribute(std::string attr, std::string value);

	virtual void rotateTo(int angle);

	void rotateBy(int angle);

	void toFront();

	void hide();

	void show();

	void removeFromView();

	void setColor(string color = "black");

	void setColor(int red, int green, int blue, float alpha = 1.0);

	void setFill(string color = "transparent");

	void setFill(int red, int green, int blue, float alpha = 1.0);

	void setStrokeWidth(int width);

	friend inline bool operator==(const SVGElement &left,
			const SVGElement &right);

	friend inline bool operator!=(const SVGElement &left,
			const SVGElement &right);

	void onclick(void (*handler)(SVGElement*));

protected:

	virtual void clicked();

	virtual void create();

};
// end of class SVGElement

class SVG: public AlgoVizView {

public:
	int nextElementID = 0;
	map<int, SVGElement*> elements = map<int, SVGElement*>();
	SVGElement *clickedElement = nullptr;

	int width;
	int height;
	string stroke = "black";
	int strokeWidth = 1;
	string fill = "transparent";
	string transform = "";

	friend class SVGElement;

	SVG(int width, int height, int gWidth, int gHeight, std::string title =
			"SVG") {
		this->id = AlgoVizView::nextViewID;
		AlgoVizView::views[this->id] = this;
		AlgoVizView::nextViewID++;

		this->type = "svg";
		this->width = width;
		this->height = height;

		AlgoViz::show();

		if (gWidth <= 0) {
			gWidth = width / this->colWidth
					+ (width % this->colWidth > 0 ? 1 : 0);
		}

		if (gHeight <= 0) {
			gHeight = (height + 40) / this->rowHeight
					+ ((height + 40) % this->rowHeight > 0 ? 1 : 0);
		}

	}

	SVG(int width, int height, std::string title = "SVG") :
			SVG(width, height, 0, 0, title) {
	}

	SVG(std::string url, int width, int height, int gw, int gh,
			std::string title = "SVG") :
			SVG(width, height, gw, gh, title) {
		this->load(url);
	}

	SVG() :
			SVG(200, 200, "SVG") {
	}

	inline int getWidth() {
		return 0;
	}

	inline int getHeight() {
		return 0;
	}

	void setViewBox(int x, int y, int w, int h, string aspect = "") {

	}

	void clear() {

	}

	void setColor(string color = "black") {

	}

	void setColor(int red, int green, int blue, float alpha = 1.0) {

	}

	void setFill(string color = "transparent") {

	}

	void setFill(int red, int green, int blue, float alpha = 1.0) {
		;
	}

	void setLineWidth(int width = 1) {

	}

	void setTransform(string transform = "") {

	}

	void drawLine(int x1, int y1, int x2, int y2) {

	}

	void drawCircle(int cx, int cy, int r) {

	}

	void drawRect(int x, int y, int width, int height, int rx = 0, int ry = 0) {

	}

	void drawEllipse(int cx, int cy, int rx, int ry) {

	}

	void drawPath(const string &d) {

	}

	void drawText(const string &text, int x, int y, int fontSize = 16,
			const string &fontFamily = "sans-serif") {

	}

	void drawImage(const string &href, int x, int y, int width, int height) {

	}

	int addElement(SVGElement *element) {
		return 0;
	}

	inline SVGElement* getElement(int id) {
		return nullptr;
	}

	inline SVGElement* getClickedElement() {
		return nullptr;
	}

	void load(std::string url) {

	}

};

void setAttribute(std::string id, std::string attr, std::string value) {

}

// end of class SVG

// ============================================================================================

/********************************
 *                              *
 * Implementation of SVGElement *
 *                              *
 ********************************/

SVGElement::SVGElement() {
	this->svg = nullptr;
	this->id = -1;
	this->x = 0;
	this->y = 0;
	this->alpha = 0;
	this->clickHandler = nullptr;
}

SVGElement::SVGElement(SVG *view) {
	this->x = 0;
	this->y = 0;
	this->alpha = 0;
	this->svg = nullptr;
	this->id = view->addElement(this);
	this->svg = view;
	this->clickHandler = nullptr;
}

SVGElement::SVGElement(const SVGElement &original) {
	this->svg = nullptr;
	this->copy(original);
}

SVGElement::~SVGElement() {
}

void SVGElement::addTo(SVG *svg) {

}

void SVGElement::create() {
}

SVGElement& SVGElement::operator=(const SVGElement &original) {
	return *this;
}

void SVGElement::copy(const SVGElement &original) {

}

int SVGElement::getId() {
	return 0;
}

void SVGElement::moveBy(int dx, int dy) {

}

void SVGElement::sendAttributes() {

}

void SVGElement::setAttribute(const std::string attr, int value) {

}

void SVGElement::setAttribute(std::string attr, std::string value) {

}

void SVGElement::rotateTo(int angle) {

}

void SVGElement::rotateBy(int angle) {

}

void SVGElement::toFront() {

}

void SVGElement::hide() {

}

void SVGElement::show() {

}

void SVGElement::removeFromView() {

}

void SVGElement::setColor(string color) {

}

void SVGElement::setColor(int red, int green, int blue, float alpha) {

}

void SVGElement::setFill(string color) {

}

void SVGElement::setFill(int red, int green, int blue, float alpha) {

}

void SVGElement::setStrokeWidth(int width) {

}

inline bool operator==(const SVGElement &left, const SVGElement &right) {
	return false;
}

inline bool operator!=(const SVGElement &left, const SVGElement &right) {
	return false;
}

void SVGElement::clicked() {

}

void SVGElement::onclick(void (*handler)(SVGElement*)) {

}

/*****************************************
 *                                       *
 * Implementation of several SVGElements *
 *                                       *
 *****************************************/

//===============================================================================
class Circle: public SVGElement {

protected:
	int radius;

public:

	Circle() :
			SVGElement() {
		radius = 0;
	}
	;

	Circle(int cx, int cy, int radius, SVG *view) :
			SVGElement(view) {
		this->x = cx;
		this->y = cy;
		this->radius = radius;

		this->create();
	}

	Circle(const Circle &original) :
			SVGElement(original) {
		this->copy(original);
	}

	Circle& operator=(const Circle &original) {
		return *this;
	}

	void create() {

	}

	void copy(const Circle &original) { // Circle(const Circle& original) : SVGElement(original) {

	}

	void moveTo(int x, int y) {

	}

	void setRadius(int radius) {

	}

	inline int getRadius() {
		return 0;
	}
};

//===============================================================================

class Line: public SVGElement {

protected:
	int x2;
	int y2;

public:

	Line() :
			SVGElement() {
		x2 = 0;
		y2 = 0;
	}
	;

	Line(int x1, int y1, int x2, int y2, SVG *view) :
			SVGElement(view) {
		this->x = x1;
		this->y = y1;
		this->x2 = x2;
		this->y2 = y2;

		this->create();
	}

	Line(const Line &original) {
		this->copy(original);
	}

	void create() {

	}

	Line& operator=(const Line &original) {
		return *this;
	}

	void copy(const Line &original) {

	}

	void moveTo(int x, int y) {

	}

	inline int getX2() {
		return 0;
	}

	inline int getY2() {
		return 0;
	}

};

//===============================================================================

class Rect: public SVGElement {

protected:
	int w;
	int h;
	int rx;
	int ry;

public:
	Rect() :
			SVGElement() {
		w = 0;
		h = 0;
		rx = 0;
		ry = 0;
	}
	;

	Rect(int x, int y, int w, int h, int rx, int ry, SVG *view) :
			SVGElement(view) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
		this->rx = 0;
		this->ry = 0;

		this->create();
	}

	void create() {

	}

	Rect(int x, int y, int w, int h, SVG *view) :
			Rect(x, y, w, h, 0, 0, view) {
	}

	Rect(const Rect &original) {
		this->copy(original);
	}

	Rect& operator=(const Rect &original) {
		return *this;
	}

	void copy(const Rect &original) {

	}

	void moveTo(int x, int y) {

	}

	void setWidth(int w) {

	}

	void setHeight(int h) {

	}

	inline int getWidth() {
		return 0;
	}

	inline int getHeight() {
		return 0;
	}

};

//===============================================================================

class Ellipse: public SVGElement {

protected:
	int rx;
	int ry;

public:

	Ellipse() :
			SVGElement() {
		rx = 0;
		ry = 0;
	}
	;

	Ellipse(int cx, int cy, int rx, int ry, SVG *view) :
			SVGElement(view) {
		this->x = cx;
		this->y = cy;
		this->rx = rx;
		this->ry = ry;

		this->create();
	}

	void create() {

	}

	Ellipse(const Ellipse &original) {
		this->copy(original);
	}

	Ellipse& operator=(const Ellipse &original) {
		return *this;
	}

	void copy(const Ellipse &original) {

	}

	void moveTo(int x, int y) {

	}

	void setRadii(int rx, int ry) {

	}

	inline int getRadiusX() {
		return 0;
	}

	inline int getRadiusY() {
		return 0;
	}

};

//===============================================================================

class Text: public SVGElement {

protected:
	std::string content;

public:

	Text() :
			SVGElement() {
	}
	;

	Text(std::string text, int x, int y, SVG *view) :
			SVGElement(view) {
		this->x = x;
		this->y = y;
		this->content = text;

		this->create();
	}

	void create() {

	}

	Text(const Text &original) {
		this->copy(original);
	}

	Text& operator=(const Text &original) {
		return *this;
	}

	void copy(const Text &original) {

	}

	void moveTo(int x, int y) {

	}

	void setText(std::string text) {

	}

	inline std::string getText() {
		return "";
	}

};

//===============================================================================

class Path: public SVGElement {

protected:
	std::string d;

public:

	Path() :
			SVGElement() {
	}
	;

	Path(std::string path, SVG *view) :
			SVGElement(view) {
		this->d = path;
		this->create();
	}

	void create() {

	}

	Path(const Path &original) {
		this->copy(original);
	}

	Path& operator=(const Path &original) {
		return *this;
	}

	void copy(const Path &original) {

	}

	void moveTo(int x, int y) {

	}

	void rotateTo(int alpha) {

	}

	void setPath(std::string path) {

	}
};

//===============================================================================

class Group: public SVGElement {

public:

	Group() :
			SVGElement() {
	}
	;

	Group(SVG *view) :
			SVGElement(view) {

	}

	void create() {

	}

	Group(const Group &original) {
		this->copy(original);
	}

	Group& operator=(const Group &original) {
		return *this;
	}

	void copy(const Group &original) {

	}

	void moveTo(int x, int y) {

	}

	void add(SVGElement *element) {

	}

	void remove(SVGElement *element) {

	}

	void clear() {

	}
};

//===============================================================================

class Image: public SVGElement {

protected:
	int w;
	int h;
	std::string path;

public:

	Image() :
			SVGElement() {
		w = 0;
		h = 0;
	}
	;

	Image(const std::string path, int x, int y, int w, int h, SVG *view) :
			SVGElement(view) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
		this->path = path;
		this->create();
	}

	void create() {

	}

	Image(const Image &original) {
		this->copy(original);
	}

	Image& operator=(const Image &original) {
		return *this;
	}

	void copy(const Image &original) {

	}

	void moveTo(int x, int y) {

	}

	void rotateTo(int alpha) {

	}

	void setSize(int w, int h) {

	}
};

#endif
