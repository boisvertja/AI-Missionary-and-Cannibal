#include "stdafx.h"
#include "Problem.h"

void display(Node* root, std::vector<Node*> solution)
{
	std::cout << "Solution:" << std::endl;

	// Display the root node (no action needed)
	std::cout << "Root node: ";
	root->get_state()->print_state();
	std::cout << std::endl;

	// Reverse the ordering of the solutions vector so the actions display first -> last
	std::reverse(solution.begin(), solution.end());

	int step = 1;
	for (auto node = solution.begin(); node != solution.end(); node++)
	{
		std::cout << "Step: " << step << " ";
		std::cout << "State: ";
		(*node)->get_state()->print_state();
		std::cout << " Action: ";
		(*node)->print_action_to_node();
		step++;
		std::cout << std::endl;
	}
}

int main()
{
	Node* root = new Node(3, 3, 0, 0, Action::SIDE::LEFT);

	Problem problem;
	display(root, problem.solve(root));

    return 0;
}
