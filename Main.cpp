#include "Spline.cpp"

int main() {
	
	//quick Vec2 & Vec3 test cases 
	/*
	Vec2 v(1, 2), s(0.3f, 4.4f);
	std::cout << "v + s = " << v + s << '\n';
	std::cout << "v - s = " << v - s << '\n';
	std::cout << "5 * s = " << s * 5.f << '\n';
	std::cout << "LERP(v, s, 0.5f) = " << lerp(v, s, 0.f) << '\n';

	Vec3 k(1, 2, 300), t(0.3f, 4.4f, 3.3f);
	std::cout << "k + t = " << k + t << '\n';
	std::cout << "k - t = " << k - t << '\n';
	std::cout << "5 * k = " << k * 5.f << '\n';
	std::cout << "LERP(k, t, 0.5f) = " << lerp(k, t, 1.f) << '\n';
	*/

	//quick test case for the Spline class
	/*
	float t;
	Vec2 a(1, 1), b(1, 2), c(1.3f, 3.4f), d(3.3f, -1.f);
	Spline<Vec2> CRS(a, b, c, d, 0.9f);

	std::cout<<"Enter the parameter t:\n";
	std::cin>> t;

	Vec2 result = CRS.getPoint(t);
	std::cout << "A point on a spline P(t) = P(" << t << ") = " << result << '\n';
	*/

	return EXIT_SUCCESS;
}