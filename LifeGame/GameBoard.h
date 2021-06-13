#include <vector>

#pragma once

class GameBoard
{
private:
	using matrix = std::vector<std::vector<bool>>;

	matrix mat;

	bool getDot(int x, int y) const;
	bool checkDot(int x, int y) const;
public:
	GameBoard(matrix mat);
	const matrix& getMatrix() const;
	void iterate();
};