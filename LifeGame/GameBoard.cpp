#include "GameBoard.h"
#include <iostream>

bool GameBoard::getDot(int x, int y) const {
	const auto& temp = mat.at(x < 0 ? mat.size() + x : x % mat.size());
	return temp.at(y < 0 ? temp.size() + y : y % temp.size());
}

bool GameBoard::checkDot(int x, int y) const {
	int xs[] = { x + 1, x, x - 1 };
	int ys[] = { y + 1, y, y - 1 };

	int count = 0;

	for (int i = 0; i != 3; ++i)
		for (int j = 0; j != 3; ++j)
			if(!(i == 1 && j == 1))
				count += getDot(xs[i], ys[j]);

	return count == 3 || (getDot(x, y) ? count == 2 : false);
}

GameBoard::GameBoard(matrix mat) : mat(mat)
{}

const std::vector<std::vector<bool>>& GameBoard::getMatrix() const {
	return mat;
}

void GameBoard::iterate() {
	matrix temp(mat.size(), std::vector<bool>(mat.at(0).size()));
	for (int x = 0; x != mat.size(); ++x)
		for (int y = 0; y != mat.at(x).size(); ++y)
			temp.at(x).at(y) = checkDot(x, y);
	mat = std::move(temp);
}