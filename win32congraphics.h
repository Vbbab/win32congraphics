#pragma once
#include <Windows.h>
#include <vector>
#include <utility>
using namespace std;
namespace w32cg {
	struct Pixel {
		int x;
		int y;
		COLORREF color;
	};

	class GraphicsObject {
	private:
		HWND c_HWND;
		HDC c_HDC;
		COLORREF color;
		vector<Pixel> pbuf; // render buffer used for final render
	public:
		void init();
		void setPixel(int x, int y);
		void line(int sx, int sy, int ex, int ey);
		void plotFunc(int sx, int sy, int limit, int (*func)(int));
		COLORREF getPenColor();
		void setPenColor(int r, int g, int b);
		void clearScreen();
		
		void render();
	};
}