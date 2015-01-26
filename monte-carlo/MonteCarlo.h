#pragma once


#include "OptionsPricingModel.h"

class MonteCarlo : public OptionsPricingModel
{
private:
	struct Configuration {
		double S;
		double V;
		double PI;
	};

public:
	MonteCarlo();
	virtual ~MonteCarlo();

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
};
