#include "Numeric.h"

NUMERIC_NAMESPACE_BEGIN

float num_integr_1D(float start, float end, function1D f)
{
	float ret = 0.0;
	float dl = (end - start) / 100;
	for (int l = start; l < end; l += dl)
	{
		ret += f(l)*dl;
	}
	return ret;
}

float num_integr_2D(vec2f start, vec2f end, function2D f)
{
	return num_integr_1D(std::get<0>(start), std::get<0>(end), [&](float y) {
		return num_integr_1D(std::get<1>(start), std::get<1>(end), [&](float x) {return f(x, y); });
	});
}

NUMERIC_NAMESPACE_END