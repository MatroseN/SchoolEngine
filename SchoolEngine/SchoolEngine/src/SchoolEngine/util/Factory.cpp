#include "Factory.h"
#include "../components/Position.h"
#include "../entities/Square.h"
#include "../constants/Constants.h"

entt::entity makeSquare(entt::registry &reg) {
	const entt::entity entity = reg.create();
	reg.emplace<Square>(entity);
	reg.emplace<Position>(entity, squareSpawnPos);
	return entity;
}