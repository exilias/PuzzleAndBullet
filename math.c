
int x4(int value)
{
	return value << 2;
}

float pow(float a, float times)
{
	int i;
	float ans;

	ans = 1;
	for (i = 0; i < times; i++) {
		ans *= a;
	}

	return a;
}

float abs(float a)
{
	return a >= 0 ? a : -a;
}