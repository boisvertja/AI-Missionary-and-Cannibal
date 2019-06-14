#include "stdafx.h"
#include "State.h"

State::State(int num_left_M, int num_left_C, int num_right_M, int num_right_C, Action::SIDE boat_side)
{
	this->num_left_M = num_left_M;
	this->num_left_C = num_left_C;
	this->num_right_M = num_right_M;
	this->num_right_C = num_right_C;
	this->boat_side = boat_side;
}

State::~State() {}

int State::get_num_left_M() const
{
	return num_left_M;
}

int State::get_num_left_C() const
{
	return num_left_C;
}

int State::get_num_right_M() const
{
	return num_right_M;
}

int State::get_num_right_C() const
{
	return num_right_C;
}

Action::SIDE State::get_boat_side() const
{
	return boat_side;
}

int State::get_num_M_on_side(Action::SIDE boat_side) const
{
	if (boat_side == Action::SIDE::LEFT)
		return num_left_M;
	else
		return num_right_M;
}

int State::get_num_C_on_side(Action::SIDE boat_side) const
{
	if (boat_side == Action::SIDE::LEFT)
		return num_left_C;
	else
		return num_right_C;
}

void State::set_num_left_M(int num_left_M)
{
	this->num_left_M = num_left_M;
}

void State::set_num_left_C(int num_left_C)
{
	this->num_left_C = num_left_C;
}

void State::set_num_right_M(int num_right_M)
{
	this->num_right_M = num_right_M;
}

void State::set_num_right_C(int num_right_C)
{
	this->num_right_C = num_right_C;
}

void State::set_boat_side(Action::SIDE boat_side)
{
	this->boat_side = boat_side;
}

bool State::is_equal(State* state)
{
	if ((num_left_M == state->get_num_left_M()) &&
		(num_left_C == state->get_num_left_C()) &&
		(num_right_M == state->get_num_right_M()) &&
		(num_right_C == state->get_num_right_C()) &&
		(boat_side == state->get_boat_side()))
		return true;
	else
		return false;
}

void State::print_state()
{
	std::cout << "M: " << num_left_M << " C: " << num_left_C << "  <==>  M: " << num_right_M << " C: " << num_right_C << " Boat: ";
	if (boat_side == Action::SIDE::LEFT)
		std::cout << "Left  ";
	else
		std::cout << "Right ";
}
