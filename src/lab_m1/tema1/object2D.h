#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{

    Mesh* CreateSquare(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateSquare2(const std::string& name, glm::vec3 leftBottomCorner, float heigh,float width, glm::vec3 color, bool fill = false);

    Mesh* CreateTriangle(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, float body_angle,bool fill = false);
    Mesh* CreateTriangle2(const std::string& name, glm::vec3 leftBottomCorner, float length, float wing_length,glm::vec3 color, float body_angle,bool down, bool fill = false);

    Mesh* CreateCircle(const std::string& name, glm::vec3 center, float radius, int numberOfSides, glm::vec3 color,bool fill = false);
    Mesh* CreateCircle2(const std::string& name, glm::vec3 center, float radius, int numberOfSides, glm::vec3 color, bool fill = false);

    Mesh* CreateRomb(const std::string& name, glm::vec3 center, float radius, int numberOfSides, glm::vec3 color, bool fill = false);
}
