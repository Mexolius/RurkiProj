#include "Matrix.h"
#include <iostream>


void Matrix::add_row(int from, int to, float mull_by)
{
	for (size_t i = 0; i < horizontal_size; i++)content[to][i] += mull_by * content[from][i];
}

void Matrix::multiply_row_by_scalar(int which, float scalar)
{
	for (size_t i = 0; i < horizontal_size; i++)content[which][i] *= scalar;
}

void Matrix::subtract_row(int from, int to, float mull_by)
{
	add_row(from, to, -1.0*mull_by);
}

Matrix::Matrix(size_t size, std::vector<std::vector<float>> content)
{
	alloc_content(size);
	this->content = content;
	horizontal_size = size;
}

Matrix::Matrix(size_t size, float ** cont)
{
	alloc_content(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) content[i][j] = cont[i][j];
	}
}

Matrix::Matrix(size_t size)
{
	alloc_content(size);
}

void Matrix::alloc_content(size_t size)
{
	content.resize(size);
	for (auto a : content) a.resize(size);
}

void Matrix::swap_with_non_zero_row(int row)
{
	for (int i = row; i < content.size(); i++)
	{
		if (content[i][row] != 0) std::swap(content[i], content[row]);
	}
}


Matrix::~Matrix()
{
}

std::vector<float> Matrix::gauss_for(std::vector<float> free_expressions)
{

	for (int i = 0; i < content.size(); i++) content[i].push_back(free_expressions[i]);
	horizontal_size++;
	for (int i = 0; i < content.size()-1; i++)
	{
		if (content[i][i] == 0)
		{
			swap_with_non_zero_row(i);
		}
		for (int j = i+1; j < content.size(); j++)
		{
			if (content[j][i] != 0)
			{
				//std::cout << content[j][i] << std::endl;
				subtract_row(i, j, content[j][i] / content[i][i]);
				//this->toString();
				
			}
		}
		for (int col = horizontal_size-2; col >= 0; col--)
		{
			for (int row = 0; row < col; row++)
			{
				if (content[row][col] != 0) subtract_row(col, row, content[row][col] / content[col][col]);
			}
		}
	}
	std::vector<float> ret(content.size());
	for (int row = 0; row < ret.size(); row++) ret[row] = content[row][horizontal_size - 1] / content[row][row];
	return ret;
}

void Matrix::toString()
{
	for (auto a : content)
	{
		for (auto b : a) std::cout << b << "\t";
			std::cout << std::endl;
	}
	std::cout << std::endl;
		
}
