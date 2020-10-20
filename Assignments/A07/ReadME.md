  
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
