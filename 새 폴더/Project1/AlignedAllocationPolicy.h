#pragma once

// for warning C4316
// 위 경고는 __declspec(align(byte))로 정렬되어야 하는 데이터를 member로 가지거나, 
// 할당할 때 생기는 경고임. For example, using XMMATRIX as a class member. 


// 자료형에 상관없이 자료를 넘겨주면 뭐가 됬든 그 자료에 맞게 메모리를 할당하고 해제하는 파일
template<size_t T>
class AlignedAllocationPolicy
{
public:
	static void* operator new(size_t size)
	{
		return _aligned_malloc(size, T);
	}

	static void operator delete(void* memory)
	{
		_aligned_free(memory);
	}
};
