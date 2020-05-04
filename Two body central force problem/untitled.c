#include <stdio.h>
#include <quadmath.h>

#define dt		1e-6q				//define time step
#define t_max	0.8q				//define simulation time
#define n		10000
#define m1		1					//define mass of particle 1
#define m2		10					//define mass of particle 2
#define x10		0
#define y10		0
#define x20		1
#define y20		0
#define vx10	-1
#define vy10	1
#define vx20	0.1q
#define vy20	-0.1q

int main()
{
	__float128 x1 = x10, y1 = y10, vx1 = vx10, vy1 = vy10, x2 = x20, y2 = y20, vx2 = vx20, vy2 = vy20, k, kx1, ky1;
	long long int i, j = 0;

	void print_coordinates(void)
	{
		printf("%.6Qf\n", x1);
		printf("%.6Qf\n", y1);
		printf("%.6Qf\n", x2);
		printf("%.6Qf\n", y2);
	}

	print_coordinates();
	for (i = 0; i <= t_max/dt; ++i)
	{
		x1 = x1 + vx1*dt;
		y1 = y1 + vy1*dt;
		x2 = x2 + vx2*dt;
		y2 = y2 + vy2*dt;

		k = -10*powq((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1), -1.5q)*dt;
		kx1 = k*(x1 - x2);
		ky1 = k*(y1 - y2);
		vx1 = vx1 + kx1/m1;
		vy1 = vy1 + ky1/m1;
		vx2 = vx2 - kx1/m2;
		vy2 = vy2 - ky1/m2;

		if (i >= t_max/dt/n*j)
		{
			print_coordinates();
			++j;
		}
	}
	printf("end\n");

	return 0;
}