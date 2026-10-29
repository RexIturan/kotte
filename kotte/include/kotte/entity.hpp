#pragma once

#include "kotte/entity_handle.hpp"

#include <cstdint>
#include <optional>
#include <raylib.h>

namespace kotte
{
    enum class EntityKind : std::uint8_t {
        player,
        bomb,
        crate,
        enemy,
        pickup
    };

    enum class CardinalDirection : std::uint8_t {
        up,
        right,
        down,
        left
    };

    struct BombState final {
        EntityHandle owner;
        float fuse_remaining = 0.0f;
        std::uint8_t blast_range = 0;
        bool detonation_requested = false;
        bool owner_cleared = false;
    };
    
    struct HealthState final {
        int health = 0;
        int max_health = 0;
        bool is_dead = false;
    };
    
    struct StatsState final {
        std::uint8_t bomb_reach = 0;
        std::uint8_t max_bomb_reach = 0;
        int bomb_count = 1;
    };

    struct Entity final {
        EntityKind kind = EntityKind::crate;
        Vector2 world_position{};
        CardinalDirection movement_heading = CardinalDirection::right;
        std::optional<BombState> bomb_state;
        std::optional<HealthState> health_state;
        std::optional<StatsState> stats_state;
    };
}
