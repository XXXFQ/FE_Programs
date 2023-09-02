#include	<stdio.h>

int	pat[2][2] = {
	{1, 1},
	{1, 0}
};
int	p_rn = sizeof(pat) / sizeof(pat[0]); // patの要素数
int p_cn = sizeof(pat[0]) / sizeof(pat[0][0]); // patの1行分の要素数

void print_frac(int);
int exists_at(int, int, int);

void print_frac(int	d)
{
	int i, j, rn, cn;
	rn = cn = 1;
	for (i = 0; i < d; i++){
		rn *= p_rn; // フラクタル図形の行数
		cn *= p_cn; // フラクタル図形の列数
	}
	for (i = 0; i < rn; i++){
		for (j = 0; j < cn; j++){
			putchar(exists_at(i, j, d) ? '*' : ' ');
		}
		putchar('\n');
	}
}

int exists_at(int i, int j, int d)
{
	if (d == 0)
		return 1;
	else if (exists_at(i / p_rn, j / p_cn, d - 1) == 0) // 空白文字の置換
		return 0;
	else
		return pat[i % p_rn][j % p_cn];
}

int main(void)
{
	/*printf("配列全体のメモリサイズ = %ld\n", sizeof pat); // 配列全体のメモリサイズ
  	printf("配列の要素一つ分のメモリサイズ = %ld\n", sizeof pat[0]); // 配列の要素一つ分の大きさ
  	printf("配列の要素数 = %d\n\n", p_rn); // 配列の要素数*/
	print_frac(2);
}