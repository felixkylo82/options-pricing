# options-pricing

Calculate option price, implied volatility with Black Scholes' model and Newton's method.

Definitions
=====
Let K be the strike price.

Let t be the time.

Let r be the risk-free interest rate.

Let sigma be the underlying volatility.

Let X be a some random variable.

Let S(t, X) be the spot price.

Let C(S, t) be the call option price.

Let delta be round(C)/round(S), theta be round(C)/round(t) and gamma be round^2(C)/round(S)^2

Delta Hedging
=====

One can build a risk-free portfolio, PI, consisting of being short one call option and long delta underlying share.
Then,

PI = -C + delta * S.

One will short one call option only if d(PI)/dt >= r * PI.
One will close the position only if d(PI)/dt <= r * PI.
So, at the equilibrium,

d(PI)/dt = r * PI.

Black Scholes' Model
=====

Based on delta hedging and that X follows geometric Brownian motion,
Black Scholes' model formulate an equation,

r * (-C + delta * S) = d(PI)/dt = -theta - (sigma * S)^2 / 2 * gamma

where theta reflecting the loss in value due to having less time for exercising the option and gamma reflects the gain in holding the option.

The model gives an analytical solution to the call (/put) European option price, delta, theta and gamma given the spot price, the strick price, the time to expiry, the risk-free interest rate and the underlying volatility.

It is also shown that theta <= 0 and gamma >= 0

Implied Volatility
=====
In reality, the actual unknown is not the option price but the underlying volatility. We can still calculate this unknown implied by the model with all sorts of numerical methods.
