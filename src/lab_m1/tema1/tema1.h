#pragma once

#include "components/simple_scene.h"
#include "components/text_renderer.h"



namespace m1
{
    class tema1 : public gfxc::SimpleScene
    {
     public:
         tema1();
        ~tema1();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
        void RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color = glm::vec3(1.0f));
       
     protected:
        float cx, cy;
        glm::mat3 modelMatrix;
        glm::mat3 modelMatrix2;
        float translateX, translateY;
        float translateX2, translateY2;
        
        float angularStep1;
        float angularStep2;
        float angularStep3;
        glm::vec3 aripa1;
        glm::vec3 aripa2;
        glm::vec3 corp ;
        float body_heigh ;
        float head_radius;
        float body_angle;
        float cap_x ;
        float cap_y ;
        glm::vec3 cap;

        float cioc_x;
        float cioc_y ;
        glm::vec3 cioc;
        float wing_length;
        float angle;
        float angle2;
        
        int directie ;
        bool impuscat;
        float duck_len;
        float x_initial;
        float y_initial;
        float viteza;
        float viteza_initiala;
        float time;
        float heigh;
        float width;
        glm::vec3 cornerA;

        float scaleX;
        int vieti;
        int nr_gloante;
        int scor;
        float color;
        float x, y;
        int duck_counter;
        float tranx, trany;

    };

   
}   
