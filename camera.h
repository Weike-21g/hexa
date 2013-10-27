#ifndef _CAMERA_H
#define _CAMERA_H

#include "3d_ext.h"

struct Camera {
	Vector position, at, up;
	double r, h, hx;
	Camera(double R = 1.0, double H = 10.0) {
		position = Vector(0, H, R);
		h = H;
		r = R;
		hx = r * r / h;
		at = Vector(0, 0, 0);
		up = Vector(0, h + hx, 0) - position;
	}
	void rotate(double angle) { //rotates the camera around the y axis
		double x, z;
		double radAngle = toRad(angle);
		x = position.x * cos(radAngle) - position.z * sin(radAngle);
		z = position.x * sin(radAngle) + position.z * cos(radAngle);
		position = Vector(x, position.y, z);
		up = Vector(0, h + hx, 0) - position;
	}
	void distance(double len) {
		double b = len * position.z / r;
		double a = len * position.x / r;
		r = len;
		hx = r * r / h;
		position = Vector(a, position.y, b);
		up = Vector(0, h + hx, 0) - position;
	}
	void height(double he) {
		position = position * (he/h);
		r = sqrt(position.x*position.x + position.z*position.z);
		h = he;
		hx = r * r / h;
		up = Vector(0, h + hx, 0) - position;
	}
};

#endif
