// 백준 1932번 정수 삼각형
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

void p1932(){
	int n, line[500][2], i, j, max, flag = 0, buf[130000], buf_index = 0;

	scanf("%d", &n); max = n*(n + 1) / 2;
	for (i = 0; i < max; i++)
		scanf("%d", &buf[i]);

	line[0][flag] = buf[buf_index++];
	for (i = 1; i < n; i++){
		flag = 1 - flag;
		line[0][flag] = buf[buf_index++];
		line[0][flag] += line[0][1-flag];
		for (j = 1; j < i; j++){
			line[j][flag] = buf[buf_index++];
			line[j][flag] += MAX(line[j - 1][1-flag], line[j][1-flag]);
		}
		line[j][flag] = buf[buf_index++];
		line[j][flag] += line[j-1][1-flag];
	}

	max = 0;
	for (i = 0; i < n; i++){
		if (max < line[i][flag])
			max = line[i][flag];
	}
	
	printf("%d", max);

	return;
}