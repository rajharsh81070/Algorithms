


void sieve(){
	bool prime[MAXN];
	memset(prime, true, sizeof(prime));
	for(int i=0; i<MAXN; i+=2)
		prime[i] = false;
	for(int i=3; i*i<MAXN; i+=2){
		if(prime[i]){
			for(int j=i*i; j<MAXN; j+=2*i)
				prime[j] = false;
		}
	}
}