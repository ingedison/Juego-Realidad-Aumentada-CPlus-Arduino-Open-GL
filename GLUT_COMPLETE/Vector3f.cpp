//#include <glut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>
//
//#define HEIGHT 480
//#define WIDTH 640
//
//double objx = 0, objy=0, objz=0;
//
//*THE FUNCTION TO DRAW THE STUFF ON THE SCREEN*/
//void display( )
//{
//	glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
//	
//	//The big green floor like polygon
//	glBegin( GL_POLYGON );
//	glColor3f( 0, 1, 0 );
//	glVertex3f( -100, 0,  100  );
//	glVertex3f( -100, 0, -100  );
//	glVertex3f( 100,  0, -100 );
//	glVertex3f( 100,  0, 100 );
//	glEnd( );
//	The red cube to be drawn at clicked position
//	glPushMatrix( );
//		glColor3f( 1, 0, 0 );
//		glTranslatef( objx, objy, objz );
//		glutSolidCube( 10 );
//	glPopMatrix( );
//
//	glFlush( );
//	glutSwapBuffers( );
//}
//
//void mouse( int button, int state, int x, int y)
//{
//	double modelview[16], projection[16];
//	int viewport[4];
//	float z = 1;
//	
//	/*Read the projection, modelview and viewport matrices
//	using the glGet functions.*/
//	glGetDoublev( GL_PROJECTION_MATRIX, projection );
//	glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
//	glGetIntegerv( GL_VIEWPORT, viewport );
//
//	//Read the window z value from the z-buffer	
//	glReadPixels( x, viewport[3]-y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z );	
//
//	//Use the gluUnProject to get the world co-ordinates of
//	//the point the user clicked and save in objx, objy, objz.
//	gluUnProject( x, viewport[3]-y, z, modelview, projection, viewport, &objx, &objy, &objz );
//}
//void keyboard( unsigned char key, int x, int y )
//{
//}
//
//void init( int width, int height )
//{
//	   float ratio = (float) width / height;
//		glViewport( 0, 0, width, height );
//		glMatrixMode( GL_PROJECTION );
//		glLoadIdentity( );
//		gluPerspective(45, ratio, 0.01, 1000);
//		glMatrixMode( GL_MODELVIEW );
//		glLoadIdentity( );
//		gluLookAt( 0, 100, 200, 0, 0, 0, 0, 1, 0 );
//}
//
//int main( int argc, char **argv )
//{
//		glutInit( &argc, argv );
//		//The most important part specify the things your
//		//glut window should provide
//		glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
//		glutInitWindowSize( 640, 480 );
//		glutCreateWindow("HI");
//		
//		glClearColor( 0, 0, 0, 0 );
//		//enable z buffer
//		glEnable( GL_DEPTH_TEST );
//		//set the value in z-buffer as 1.0
//		glClearDepth( 1.0 );
//		init( 640, 480 );
//		glutDisplayFunc( display );
//		glutReshapeFunc( init );
//		glutIdleFunc( display );
//		glutMouseFunc( mouse );
//		glutKeyboardFunc( keyboard );
//		glutMainLoop( );
//}
