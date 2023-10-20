/*The first typical variant of the problem is when a rational number 
 is given, and its root must be calculated with some accuracy eps:*/
double sqrt_newton(double n) {
	const double eps = 1E-15;
	double x = 1;
	for (;;) {
		double nx = (x + n / x) / 2;
		if (abs(x - nx) < eps)
			break;
		x = nx;
	}
	return x;
}
/*Another common variant of the problem is when we need to calculate the integer root (for the given 
 find the largest 
 such that 
). Here it is necessary to slightly change the termination condition of the algorithm, since it may happen that 
 will start to "jump" near the answer. Therefore, we add a condition that if the value 
 has decreased in the previous step, and it tries to increase at the current step, then the algorithm must be stopped.*/
int isqrt_newton(int n) {
	int x = 1;
	bool decreased = false;
	for (;;) {
		int nx = (x + n / x) >> 1;
		if (x == nx || nx > x && decreased)
			break;
		decreased = nx < x;
		x = nx;
	}
	return x;
}
/*Finally, we are given the third variant - for the case of bignum arithmetic. Since the number 
 can be large enough, it makes sense to pay attention to the initial approximation. Obviously, the closer it is to the root, the faster the result will be achieved. It is simple enough and effective to take the initial approximation as the number 
, where 
 is the number of bits in the number 
. Here is the Java code that demonstrates this variant:*/
public static BigInteger isqrtNewton(BigInteger n) {
	BigInteger a = BigInteger.ONE.shiftLeft(n.bitLength() / 2);
	boolean p_dec = false;
	for (;;) {
		BigInteger b = n.divide(a).add(a).shiftRight(1);
		if (a.compareTo(b) == 0 || a.compareTo(b) < 0 && p_dec)
			break;
		p_dec = a.compareTo(b) > 0;
		a = b;
	}
	return a;
}