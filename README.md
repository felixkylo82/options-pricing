# options-pricing

Calculate option price, implied volatility with Black Scholes' model and Newton's method.

Delta Hedging
=====

Let t be the time and X be some random variable.
And S(t, X, ...) be the spot price and C(t, X, ...) be the call option price.
One can build a risk-free portfolio consisting of being short one call option and long delta(S, C) underlying share.

Let r be the risk-free interest rate and PI(t, ...) be (-C + delta(S, C) * S).
One will short one call option only if d(PI)/dt >= r * PI
One will close the position only if d(PI)/dt <= r * PI

So at the equilibrium, d(PI)/dt = r * PI

Black Scholes' Model
=====
Let sigma be the volatility.
In this model, d(PI)/dt = -theta(C, t) - (sigma * S)^2 / 2 * gamma(S, C)
where theta reflecting the loss in value due to having less time for exercising the option and gamma reflects the gain in holding the option.
Also, theta <= 0 and gamma >= 0
