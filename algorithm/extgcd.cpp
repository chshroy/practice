// ax + by = gcd(a, b)
void extgcd(int a, int b, int &x, int &y) {
	if(a == 0) {
		x = 0;
		y = b;
		return;
	}
	int x1, y1;
	extgcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return;
}
