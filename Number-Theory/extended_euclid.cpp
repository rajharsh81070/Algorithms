


void eeuclid(int a, int b){
	if(b==0){
		ex = 1;
		ey = 0;
	}
	else{
		eeuclid(b, a%b);
		ll temp = ex;
		ex = ey;
		ey = temp - (a/b)*ey;
	}
}