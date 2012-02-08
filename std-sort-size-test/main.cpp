#include "common.h"

#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void TestSort()
{
	vector<T> v(NumElements);
	iota(begin(v), end(v), T(0));
	random_shuffle(begin(v), end(v));

	auto sortTime = TimeFunction([&]() { sort(begin(v), end(v)); });

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