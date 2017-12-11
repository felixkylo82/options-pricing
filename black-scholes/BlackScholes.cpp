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

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;
	double dividendYield = _dividendYield / 100.0;

	return Cdf::N(this->d1(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield)) * exp(-dividendYield * yearsToExpiry) * spotPrice - Cdf::N(this->d2(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield)) * exp(-riskFreeInterestRate * yearsToExpiry) * strickPrice;
}

double BlackScholes::callOptionDelta(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	if (0.0 == _dividendYield)
		this->OptionsPricingModel::callOptionDelta(spotPrice, strickPrice, yearsToExpiry, _riskFreeInterestRate, _volatility, _dividendYield);

	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;
	double dividendYield = _dividendYield / 100.0;

	return Cdf::N(this->d1(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield));
}

double BlackScholes::callOptionVega(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	if (0.0 == _dividendYield)
		this->OptionsPricingModel::callOptionVega(spotPrice, strickPrice, yearsToExpiry, _riskFreeInterestRate, _volatility, _dividendYield);

	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;
	double dividendYield = _dividendYield / 100.0;

	return spotPrice * Cdf::dN(this->d1(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield)) * sqrt(yearsToExpiry);
}

double BlackScholes::callOptionTheta(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	if (0.0 == _dividendYield)
		this->OptionsPricingModel::callOptionTheta(spotPrice, strickPrice, yearsToExpiry, _riskFreeInterestRate, _volatility, _dividendYield);

	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;
	double dividendYield = _dividendYield / 100.0;

	return -(this->callOptionVega(spotPrice, strickPrice, yearsToExpiry, _riskFreeInterestRate, _volatility, _dividendYield) * volatility / 2.0 + Cdf::N(this->d2(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield)) * exp(-riskFreeInterestRate * yearsToExpiry) * riskFreeInterestRate);
}

double BlackScholes::callOptionRho(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	if (0.0 == _dividendYield)
		this->OptionsPricingModel::callOptionRho(spotPrice, strickPrice, yearsToExpiry, _riskFreeInterestRate, _volatility, _dividendYield);

	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;
	double dividendYield = _dividendYield / 100.0;

	return Cdf::N(this->d2(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield)) * exp(-riskFreeInterestRate * yearsToExpiry) * yearsToExpiry;
}

double BlackScholes::putOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;
	double dividendYield = _dividendYield / 100.0;

	return -Cdf::N(-this->d1(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield)) * exp(-dividendYield * yearsToExpiry) * spotPrice - -Cdf::N(-this->d2(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield)) * exp(-riskFreeInterestRate * yearsToExpiry) * strickPrice;
}

double BlackScholes::putOptionDelta(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	if (0.0 == _dividendYield)
		this->OptionsPricingModel::putOptionDelta(spotPrice, strickPrice, yearsToExpiry, _riskFreeInterestRate, _volatility, _dividendYield);

	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;
	double dividendYield = _dividendYield / 100.0;

	return -Cdf::N(-this->d1(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield));
}

double BlackScholes::putOptionVega(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	if (0.0 == _dividendYield)
		this->OptionsPricingModel::putOptionVega(spotPrice, strickPrice, yearsToExpiry, _riskFreeInterestRate, _volatility, _dividendYield);

	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;
	double dividendYield = _dividendYield / 100.0;

	return spotPrice * Cdf::dN(this->d1(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield)) * sqrt(yearsToExpiry);
}

double BlackScholes::putOptionTheta(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	if (0.0 == _dividendYield)
		this->OptionsPricingModel::putOptionTheta(spotPrice, strickPrice, yearsToExpiry, _riskFreeInterestRate, _volatility, _dividendYield);

	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;
	double dividendYield = _dividendYield / 100.0;

	return -(this->putOptionVega(spotPrice, strickPrice, yearsToExpiry, _riskFreeInterestRate, _volatility, _dividendYield) * volatility / 2.0 + -Cdf::N(-this->d2(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield)) * exp(-riskFreeInterestRate * yearsToExpiry) * riskFreeInterestRate);
}

double BlackScholes::putOptionRho(double spotPrice, double strickPrice, double yearsToExpiry, double _riskFreeInterestRate, double _volatility, double _dividendYield) const {
	if (0.0 == _dividendYield)
		this->OptionsPricingModel::putOptionRho(spotPrice, strickPrice, yearsToExpiry, _riskFreeInterestRate, _volatility, _dividendYield);

	assert(spotPrice >= 0.0);
	assert(strickPrice >= 0.0);
	if (yearsToExpiry < 0.0) yearsToExpiry = 0.0;
	assert(_volatility >= 0.0);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;
	double dividendYield = _dividendYield / 100.0;

	return -Cdf::N(-this->d2(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield)) * exp(-riskFreeInterestRate * yearsToExpiry) * yearsToExpiry;
}

double BlackScholes::d1(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const {
	return (1.0 / (volatility * sqrt(yearsToExpiry))) * (log(spotPrice / strickPrice) + (riskFreeInterestRate - dividendYield + volatility * volatility / 2.0) * yearsToExpiry);
}

double BlackScholes::d2(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const {
	return (1.0 / (volatility * sqrt(yearsToExpiry))) * (log(spotPrice / strickPrice) + (riskFreeInterestRate - dividendYield - volatility * volatility / 2.0) * yearsToExpiry);
}
