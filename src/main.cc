#include <cmath>

#include <array>
#include <iostream>
#include <vector>

int main() {

  // Initialize Domain (rectangle) dimensions
  const double height = 5;
  const double width = 5;

  // Initialize spacing and number of points in each direction
  const double vertical_spacing = 1;
  const double horizontal_spacing = 1;
  unsigned nvertical_points, nhorizontal_points;

  // Determine the number of points in each direction
  nvertical_points = 1 + std::ceil(height / vertical_spacing);
  nhorizontal_points = 1 + std::ceil(width / horizontal_spacing);

  // Initialize the variable with the total number of points
  const int npoints = nvertical_points * nhorizontal_points;

  // Create a list of all the points
  std::vector<std::array<double, 2>> points;

  // Print mesh details
  std::cout << "total number of points: " << npoints << std::endl;
  std::cout << "total number of vertical points: " << nvertical_points
            << std::endl;
  std::cout << "total number of horizontal points: " << nhorizontal_points
            << std::endl;

  // Loop over all the vertical ('i' represents each column) and horizontal ('j'
  // represents each row) points and add each of them to the list of points by
  // assigning their position.
  for (int i = 0; i < nvertical_points; ++i) {
    for (int j = 0; j < nhorizontal_points; ++j) {
      // Declare an auxiliary point
      std::array<double, 2> aux_point;

      // assign the position to the auxiliary point
      aux_point.at(0) = j * horizontal_spacing;
      aux_point.at(1) = i * vertical_spacing;

      //add the auxiliary point to the list of points
      points.emplace_back(aux_point);
    }
  }

  // Print the (x,y) values of each point
  int i = 1;  // helps counting the points to be printed
  for (const auto& point : points) {
    std::cout << "Point #" << i << " (" << point.at(0) << "," << point.at(1)
              << ")\n";
    ++i;
  }
}
