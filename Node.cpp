#include "stdafx.h"
#include "Node.h"

Node::Node() 
{
	state = new State(0, 0, 0, 0, Action::SIDE::LEFT);
}

Node::Node(int m1, int c1, int m2, int c2, Action::SIDE boat_side)
{
	state = new State(m1, c1, m2, c2, boat_side);
}

Node::~Node() {}

void Node::set_parent(Node* parent)
{
	this->parent = parent;
}

void Node::set_state(State* state)
{
	this->state->set_boat_side(state->get_boat_side());
	this->state->set_num_left_C(state->get_num_left_C());
	this->state->set_num_left_M(state->get_num_left_M());
	this->state->set_num_right_C(state->get_num_right_C());
	this->state->set_num_right_M(state->get_num_right_M());
}

void Node::set_action_to_node(Action* action_to_node)
{
	this->action_to_node = action_to_node;
}

void Node::print_action_to_node()
{
	action_to_node->print_action();
}

void Node::set_M(Action::SIDE side, int m)
{
	if (side == Action::LEFT)
		state->set_num_left_M(m);
	else
		state->set_num_right_M(m);
}

void Node::set_C(Action::SIDE side, int c)
{
	if (side == Action::LEFT)
		state->set_num_left_C(c);
	else
		state->set_num_right_C(c);
}

void Node::set_state(int m1, int c1, int m2, int c2, Action::SIDE boat_side)
{
	state->set_num_left_M(m1);
	state->set_num_right_M(m2);
	state->set_num_left_C(c1);
	state->set_num_right_C(c2);
	state->set_boat_side(boat_side);
}

Node* Node::get_parent() const
{
	return parent;
}

int Node::get_M(Action::SIDE side) const
{
	if (side == Action::LEFT)
		return state->get_num_left_M();
	else
		return state->get_num_right_M();
}

int Node::get_C(Action::SIDE side) const
{
	if (side == Action::LEFT)
		return state->get_num_left_C();
	else
		return state->get_num_right_C();
}

State* Node::get_state() const
{
	return state;
}

std::vector<Node*> Node::get_actions_to_node(Node* node)
{
	State* root = new State(3, 3, 0, 0, Action::SIDE::LEFT);
	std::vector<Node*> nodes;

	// While the node's state is not equal to root
	while (!node->get_state()->is_equal(root))
	{
		// Add the node to the list of nodes
		nodes.push_back(node);

		// Set node equal to node's parent node
		node = node->get_parent();
	}
	return nodes;
}
