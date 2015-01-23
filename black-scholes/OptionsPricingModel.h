#pragma once


class OptionsPricingModel
{
public:
	OptionsPricingModel();
	virtual ~OptionsPricingModel();

	virtual double callOptionValue(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;
	virtual double callOptionDelta(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;
	virtual double callOptionVega(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;
	virtual double callOptionTheta(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;
	virtual double callOptionRho(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;

	virtual double putOptionValue(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;
	virtual double putOptionDelta(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;
	virtual double putOptionVega(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;
	virtual double putOptionTheta(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;
	virtual double putOptionRho(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;
};

class Function {
protected:
	const OptionsPricingModel& model;

public:
	Function(OptionsPricingModel& model);
	virtual ~Function();

	inline virtual double value(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;
	inline virtual double delta(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;
	inline virtual double vega(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;
	inline virtual double theta(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;
	inline virtual double rho(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const = 0;

	double impliedInterestRate(double optionValue, double spotPrice, double strickPrice, double years, double volatility) const;
	double impliedVolatility(double optionValue, double spotPrice, double strickPrice, double years, double riskFreeInterestRate) const;
};

class CallOptionValue : public Function {
public:
	CallOptionValue(OptionsPricingModel& model);
	virtual ~CallOptionValue();

	inline virtual double value(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const;
	inline virtual double delta(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const;
	inline virtual double vega(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const;
	inline virtual double theta(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const;
	inline virtual double rho(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const;
};

class PutOptionValue : public Function {
public:
	PutOptionValue(OptionsPricingModel& model);
	virtual ~PutOptionValue();

	inline virtual double value(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const;
	inline virtual double delta(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const;
	inline virtual double vega(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const;
	inline virtual double theta(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const;
	inline virtual double rho(double spotPrice, double strickPrice, double years, double riskFreeInterestRate, double volatility) const;
};
