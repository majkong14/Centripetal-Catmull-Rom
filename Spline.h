#ifndef SPLINE_H
#define SPLINE_H

#include <cmath>

template<typename T>
class Spline {
	T p0_, p1_, p2_, p3_;
	float alpha_;				//Curve parameter (ranges from 0 to 1)

public:
	Spline(T p0, T p1, T p2, T p3, float a) : 
		alpha_(a), p0_(p0), p1_(p1), p2_(p2), p3_(p3) {}

	//Copy-constructor (might choose move-semantics instead of copy-semantics)
	Spline(const Spline<T>& spl) {
		p0_ = spl.p0_;
		p1_ = spl.p1_;
		p2_ = spl.p2_;
		p3_ = spl.p3_;
		alpha_ = spl.alpha_;
	}

	//Destructor (stays default)
	~Spline() {};

	//Evaluates a point at the given t-value (here - alpha) from 0 to 1
	T getPoint(float t) {
		//Calculate knots
		const float k0 = 0;
		float k1 = getKnotInterval(p0_, p1_);
		float k2 = getKnotInterval(p1_, p2_) + k1;
		float k3 = getKnotInterval(p2_, p3_) + k2;

		//evaluate the point
		float u = std::lerp(k1, k2, t);
		T A1 = Remap(k0, k1, p0_, p1_, u);
		T A2 = Remap(k1, k2, p1_, p2_, u);
		T A3 = Remap(k2, k3, p2_, p3_, u);
		T B1 = Remap(k0, k2, A1, A2, u);
		T B2 = Remap(k1, k3, A2, A3, u);
		return Remap(k1, k2, B1, B2, u);
	}

	//Returns the vector of the next stage of the pyramidal formulation 
	//of the spline construction algorithm (refer to Wiki)
	static T Remap(float a, float b, const T& c, const T& d, float u) {
		return lerp(c, d, (u - a) / (b - a));
	}

	//Returns the sqared length of the A-B vector in the degree of 0.5 * alpha_
	float getKnotInterval(const T& a, const T& b) {
		//T temp = a - b;
		return std::powf((a - b).lengthSquared(), 0.5f * alpha_);
	}
};

#endif