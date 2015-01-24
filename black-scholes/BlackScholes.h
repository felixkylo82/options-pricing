#pragma once


#include "OptionsPricingModel.h"

class BlackScholes : public OptionsPricingModel
{
public:
	BlackScholes();
	virtual ~BlackScholes();

public:
	virtual double callOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility) const;
	virtual double callOptionDelta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility) const;
	virtual double callOptionVega(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility) const;
	virtual double callOptionTheta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility) const;
	virtual double callOptionRho(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility) const;

	virtual double putOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility) const;
	virtual double putOptionDelta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility) const;
	virtual double putOptionVega(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility) const;
	virtual double putOptionTheta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility) const;
	virtual double putOptionRho(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility) const;

private:
	inline double d1(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility) const;
	inline double d2(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility) const;
};
