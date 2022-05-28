#pragma once
template <typename T>
struct identity {
	const T& operator()(const T& x) const { return x; }
};

template <typename Pair>
struct select1st {
	const typename Pair::first_type& operator()(const Pair& x) const { return x.first; }
};

template <typename Pair>
struct select2nd {
	const typename Pair::second_type& operator()(const Pair& x) const { return x.second; }
};

