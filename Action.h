#pragma once
#include <string>

class Action
{
public:
	enum SIDE { LEFT, RIGHT };

	Action(int num_M_getting_off, int num_C_getting_off, Action::SIDE boat_side);
	~Action() {}

	int get_num_M_getting_off() const;
	int get_num_C_getting_off() const;
	Action::SIDE get_boat_side();

	void print_action();

private:
	int num_M_getting_off;
	int num_C_getting_off;
	Action::SIDE boat_side;
};
