#include <iostream>


int InterpolationSearch(int arr[], int target, int left, int right)
{
	// binarysearch�� �ٸ��� ��� �ε����� ������ ������ �����Ƿ� target�� left idx�� right idx ���̿� �������� ���� �� ����.
	// �̷��� ��� ���ѷ����� �����Ƿ� target�� ���� ���� ��������� �ľ��� Ż�� �������� �����ؾ� ��.
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