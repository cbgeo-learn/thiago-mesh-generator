#include <array>
#include <cmath>
#include <iostream>
#include <vector>

int main() {

	// Initialize the variables
	double vertical_spacing, horizontal_spacing;
	int num_vertical_points, num_horizontal_points;
	int num_points;
	
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

	// Check mesh type choice
	if (choice == 1) {
		// Prompt the user for the maximum spacing between adjacent points
		std::cout << "What is the maximum spacing between points?\n";
		std::cout << "Horizontal spacing: ";
		std::cin  >> horizontal_spacing;
		std::cout << "vertical spacing: ";
		std::cin >> vertical_spacing;

		// Create the list of points
		num_vertical_points = 1 + std::ceil(height/vertical_spacing);
		num_horizontal_points = 1 + std::ceil(width/horizontal_spacing);				
	} else {	
		// Prompt the user for the number of points in each direction
		std::cout << "How many points in the horizontal direction? ";
		std::cin >> num_horizontal_points;
		std::cout << "How many points in the vertical direction? ";
		std::cin >> num_vertical_points;
	}

	// Update the size of each horizontal or vertical spacing
	horizontal_spacing = width/(num_horizontal_points - 1);
	vertical_spacing = height/(num_vertical_points - 1);

	// Create the list of points
	num_points = num_vertical_points * num_horizontal_points;
	std::vector<std::array<double,2>> list_of_points;

	// Print mesh details
	std::cout << "total number of points: " << num_points << std::endl;
	std::cout << "total number of vertical points: " << num_vertical_points << std::endl;
	std::cout << "total number of horizontal points: " << num_horizontal_points << std::endl;

	int point = 0; // variable that indicates the point number in the list
		       // of points and increases as each point is created.

	// Loop over all the vertical ('i' represents each column) and horizontal ('j'
	// represents each row) points.
	for (int i=0;i<num_vertical_points;++i) {
		for (int j=0;j<num_horizontal_points;++j) {
			// Create a point at the (i+1)-th column and (j+1)-th row of 
			// points. This point is assigned a vertical and horizontal coordinate.
			list_of_points.push_back({j*horizontal_spacing,i*vertical_spacing});
			++point;
		}
	}

	// Print the (x,y) values of each point
	int i=1; // helps counting the points to be printed	
	for (auto chosen_point:list_of_points) {
		std::cout << "Point #" << i << " (" << chosen_point[0] << "," << chosen_point[1] << ")\n";
		++i;
	}
}
