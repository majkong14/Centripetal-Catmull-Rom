#ifndef VEC2_H
#define VEC2_H

class Vec2
{
public:
	float x_, y_;

	//Default constructor
	Vec2() : x_(0), y_(0) {}

	Vec2(float x, float y) :
		x_(x), y_(y) {}

	//Copy-constructor, can delete and add move-constructor in the future
	Vec2(const Vec2& v) {
		x_ = v.x_;
		y_ = v.y_;
	}

	~Vec2() {}

	//Minimal set of vector operations (we don't need dot, cross, etc. here)
	Vec2 operator+(const Vec2& v) const {
		return Vec2(x_ + v.x_, y_ + v.y_);
	}

	Vec2 operator-(const Vec2& v) const {
		return Vec2(x_ - v.x_, y_ - v.y_);
	}

	Vec2 operator*(float s) const {
		return Vec2(x_ * s, y_ * s);
	}

	friend std::ostream& operator<<(std::ostream& out, const Vec2& v) {
		out << '(' << v.x_ << ',' << v.y_ << ')';
		return out;
	}
};

#endif