/*

Eg:		1,2,3 → 1,3,2
		3,2,1 → 1,2,3
		1,1,5 → 1,5,1

The steps to solve this problem:
1) scan from right to left, find the first element that is less than its previous one.
2) scan from right to left, find the first element that is greater than p.
3) swap p and q
4) reverse elements [p+1, nums.length] 

*/

#include <stdio.h>

void reverse(int[] , int , int );

int main(){
	
	int num,num_arr[20];
	int p = 0,q = 0;
	printf("Enter the number of digits of the number:\n");
	scanf("%d", &num);
	printf("Enter the digits:\n");
	for(int i=0; i<num; i++){
		scanf("%d", &num_arr[i]);
	}

	if(num == 0 || num<2){
		printf("End...");
		return 1;
	}

	for(int i=num-2; i>=0; i--){
		if(num_arr[i] < num_arr[i+1]){
			p = i;
			break;
		}
	}

	for(int i=num-1; i>=p; i--){
		if(num_arr[i] > num_arr[p]){
			q = i;
			break;
		}
	}

	if(p == 0 && q == 0){
		reverse(num_arr, 0, num-1);
		return 1;
	}

	int temp = num_arr[p];
	num_arr[p] = num_arr[q];
	num_arr[q] = temp;

	if(p<num-1){
		reverse(num_arr, p+1, num-1);
	}

	printf("The next permutation is:\n");
	for(int i=0; i<num; i++){
		printf("%d", num_arr[i]);
	}

	return 1;
}

void reverse(int nums[], int left, int right){
	while(left < right){
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		left++;
		right--;
	}
}


