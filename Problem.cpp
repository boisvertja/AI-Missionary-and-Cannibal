#include "stdafx.h"
#include "Problem.h"

Problem::Problem() {}

Problem::~Problem() {}

std::vector<Node*> Problem::solve(Node* root)
{
	// If the root node is the solution then add the node to the solution sequence and return the sequence
	if (is_goal(root))
	{
		std::cout << "Root is solution!" << std::endl;
		actions_to_current_node.push_back(root);
		return actions_to_current_node;
	}

	// Add the root node to the frontier
	frontier.push_back(root);

	while (true)
	{
		if (frontier.empty())
		{
			std::cerr << "ERROR::SOLUTION_NOT_FOUND!" << std::endl;
			return actions_to_current_node;
		}

		// Remove a node from the frontier
		Node* node = frontier.front();
		frontier.pop_front();

		// Add the node's state to the list of explored states
		explored.push_back(node->get_state());

		// Get the set of legal actions for the current node
		auto set = get_legal_actions(node);

		for (auto action = set.begin(); action != set.end(); action++)
		{
			// Create a child node from the current node and the action
			Node* child = child_node(node, *action);

			// Set the child node's action to get from its parent to it
			child->set_action_to_node(*action);

			// Check if the child's state is not in the explored or frontier
			bool is_in_explored = false;
			bool is_in_frontier = false;

			for (auto iter = explored.begin(); iter != explored.end(); iter++)
				if (child->get_state()->is_equal(*iter))
					is_in_explored = true;

			for (auto iter = frontier.begin(); iter != frontier.end(); iter++)
				if (child->get_state()->is_equal((*iter)->get_state()))
					is_in_frontier = true;

			if ((!is_in_explored) && (!is_in_frontier))
			{
				if (is_goal(child)) // Return list of actions to current node
				{
					std::cout << "Found goal!" << std::endl;
					return child->get_actions_to_node(child);
				}

				frontier.push_back(child);
			}
		}
	}
}

Node* Problem::child_node(Node* parent, Action* action)
{
	Node* child = new Node();

	// Set the child node's state equal to the parent node's
	child->set_state(parent->get_state());

	// Set the boat side for the child node to the side of the action
	child->get_state()->set_boat_side(action->get_boat_side());

	Action::SIDE action_side = action->get_boat_side();
	Action::SIDE other_side;
	if (action_side == Action::SIDE::LEFT) other_side = Action::SIDE::RIGHT;
	else other_side = Action::SIDE::LEFT;

	// Add the passengers from the boat to the corresponding values on the corresponding side
	child->set_M(action_side, child->get_M(action_side) + action->get_num_M_getting_off());
	child->set_C(action_side, child->get_C(action_side) + action->get_num_C_getting_off());

	// Decrement the number of individuals on the other side by the number getting off
	child->set_M(other_side, child->get_M(other_side) - action->get_num_M_getting_off());
	child->set_C(other_side, child->get_C(other_side) - action->get_num_C_getting_off());

	child->set_parent(parent);

	return child;
}

bool Problem::is_goal(Node* node)
{
	if (node->get_M(Action::LEFT) == 0 && node->get_C(Action::LEFT) == 0)
		return true;

	return false;
}

bool Problem::is_legal(Node* node)
{
	// Checks if the number of missionaries is less than the number of cannibals on any given side
	// when the number of missionaries is greater than or equal to 1
	if ((node->get_M(Action::LEFT) < node->get_C(Action::LEFT) && node->get_M(Action::LEFT) > 0) ||
		node->get_M(Action::RIGHT) < node->get_C(Action::RIGHT) && node->get_M(Action::RIGHT) > 0)
		return false;

	return true;
}

std::vector<Action*> Problem::get_legal_actions(Node* node)
{
	// check if legal is a function called in here
	std::vector<Action*> list_of_actions;

	// Get the current side of the boat
	Action::SIDE current_side = node->get_state()->get_boat_side();

	// Set the action's boat side to the opposite side of the parent node (each action alternates the boat's side)
	Action::SIDE other_side;
	if (current_side == Action::SIDE::LEFT)
		other_side = Action::SIDE::RIGHT;
	else
		other_side = Action::SIDE::LEFT;

	// Get maximum number of missionaries that can move
	int max_M = node->get_state()->get_num_M_on_side(current_side);

	// Get maximum number of cannibals that can move
	int max_C = node->get_state()->get_num_C_on_side(current_side);

	// Iterate through all possible combinations of movements and check if valid
	for(int m = 0; m <= max_M; m++)
	{
		for (int c = 0; c <= max_C; c++)
		{
			/* Check if the total number of passengers is less than or equal to the boat size
			   and there is at least 1 passenger on the boat */
			if ((m + c <= State::MAX_NUM_ON_BOAT) && (m + c >= 1))
			{
				// Create a new action for every combination
				Action* action = new Action(m, c, other_side);
				
				// Test if the new action is legal
				if (is_legal(child_node(node, action)))
					list_of_actions.push_back(action);
			}
		}
	}

	return list_of_actions;
}
