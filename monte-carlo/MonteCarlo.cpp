#include "MonteCarlo.h"
#include "Cdf.h"

#include <cassert>
#include <cfloat>


MonteCarlo::MonteCarlo()
{
}

MonteCarlo::~MonteCarlo()
{
}

double MonteCarlo::callOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0 / 2.0;
	double dividendYield = _dividendYield / 100.0;

	int n = 1000;
	double deltaT = yearsToExpiry / (n - 1);
	double sqrtDeltaT = sqrt(deltaT);

	Configuration** configurations = new Configuration*[n];
	for (int i = 0; i < n; ++i) {
		configurations[i] = new Configuration[n];
	}

	double ret = 0.0;
	for (int i = 0; i < n; ++i) {
		Configuration* configuration = configurations[i];
		configuration[0].S = spotPrice;

		for (int j = 1; j < n; ++j) {
			double X1, X2;
			Cdf::X(X1, X2);
			configuration[j].S = configuration[j - 1].S * exp(dividendYield * deltaT + volatility * X1 * sqrtDeltaT);
		}

		configuration[n - 1].V = configuration[n - 1].S - strickPrice;
		if (configuration[n - 1].V < 0.0) configuration[n - 1].V = 0.0;
		configuration[n - 1].PI = -configuration[n - 1].V;

		for (int j = n - 2; j >= 0; --j) {
			configuration[j].PI = configuration[j + 1].PI / exp(riskFreeInterestRate * deltaT);
			
			double deltaS = configuration[j + 1].S - configuration[j].S;
			double deltaPI = configuration[j + 1].PI - configuration[j].PI;

			configuration[j].V = (
				(deltaPI * configuration[j].S - configuration[j].PI * deltaS + configuration[j + 1].V) + 
				(configuration[j + 1].V * (configuration[j].S - 1.0))
				) / configuration[j + 1].S;
		}

		ret += configuration[0].V;
	}
	ret /= (double)n;

	for (int i = 0; i < n; ++i) {
		delete[] configurations[i];
	}
	delete[] configurations;

	return ret;
}

double MonteCarlo::putOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0 / 2.0;
	double dividendYield = _dividendYield / 100.0;

	int n = 1000;
	double deltaT = yearsToExpiry / (n - 1);
	double sqrtDeltaT = sqrt(deltaT);

	Configuration** configurations = new Configuration*[n];
	for (int i = 0; i < n; ++i) {
		configurations[i] = new Configuration[n];
	}

	double ret = 0.0;
	for (int i = 0; i < n; ++i) {
		Configuration* configuration = configurations[i];
		configuration[0].S = spotPrice;

		for (int j = 1; j < n; ++j) {
			double X1, X2;
			Cdf::X(X1, X2);
			configuration[j].S = configuration[j - 1].S * exp(dividendYield * deltaT + volatility * X1 * sqrtDeltaT);
		}

		configuration[n - 1].V = strickPrice - configuration[n - 1].S;
		if (configuration[n - 1].V < 0.0) configuration[n - 1].V = 0.0;
		configuration[n - 1].PI = -configuration[n - 1].V;

		for (int j = n - 2; j >= 0; --j) {
			configuration[j].PI = configuration[j + 1].PI / exp(riskFreeInterestRate * deltaT);

			double deltaS = configuration[j + 1].S - configuration[j].S;
			double deltaPI = configuration[j + 1].PI - configuration[j].PI;

			configuration[j].V = (
				(deltaPI * configuration[j].S - configuration[j].PI * deltaS + configuration[j + 1].V) +
				(configuration[j + 1].V * (configuration[j].S - 1.0))
				) / configuration[j + 1].S;
		}

		ret += configuration[0].V;
	}
	ret /= (double)n;

	for (int i = 0; i < n; ++i) {
		delete[] configurations[i];
	}
	delete[] configurations;

	return ret;
}
