#pragma once
template<typename T1, typename T2>
struct Pair {
	T1 first;
	T2 second;

	Pair(): first{T1()}, second{T2()} {}
	Pair(const T1& a, const T2& b): first{a}, second{b} {}
	
	// ��C++������һ�㡰Э�䡱��covariant���о��Ķ���
	// �²ۣ��� Objective-C �ļٷ��Ͷ���һ��covariant�ؼ��֣�û�뵽C++��û��
	// �ؼ�����ֵ��ʱ���ܷ�� derivedPair.first ��ֵ�� first?
	// ������ԵĻ���˵��T1��DerivedT1 �и��ӹ�ϵ��DerivedT1 �� T1 ������
	// ���ԣ�Pair ʵ����Э��
	template<typename DerivedT1, typename DerivedT2>
	explicit Pair(const Pair<DerivedT1, DerivedT2>& derivedPair): first{derivedPair.first}, second{derivedPair.second} {}
};
