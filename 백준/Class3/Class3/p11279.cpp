// 백준 11279번 최대 힙
#include <stdio.h>

int main() {
	int n, x, max_heap[100001], size = 0, tmp;

	scanf("%d\n", &n);
	for (int i = 0; i < n; i++){
		scanf("%d\n", &x);
		if (x == 0){
			if (size == 0){
				printf("0\n");
				continue;
			}
			printf("%d\n", max_heap[1]);
			max_heap[1] = max_heap[size];
			x = 1;
			while ((x << 1) < size){
				if ((x << 1) + 1 < size){
					if (max_heap[x << 1] < max_heap[(x << 1) + 1]){
						if (max_heap[x] < max_heap[(x << 1) + 1]){
							tmp = max_heap[x];
							max_heap[x] = max_heap[(x << 1) + 1];
							(x <<= 1)++;	max_heap[x] = tmp;
						}
						else
							break;
					}
					else{
						if (max_heap[x] < max_heap[x << 1]){
							tmp = max_heap[x];
							max_heap[x] = max_heap[x << 1];
							x <<= 1;	max_heap[x] = tmp;
						}
						else
							break;
					}
				}
				else{
					if (max_heap[x] < max_heap[x << 1]){
						tmp = max_heap[x];
						max_heap[x] = max_heap[x << 1];
						x <<= 1;	max_heap[x] = tmp;
					}
					else
						break;
				}
			}
			size--;
		}
		else{
			size++;
			max_heap[size] = x;
			x = size;
			while ((x >> 1) > 0){
				if (max_heap[x] > max_heap[x >> 1]){
					tmp = max_heap[x];
					max_heap[x] = max_heap[x >> 1];
					x >>= 1;	max_heap[x] = tmp;
				}
				else
					break;
			}
		}
	}

	return 0;
}