#include "common.h"

#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <iostream>

using namespace std;

__declspec(noinline) void StdSort(vector<int>& v)
{
	sort(begin(v), end(v));
}

int IntComp(const void* a, const void* b)
{
	int ia = *static_cast<const int*>(a);
	int ib = *static_cast<const int*>(b);
	return ia < ib ? -1 : (ia == ib ? 0 : 1);
}

__declspec(noinline) void Qsort(vector<int>& v)
{
	qsort(&v[0], v.size(), sizeof(v[0]), IntComp);
}

int main()
{
	vector<int> v(100000);
	iota(begin(v), end(v), 0);
	random_shuffle(begin(v), end(v));

	auto stdSortTotalTime = 0.f;
	auto qsortTotalTime = 0.f;
	const auto numIterations = 100;
	for (int i = 0; i < numIterations; ++i)
	{
		auto v1(v);
		auto v2(v);

		stdSortTotalTime += TimeFunction([&]() { StdSort(v1); });
		qsortTotalTime += TimeFunction([&]() { Qsort(v2); });

		cout << "v1 " << (is_sorted(begin(v1), end(v1)) ? "is " : "is not ") << "sorted" << endl;
		cout << "v2 " << (is_sorted(begin(v2), end(v2)) ? "is " : "is not ") << "sorted" << endl;
	}

	cout << "std::sort average time = " << (stdSortTotalTime / numIterations) << "s." << endl;
	cout << "qsort average time = " << (qsortTotalTime / numIterations) << "s" << endl;
	cout << "Runtime of std::sort is " << (100.f * stdSortTotalTime / qsortTotalTime) << "% of runtime of qsort." << endl;

	return 0;
}