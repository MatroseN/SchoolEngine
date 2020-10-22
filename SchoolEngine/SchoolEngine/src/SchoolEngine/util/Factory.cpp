#include "Factory.h"
#include "../entities/Square.h"
#include "../constants/Constants.h"
#include "../util/Point.h"
#include "../util/Vector2.h"
#include "../components/Angle.h"

entt::entity makeSquare(entt::registry &reg, Vector2 size) {
	const entt::entity entity = reg.create();
	reg.emplace<Square>(entity);
	reg.emplace<Point>(entity, squareSpawnPos);
	reg.emplace<Vector2>(entity, size);
	reg.emplace<Angle>(entity, squareDefaultAngle);
	reg.emplace<Velocity>(entity, squareVelocity);
	reg.emplace<Direction>(entity, squareDefualtDirection);
	reg.emplace<Acceleration>(entity, 0.0f);
	return entity;
}