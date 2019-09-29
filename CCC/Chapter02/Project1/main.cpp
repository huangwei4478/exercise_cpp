#include <cstdio>

struct PodStruct {
	uint64_t a;
	char b[256];
	bool c;
};

int main() {
	PodStruct initialized_pod1{};
	PodStruct initialized_pod2 = {};
}