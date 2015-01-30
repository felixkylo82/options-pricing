#pragma once


#include "OptionsPricingModel.h"

class MonteCarlo : public OptionsPricingModel
{
private:
	struct Configuration {
		double S;
	};

public:
	MonteCarlo();
	virtual ~MonteCarlo();

public:
	virtual double callOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;
	virtual double putOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;
};
