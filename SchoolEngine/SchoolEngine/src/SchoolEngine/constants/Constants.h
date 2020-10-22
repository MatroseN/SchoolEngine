#pragma once

#include "../util/Point.h"
#include "../components/Angle.h"
#include "../components/Velocity.h"
#include "../components/Acceleration.h"
#include "../components/Direction.h"

// Square
constexpr Point squareSpawnPos{300, 200};
constexpr Angle squareDefaultAngle{0};
constexpr Velocity squareVelocity{0.0f, 0.0f};
constexpr float squareMaxVelocity =  1000.0f;
constexpr Direction squareDefualtDirection{EntityDirection::NORTH};
constexpr float squareAcceleration = 1000.0f;