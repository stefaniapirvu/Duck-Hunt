#include "lab_m1/tema1/tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"
#include "components/text_renderer.h"

#include "math.h"


using namespace std;
using namespace m1;


tema1::tema1()
{
}


tema1::~tema1()
{
}


void tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);
    

    
    
     x_initial =200;
    float random = 2.8 + (rand() % 6);
    if (x_initial < resolution.x/2) {
        angle = M_PI / random;
    }
    else {
        angle = M_PI_2 + M_PI / random;
       
    }
    y_initial = 15;
    corp = glm::vec3(x_initial, y_initial, 0);
    time = 0;

    vieti = 3;
    nr_gloante = 3;
    directie = 0;
    body_heigh = 100;
    head_radius = 30;
    viteza = 400;
    viteza_initiala = viteza;
    scor = 0;

    body_angle = 0.3;
    impuscat = false;
    duck_counter = 1;

    cap_x = body_heigh - body_heigh * 0.15 + head_radius;
    cap_y = body_heigh * tan(body_angle);
    cap = corp + glm::vec3(cap_x, cap_y, 0);

    cioc_x = cap_x + head_radius;
    cioc_y = cap_y - head_radius/2.7;
    cioc = corp + glm::vec3(cioc_x, cioc_y, 0);


    aripa1 = corp + glm::vec3(body_heigh * 2 / 3, body_heigh *tan(body_angle) * 2 / 3, 0);
    aripa2 = corp + glm::vec3(body_heigh * 2 / 3, body_heigh * tan(body_angle) * 4 / 3, 0);

    wing_length = body_heigh / 3;
   
    cx = body_heigh /2;
    cy = body_heigh /2;
    translateX = 0;
    translateY = 0;
    translateY2 = 0;
    tranx = 0;
    trany = 0;
    scaleX = 1;
    
    angularStep1 = 0;
    angularStep2 = 0;
    angularStep3 = 0;
    color = 0;
    Mesh* head = object2D::CreateCircle("head", cap, head_radius, 360, NormalizedRGB(255,105,180), true);
    AddMeshToList(head);

    Mesh* body = object2D::CreateTriangle("body", corp, body_heigh, NormalizedRGB(255, 105, 180),body_angle, true);
    AddMeshToList(body);

  
    Mesh* beak = object2D::CreateTriangle("beak", cioc, head_radius / 2.7, NormalizedRGB(128, 0,0), 0.523, true);
    AddMeshToList(beak);


    Mesh* wing1 = object2D::CreateTriangle2("wing1", aripa1,body_heigh, wing_length, glm::vec3(1, 1, 0), body_angle,true, true);
    AddMeshToList(wing1);

    Mesh* wing2 = object2D::CreateTriangle2("wing2", aripa2, body_heigh, wing_length, glm::vec3(1, 1, 0), body_angle, false, true);
    AddMeshToList(wing2);


    heigh = wing_length + 2 * body_heigh * tan(body_angle);
    width = body_heigh + (head_radius * 2);
    cornerA = corp + glm::vec3(0, -wing_length / 2, 0);

   
    glm::vec3 romburi( 15,resolution.y -30 , 0);
    Mesh* romb1 = object2D::CreateRomb("romb1", romburi, 20, 360, NormalizedRGB(142, 36, 170), true);
    AddMeshToList(romb1);
    Mesh* romb2 = object2D::CreateRomb("romb2", romburi + glm::vec3(40,0,0), 20, 360, NormalizedRGB(142, 36, 170), true);
    AddMeshToList(romb2);
    Mesh* romb3 = object2D::CreateRomb("romb3", romburi + glm::vec3(80, 0, 0), 20, 360, NormalizedRGB(142, 36, 170), true);
    AddMeshToList(romb3);

    glm::vec3 gloante(15, resolution.y - 70, 0);
    Mesh* glont1 = object2D::CreateCircle("glont1", gloante, 15, 360, NormalizedRGB(255, 255, 0), true);
    AddMeshToList(glont1);
    Mesh* glont2 = object2D::CreateCircle("glont2", gloante + glm::vec3(40, 0, 0), 15, 360, NormalizedRGB(255, 255, 0), true);
    AddMeshToList(glont2);
    Mesh* glont3 = object2D::CreateCircle("glont3", gloante + glm::vec3(80, 0, 0), 15, 360, NormalizedRGB(255, 255, 0), true);
    AddMeshToList(glont3);

    glm::vec3 casete(resolution.x-170, resolution.y - 40, 0);
    Mesh* caseta_scor1 = object2D::CreateSquare2("caseta_scor1", casete, 30, 150, NormalizedRGB(0, 0, 205), false);
    AddMeshToList(caseta_scor1);
    Mesh* caseta_scor2 = object2D::CreateSquare2("caseta_scor2", casete,30, 3, NormalizedRGB(0, 0, 205),true);
    AddMeshToList(caseta_scor2);

    Mesh* cer = object2D::CreateSquare2("cer", glm::vec3(0, 0, 0), resolution.y, resolution.x, NormalizedRGB(135, 206, 250), true);
    AddMeshToList(cer);
    Mesh* cer2 = object2D::CreateSquare2("cer2", glm::vec3(0, 0, 0), resolution.y, resolution.x, NormalizedRGB(255, 69, 0), true);
    AddMeshToList(cer2);

    Mesh* iarba = object2D::CreateSquare2("iarba", glm::vec3(0, 0, 0), resolution.y /5, resolution.x, NormalizedRGB(34,139,34), true);
    AddMeshToList(iarba);

    Mesh* trunchi = object2D::CreateSquare2("trunchi", glm::vec3(100, 40, 0), 300,36, NormalizedRGB(121, 85, 72), true);
    AddMeshToList(trunchi);
    Mesh* pom1 = object2D::CreateCircle("pom1",  glm::vec3(118, 340, 0), 80, 360, NormalizedRGB(100, 221,23), true);
    AddMeshToList(pom1);
    Mesh* pom2 = object2D::CreateCircle("pom2", glm::vec3(160, 310, 0), 50, 360, NormalizedRGB(100, 221, 23), true);
    AddMeshToList(pom2);
    Mesh* pom3 = object2D::CreateCircle("pom3", glm::vec3(76, 310, 0), 50, 360, NormalizedRGB(100, 221, 23), true);
    AddMeshToList(pom3);
    Mesh* pom4 = object2D::CreateCircle("pom4", glm::vec3(160, 360, 0), 50, 360, NormalizedRGB(100, 221, 23), true);
    AddMeshToList(pom4);
    Mesh* pom5 = object2D::CreateCircle("pom5", glm::vec3(76, 360, 0), 50, 360, NormalizedRGB(100, 221, 23), true);
    AddMeshToList(pom5);
    Mesh* pom6 = object2D::CreateCircle("pom6", glm::vec3(118, 390, 0), 50, 360, NormalizedRGB(100, 221, 23), true);
    AddMeshToList(pom6);

 
    Mesh* fulg1 = object2D::CreateTriangle2("fulg1",  glm::vec3(0, 0, 0), 20, 15, glm::vec3(1, 1, 0), body_angle, true, true);
    AddMeshToList(fulg1);
    Mesh* fulg2 = object2D::CreateTriangle2("fulg2", glm::vec3(0, 0, 0), 20, 15, glm::vec3(1, 1, 0), body_angle, true, true);
    AddMeshToList(fulg2);
    Mesh* fulg3 = object2D::CreateTriangle2("fulg3", glm::vec3(0, 0, 0), 20, 15, glm::vec3(1, 1, 0), body_angle, true, true);
    AddMeshToList(fulg3);
    Mesh* fulg4 = object2D::CreateTriangle2("fulg4", glm::vec3(0, 0, 0), 20, 15, glm::vec3(1, 1, 0), body_angle, true, true);
    AddMeshToList(fulg4);
    Mesh* fulg5 = object2D::CreateTriangle2("fulg5", glm::vec3(0, 0, 0), 20, 15, glm::vec3(1, 1, 0), body_angle, true, true);
    AddMeshToList(fulg5);
    Mesh* fulg6 = object2D::CreateTriangle2("fulg6", glm::vec3(0, 0, 0), 20, 15, glm::vec3(1, 1, 0), body_angle, true, true);
    AddMeshToList(fulg6);


    Mesh* aim = object2D::CreateCircle2("aim", glm::vec3(0, 0, 0), 15, 360, NormalizedRGB(255,0,0), false);
    AddMeshToList(aim);

    Mesh* weapon1 = object2D::CreateSquare2("weapon1", glm::vec3(20, -20, 0), 10, 32, NormalizedRGB(139, 69, 19), true);
    AddMeshToList(weapon1);
    Mesh* weapon2 = object2D::CreateSquare2("weapon2", glm::vec3(45, -40, 0), 20, 10, NormalizedRGB(0,0,0), true);
    AddMeshToList(weapon2);
  
}


