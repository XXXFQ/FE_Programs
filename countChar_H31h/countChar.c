#include	<stdio.h>

#define	InName "Fractal.c"

int	main(void)
{
	FILE *inflie;
	int chr, i;
	long cnt, freq[256];
	for (chr = 0; chr <= 255; chr++) {
		freq[chr] = 0;
	}

	inflie = fopen(InName, "rb");
	cnt = 0;
	while ((chr = fgetc(inflie)) != EOF) {
		cnt++;
		freq[chr]++;
	}
	fclose(inflie);
	printf("%10ld bytes processed\n\n", cnt);
	for (i = 0; i < 64; i++) {
		for (chr = i; chr <= i + 192; chr += 64) {
			if ((0x20 <= chr) && (chr <= 0x7E)) {
				printf("%10ld %02X '%c'", freq[chr], chr, chr);
			} else {
				printf("%10ld %02X    ", freq[chr], chr);
			}
		}
		printf("\n");
	}
}
