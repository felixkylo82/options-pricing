#include "BlackScholes.h"
#include "Cdf.h"

#include <cassert>
#include <cfloat>


BlackScholes::BlackScholes()
{
}

BlackScholes::~BlackScholes()
{
}

double BlackScholes::callOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);
	assert(_dividendYield == 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return this->callOptionDelta(spotPrice, strickPrice, yearsToExpiry, _riskFreeInterestRate, _volatility, _dividendYield) * spotPrice - Cdf::N(this->d2(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility)) * exp(-riskFreeInterestRate * yearsToExpiry) * strickPrice;
}

double BlackScholes::callOptionDelta(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);
	assert(_dividendYield == 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return Cdf::N(this->d1(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility));
}

double BlackScholes::callOptionVega(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);
	assert(_dividendYield == 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return spotPrice * Cdf::dN(this->d1(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility)) * sqrt(yearsToExpiry);
}

double BlackScholes::callOptionTheta(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);
	assert(_dividendYield == 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return -(this->callOptionVega(spotPrice, strickPrice, yearsToExpiry, _riskFreeInterestRate, _volatility, _dividendYield) * volatility / 2.0 + Cdf::N(this->d2(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility)) * exp(-riskFreeInterestRate * yearsToExpiry) * riskFreeInterestRate);
}

double BlackScholes::callOptionRho(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);
	assert(_dividendYield == 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return Cdf::N(this->d2(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility)) * exp(-riskFreeInterestRate * yearsToExpiry) * yearsToExpiry;
}

double BlackScholes::putOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);
	assert(_dividendYield == 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return this->putOptionDelta(spotPrice, strickPrice, yearsToExpiry, _riskFreeInterestRate, _volatility, _dividendYield) * spotPrice - -Cdf::N(-this->d2(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility)) * exp(-riskFreeInterestRate * yearsToExpiry) * strickPrice;
}

double BlackScholes::putOptionDelta(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);
	assert(_dividendYield == 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return -Cdf::N(-this->d1(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility));
}

double BlackScholes::putOptionVega(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);
	assert(_dividendYield == 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return spotPrice * Cdf::dN(this->d1(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility)) * sqrt(yearsToExpiry);
}

double BlackScholes::putOptionTheta(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);
	assert(_dividendYield == 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return -(this->putOptionVega(spotPrice, strickPrice, yearsToExpiry, _riskFreeInterestRate, _volatility, _dividendYield) * volatility / 2.0 + -Cdf::N(-this->d2(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility)) * exp(-riskFreeInterestRate * yearsToExpiry) * riskFreeInterestRate);
}

double BlackScholes::putOptionRho(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);
	assert(_dividendYield == 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return -Cdf::N(-this->d2(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility)) * exp(-riskFreeInterestRate * yearsToExpiry) * yearsToExpiry;
}

double BlackScholes::d1(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility) const {
	return (1.0 / volatility * sqrt(yearsToExpiry)) * (log(spotPrice / strickPrice) + (riskFreeInterestRate + volatility * volatility / 2.0) * yearsToExpiry);
}

double BlackScholes::d2(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility) const {
	return (1.0 / volatility * sqrt(yearsToExpiry)) * (log(spotPrice / strickPrice) + (riskFreeInterestRate - volatility * volatility / 2.0) * yearsToExpiry);
}
