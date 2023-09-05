
#pragma once

#include <cmath>
#include <iostream>

struct Point_3D
{
    double x, y, z;
};

void print_point(const Point_3D& A)
{
    std::cout << "{ " << A.x << ", " << A.y << ", " << A.z << " }";
}

Point_3D middle(const Point_3D& A, const Point_3D& B)
{
    Point_3D mid{(A.x + B.x)/2, (A.y + B.y)/2, (A.z + B.z)/2};
    return mid;
}

double distance(const Point_3D& A, const Point_3D& B)
{
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2) + pow(A.z - B.z, 2));
}

Point_3D center_of_mass(Point_3D const * const begin, Point_3D const * const end)
{
    unsigned count = 0;
    Point_3D sum_of_points{0, 0, 0};

    for (const Point_3D* iter = begin; iter != end; iter++)
    {
        count++;

        sum_of_points.x += iter->x;
        sum_of_points.y += iter->y;
        sum_of_points.z += iter->z;
    }

    sum_of_points.x /= count;
    sum_of_points.y /= count;
    sum_of_points.z /= count;

    return sum_of_points;
}


