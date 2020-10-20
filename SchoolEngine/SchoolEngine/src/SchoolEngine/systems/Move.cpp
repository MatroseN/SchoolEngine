#include "Move.h"

void move(entt::registry &reg) {
	auto view = reg.view<Position, Direction, Velocity>();
	for (const entt::entity entity : view) {
		Position& pos = view.get<Position>(entity).position;
		Velocity& velocity = view.get<Velocity>(entity).velocity;
		const Direction direction = view.get<Direction>(entity).direction;

		switch (direction.direction){
			case EntityDirection::NORTH: pos.position.Y -= velocity.velocity.Y;
				break;
			case EntityDirection::SOUTH: pos.position.Y += velocity.velocity.Y;
				break;
			case EntityDirection::WEST: pos.position.X += velocity.velocity.X;
				break;
			case EntityDirection::EAST: pos.position.X -= velocity.velocity.X;
				break;
			default:
				break;
		}
	}
}