#include "stdafx.h"
#include "dynlib.h"
#include <stdexcept>

using namespace std;

int condition(double *a, int temp, int to)
{
	if (pow(pow(a[temp], 2) + 2, 0.3333) < 10) return 1;
	else
	{
		if (temp == to) return 0;
		else return condition(a, ++temp, to);
	}
}

