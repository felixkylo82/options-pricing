#pragma once


#include "OptionsPricingModel.h"

class BlackScholes : public OptionsPricingModel
{
public:
	BlackScholes();
	virtual ~BlackScholes();

public:
	virtual double callOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;
	virtual double callOptionDelta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;
	virtual double callOptionVega(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;
	virtual double callOptionTheta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;
	virtual double callOptionRho(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;

	virtual double putOptionValue(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;
	virtual double putOptionDelta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;
	virtual double putOptionVega(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;
	virtual double putOptionTheta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;
	virtual double putOptionRho(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;

private:
	inline double d1(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;
	inline double d2(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const;
};
