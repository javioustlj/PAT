#include<stdio.h>
#include<stdlib.h>

#define N 104

typedef enum sort
{
	merge = 0,
	insertion = 1
}sort_alg;

void insertion_sort_next(int seq[], int seq_s[], int n)
{
	int i = 0, j = 0;

	for (i = 1; i < n; ++i)
		if (seq_s[i] == seq[i] && seq_s[i] < seq_s[i - 1])
			break;
	for (j = 0; j < i; j++)
		if (seq_s[i] < seq_s[j])
			break;
	for (int k = i; k > j; --k)
		seq_s[k] = seq_s[k - 1];
	seq_s[j] = seq[i];

	return;
}
int compare_number(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void merge_sort_next(int seq[], int seq_s[], int n)
{
	int index = 0, gap = n;
	int *p = seq_s;
	int new_gap = 0;

	for (int i = 1; i < n; ++i)
	{
		if (seq_s[i] < seq_s[i - 1])
		{
			if (i - index < gap)
				gap = i - index;
			index = i;
		}
	}
	new_gap = 2 * gap;
	for (int i = 0; i < n - n % new_gap; i += new_gap)
	{
		qsort(p, new_gap, sizeof(int), compare_number);
		p += new_gap;
	}
	qsort(p, n % new_gap, sizeof(int), compare_number);

	return;
}

int main(void)
{
	int n = 0, i = 0;
	int seq[N] = {0};
	int seq_s[N] = {0};
	char output[2][10] = { "Merge", "Insertion"};
	sort_alg sort = insertion;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq_s[i]);

	for (i = 1; i < n; ++i)
	{
		if (seq_s[i] < seq_s[i - 1])
		{
			for (int j = i + 1; j < n; ++j)
			{
			       if (seq[j] != seq_s[j])
			       {	       
				       sort = merge;
				       break;
			       }
			}
			break;
		}
	}

	if (sort == merge)
		merge_sort_next(seq, seq_s, n);
	else if (sort == insertion)
		insertion_sort_next(seq, seq_s, n);

	printf("%s Sort\n", output[sort]);
	printf("%d", seq_s[0]);
	for (int i = 1; i < n; ++i)
		printf(" %d", seq_s[i]);

	return 0;
}
