
#pragma once

#include <random>
#include "Point_3D.h"


struct PointCloud
{
    Point_3D* begin = nullptr;
    unsigned size = 0u;
};

void print_cloud(PointCloud* cloud)
{
    for (int i = 0; i < cloud->size; i++)
    {
        std::cout << i + 1 << ": "; print_point(cloud->begin[i]); std::cout << std::endl;
    }
}

void create_cloud(PointCloud* new_cloud, unsigned N = 1)
{
    std::uniform_real_distribution<double> distrib(-1., 1.);
    std::default_random_engine random;

    Point_3D* points = new Point_3D[N];
    
    for (unsigned i = 0; i < N; i++)
    {
        points[i].x = distrib(random);
        points[i].y = distrib(random);
        points[i].z = distrib(random);
    }

    new_cloud = new PointCloud{points, N};
}

void delete_cloud(PointCloud* delete_cloud)
{
    delete[] delete_cloud->begin;
    delete_cloud->size = 0u;

    delete delete_cloud;
}

void merge_cloud(PointCloud* point_cloud1, PointCloud* point_cloud2)
{

}
