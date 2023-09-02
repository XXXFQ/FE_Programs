#include	<stdio.h>

// ハッシュ探索
int hash_search(int *numbers, int length, int hash, int index)
{
	int i;

	// 配列を探索する
	for (i = index % hash; i <= length && numbers[i] != index && numbers[i] != -1; i++);

	if (i > length || numbers[i] == -1) {
		printf("検索エラー!\n");
		return -1;
	}

	// 結果表示して返す
	printf("添え字 = %d\n", i);
	return i;
}

int main(void)
{
	int numbers[] = { 90, -1, 92, 43, 14, 65, 55, 46, -1, 29 };
	int length = sizeof(numbers) / sizeof(int);
	int index;

	printf("検索値？");
	scanf("%d", &index);

	// ハッシュ探索
	hash_search(numbers, length, 10, index);

	return 0;
}
