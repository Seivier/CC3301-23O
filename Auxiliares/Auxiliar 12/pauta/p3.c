int *fun(int *a, int x){
	do{
		a[1] = a[0];
		a--;
	} while(a[0] > x);
	a[0] = x;
	return a;
}
