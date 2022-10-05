// 백준 1927번 최소 힙
#include <iostream>

using namespace std;

void printheap(int size, int* heap){
	int x = 2;
	cout << "current heap" << endl;
	for (int i = 1; i < size + 1; i++){
		if (i == x){
			cout << endl;
			x <<= 1;
		}
		cout << heap[i] << ' ';
	}
	cout << endl << endl;
}

void p1927() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, x, min_heap[100001], size = 0, tmp;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x;
		if (x == 0){
			if (size == 0){
				cout << 0 << '\n';
				continue;
			}
			cout << min_heap[1] << '\n';
			min_heap[1] = min_heap[size];
			x = 1;
			while ((x << 1) < size){
				if ((x << 1) + 1 < size){
					if (min_heap[x << 1] > min_heap[(x << 1) + 1]){
						if (min_heap[x] > min_heap[(x << 1) + 1]){
							tmp = min_heap[x];
							min_heap[x] = min_heap[(x << 1) + 1];
							(x <<= 1)++;	min_heap[x] = tmp;
						}
						else
							break;
					}
					else{
						if (min_heap[x] > min_heap[x << 1]){
							tmp = min_heap[x];
							min_heap[x] = min_heap[x << 1];
							x <<= 1;	min_heap[x] = tmp;
						}
						else
							break;
					}
				}
				else{
					if (min_heap[x] > min_heap[x << 1]){
						tmp = min_heap[x];
						min_heap[x] = min_heap[x << 1];
						x <<= 1;	min_heap[x] = tmp;
					}
					else
						break;
				}
			}
			size--;
		}
		else{
			size++;
			min_heap[size] = x;
			x = size;
			while ((x >> 1) > 0){
				if (min_heap[x] < min_heap[x >> 1]){
					tmp = min_heap[x];
					min_heap[x] = min_heap[x >> 1];
					x >>= 1;	min_heap[x] = tmp;
				}
				else
					break;
			}
		}
		printheap(size, min_heap);
	}
	
	return;
}