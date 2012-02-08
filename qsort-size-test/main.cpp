#include "common.h"

#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
int CompareFunc(const void* a, const void* b) {
	auto aT = *static_cast<const T*>(a);
	auto bT = *static_cast<const T*>(b);
	return aT < bT ? -1 : (aT == bT ? 0 : 1);
}

template<typename T>
void TestSort()
{
	vector<T> v(NumElements);
	iota(begin(v), end(v), T(0));
	random_shuffle(begin(v), end(v));

	auto sortTime = TimeFunction([&]() { qsort(&v[0], NumElements, sizeof(v[0]), CompareFunc<T>); });

	cout << "v " << (is_sorted(begin(v), end(v)) ? "is " : "is not ") << "sorted" << endl;
	cout << "v sorted in " << sortTime << "s" << endl;
}

int main()
{
	TestSort<int>();
	TestSort<unsigned int>();
	TestSort<float>();
	TestSort<double>();
	TestSort<long>();
	TestSort<unsigned long>();
	TestSort<long long>();
	TestSort<unsigned long long>();
	TestSort<NumString>();

	return 0;
}