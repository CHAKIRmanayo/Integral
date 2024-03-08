#include <stdio.h>
#include <conio.h>
#include <math.h>

float sum(float, float, float);
float func(float);

void main() {
	printf("Enter three numbers (two borders and epsilon): \n");
	float x1, x2, eps;
	int steps, count;
	scanf("%f%f%f", &x1, &x2, &eps);
	if (x1 > x2) { //switch values
		x1 += x2;
		x2 = x1 - x2;
		x1 -= x2;
	}
	x2 -= x1; // x2 - interval
	steps = 1;
	count = 1; 
	do {
		steps *= 2;
		printf("%i  ", count); // counter of iterations
		printf("%f \n", sum(x1, x2, steps));
		count++;
	} while (fabs(sum(x1, x2, (steps / 2)) - sum(x1, x2, steps)) > eps);
	getch();
}
float sum(float x1, float interval, float steps) {
	float y, c;
	float step = interval / steps;
	c = 0;
	y = 0;
	while (c < steps) {
		y = y + (step * (func(x1 + c * step) + func(x1 + (c + 1) * step)) / 2);
		c++;
	}
	return y;
}
float func(float x) {
	return sin(x); 
}
