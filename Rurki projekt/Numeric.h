#pragma once

#define NUMERIC_NAMESPACE numeric
#define NUMERIC_NAMESPACE_FULL NUMERIC_NAMESPACE
#define NUMERIC_NAMESPACE_BEGIN namespace NUMERIC_NAMESPACE_FULL{
#define NUMERIC_NAMESPACE_END }

#include<functional>
#include<tuple>
#include<array>

using function1D = std::function<float(float)>;
using function2D = std::function<float(float, float)>;

using vec2f = std::tuple<float, float>;

NUMERIC_NAMESPACE_BEGIN

float num_integr_1D(float start, float end, function1D f);
float num_integr_2D(vec2f start, vec2f end, function2D f);

NUMERIC_NAMESPACE_END