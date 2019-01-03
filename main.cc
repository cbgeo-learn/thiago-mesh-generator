#include <cmath>

#include <array>
#include <iostream>
#include <vector>

int main() {

  // Introduce user to the point-generator
  std::cout << "Point generator\n";
  std::cout << "This program generates points within a given rectangle \n";
  std::cout << "according to a given mesh.\n\n";

  // Prompt the user for the type of point generation he wants to do
  std::cout << "What type of point generation do you want to do? \n";
  std::cout << "1) set a maximum size for the spacing between points.\n";
  std::cout << "2) set the number of points in each direction.\n";
  std::cout << "Choice: ";
  int choice;
  std::cin >> choice;

  // Ask the user for the size of the rectangle
  double height, width;
  std::cout << "What are the dimensions of your rectangle?\n";
  std::cout << "width: ";
  std::cin >> width;
  std::cout << "height: ";
  std::cin >> height;

  // Initialize spacing and number of points in each direction
  double vertical_spacing, horizontal_spacing;
  unsigned int nvertical_points, nhorizontal_points;

  // Check mesh type choice
  if (choice == 1) {
    // Prompt the user for the maximum spacing between adjacent points
    std::cout << "What is the maximum spacing between points?\n";
    std::cout << "Horizontal spacing: ";
    std::cin >> horizontal_spacing;
    std::cout << "Vertical spacing: ";
    std::cin >> vertical_spacing;

    // Determine the number of points in each direction
    nvertical_points = 1 + std::ceil(height / vertical_spacing);
    nhorizontal_points = 1 + std::ceil(width / horizontal_spacing);
  } else {
    // Prompt the user for the number of points in each direction
    std::cout << "How many points in the horizontal direction? ";
    std::cin >> nhorizontal_points;
    std::cout << "How many points in the vertical direction? ";
    std::cin >> nvertical_points;
  }

  // Update the size of each horizontal or vertical spacing
  horizontal_spacing = width / (nhorizontal_points - 1);
  vertical_spacing = height / (nvertical_points - 1);

  // Initialize the variables with the total number of points
  const int npoints = nvertical_points * nhorizontal_points;

  // Create a list of all the points
  std::vector<std::array<double, 2>> points;

  // Print mesh details
  std::cout << "total number of points: " << npoints << std::endl;
  std::cout << "total number of vertical points: " << nvertical_points
            << std::endl;
  std::cout << "total number of horizontal points: " << nhorizontal_points
            << std::endl;

  // Declare an auxiliary point
  std::array<double, 2> aux_point;

  // Loop over all the vertical ('i' represents each column) and horizontal ('j'
  // represents each row) points and add each of them to the list of points by
  // assigning their position.
  for (int i = 0; i < nvertical_points; ++i)
    for (int j = 0; j < nhorizontal_points; ++j) {
      aux_point.at(0) = j * horizontal_spacing;
      aux_point.at(1) = i * vertical_spacing;
      points.emplace_back(aux_point);
    }

  // Print the (x,y) values of each point
  int i = 1;  // helps counting the points to be printed
  for (auto& point : points) {
    std::cout << "Point #" << i << " (" << point.at(0) << "," << point.at(1)
              << ")\n";
    ++i;
  }
}
