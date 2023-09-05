
#include <iostream>

#include "Point_3D.h"

#include "PointCloud.h"

int main()
{
    Point_3D A{0, 0, 0};
    Point_3D B{2, 2, 2};

    std::cout << "A: "; print_point(A); std::cout << std::endl;
    std::cout << "B: "; print_point(B); std::cout << std::endl;

    Point_3D C = middle(A, B);
    std::cout << "C: "; print_point(C); std::cout << std::endl;

    std::cout << "dist(A, B): " << distance(A, C) << std::endl;

    const Point_3D* points = new const Point_3D[4]{{1, -1, 0}, {1, 1, 0}, {-1, 1, 0}, {-1, -1, 0}};
    Point_3D center = center_of_mass(points, points + 4);

    std::cout << "center: "; print_point(center); std::cout << std::endl;





    PointCloud* cloud;
    create_cloud(cloud, 10);

    

    return 0;
}