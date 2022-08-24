#ifndef VEC3_H
#define VEC3_H

#include "Vec2.h"

//Inherits from the Vec2 class, all is similar 
class Vec3 : public Vec2{
public:
	float z_;

	Vec3() : Vec2(), z_(0) {}

	Vec3(float x, float y, float z) :
		Vec2(x, y), z_(z) {}

	Vec3(const Vec3& v) {
		x_ = v.x_;
		y_ = v.y_;
		z_ = v.z_;
	}

	~Vec3() {}

	Vec3 operator+(const Vec3& v) const {
		return Vec3(x_ + v.x_, y_ + v.y_, z_ + v.z_);
	}


	Vec3 operator-(const Vec3& v) const {
		return Vec3(x_ - v.x_, y_ - v.y_, z_ - v.z_);
	}

	Vec3 operator*(float s) const {
		return Vec3(x_ * s, y_ * s, z_ * s);
	}

	float length() {
		return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
	}

	float lengthSquared() {
		return x_ * x_ + y_ * y_ + z_ * z_;
	}

	friend std::ostream& operator<<(std::ostream& out, const Vec3& v) {
		out << '(' << v.x_ << ',' << v.y_ << ',' << v.z_ << ')';
		return out;
	}

	friend Vec3 lerp(const Vec3& a, const Vec3& b, float t) {
		return a * t + b * (1.f - t);
	}
};

#endif