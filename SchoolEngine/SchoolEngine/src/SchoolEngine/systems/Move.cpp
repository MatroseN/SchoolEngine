#include "Move.h"
#include "../constants/Constants.h"
#include <iostream>

void move(entt::registry &reg, float deltaTime) {
	auto view = reg.view<Square, Point, Direction, Velocity>();
	for (const entt::entity entity : view) {
		Point& pos = view.get<Point>(entity);
		Velocity& velocity = view.get<Velocity>(entity);
		const Direction direction = view.get<Direction>(entity);

		switch (direction.direction){
			case EntityDirection::NORTH: pos.Y += -velocity.velocity.Y * deltaTime;
				break;
			case EntityDirection::SOUTH: pos.Y += velocity.velocity.Y * deltaTime;
				break;
			case EntityDirection::WEST: pos.X += -squareAcceleration * deltaTime;
				break;
			case EntityDirection::EAST: pos.X += squareAcceleration * deltaTime;
				break;
			default:
				break;
		}
	}
}