#include	<stdio.h>

#define WIDTH 60 /* 行当たり表示バイト数 */
#define MASKCHR '.' /* 16進数表示で20～7E以外の場合の表示用文字 */

void dump(char *filename, long from, long to) // 開始位置from、終了位置to
{
	FILE *inflie;
	int chr, pos = 0;
	long cnt = 0;
	char tblC[256], bufC[WIDTH + 1]; // 文字を格納する配列
	char tblH[256], bufH[WIDTH + 1]; // 文字の上2桁を格納する配列
	char tblL[256], bufL[WIDTH + 1]; // 文字の下2桁を格納する配列
	char hex[] = "0123456789ABCDEF";
	
	for (chr = 0x00; chr <= 0xFF; chr++) {
		if ((0x20 <= chr) && (chr <= 0x7E)) {
			tblC[chr] = chr;
		} else {
			tblC[chr] = MASKCHR;
		}
		tblH[chr] = hex[chr >> 4];
		tblL[chr] = hex[chr & 0x0F];
	}
	bufC[WIDTH] = bufH[WIDTH] = bufL[WIDTH] = '\0';
	inflie = fopen(filename, "rb");
	while (((chr = fgetc(inflie)) != EOF) && ((to < 0) || (cnt <= to))) {
		cnt++;
		if (cnt > from) {
			bufC[pos] = tblC[chr];
			bufH[pos] = tblH[chr];
			bufL[pos] = tblL[chr];
			pos++;
			if (pos == WIDTH) {
				printf("%10ld  %s\n%12s%s\n%12s%s\n\n", cnt - WIDTH, bufC, " ", bufH, " ", bufL);
				pos = 0;
			}
		}
	}
	if (pos > 0) {
		bufC[pos] = bufH[pos] = bufL[pos] = '\0';
		printf("%10ld  %s\n%12s%s\n%12s%s\n\n", cnt - pos, bufC, " ", bufH, " ", bufL);
	}
	if (chr == EOF) {
		printf("END OF DATA...%ld byte(s)\n", cnt - from);
	} else {
		printf("END OF DUMP...%ld byte(s)\n", cnt - from);
	}
	fclose(inflie);
}

int	main(void)
{
	/* for testing dump */
	dump("dump.c", 0L, -1L);
	// dump("dump.c", 133L, 192L);
	return 0;
}