# options-pricing

Calculate option price, implied volatility with Black Scholes' model and Newton's method.

Definitions
=====
Let K be the strike price.

Let t be the time.

Let r(t) be the risk-free interest rate.

Let sigma be the underlying volatility.

Let X be a some random variable.

Let S(t, X) be the spot price.

Let C(S, K, t, r, sigma) be the call option price.

Let delta be round(C)/round(S), theta be round(C)/round(t) and gamma be round^2(C)/round(S)^2

Delta Hedging
=====

One can build a risk-free portfolio, PI, consisting of being short one call option and long delta underlying share.
Then,

PI = -C + delta * S.

One will short one call option only if d(PI)/dt >= r * PI
One will close the position only if d(PI)/dt <= r * PI
So at the equilibrium, d(PI)/dt = r * PI

Black Scholes' Model
=====

In this model,

r * (-C + delta * S) = d(PI)/dt = -theta - (sigma * S)^2 / 2 * gamma

where theta reflecting the loss in value due to having less time for exercising the option and gamma reflects the gain in holding the option.
Also, theta <= 0 and gamma >= 0

With this model, we can calculate the call (/put) option price, delta, theta and gamma given the spot price, the strick price, the time to expiry, the risk-free interest rate and the underlying volatility.

Implied Volatility
=====
In reality, the actual unknown is not the option price but the underlying volatility. We can still calculate this unknown implied by the model with all sorts of numerical methods.
