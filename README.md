# options-pricing

Calculate price, implied volatility of European options with Black Scholes' model, Binomial model and Monte Carlo model.

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

where theta reflects the loss in value due to having less time for exercising the option and gamma reflects the gain in holding the option.

The model gives an analytical solution to the call (/put) European option price, delta, theta and gamma given the spot price, the strike price, the time to expiry, the risk-free interest rate and the underlying volatility.

Binomial Model and Monte Carlo Model
=====

Based on delta hedging and that X follows geometric Brownian motion, using different options pricing model,
we can compute the same results as Black Scholes' model.
Binomial model computes option prices with a probability tree and Monte Carlo model computes option prices by simulation. In different problem settings, like calculating American option price, where analytical solutions do not exist, these models are particularly useful.

Implied Volatility
=====
In reality, the actual unknown may not be the option price but the underlying volatility. We can, howerver, calculate the underlying volatility and the risk-free interest rate implied by the model with numerical methods.
