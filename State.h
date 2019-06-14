#pragma once
#include "Action.h"

class State
{
public:
	State(int num_left_M, int num_left_C, int num_right_M, int num_right_C, Action::SIDE boat_side);
	~State();

	int get_num_left_M() const;
	int get_num_left_C() const;
	int get_num_right_M() const;
	int get_num_right_C() const;
	int get_num_M_on_side(Action::SIDE boat_side) const;
	int get_num_C_on_side(Action::SIDE boat_side) const;

	Action::SIDE get_boat_side() const;

	void set_num_left_M(int num_left_M);
	void set_num_left_C(int num_left_C);
	void set_num_right_M(int num_right_M);
	void set_num_right_C(int num_right_C);
	void set_boat_side(Action::SIDE boat_side);

	bool is_equal(State* state);
	void print_state();

	const static int MAX_NUM_ON_BOAT = 2;

private:
	int num_left_M;
	int num_left_C;
	int num_right_M;
	int num_right_C;
	Action::SIDE boat_side;
};
