// MergeSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

std::vector<int> NumList, AuxA, AuxB;

void Merge(int left, int right, int mid)
{
	int i, j, k, lleng = mid - left + 1, rleng = right - mid;
	AuxA.clear();
	AuxB.clear();
	for (i = left; i <= mid; i++)
	{
		AuxA.push_back(NumList[i]);
	}
	for (i = mid + 1; i <= right; i++)
	{
		AuxB.push_back(NumList[i]);
	}
	for (i = j = 0, k = left; k <= right; k++)
	{
		if (i == lleng)
		{
			NumList[k] = AuxB[j++];
			continue;
		}
		if (j == rleng)
		{
			NumList[k] = AuxA[i++];
			continue;
		}
		NumList[k] = (AuxA[i] <= AuxB[j]) ? AuxA[i++] : AuxB[j++];
	}
	return;
}

void RecursionSort(int left, int right)
{
	int mid = (left + right) / 2;
	if (right > left)
	{
		RecursionSort(left, mid);
		RecursionSort(mid + 1, right);
		Merge(left, right, mid);
	}
	return;
}

void MergeSort()
{
	RecursionSort(0, NumList.size() - 1);
}

int main()
{
	int input, n;
	std::cout << "Data size (* 1k): ";
	std::cin >> n;
	NumList.clear();

	std::streambuf *backup;
	std::ifstream fin;
	fin.open("random.txt");
	backup = std::cin.rdbuf();
	std::cin.rdbuf(fin.rdbuf());

	for (int i = 0; i < n * 1000; i++)
	{
		std::cin >> input;
		NumList.push_back(input);
	}

	std::cin.rdbuf(backup);
	fin.close();

	DWORD begin, end;
	begin = timeGetTime();

	MergeSort();

	end = timeGetTime();

	for (int i = 0; i < NumList.size(); i++)
	{
		std::cout << NumList[i] << std::endl;
	}
	std::cout << std::endl << n << "k numbers sorted" << std::endl;
	std::cout << "Duration: " << end - begin << " ms" << std::endl;
	system("PAUSE");

    return 0;
}

