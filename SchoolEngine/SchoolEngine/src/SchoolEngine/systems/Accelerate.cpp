#include "Accelerate.h"

void accelerate(entt::registry& reg) {
	auto view = reg.view<Acceleration, Velocity>();
	for (const entt::entity entity : view) {
		Acceleration& accel = view.get<Acceleration>(entity);
		Velocity& velocity = view.get<Velocity>(entity);

		if(accel.acceleration.X < accel.max)
			velocity.velocity.X += accel.acceleration.X;

		if(accel.acceleration.Y < accel.max)
			velocity.velocity.Y += accel.acceleration.Y;
	}
}