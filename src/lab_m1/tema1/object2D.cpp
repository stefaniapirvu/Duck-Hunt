#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"



Mesh* object2D::CreateSquare2(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float heigh,
    float width,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(width, 0, 0), color),
        VertexFormat(corner + glm::vec3(width, heigh, 0), color),
        VertexFormat(corner + glm::vec3(0, heigh, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}


Mesh* object2D::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}



Mesh* object2D::CreateTriangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    float body_angle,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length , length * tan(body_angle), 0), color),
        VertexFormat(corner + glm::vec3(0, 2 * length * tan(body_angle), 0), color),
       
    };

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2};

    if (!fill) {
        triangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
     
        indices.push_back(2);
    }

    triangle->InitFromData(vertices, indices);
    return triangle;
}

Mesh* object2D::CreateTriangle2(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    float wing_length,
    glm::vec3 color,
    float body_angle,
    bool down,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    if (!fill) {
        triangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        indices.push_back(2);
    }

    if (down) {
        std::vector<VertexFormat> vertices =
        {
            VertexFormat(corner, color),
            VertexFormat(corner + glm::vec3(-wing_length ,-tan(body_angle) * wing_length , 0), color),
            VertexFormat(corner + glm::vec3(-wing_length * 2 / 3,   -wing_length * 1.5, 0), color),

        };
        triangle->InitFromData(vertices, indices);

    }
    else {
        std::vector<VertexFormat> vertices =
        {
            VertexFormat(corner, color),
            VertexFormat(corner + glm::vec3(-wing_length ,tan(body_angle) * wing_length , 0), color),
            VertexFormat(corner + glm::vec3(-wing_length * 2 / 3,   wing_length * 1.5, 0), color),

           
        };
        triangle->InitFromData(vertices, indices);
    }
   

  
    return triangle;
}


Mesh* object2D::CreateCircle(
    const std::string& name,
    glm::vec3 center,
    float radius,
    int numberOfSides,
    glm::vec3 color,
    bool fill)
{
    float doublePI = 2.0f * M_PI;
    glm::vec3 Circle_center = center;
    int numberOfVerices = numberOfSides;
    std::vector<VertexFormat> vertices;
    vertices.push_back(VertexFormat(Circle_center, color));
    for (int i = 0; i <= numberOfVerices; i ++) {
       
        vertices.push_back(VertexFormat(Circle_center+ glm::vec3(radius * cos(i * doublePI / numberOfSides), radius * sin(i * doublePI / numberOfSides), 0), color));

        
    }

    Mesh* circle = new Mesh(name);
    std::vector<unsigned int> indices; 
    for (int i = 0; i <= numberOfVerices-1; i++) {
        indices.push_back(0);
        indices.push_back(i+1);
        indices.push_back(i+2);
    }

    circle->SetDrawMode(GL_TRIANGLES);
    
    circle->InitFromData(vertices, indices);
    return circle;
}


Mesh* object2D::CreateCircle2(
    const std::string& name,
    glm::vec3 center,
    float radius,
    int numberOfSides,
    glm::vec3 color,
    bool fill)
{
    float doublePI = 2.0f * M_PI;
    glm::vec3 Circle_center = center;
    int numberOfVerices = numberOfSides;
    std::vector<VertexFormat> vertices;
   
    for (int i = 0; i <= numberOfVerices-1; i++) {

        vertices.push_back(VertexFormat(Circle_center + glm::vec3(radius * cos(i * doublePI / numberOfSides), radius * sin(i * doublePI / numberOfSides), 0), color));

    }

    Mesh* circle = new Mesh(name);
    std::vector<unsigned int> indices;
    for (int i = 0; i <= numberOfVerices +2; i++) {
    
        indices.push_back(i + 1);
        indices.push_back(i + 2);
    }
    vertices.push_back(VertexFormat(Circle_center + glm::vec3(0, 0, 0), color));
    vertices.push_back(VertexFormat(Circle_center + glm::vec3(0,-radius, 0), color));
    vertices.push_back(VertexFormat(Circle_center + glm::vec3(0, radius, 0), color));
    vertices.push_back(VertexFormat(Circle_center + glm::vec3(0, 0, 0), color));
    vertices.push_back(VertexFormat(Circle_center + glm::vec3(-radius , 0, 0), color));


    circle->SetDrawMode(GL_LINE_STRIP);

    circle->InitFromData(vertices, indices);
    return circle;
}



Mesh* object2D::CreateRomb(
    const std::string& name,
    glm::vec3 center,
    float radius,
    int numberOfSides,
    glm::vec3 color,
    bool fill)
{
    float doublePI = 2.0f * M_PI;
    glm::vec3 Circle_center = center;
    int numberOfVerices = (numberOfSides+2)*3;
    std::vector<VertexFormat> vertices;
    
    for (int i = 0; i <= numberOfVerices; i++) {
        vertices.push_back(VertexFormat(Circle_center + glm::vec3(radius * cos(i * doublePI / numberOfSides), 0, 0), color));
        vertices.push_back(VertexFormat(Circle_center + glm::vec3(0, radius * sin(i * doublePI / numberOfSides), 0), color));
        vertices.push_back(VertexFormat(Circle_center, color));
      
    }

    Mesh* romb = new Mesh(name);
    std::vector<unsigned int> indices;
    for (int i = 0; i <= numberOfVerices; i++) {
        indices.push_back(i);
      
    }

    romb->InitFromData(vertices, indices);
    return romb;
}