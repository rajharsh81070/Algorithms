
vector <int> primes;

void factors_of_a_number(int num){
	sieve(); // Call sieve to find the prime numbers.
	vector <int> factors;
	int i = 0;
	int p = primes[i];
	while(p*p<=num){
		if(!(num/p)){
			factors.push_back(p);
			while(!(num/p)){
				num/=p;
			}
		}
		i++;
		p = primes[i];
	}

}