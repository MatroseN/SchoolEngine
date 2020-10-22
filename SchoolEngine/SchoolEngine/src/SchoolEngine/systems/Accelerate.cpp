#include "Accelerate.h"
#include "../constants/Constants.h"

void accelerate(entt::registry& reg, float deltaTime) {
	auto view = reg.view<Velocity, Acceleration>();
	for (const entt::entity entity : view) {
		Velocity& velocity = view.get<Velocity>(entity);
		Acceleration& acceleration = view.get<Acceleration>(entity);

		velocity.velocity.X += squareAcceleration * deltaTime;

		if (velocity.velocity.X >= squareMaxVelocity) {
			velocity.velocity.X = squareMaxVelocity;
		}

		velocity.velocity.Y += squareAcceleration * deltaTime;

		if (velocity.velocity.Y >= squareMaxVelocity) {
			velocity.velocity.Y = squareMaxVelocity;
		}
	}
}