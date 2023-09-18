#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define OUTPUT	"output.txt"
#define INPUT	"input.txt"

void find_square(int n, int m, FILE *fout) {
	int ans;

	/*
	 * The edge of the largest square should equal to the min edge
	 * of input paper size.
	 */
	while (n != m) {
		if (n > m) {
			ans = m;
			n -= ans;
		} else {
			ans = n;
			m -= ans;
		}
		fprintf(fout, "%dx%d, ", ans, ans);
	}

	/* If n == m, output the square and return */
	fprintf(fout, "%dx%d\n", n, m);
}

int main(int argc, char **argv)
{
	FILE *fin, *fout;
	int n, m, ans;

	fin = fopen(INPUT, "r");
	if (!fin) {
		fprintf(stderr, "Error opening input file, %s\n", INPUT);
		goto err_in;
	}

	fout = fopen(OUTPUT, "w");
	if (!fout) {
		fprintf(stderr, "Error opening output file, %s\n", OUTPUT);
		goto err_out;
	}

	/* Read input continuously */
	while(fscanf(fin, "N=%d, M=%d\n", &n, &m) == 2)
		find_square(n, m, fout);

	fclose(fout);
	fclose(fin);

	return 0;

err_out:
	fclose(fin);
err_in:

	return EINVAL;
}
