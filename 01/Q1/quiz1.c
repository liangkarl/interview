#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define OUTPUT	"output.txt"
#define INPUT	"input.txt"

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

	while(fscanf(fin, "N=%d, M=%d\n", &n, &m) == 2) {
		/*
		 * The edge of the largest square should equal to the min edge
		 * of input paper size.
		 */
		ans = n < m ? n : m;
		fprintf(fout, "%dx%d\n", ans, ans);
	}

	fclose(fout);
	fclose(fin);

	return 0;

err_out:
	fclose(fin);
err_in:

	return EINVAL;
}
