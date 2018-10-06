#include <iostream>
#include <math.h>
#include <vector>
#include <array>

int main() {

	// Initializing the variables
	float height, width;
	float element_height, element_width;
	int num_vertical_elements, num_horizontal_elements;
	int num_nodes;
	int node;
	int choice;
	std::cout << "Point generator" << std::endl;
	std::cout << "This program generates points within a given rectangle" << std::endl;
	std::cout << "according to a given mesh." << std::endl << std::endl;

	// Prompting the user for the type of meshing he wants to do
	std::cout << "What type of meshing do you want to do\? " << std::endl;
	std::cout << "1) set a maximum size for each element. " << std::endl;
	std::cout << "2) set the number of elements in each direction. " << std::endl;
	std::cout << "Choice: ";
	std::cin >> choice;

	// Asking the user for the size of the rectangle
	std::cout << "What are the dimensions of your rectangle\?" << std::endl;
	std::cout << "width: ";
	std::cin >> width;
	std::cout << "height: ";
	std::cin >> height;

	// Checking mesh type choice
	if (choice == 1)
	{
		// Prompting the user forrr the maximum size o elements
		std::cout << "What are the maximum dimensions of each element/?" <<  std::endl;
		std::cout << "width of element: ";
		std::cin  >> element_width;
		std::cout << "height of element: ";
		std::cin >> element_height;

		// Creating the list of nodes (or points)
		num_vertical_elements = std::ceil(height/element_height);
		num_horizontal_elements = std::ceil(width/element_width);				
	} else 
	{	
		// Prompt the user for the number of elements in each direction
		std::cout << "How many elements in the horizontal direction\?";
		std::cin >> num_horizontal_elements;
		std::cout << "How many elements in the vertical direction\?";
		std::cin >> num_vertical_elements;
	}

	// Update the size oooff each element
	element_width = width/num_horizontal_elements;
	element_height = height/num_vertical_elements;

	// Creating the list of nodes (or points)
	num_nodes = (num_vertical_elements + 1)*(num_horizontal_elements + 1);
	std::vector<std::array<float,2>> list_of_nodes;

	// Printing mesh details
	std::cout << "total number of points/nodes: " << num_nodes << std::endl;
	std::cout << "total number of vertical elements: " << num_vertical_elements << std::endl;
	std::cout << "total number of horizontal elements: " << num_horizontal_elements << std::endl;

	// Generating points by using a loop along the vertical and horizontal
	// directions of  the rectangle
	node = 0;
	for (int i=0;i<=num_vertical_elements;i++)
	{
		for (int j=0;j<=num_horizontal_elements;j++)
		{			
			list_of_nodes.push_back({j*element_width,i*element_height});
			if (j==num_horizontal_elements)
				list_of_nodes[node][0] = width;
			if (i==num_vertical_elements)
				list_of_nodes[node][1] = height;
			node++;
		}
	}

	// Printing the (x,y) values of each node/point
	node = 0;
	for (;node<num_nodes;node++)
	{
		std::cout << "Point #" << node+1 << " (" << list_of_nodes[node][0] << "," << list_of_nodes[node][1] << ")" << std::endl;
	}
}
