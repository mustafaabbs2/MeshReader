#pragma once

#include <hc.h>
#include <iostream>

void render_polygon() {

  HC_Open_Segment("/segment1");
  {
    HC_Set_Visibility("everything=on");
    HC_Set_Color("windows=white");
    // HC_Set_Rendering_Options("ztest=on");
    // HC_Set_Rendering_Options("zwrite=on");
    // HC_Set_Rendering_Options("f2d");

    // Define the vertices of the triangle
    float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f,
                        0.0f,  0.0f,  0.5f, 0.0f};

    HC_Insert_Polygon(3, vertices);

    HC_Update_Display();
  }
  HC_Close_Segment();
}