  
## Assignment 6 - Finding Primes

- Name: Byron Dowling
- Date: 19 October 2020
- Class: 4663 Cryptography


#### The AKS Primality Test *Deterministic*
> The AKS Primality Test was the first algorithim to have all four characteristics of:
> - General
> - Deterministic
> - Unconditional
> - Polynomial
>
> Another major breakthrough for this algorithm is that is was the first that could determine whether any given number was prime or composite within polynomial time 
> and this is achieved without relying on the *Generalized Riemann Hypothesis*. Arguably the biggest achievement of this algorithm is unliek many other algorithms that
> return a probability to the level of certainty that a number may be prime, the AKS algorithms can verify the primality of any general number is *Deterministically Correct*.
##### Disadvantages
> However despite the breakthrough of this discovery, the algorithm is seldom is ever used in practice and has been referred to as a galactice algorithm because they are never
> used in practice. Additionally, there are other primality tests whose results are unconditionally correct and can achieve this result significantly faster than AKS which 
> allows time for independant and rapid verifcation of the results, something that isn't possible for AKS.
>
> ![image of AKS](https://slideplayer.com/slide/236065/1/images/3/Original+AKS+Algorithm+August+6%2C+2002+version%3A.jpg)
>

#### Brute Force Algorithm *Certification*
> The Brute Force Primality-Test Algorithm is pretty self explanatory and is the a straightforward albeit time consuming algorithm for verifying if a nu,ber is prime.
> The idea is simple enough, if we have an integer N, and we want to determine if N is indeed Prime, we will check all factor combinations up to the Square Root of N.
> This could also be sped up if a pre-made list of known primes is available for all integers < Square Root of N, however this is impractical if not impossible for 
> very large numbers and this is why this algorithm is unsuitable for very large numbers. Therefore, there are other more efficient methods for verifying primality.

#### Miller-Rabin Test *Deterministic/Compositeness*
> The Miller-Rabin Test builds upon what the Fermat Test achieves and adds a higher level of accuracy to testing for primality of a number.
> The Test relies on an equality or set of equalities that hold true for prime values, then checks whether or not they hold for a number that we want to test for primality.
> Recall that N is prime if and only if the solutions of x^2 (mod N) is = +1 or -1, and if a^(n-1)=1 then we would also check a^(n-1)/2 is equal to +1 or -1 because this
> is the square root of 1. The result provides a high level of accuracy to whether a number is prime or not as well as if it's instead a composite value.
>
>##### Disadvantages
> The Miller-Rabin test claims to be Deterministic and shares some properties of a Deterministic Algorithm, however unlike the AKS Primality Test, the Miller Rabin test relies 
> on the extended Riemann Hypothesis.
> Additionally, numbers such as the third Carmichael number **1729** break this test.


#### Solovay Strassen Primality Test *Compositeness* or *Probablistic*
> The Solovay Strassen Primality Algorithm is another example of an Algorithm that sacrifies 100% certification and accuracy for greatly improving the speed of determining
> whether a number is prime of not. 
>
> The algorithm states that Let N be an integer adn let A be >= to 0, if N is prime then the Jacobi Symbol of A/N is equivalent to: A^(N-1)/2 mod(N)
> If N is not prime, then the Jacobi Symbol of A/N will not be equal to A^(N-1)/2 mod(N)
>
> ##### Disadvantages
> Like other Probability-based Primality Tests, there is always the chance of returning a high probability of a number being Prime and have it not actually be prime.
>
> Source: http://www-math.ucdenver.edu/~wcherowi/courses/m5410/ctcprime.html


