#ifndef _COLOR_H
#define _COLOR_H

class Color {
public:
   double r, g, b;

   Color( ) { 
	r = g = b = 0;
   }
   Color(double r0, double g0, double b0) { 
	r = r0; g = g0; b = b0;
   }
   Color operator*(double a) { 
	return Color(r * a, g * a, b * a); 
   }
   Color operator*(const Color& c) { 
	return Color(r * c.r, g * c.g, b * c.b); 
   }
   Color operator+(const Color& c) {
 	return Color(r + c.r, g + c.g, b + c.b); 
   }
   Color operator/(const float x) {
 	return Color(r / x, g / x, b / x); 
   }
};

Color c_red(1, 0, 0);
Color c_green(0, 1, 0);
Color c_blue(0, 0, 1);
Color c_yellow(1, 1, 0);
Color c_magenta(1, 0, 1);
Color c_cyan(0, 1, 1);
Color c_white(1, 1, 1);
Color c_black(0, 0, 0);

#endif
