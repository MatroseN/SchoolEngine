#include "Factory.h"
#include "../entities/Square.h"
#include "../constants/Constants.h"
#include "../util/Point.h"

entt::entity makeSquare(entt::registry &reg) {
	const entt::entity entity = reg.create();
	reg.emplace<Square>(entity);
	reg.emplace<Point>(entity, squareSpawnPos);
	return entity;
}