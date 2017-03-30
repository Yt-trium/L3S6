#ifndef IRIS_H
#define IRIS_H


class Iris
{
public:
    Iris();
    void set(float sl, float sw, float pl, float pw, int ic);

    float get_sepal_length();
    float get_sepal_width();
    float get_petal_length();
    float get_petal_width();
    int get_iris_class();

private:
    /*
        Attribute Information:
        1. sepal length in cm
        2. sepal width in cm
        3. petal length in cm
        4. petal width in cm
        5. class:
            -- Iris Setosa
            -- Iris Versicolour
            -- Iris Virginica
    */
    float sepal_length;
    float sepal_width;
    float petal_length;
    float petal_width;
    int iris_class;
};

#endif // IRIS_H
