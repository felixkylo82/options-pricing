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
	double spotPrice = _spotPrice * exp((riskFreeInterestRate - dividendYield) * yearsToExpiry);

	const int m = 100000;

	//double deltaT = yearsToExpiry / (n - 1);
	//double sqrtDeltaT = sqrt(deltaT);

	Configuration configuration;
	double ret = 0.0;
	for (int i = 0; i < m; ++i) {
		double X1, X2;
		Cdf::X(X1, X2);
		configuration.S = spotPrice * exp(volatility * X1 * yearsToExpiry);

		configuration.V = configuration.S - strickPrice;
		if (configuration.V < 0.0) configuration.V = 0.0;
		ret += configuration.V;
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
	double spotPrice = _spotPrice * exp((riskFreeInterestRate - dividendYield) * yearsToExpiry);

	const int m = 100000;

	//double deltaT = yearsToExpiry / (n - 1);
	//double sqrtDeltaT = sqrt(deltaT);

	Configuration configuration;
	double ret = 0.0;
	for (int i = 0; i < m; ++i) {
		double X1, X2;
		Cdf::X(X1, X2);
		configuration.S = spotPrice * exp(volatility * X1 * yearsToExpiry);

		configuration.V = strickPrice - configuration.S;
		if (configuration.V < 0.0) configuration.V = 0.0;
		ret += configuration.V;
	}
	ret /= (double)m;
	ret *= exp(-riskFreeInterestRate * yearsToExpiry);

	return ret;
}
