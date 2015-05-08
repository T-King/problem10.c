//Troy King 08 April 2015
//Project Euler Problem 10
//Find the sum of all prime numbers below 2 million
//gcc needs -lm tag to define math.h functions

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* findNextPrime(int*, int*, int*);

int main(int argc, char** argv)
{
        unsigned int i, range;
        int primeNum = 2,* primes, sizeofPrimes = 1;
	long long int sum = 0;

        if(argc < 2)
        {
                printf("No value entered.\n");
                exit(0);
        }

        range = atoi(argv[1]);
	primes = (int*) malloc (sizeof(int));
	primes[0] = primeNum;

	while(primeNum < range)
	{
		sum += primeNum;
      		primes = findNextPrime(&primeNum, primes, &sizeofPrimes);
	}

	printf("The sum of all prime numbers below %d is: %lld\n", range, sum);

	free(primes);
        return 0;
}

int* findNextPrime(int* primeNum, int* primes, int* sizeofPrimes)
{
        unsigned int nextPrime = *primeNum;
	unsigned int i;
	float check;

	while(1)
	{
		check = sqrt(++nextPrime);
		for(i = 0; i < *sizeofPrimes; i++)
		{
			if((primes[i] >= check) && (check > 3)) break;
			else if(nextPrime%primes[i] == 0) break;
			else if((primes[i + 1] > check) || (i == *sizeofPrimes - 1))
			{
				primes = (int*) realloc (primes, (++(*sizeofPrimes)) * sizeof(int));
				primes[*sizeofPrimes - 1] = nextPrime;
				*primeNum = nextPrime;
				return primes;
			}
		}
	}
}
