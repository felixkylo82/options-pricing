#pragma once


#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdlib>
#include <cfloat>


class Cdf
{
public:

	static double N(double _X) {
		static const double INF = _HUGE_ENUF * _HUGE_ENUF * _HUGE_ENUF * _HUGE_ENUF;
		static const double NINF = -_HUGE_ENUF * _HUGE_ENUF * _HUGE_ENUF * _HUGE_ENUF;
		static const double C = 2.0 - sqrt(2.0);

		if (NINF == _X) return 0.0;
		if (INF == _X) return 1.0;
		if (0.0 == _X) return 0.5;

		double X = abs(_X);
		double Y = X * X;
		double N = 0.5 * sqrt(1.0 - 1.0 / 30.0 * (
			7.0 * exp(-Y / 2.0) + 16.0 * exp(-Y * C) + (7.0 + M_PI_4 * Y) * exp(-Y)
			));
		if (_X > 0) return 0.5 + N;
		return 0.5 - N;
	}

	static double dN(double X) {
		static const double INF = _HUGE_ENUF * _HUGE_ENUF * _HUGE_ENUF * _HUGE_ENUF;
		static const double NINF = -_HUGE_ENUF * _HUGE_ENUF * _HUGE_ENUF * _HUGE_ENUF;
		static const double C = 1.0 / sqrt(2.0 * M_PI);

		if (NINF == X) return 0.0;
		if (INF == X) return 0.0;

		return C * exp(-X * X / 2.0);
	}

	static void X(double& X1, double&X2)
	{
#define TWO_PI 2.0 * M_PI

		double rand1 = 0.0;
		while (rand1 == 0.0)
			rand1 = (double)rand() / (double)RAND_MAX;
		rand1 = sqrt(-2.0 * log(rand1));
		double rand2 = (double)rand() / (double)RAND_MAX * TWO_PI;

		X1 = rand1 * cos(rand2);
		X2 = rand1 * sin(rand2);
	}

	static double pow(double X, int n) {
		int m = (n < 0 ? -n : n);
		double Y = X;

		double Z = 1.0;
		while (m != 0) {
			if (m & 0x1)
			{
				Z *= Y;
			}
			Y = Y * Y;
			m >>= 1;
		}

		return (n < 0 ? 1.0 / Z : Z);
	}
};

