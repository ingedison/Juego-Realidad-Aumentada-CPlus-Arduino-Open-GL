#include "Crear_Escenario.h"

void circle(float x, float y, float z, float r, int segments)
{
    glBegin( GL_TRIANGLE_FAN );
        glVertex3f(x, y, z);
        for( int n = 0; n <= segments; ++n ) {
            float const t = 2*M_PI*(float)n/(float)segments;
            glVertex3f(x + sin(t)*r, y + cos(t)*r, z);
        }
    glEnd();
}
