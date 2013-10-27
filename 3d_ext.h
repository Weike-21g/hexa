#ifndef _3D_EXT
#define _3D_EXT

double toRad(double angle) {
	return (3.14159265359 / 180) * angle;
}

class Vector {
public:
	double x, y, z;

	Vector(double x0 = 0, double y0 = 0, double z0 = 0) {
		x = x0; y = y0; z = z0;
	}
	Vector operator*(double a) {
		return Vector(x * a, y * a, z * a); 
	}
	Vector operator/(double a) { 
		return Vector(x / a, y / a, z / a); 
	}
	Vector operator+(const Vector& v) {
	 	return Vector(x + v.x, y + v.y, z + v.z); 
	}
	Vector operator-(const Vector& v) {
	 	return Vector(x - v.x, y - v.y, z - v.z); 
	}
	double operator*(const Vector& v) {
		return (x * v.x + y * v.y + z * v.z); 
	}
	Vector operator%(const Vector& v) {
		return Vector(y*v.z-z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
	}
	double Length() {
		return sqrt(x * x + y * y + z * z);
	}
};

bool sameSide(Vector p1, Vector p2, Vector a, Vector b) { //returns with true if p1 and p2 are on the same side of the line AB
	 Vector cp1 = (b-a) % (p1-a);
	 Vector cp2 = (b-a) % (p2-a);
	 if ((cp1 * cp2) >= 0)
		return true;
	 else
		return false;
}

#endif
