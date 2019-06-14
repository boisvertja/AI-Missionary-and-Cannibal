#pragma once
#include <algorithm>

#include "Action.h"
#include "State.h"

class Node
{
public:
	Node();
	Node(int m1, int c1, int m2, int c2, Action::SIDE boat_side);
	~Node();

	int get_M(Action::SIDE side) const;
	int get_C(Action::SIDE side) const;
	State* get_state() const;
	Node* get_parent() const;

	std::vector<Node*> get_actions_to_node(Node* node);
	void set_M(Action::SIDE side, int m);
	void set_C(Action::SIDE side, int c);
	void set_state(int m1, int c1, int m2, int c2, Action::SIDE boat_side);
	void set_parent(Node* parent);
	void set_state(State* state);
	void set_action_to_node(Action* action);
	void print_action_to_node();

private:
	Node* parent;
	State* state;
	Action* action_to_node;
};
