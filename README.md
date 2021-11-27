# Win32 Console Graphics
(Hacky) 24-bit color native resolution graphics in the console!


## Example usage
```c++
#include <win32congraphics.h>

w32cg::GraphicsObject* go = new w32cg::GraphicsObject(); // You would use 'go' to handle drawing operations. **Please only ever create one GraphicsObject, as multiple together may cause unexpected behavior.**

// **IMPORTANT**: you must call init() before doing anything! (This function will setup the necessary stuff needed and also clear the screen for drawing.)
go->init();

// Draw some stuff:
go->setPenColor(255, 0, 0);
go->line(200, 230, 400, 450); // (sx, sy, ex, ey) -> Coords of start and end point that make the line segment


// When you are done, nothing will show unless you make your render loop:

while(1) { // This can be made more advanced and such, but for demo purposes we'll just have an infinite loop
  go->render(); // Handles necessary rendering for single frame
  // TIP: if you would like to avoid calling render() so much, you can call render only when the console repaints itself (namely, resizing the window, selecting text, etc)
  // You can also choose to hide the blinking cursor if you wish.
}
```
