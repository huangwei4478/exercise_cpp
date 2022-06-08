#pragma once
template<typename T1, typename T2>
struct Pair {
	T1 first;
	T2 second;

	Pair(): first{T1()}, second{T2()} {}
	Pair(const T1& a, const T2& b): first{a}, second{b} {}
	
	// 在C++里做出一点“协变”（covariant）感觉的东西
	// 吐槽：连 Objective-C 的假泛型都有一个covariant关键字，没想到C++里没有
	// 关键：赋值的时候，能否把 derivedPair.first 赋值给 first?
	// 如果可以的话，说明T1和DerivedT1 有父子关系，DerivedT1 是 T1 的子类
	// 所以，Pair 实现了协变
	template<typename DerivedT1, typename DerivedT2>
	explicit Pair(const Pair<DerivedT1, DerivedT2>& derivedPair): first{derivedPair.first}, second{derivedPair.second} {}
};
