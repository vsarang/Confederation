/**
 * @file vector.h
 * @author Vikrant Sarang
 * @date May 2015
 */

#ifndef VECTOR_H
#define VECTOR_H

class Vector {
    public:
        int dim;

        Vector(int dim);
        Vector(const Vector & other);
        Vector(const float* & ref);
        ~Vector();
        Vector & operator=(const Vector & other);
        float operator[](int i) const;
        float & operator[](int i);
    private:
        float * vector;

        void copy(const Vector & other);
};

#endif //VECTOR_H
