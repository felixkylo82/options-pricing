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

double BlackScholes::callOptionValue(double spotPrice, double strickPrice, double years, double _riskFreeInterestRate, double _volatility) const {
	if (spotPrice < 0.0) assert(false);
	if (strickPrice < 0.0) assert(false);
	if (years < FLT_EPSILON) years = FLT_EPSILON;
	if (_volatility < 0.0) assert(false);

	return this->callOptionDelta(spotPrice, strickPrice, years, _riskFreeInterestRate, _volatility) * spotPrice - this->callOptionRho(spotPrice, strickPrice, years, _riskFreeInterestRate, _volatility) / years * strickPrice;
}

double BlackScholes::callOptionDelta(double spotPrice, double strickPrice, double years, double _riskFreeInterestRate, double _volatility) const {
	if (spotPrice < 0.0) assert(false);
	if (strickPrice < 0.0) assert(false);
	if (years < FLT_EPSILON) years = FLT_EPSILON;
	if (_volatility < 0.0) assert(false);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return Cdf::N(this->d1(spotPrice, strickPrice, years, riskFreeInterestRate, volatility));
}

double BlackScholes::callOptionVega(double spotPrice, double strickPrice, double years, double _riskFreeInterestRate, double _volatility) const {
	if (spotPrice < 0.0) assert(false);
	if (strickPrice < 0.0) assert(false);
	if (years < FLT_EPSILON) years = FLT_EPSILON;
	if (_volatility < 0.0) assert(false);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return spotPrice * Cdf::dN(this->d1(spotPrice, strickPrice, years, riskFreeInterestRate, volatility)) * sqrt(years);
}

double BlackScholes::callOptionTheta(double spotPrice, double strickPrice, double years, double _riskFreeInterestRate, double _volatility) const {
	if (spotPrice < 0.0) assert(false);
	if (strickPrice < 0.0) assert(false);
	if (years < FLT_EPSILON) years = FLT_EPSILON;
	if (_volatility < 0.0) assert(false);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return -(this->callOptionVega(spotPrice, strickPrice, years, _riskFreeInterestRate, _volatility) * volatility / 2.0 + this->callOptionRho(spotPrice, strickPrice, years, _riskFreeInterestRate, _volatility) * riskFreeInterestRate) / years;
}

double BlackScholes::callOptionRho(double spotPrice, double strickPrice, double years, double _riskFreeInterestRate, double _volatility) const {
	if (spotPrice < 0.0) assert(false);
	if (strickPrice < 0.0) assert(false);
	if (years < FLT_EPSILON) years = FLT_EPSILON;
	if (_volatility < 0.0) assert(false);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return Cdf::N(this->d2(spotPrice, strickPrice, years, riskFreeInterestRate, volatility)) * exp(-riskFreeInterestRate * years) * years;
}

double BlackScholes::putOptionValue(double spotPrice, double strickPrice, double years, double _riskFreeInterestRate, double _volatility) const {
	if (spotPrice < 0.0) assert(false);
	if (strickPrice < 0.0) assert(false);
	if (years < FLT_EPSILON) years = FLT_EPSILON;
	if (_volatility < 0.0) assert(false);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return this->putOptionDelta(spotPrice, strickPrice, years, _riskFreeInterestRate, _volatility) * spotPrice - this->putOptionRho(spotPrice, strickPrice, years, _riskFreeInterestRate, _volatility) / years * strickPrice;
}

double BlackScholes::putOptionDelta(double spotPrice, double strickPrice, double years, double _riskFreeInterestRate, double _volatility) const {
	if (spotPrice < 0.0) assert(false);
	if (strickPrice < 0.0) assert(false);
	if (years < FLT_EPSILON) years = FLT_EPSILON;
	if (_volatility < 0.0) assert(false);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return -Cdf::N(-this->d1(spotPrice, strickPrice, years, riskFreeInterestRate, volatility));
}

double BlackScholes::putOptionVega(double spotPrice, double strickPrice, double years, double _riskFreeInterestRate, double _volatility) const {
	if (spotPrice < 0.0) assert(false);
	if (strickPrice < 0.0) assert(false);
	if (years < FLT_EPSILON) years = FLT_EPSILON;
	if (_volatility < 0.0) assert(false);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return spotPrice * Cdf::dN(this->d1(spotPrice, strickPrice, years, riskFreeInterestRate, volatility)) * sqrt(years);
}

double BlackScholes::putOptionTheta(double spotPrice, double strickPrice, double years, double _riskFreeInterestRate, double _volatility) const {
	if (spotPrice < 0.0) assert(false);
	if (strickPrice < 0.0) assert(false);
	if (years < FLT_EPSILON) years = FLT_EPSILON;
	if (_volatility < 0.0) assert(false);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return -(this->putOptionVega(spotPrice, strickPrice, years, _riskFreeInterestRate, _volatility) * volatility / 2.0 + this->putOptionRho(spotPrice, strickPrice, years, _riskFreeInterestRate, _volatility) * riskFreeInterestRate) / years;
}

double BlackScholes::putOptionRho(double spotPrice, double strickPrice, double years, double _riskFreeInterestRate, double _volatility) const {
	if (spotPrice < 0.0) assert(false);
	if (strickPrice < 0.0) assert(false);
	if (years < FLT_EPSILON) years = FLT_EPSILON;
	if (_volatility < 0.0) assert(false);

	double riskFreeInterestRate = _riskFreeInterestRate / 100.0;
	double volatility = _volatility / 100.0;

	return -Cdf::N(-this->d2(spotPrice, strickPrice, years, riskFreeInterestRate, volatility)) * exp(-riskFreeInterestRate * years) * years;
}

double BlackScholes::d1(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const {
	return (1.0 / volatility * sqrt(years)) * (log(spotPrice / strickPrice) + (riskFreeInterestRate + volatility * volatility / 2.0) * years);
}

double BlackScholes::d2(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const {
	return (1.0 / volatility * sqrt(years)) * (log(spotPrice / strickPrice) + (riskFreeInterestRate - volatility * volatility / 2.0) * years);
}
