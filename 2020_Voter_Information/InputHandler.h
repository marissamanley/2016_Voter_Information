#pragma once
/*
 * The purpose of this class is to handle all user input.
 * Each method handles information each possible output option.
 */
class InputHandler
{
private:
	TimeMeasure meas;
	std::string presidentDem = "Joe Biden";
	std::string presidentRep = "Donald Trump";
	int sortInput = -1;
public:
	void Start();
	void nationalInfoMap();
	void nationalInfoTree();
	void nationalSenatorialData();
	void dataAccess();
	void stateSelect(int input);
};