void tema1::FrameStart()
{
    
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
 
    glViewport(0, 0, resolution.x, resolution.y);
}


void tema1::Update(float deltaTimeSeconds)
{
    glm::ivec2 resolution = window->GetResolution();

    modelMatrix = glm::mat3(1);
    time += deltaTimeSeconds;
    float random;
    bool switch_color = false;
   
    modelMatrix = glm::mat3(1);
    RenderMesh2D(meshes["iarba"], shaders["VertexColor"], modelMatrix);


    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(tranx, trany);
    RenderMesh2D(meshes["aim"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["weapon1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["weapon2"], shaders["VertexColor"], modelMatrix);
    
   


    if (vieti >0 && scaleX <=50)
    {

        if (impuscat)
        {
            modelMatrix = glm::mat3(1);


            modelMatrix *= transform2D::Translate(x, y);
            translateY2 += deltaTimeSeconds * 300;
            translateX2 += deltaTimeSeconds * 300;
            glm::mat3 modelMatrix2 = modelMatrix;
            glm::mat3 modelMatrix3 = modelMatrix;
            glm::mat3 modelMatrix4 = modelMatrix;
            glm::mat3 modelMatrix5 = modelMatrix;
            glm::mat3 modelMatrix6 = modelMatrix;

            modelMatrix  *= transform2D::Translate(translateX2 * cos(0), translateY2 * sin(0));
            modelMatrix2 *= transform2D::Translate(translateX2 * cos(M_PI/3), translateY2 * sin(M_PI / 3));
            modelMatrix3 *= transform2D::Translate(translateX2 * cos(2 * M_PI / 3), translateY2 * sin(2 * M_PI / 3));
            modelMatrix4 *= transform2D::Translate(translateX2 * cos(M_PI), -translateY2 * sin(M_PI));
            modelMatrix5 *= transform2D::Translate(translateX2 * cos(4 * M_PI / 3), translateY2 * sin(4 * M_PI / 3));
            modelMatrix6 *= transform2D::Translate(translateX2 * cos(5 * M_PI / 3), translateY2 * sin(5 * M_PI / 3));

            RenderMesh2D(meshes["fulg1"], shaders["VertexColor"], modelMatrix);
            RenderMesh2D(meshes["fulg2"], shaders["VertexColor"], modelMatrix2);
            RenderMesh2D(meshes["fulg3"], shaders["VertexColor"], modelMatrix3);
            RenderMesh2D(meshes["fulg4"], shaders["VertexColor"], modelMatrix4);
            RenderMesh2D(meshes["fulg5"], shaders["VertexColor"], modelMatrix5);
            RenderMesh2D(meshes["fulg6"], shaders["VertexColor"], modelMatrix6);

        }



        if (impuscat ) {
            translateY -= deltaTimeSeconds * 200;
            angle = 3.0 * M_PI_2;
            time = 0;
            
            switch_color = true;
            if (cap.y + translateY < 0) {
               
                translateX = 100 + (rand() % 700);
                
                random = 2.8 + (rand() % 6);
                angle = M_PI / random;
                if (x_initial + translateX < resolution.x / 2) {
                    angle = M_PI / random;
                }
                else {
                    angle = M_PI_2 + M_PI / random;
                }
                translateY = 10;
               
               
                impuscat = false;
                time = 0;
                duck_counter++;
                if (duck_counter % 5 == 0)
                    viteza = viteza_initiala + ((viteza - viteza_initiala) / viteza_initiala + 1) * viteza_initiala / 3;
                nr_gloante= 3;
                
                scor++;

            }


        }
        else {
            
            if (cioc.y + translateY > resolution.y-5) {
                 angle = 2.0 * M_PI - angle;
             
            }
            if (cioc.x + translateX > resolution.x-5) {            
                    if (angle < M_PI) {
                        angle = M_PI - angle;
                    }
                    else {
                        angle = 3 * M_PI - angle;
                    }
            }

            if (cioc.x + translateX < 5) {           
                if (angle < M_PI) {
                    angle = M_PI - angle;
                }
                else {
                    angle = 3 * M_PI - angle;
                }         
            }

            if (cioc.y + translateY < 5) {              
                angle = 2.0 * M_PI - angle;          
            }  

            translateY += deltaTimeSeconds * viteza * sin(angle);
            translateX += deltaTimeSeconds * viteza * cos(angle);
        }
     
        if (time > 5 || (nr_gloante == 0 && !impuscat)) {
            translateY += deltaTimeSeconds * viteza;
            angle = M_PI_2;
            if (cap.y + translateY > resolution.y){
                time = 0;
                translateX = 0;
                translateY = 0;
                translateX = 100 + (rand() % 700);
                translateY = 15;
                random = 2.8 + (rand() % 6);
                angle = M_PI / random;
                if (x_initial + translateX < resolution.x / 2) {
                    angle = M_PI / random;
                }
                else {
                    angle = M_PI_2 + M_PI / random;
                }
              

                duck_counter++;
                if (duck_counter %5 ==0)
                    viteza = viteza_initiala + ((viteza - viteza_initiala) / viteza_initiala + 1) * viteza_initiala / 3;

                vieti--;
                nr_gloante = 3;
            }
        }


        modelMatrix = glm::mat3(1);

        modelMatrix *= transform2D::Translate(translateX, translateY);

        modelMatrix *= transform2D::Translate(cioc.x, cioc.y);
        modelMatrix *= transform2D::Rotate(angle);
        modelMatrix *= transform2D::Translate(-cioc.x, -cioc.y);

       
        RenderMesh2D(meshes["beak"], shaders["VertexColor"], modelMatrix);
        RenderMesh2D(meshes["head"], shaders["VertexColor"], modelMatrix);
        RenderMesh2D(meshes["body"], shaders["VertexColor"], modelMatrix);





        angularStep1 += deltaTimeSeconds;
        if (angularStep1 >= 0) {
            angularStep1 -= 0.7;
        }

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(translateX, translateY);
        modelMatrix *= transform2D::Translate(cioc.x, cioc.y);
        modelMatrix *= transform2D::Rotate(angle);
        modelMatrix *= transform2D::Translate(-cioc.x, -cioc.y);


        if (!impuscat)
        {

            modelMatrix *= transform2D::Translate(aripa1.x, aripa1.y);
            modelMatrix *= transform2D::Rotate(angularStep1);
            modelMatrix *= transform2D::Translate(-aripa1.x, -aripa1.y);
        }

        RenderMesh2D(meshes["wing1"], shaders["VertexColor"], modelMatrix);

        angularStep2 -= deltaTimeSeconds;
        if (angularStep2 <= 0) {
            angularStep2 += 0.7;
        }
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(translateX, translateY);
        modelMatrix *= transform2D::Translate(cioc.x, cioc.y);
        modelMatrix *= transform2D::Rotate(angle);
        modelMatrix *= transform2D::Translate(-cioc.x, -cioc.y);

        if (!impuscat)
        {
            modelMatrix *= transform2D::Translate(aripa2.x, aripa2.y);
            modelMatrix *= transform2D::Rotate(angularStep2);
            modelMatrix *= transform2D::Translate(-aripa2.x, -aripa2.y);
        }

        RenderMesh2D(meshes["wing2"], shaders["VertexColor"], modelMatrix);


        modelMatrix = glm::mat3(1);
        if (vieti == 1) {
            RenderMesh2D(meshes["romb1"], shaders["VertexColor"], modelMatrix);
        }
        if (vieti == 2) {
            RenderMesh2D(meshes["romb1"], shaders["VertexColor"], modelMatrix);
            RenderMesh2D(meshes["romb2"], shaders["VertexColor"], modelMatrix);
        }
        if (vieti >= 3) {
            RenderMesh2D(meshes["romb1"], shaders["VertexColor"], modelMatrix);
            RenderMesh2D(meshes["romb2"], shaders["VertexColor"], modelMatrix);
            RenderMesh2D(meshes["romb3"], shaders["VertexColor"], modelMatrix);
        }



        modelMatrix = glm::mat3(1);
        if (nr_gloante == 1) {
            RenderMesh2D(meshes["glont1"], shaders["VertexColor"], modelMatrix);
        }
        if (nr_gloante == 2) {
            RenderMesh2D(meshes["glont1"], shaders["VertexColor"], modelMatrix);
            RenderMesh2D(meshes["glont2"], shaders["VertexColor"], modelMatrix);
        }
        if (nr_gloante >= 3) {
            RenderMesh2D(meshes["glont1"], shaders["VertexColor"], modelMatrix);
            RenderMesh2D(meshes["glont2"], shaders["VertexColor"], modelMatrix);
            RenderMesh2D(meshes["glont3"], shaders["VertexColor"], modelMatrix);
        }

        modelMatrix = glm::mat3(1);
        RenderMesh2D(meshes["caseta_scor1"], shaders["VertexColor"], modelMatrix);



        for (int i = 0; i <= scor; i++) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(i*3, 0);
            RenderMesh2D(meshes["caseta_scor2"], shaders["VertexColor"], modelMatrix);
        }
       
    }

    modelMatrix = glm::mat3(1);
    RenderMesh2D(meshes["pom1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["pom2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["pom3"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["pom4"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["pom5"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["pom6"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["trunchi"], shaders["VertexColor"], modelMatrix);
    
  

    if (vieti == 0) {
        gfxc::TextRenderer* textRenderer = new gfxc::TextRenderer(window->props.selfDir, resolution.x, resolution.y);
        textRenderer->Load(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::FONTS, "Hack-Bold.ttf"), 30);
        textRenderer->RenderText("GAME OVER! PRESS 'A' to restart", resolution.x / 2 - 220, resolution.y / 2, 1.0f, glm::vec3(1, 0, 0));


    }
    else {
        if (!switch_color) {
            RenderMesh2D(meshes["cer"], shaders["VertexColor"], modelMatrix);

        }
        else {
            RenderMesh2D(meshes["cer2"], shaders["VertexColor"], modelMatrix);
            switch_color = false;
        }
    
    }

    
}


void tema1::FrameEnd()
{
}


void tema1::OnInputUpdate(float deltaTime, int mods)
{
    
}


void tema1::OnKeyPress(int key, int mods)
{
    if (key == GLFW_KEY_A && vieti <=0) {
        vieti = 3;
        time = 0;
        viteza = viteza_initiala;
        nr_gloante = 3;
        duck_counter = 1;
        scor = 0;
        
    }
   
}


void tema1::OnKeyRelease(int key, int mods)
{

}


void tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
   
    glm::ivec2 resolution = window->GetResolution();
    tranx = mouseX + deltaX;
    trany = resolution.y - mouseY + deltaY;
}


void tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
  
    glm::ivec2 resolution = window->GetResolution();
    y = resolution.y - mouseY;
    x = mouseX;

   
   
    glm::vec3 cornerC = cornerA + glm::vec3(width, heigh, 0);
    float x2, y2, x3, y3;
    x2 = x - cioc.x - translateX;
    y2 = y - cioc.y - translateY;

    x3 = x2 * cos(-angle) - sin(-angle) * y2 + cioc.x;
    y3 = x2 * sin(-angle) + cos(-angle) * y2 + cioc.y;

    if (cornerA.x <= x3 && x3 <= cornerC.x && cornerA.y <= y3 && y3 <= cornerC.y &&  nr_gloante > 0) {
        impuscat = true;
        translateY2 = 0;
        translateX2 = 0;

    }

    nr_gloante--;

   
}


void tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
   
}


void tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void tema1::OnWindowResize(int width, int height)
{
}
