#pragma once

#include <vector>

class Matrix
{
private:
	

public:
	Matrix(size_t size, std::vector<std::vector<float>> content);
	Matrix(size_t size, float ** cont);
	Matrix(size_t size);
	~Matrix();

	std::vector<float> gauss_for(std::vector<float> free_expressions);
	void toString();

	//
	size_t horizontal_size;
	std::vector<std::vector<float>> content;
	void add_row(int from, int to, float mull_by);
	void multiply_row_by_scalar(int which, float scalar);
	void subtract_row(int from, int to, float mull_by);
	void alloc_content(size_t size);
	void swap_with_non_zero_row(int row);
	//
};
