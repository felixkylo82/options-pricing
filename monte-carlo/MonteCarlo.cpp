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

double MonteCarlo::callOptionValue(double _spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(_spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;
	double dividendYield = _dividendYield / 100.0;

	const int m = 100000;
	const int n = 100;

	double deltaT = yearsToExpiry / (n - 1);
	double sqrtDeltaT = sqrt(deltaT);
	double spotPrice = _spotPrice * exp((riskFreeInterestRate - dividendYield) * yearsToExpiry);

	Configuration configuration[n];
	double ret = 0.0;
	for (int i = 0; i < m; ++i) {
		configuration[0].S = spotPrice;
		for (int j = 1; j < n; ++j) {
			double X1 = (double)(rand() % 2 * 2 - 1);
			configuration[j].S = configuration[j - 1].S * exp(volatility * X1 * sqrtDeltaT);
		}

		double V = configuration[n - 1].S - strickPrice;
		if (V < 0.0) V = 0.0;

		ret += V;
	}
	ret /= (double)m;
	ret *= exp(-riskFreeInterestRate * yearsToExpiry);

	return ret;
}

double MonteCarlo::putOptionValue(double _spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(_spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;
	double dividendYield = _dividendYield / 100.0;

	const int m = 100000;
	const int n = 100;

	double deltaT = yearsToExpiry / (n - 1);
	double sqrtDeltaT = sqrt(deltaT);
	double spotPrice = _spotPrice * exp((riskFreeInterestRate - dividendYield) * yearsToExpiry);

	Configuration configuration[n];
	double ret = 0.0;
	for (int i = 0; i < m; ++i) {
		configuration[0].S = spotPrice;
		for (int j = 1; j < n; ++j) {
			double X1 = (double)(rand() % 2 * 2 - 1);
			configuration[j].S = configuration[j - 1].S * exp(volatility * X1 * sqrtDeltaT);
		}

		double V = strickPrice - configuration[n - 1].S;
		if (V < 0.0) V = 0.0;

		ret += V;
	}
	ret /= (double)m;
	ret *= exp(-riskFreeInterestRate * yearsToExpiry);

	return ret;
}
