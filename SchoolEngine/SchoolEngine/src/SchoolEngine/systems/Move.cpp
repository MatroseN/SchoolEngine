#include "Move.h"

void move(entt::registry &reg) {
	auto view = reg.view<Point, Direction, Velocity>();
	for (const entt::entity entity : view) {
		Point& pos = view.get<Point>(entity);
		Velocity& velocity = view.get<Velocity>(entity);
		const Direction direction = view.get<Direction>(entity);

		switch (direction.direction){
			case EntityDirection::NORTH: pos.Y -= velocity.velocity.Y;
				break;
			case EntityDirection::SOUTH: pos.Y += velocity.velocity.Y;
				break;
			case EntityDirection::WEST: pos.X += velocity.velocity.X;
				break;
			case EntityDirection::EAST: pos.X -= velocity.velocity.X;
				break;
			default:
				break;
		}
	}
}