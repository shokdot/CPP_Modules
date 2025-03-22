#pragma once

template <typename L>
void swap(L &a, L &b)
{
	L tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T &min(T &a, T &b) { return a < b ? a : b; }

template <typename T>
const T &max(T &a, T &b) { return a > b ? a : b; }
