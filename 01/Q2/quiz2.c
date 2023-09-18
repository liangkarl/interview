#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define N	62
#define OUTPUT	"output.txt"
#define INPUT	"input.txt"
#define DATA	"data.txt"

int build_table(FILE *fdata, char *table)
{
	int x, i;
	char y[4];

	/* Rebuild the table from decimal number to 62-based number. */
	while (fscanf(fdata, "%d\t%s\n", &x, y) == 2) {
		table[x % N] = y[2];
		table[x / N % N] = y[1];
		table[x / N / N % N] = y[0];
	}

	/*
	 * In the spreadsheet, there is no sample for y=f(21), but it's
	 * easy to find out that f(21)=5
	 */
	table[21] = '5';

#ifdef DEBUG
	printf("Mapping Table:\n");
	for (i = 0; i < N; i++) {
		printf("%d=%c,\t", i, table[i]);
		if (i % 8 == 7)
			puts("");
	}
	puts("");
#endif

	return 0;
}

void f(char *table, int x, char *y)
{
	static int i;

	if (x == 0)
		return;

	i = 0;
	f(table, x / N, y);
	y[i++] = table[x % N];
}

int main(int argc, char **argv)
{
	FILE *fdata, *fin, *fout;
	char table[64] = {0};
	char y[16] = {0};
	int x;

	fdata = fopen(DATA, "r");
	if (!fdata) {
		fprintf(stderr, "Error opening data file, %s\n", DATA);
		goto err_data;
	}

	fin = fopen(INPUT, "r");
	if (!fin) {
		fprintf(stderr, "Error opening output file, %s\n", INPUT);
		goto err_in;
	}

	fout = fopen(OUTPUT, "w");
	if (!fout) {
		fprintf(stderr, "Error opening output file, %s\n", OUTPUT);
		goto err_out;
	}

	build_table(fdata, table);

	while (fscanf(fin, "%d", &x) == 1) {
		if (x == 0)
			y[0] = table[0];
		else
			f(table, x, y);
		fprintf(fout, "%s\n", y);
	};

	fclose(fin);
	fclose(fout);
	fclose(fdata);

	return 0;

err_out:
	fclose(fin);
err_in:
	fclose(fdata);
err_data:

	return EINVAL;
}
