#include<iostream>

using namespace std;

int arr[5];

void printarr() {
	for(int i=0;i<5;i++)
	cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int chk=1,tmp=0;
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	
	while (chk!=0) {
		chk = 0;
		for (int i = 0; i < 5; i++) {
			if (arr[i] != i + 1)chk = 1;
		}
		for (int i = 0; i < 4; i++) {
			if (arr[i] > arr[i + 1]) {
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				printarr();
			}
		}
	}
}

