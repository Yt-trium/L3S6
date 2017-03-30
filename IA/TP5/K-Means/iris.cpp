#include "iris.h"

Iris::Iris()
{

}

void Iris::set(float sl, float sw, float pl, float pw, int ic)
{
    sepal_length = sl;
    sepal_width = sw;
    petal_length = pl;
    petal_width = pw;
    iris_class = ic;
}

float Iris::get_sepal_length()
{
    return sepal_length;
}

float Iris::get_sepal_width()
{
    return sepal_width;
}

float Iris::get_petal_length()
{
    return petal_length;
}

float Iris::get_petal_width()
{
    return petal_width;
}

int Iris::get_iris_class()
{
    return iris_class;
}
