#ifndef HEADER_H
#define HEADER_H

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

constexpr size_t numberOfPoints = 10;

/**
 * Classe représentant un point en 3D avec des coordonnées x, y et z.
 */
class Point3D {
private:
    float x, y, z;

public:
    Point3D();
    Point3D(const float &newx, const float &newy, const float &newz);

    void setXYZ(const float &newx, const float &newy, const float &newz);
    void setX(const float &newx);
    void setY(const float &newy);
    void setZ(const float &newz);

    float getX() const;
    float getY() const;
    float getZ() const;

    void print() const;
    float distanceTo(const Point3D &otherPoint3D) const;
};

/**
 * Classe représentant une trajectoire composée de plusieurs points en 3D.
 */
class Trajectory {
private:
    Point3D points[numberOfPoints];

public:
    void print() const;
    Point3D& getPoint(const int &n);
    float getTotalDistance() const;
};

// Classe My_vector
typedef float my_type;

/**
 * Classe représentant un vecteur de type spécifié.
 */
class My_vector {
private:
    size_t size;
    my_type *tab;

public:
    My_vector();
    My_vector(const size_t &size);
    My_vector(const My_vector &other);
    ~My_vector();

    const size_t &get_size() const;
    void set_an_element(const size_t &index, const my_type &val);
    const my_type &get_an_element(const size_t &index) const;
    void push(const my_type &val);
};

#endif
