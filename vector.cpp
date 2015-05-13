/**
 * @file vector.cpp
 * @author Vikrant Sarang
 * @date May 2015
 */

#include "vector.h"

Vector::Vector(int dim) {
    (*this).dim = dim;
    vector = new float[dim];
    for (int i = 0; i < dim; i++) {
        vector[i] = 0.;
    }
}

Vector::Vector(const Vector & other) {
    copy(other);
}

Vector::Vector(const float* & ref) {
    (*this).dim = sizeof(ref)/sizeof(*ref);
    vector = new float[dim];
    for (int i = 0; i < dim; i++) { 
        vector[i] = ref[i];
    }
}

Vector::~Vector() {
    // nothing
}

Vector & Vector::operator=(const Vector & other) {
    copy(other);
    return *this;
}

float Vector::operator[](int i) const {
    return vector[i];
}

float & Vector::operator[](int i) {
    return vector[i];
}

void Vector::copy(const Vector & other) {
    (*this).dim = other.dim;
    vector = new float[other.dim];
    for (int i = 0; i < dim; i++) {
        vector[i] = other[i];
    }
}
