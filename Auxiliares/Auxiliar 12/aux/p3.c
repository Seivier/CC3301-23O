int* fun(int* a0, int a1) {
	do {
		a0[1] = a0[0];
		a0--;
	} while (a0[0] > a1);
	a0[0] = a1;
	return a0;
}