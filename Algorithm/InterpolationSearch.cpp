#include <iostream>


int InterpolationSearch(int arr[], int target, int left, int right)
{
	// binarysearch와 다르게 모든 인덱스를 촘촘히 지나지 않으므로 target이 left idx와 right idx 사이에 존재하지 않을 수 있음.
	// 이러한 경우 무한루프에 빠지므로 target이 범위 밖을 벗어났는지를 파악해 탈출 조건으로 지정해야 함.
	//if (left > right)
	if (arr[left] > target || arr[right] < target)
	{
		return -1;
	}
	int point = (static_cast<double>(target) - arr[left]) / (arr[right] - arr[left]) * (right - left) + left;
	
	if (arr[point] == target)
	{
		return point;
	}
	else if (arr[point] < target)
	{
		return InterpolationSearch(arr, target, point + 1, right);
	}
	else
	{
		return InterpolationSearch(arr, target, left, point - 1);
	}
}

//int main()
//{
//	/*int arr[20]{ 0 };
//
//	for (int i = 0; i < 20; i++)
//	{
//		arr[i] = i + 10;
//	}*/
//	int arr[]{ 1,3,5,7,9 };
//
//	std::cout << InterpolationSearch(arr, 2, 0, 4);
//
//	return 0;
//}