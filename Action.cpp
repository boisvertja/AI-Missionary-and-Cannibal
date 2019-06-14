#include "stdafx.h"
#include "Action.h"

Action::Action(int num_M_getting_off, int num_C_getting_off, SIDE boat_side)
{
	this->num_M_getting_off = num_M_getting_off;
	this->num_C_getting_off = num_C_getting_off;
	this->boat_side = boat_side;
}

int Action::get_num_M_getting_off() const
{
	return num_M_getting_off;
}

int Action::get_num_C_getting_off() const
{
	return num_C_getting_off;
}

Action::SIDE Action::get_boat_side()
{
	return boat_side;
}

void Action::print_action()
{
	std::string side;
	if (boat_side == Action::SIDE::LEFT)
		side = "LEFT";
	else
		side = "RIGHT";

	std::cout << "M: " << num_M_getting_off << " C: " << num_C_getting_off << " Other Side: " << side << " ";
}
