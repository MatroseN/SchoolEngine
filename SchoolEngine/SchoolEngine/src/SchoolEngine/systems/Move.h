#pragma once
#include <entt.hpp>
#include "../components/Acceleration.h"
#include "../components/Velocity.h"
#include "../components/Direction.h"
#include "../util/Point.h"
#include "../entities/Square.h"

void move(entt::registry &, float deltaTime);