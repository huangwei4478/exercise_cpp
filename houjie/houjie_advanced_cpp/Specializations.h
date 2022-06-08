#pragma once
template <typename Key>
struct hash {};

// specialization
template<>
struct hash<char> {
	size_t operator()(char x) const { return x;  }
};

template<>
struct hash<int> {
	size_t operator()(int x) const { return x;  }
};

template<>
struct hash<long> {
	size_t operator()(long x) const { return x;  }
};

