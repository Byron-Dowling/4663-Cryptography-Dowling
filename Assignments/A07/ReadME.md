  
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
> The Brute Force Primality-Test Algorithm is pretty self explanatory and is the a straightforward albeit time consuming algorithm for verifying if a number is prime.
> The idea is simple enough, if we have an integer N, and we want to determine if N is indeed Prime, we will check all factor combinations up to the Square Root of N.
> This could also be sped up if a pre-made list of known primes is available for all integers < Square Root of N, however this is impractical if not impossible for 
> very large numbers and this is why this algorithm is unsuitable for very large numbers. Therefore, there are other more efficient methods for verifying primality.

#### Miller-Rabin Test *Deterministic/Compositeness*
> The Miller-Rabin Test builds upon what the Fermat Test achieves and adds a higher level of accuracy to testing for primality of a number.
> The Test relies on an equality or set of equalities that hold true for prime values, then checks whether or not they hold for a number that we want to test for primality.
> Recall that N is prime if and only if the solutions of x^2 (mod N) is = +1 or -1, and if a^(n-1)=1 then we would also check a^(n-1)/2 is equal to +1 or -1 because this
> is the square root of 1. The result provides a high level of accuracy to whether a number is prime or not as well as if it's instead a composite value.
>
> ![image of Miller Rabin](https://slideplayer.com/slide/4358163/14/images/5/Miller-Rabin+Test+What+are+we+doing+b0+%3D+am+%28mod+n%29+b1+%3D+a2m+%28mod+n%29.jpg)
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
> The biggest claim to fame that this Test/Agorithm has is that it is a great historical importance as it showed the feasability of the RSA Cryptosytem.
> ##### Disadvantages
> Like other Probability-based Primality Tests, there is always the chance of returning a high probability of a number being Prime and have it not actually be prime.


#### Elliptic Curve Primality Proving (ECPP) *General Purpose/Certification*
> The Elliptic Curve Primality technique is among one of the quickest and most widely used methods in primality proving building upon a previous concept of using elliptic
> curves in the factorization process.
>
> The overall approach of ECCP is to reduce the question of the primality of p to the question of the primality of a smaller prime q, where q ≤ p/2 + o(p). 
> This results in a chain of primes p0, p1, . . . , pi , where p0 = p is the original prime, and pi is small enough to be verified deterministically in polynomial time. 
> This chain is a certificate of primality for p and can be verified quickly in polynomial time
> 
> One major advantage of Elliptic Curve Primality is that it is easier to implement in practice compared to rival algorithms that are not as easily implemented such as
> the Pocklington Primality Test.

#### Baillie-PSW Primality Test *Composite/Probalistic*
> Similar in nature to the Fermat Test and Miller-Rabin test the general nature of the algorithm is as follows:
- Process all N < 3 and all even N
- Check N for an small prime divisors where P < 1000
- Perform a Miller-Rabin (or strong probable prime) tes, base 2, on N
- Perform a standard or strong Lucas-Selfridge test on N, using Lucas sequences with the parameters suggested by Selfridge.
>
> At any point during this procedure, N may be revealed to be definitely composite, if this doesn't occur it has passed with a standard/strong rating and is either a
> Prime or a BPSW (Baillie-PSW) Pseudoprime
>
>##### Advantages
> As of 2009, there have not been any BPSW pseudoprimes discovered which bolsters the credibility and accuracy of this algorithm over running multiple Miller-Rabin Tests
> Many commercial software packages rely on this algorithm
>
>##### Disadvantages
> BPSW requires 3-7 times more operations than a single Miller-Rabin test.
> There is a theoretical concern that for very large N, the algorithm would become computationally useless


#### Primality Testing with Gaussian Periods *Deterministic*
> Loosely based on some aspects of AKS, Lenstra and Pomerance created a primality test attempting to deterministically prove if N is prime
>
> To begin, we are given an integer N > 1 and want to determine if N is prime or composite
> - Check if N is a power other than a first power. If it is then N is composite.
> - Let D = log2(N)
> - Let B = d^(1/2)log2N. Check to see if N has a prime factor within the interval of 1 to B. If N has such a factor that is not equal to N, we declare it composite.
>   If N itself is this prime factor then declare it prime and stop.
> - Find a Monic polynomial F in (Z/NZ)(x) of degree d.
> - For each integer a, 1 <+ B, check if (A+B)^N is congruent to X^N + A mod(N,f(x)). If one of these congruences should fail, declare N composite. Else, declare N Prime.
>

#### Sources:
> - https://math.dartmouth.edu/~carlp/PDF/complexity12.pdf
> - https://faculty.lynchburg.edu/~nicely/misc/bpsw.html
> - https://math.dartmouth.edu/~carlp/dopo.pdf
> - http://theory.stanford.edu/~dfreeman/cs259c-f11/finalpapers/primalityproving.pdf
> - http://www-math.ucdenver.edu/~wcherowi/courses/m5410/ctcprime.html
> - https://crypto.stanford.edu/pbc/notes/numbertheory/millerrabin.html
> - https://crypto.stanford.edu/pbc/notes/numbertheory/poly.html
> - https://www.whitman.edu/documents/Academics/Mathematics/2018/Worthington.pdf

