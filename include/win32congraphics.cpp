#include <Windows.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;



namespace w32cg {
	void GraphicsObject::init() {
		// Do some setup:
		// Get HWND
		c_HWND = GetConsoleWindow();
		// Get HDC
		c_HDC = GetDC(c_HWND);
		color = RGB(255, 255, 255);
		system("cls");
	}

	void GraphicsObject::setPixel(int x, int y) {
		Pixel p = { x, y, color };
		pbuf.push_back(p);
	}

	void GraphicsObject::line(int sx, int sy, int ex, int ey) {
		// Xiaolin Wu's is too complex (antialiasing and all that). Considering the efficiency of SetPixel() rendering, let's resort to Bresenham's.
		// Edge case check:
		if (sx == ex) {
			// Vertical line
			int smallerY = (sy < ey) ? sy : ey;
			for (int i = sy; i <= ey; i++) {
				setPixel(sx, i);
			}
			return;
		}
		for (int x = sx; x <= ex; x++) {
			int y = round(double(ey - sy) / double(ex - sx) * double(x - sx) + (double)sy);
			setPixel(x, y);
		}
	}

	void GraphicsObject::plotFunc(int sx, int sy, int limit, int (*func)(int)) {
		for (int x = sx; x < sx + limit; x++) {
			int y = func(x - sx);
			setPixel(x, sy - y);
		}
	}

	COLORREF GraphicsObject::getPenColor() {
		return color;
	}

	void GraphicsObject::setPenColor(int r, int g, int b) {
		color = RGB(r, g, b);
	}

	void GraphicsObject::clearScreen() {
		// Clear the pbuf
		pbuf.clear();
		// Ask the system to repaint the window
		system("cls");
	}

	void GraphicsObject::render() {
		for (int i = 0; i < pbuf.size(); i++) {
			SetPixel(c_HDC, pbuf[i].x, pbuf[i].y, pbuf[i].color);
			//Sleep(1); // Animation!
		}
	}
}

