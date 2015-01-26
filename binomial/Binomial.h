#pragma once


#include "OptionsPricingModel.h"

class Binomial : public OptionsPricingModel
{
public:
	Binomial();
	virtual ~Binomial();

public:
	virtual double callOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;
	virtual double putOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;
};
