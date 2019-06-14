#pragma once
#include "Node.h"
#include <deque>
#include <stdexcept>

class Problem
{
public:
	Problem();
	~Problem();

	std::vector<Node*> solve(Node* root);

private:
	Node* child_node(Node* parent, Action* action);
	std::vector<Action*> get_legal_actions(Node* node);
	bool is_goal(Node* node);
	bool is_legal(Node* node);

	std::deque<Node*> frontier;
	std::vector<Node*> actions_to_current_node = std::vector<Node*>();

	// Vector of every explored node's state
	std::vector<State*> explored = std::vector<State*>();
};
