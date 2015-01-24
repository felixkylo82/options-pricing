#include "OptionsPricingModel.h"

#include <limits>
#include <cstdlib>


OptionsPricingModel::OptionsPricingModel() {
}

OptionsPricingModel::~OptionsPricingModel() {
}

Function::Function(OptionsPricingModel& model) : model(model) {

}

Function::~Function() {

}

double Function::impliedInterestRate(double _optionValue, double spotPrice, double strickPrice, double yearsToExpiry, double volatility, double dividendYield) const {
	double impliedInterestRate = 0.0;

	while (true) {
		double optionValue = this->value(spotPrice, strickPrice, yearsToExpiry, impliedInterestRate, volatility, dividendYield);
		double derivative = this->rho(spotPrice, strickPrice, yearsToExpiry, impliedInterestRate, volatility, dividendYield);

		double newImpliedInterestRate = 0.0;
		if (abs(derivative) < FLT_EPSILON) {
			double diff = optionValue - _optionValue;
			if (abs(diff) < 0.5) {
				double offset = (double)rand() / (double)RAND_MAX;
				newImpliedInterestRate = (diff < 0 ? impliedInterestRate + offset : impliedInterestRate - offset);
			}
			else {
				double ratio = 1.0 + (double)rand() / (double)RAND_MAX;
				newImpliedInterestRate = (diff < 0 ? impliedInterestRate * ratio : impliedInterestRate / ratio);
			}
		}
		else {
			newImpliedInterestRate = impliedInterestRate - (optionValue - _optionValue) / derivative;
		}
		if (newImpliedInterestRate < -100.0) newImpliedInterestRate = -100.0;
		if (newImpliedInterestRate > 100.0) newImpliedInterestRate = 100.0;

		if (abs(newImpliedInterestRate - impliedInterestRate) < FLT_EPSILON) {
			return newImpliedInterestRate;
		}
		impliedInterestRate = newImpliedInterestRate;
	}
}

double Function::impliedVolatility(double _optionValue, double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double dividendYield) const {
	double impliedVolatility = 20.0;

	while (true) {
		double optionValue = this->value(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, impliedVolatility, dividendYield);
		double derivative = this->vega(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, impliedVolatility, dividendYield);

		double newImpliedVolatility = 0.0;
		if (abs(derivative) < FLT_EPSILON) {
			double ratio = 1.0 + (double)rand() / (double)RAND_MAX;
			newImpliedVolatility = (optionValue < _optionValue ? impliedVolatility * ratio : impliedVolatility / ratio);
		}
		else {
			newImpliedVolatility = impliedVolatility - (optionValue - _optionValue) / derivative;
		}
		if (newImpliedVolatility < FLT_EPSILON) newImpliedVolatility = FLT_EPSILON;
		if (newImpliedVolatility > 100.0) newImpliedVolatility = 100.0;

		if (abs(newImpliedVolatility - impliedVolatility) < FLT_EPSILON) {
			return newImpliedVolatility;
		}
		impliedVolatility = newImpliedVolatility;
	}
}

CallOptionValue::CallOptionValue(OptionsPricingModel& model) : Function(model) {

}

CallOptionValue::~CallOptionValue() {

}

double CallOptionValue::value(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const {
	return this->model.callOptionValue(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield);
}

double CallOptionValue::delta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const {
	return this->model.callOptionDelta(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield);
}

double CallOptionValue::vega(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const {
	return this->model.callOptionVega(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield);
}

double CallOptionValue::theta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const {
	return this->model.callOptionTheta(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield);
}

double CallOptionValue::rho(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const {
	return this->model.callOptionRho(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield);
}

PutOptionValue::PutOptionValue(OptionsPricingModel& model) : Function(model) {

}

PutOptionValue::~PutOptionValue() {

}

double PutOptionValue::value(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const {
	return this->model.putOptionValue(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield);
}

double PutOptionValue::delta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const {
	return this->model.putOptionDelta(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield);
}

double PutOptionValue::vega(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const {
	return this->model.putOptionVega(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield);
}

double PutOptionValue::theta(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const {
	return this->model.putOptionTheta(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield);
}

double PutOptionValue::rho(double spotPrice, double strickPrice, double yearsToExpiry, double riskFreeInterestRate, double volatility, double dividendYield) const {
	return this->model.putOptionRho(spotPrice, strickPrice, yearsToExpiry, riskFreeInterestRate, volatility, dividendYield);
}
