//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01
CTexture textMesa;
CTexture textburo;
CTexture textManija;
CTexture textCajon;
CTexture textPez;
CTexture textlibre;
CTexture textlibros;
CTexture textportada;
CTexture texttele;
CTexture textbaul;
CTexture textboton;
CTexture textmabaul;
CTexture textbase;
CTexture textpantalla;
CTexture textcamas;
CTexture textcobija;
CTexture textalmu;
CTexture textcamabase;
CTexture textpuerta;
CTexture textventana;
CTexture textcasamadera;
CTexture texttejado;
CTexture textpiso1;
CTexture textparedint;
CTexture textescalon;
CTexture textcuadro;
CTexture textbalon;
CTexture textpag;
CTexture textportada1;
CTexture textlomo;
CTexture textglobo;



CTexture tree;
CTexture edificio;


CFiguras cubo;
CFiguras sky;

//END NEW//////////////////////////////////////////


CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito
CFiguras miobj; 
//casa proyecto
CFiguras tablaMesa;
CFiguras maderaBuro;
CFiguras manija;
CFiguras cajon;
CFiguras pecera;
CFiguras libre;
CFiguras libros;
CFiguras portada;
CFiguras televi;
CFiguras baul;
CFiguras mabaul;
CFiguras antena;
CFiguras boton;
CFiguras base;
CFiguras cilindro;
CFiguras pantalla;
CFiguras camas;
CFiguras almu;
CFiguras mueblecama;
CFiguras cobija;
CFiguras puerta;
CFiguras ventanas;
CFiguras maderacasa;
CFiguras tejado;
CFiguras piso1;
CFiguras paredint;
CFiguras escalon;
CFiguras cuadro;
CFiguras balon;
CFiguras pagina;
CFiguras portada1;
CFiguras lomo;
CFiguras globo;

float open=0.0;
float open2 = 0.0;
bool p_animacion= false;
bool p_animacion1= false;
bool p_animacion2 = false;
bool p_animacion3 = false;
bool circuito = false;
bool recorrido1 = true;
bool recorrido2 = false;
bool recorrido3 = false;
bool recorrido4 = false;
bool recorrido5 = false;
float bota = 0.0;
float movglovx = 0.0;
float movglovz = 0.0;








void ciudad ()
{

		glPushMatrix(); //Camino1
			glTranslatef(23.5,0.0,0.0);
			glScalef(40,0.1,7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Camino2
			glTranslatef(-23.5,0.0,0.0);
			glScalef(54,0.1,7);
			glDisable(GL_LIGHTING);
			fig3.prisma2(text4.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,-34.0);
			glScalef(87,0.1,60);
			glDisable(GL_LIGHTING);
			fig4.prisma2(text5.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Pasto
			glTranslatef(0.0,0.0,18.5);
			glScalef(87,0.1,30);
			glDisable(GL_LIGHTING);
			fig4.prisma2(text5.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Casa01
			glTranslatef(0.0,3.0,7.0);
			glRotatef(90,1,0,0);
			glRotatef(180,0,0,1);
			glScalef(6,5.0,6);
			glDisable(GL_LIGHTING);
			fig5.prisma2(text6.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix(); //Casa01
			glTranslatef(0.0,3.0,-7.0);
			glRotatef(90,1,0,0);
			
			glScalef(6,5.0,6);
			glDisable(GL_LIGHTING);
			fig5.prisma2(text6.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();
}


GLuint createDL() 
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL,GL_COMPILE);
	// call the function that contains 
	// the rendering commands
		ciudad();
		//monito();
	// endList
	glEndList();

	return(ciudadDL);
}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();


	tree.LoadTGA("tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	edificio.LoadTGA("edificio.tga");
	edificio.BuildGLTexture();
	edificio.ReleaseImage();


	//casa proyecto
	textMesa.LoadTGA("madera.tga");
	textMesa.BuildGLTexture();
	textMesa.ReleaseImage();

	textburo.LoadTGA("maderaburo.tga");
	textburo.BuildGLTexture();
	textburo.ReleaseImage();

	textManija.LoadTGA("jala.tga");
	textManija.BuildGLTexture();
	textManija.ReleaseImage();

	textCajon.LoadTGA("piso1.tga");
	textCajon.BuildGLTexture();
	textCajon.ReleaseImage();

	textPez.LoadTGA("cosmo.tga");
	textPez.BuildGLTexture();
	textPez.ReleaseImage();

	textlibros.LoadTGA("libros1.tga");
	textlibros.BuildGLTexture();
	textlibros.ReleaseImage();

	textportada.LoadTGA("portada.tga");
	textportada.BuildGLTexture();
	textportada.ReleaseImage();

	textportada1.LoadTGA("portada1.tga");
	textportada1.BuildGLTexture();
	textportada1.ReleaseImage();

	textmabaul.LoadTGA("maderabaul.tga");
	textmabaul.BuildGLTexture();
	textmabaul.ReleaseImage();

	textbaul.LoadTGA("baul.tga");
	textbaul.BuildGLTexture();
	textbaul.ReleaseImage();


	textbase.LoadTGA("basetele.tga");
	textbase.BuildGLTexture();
	textbase.ReleaseImage();

	texttele.LoadTGA("intro.tga");
	texttele.BuildGLTexture();
	texttele.ReleaseImage();

	textpantalla.LoadTGA("botones.tga");
	textpantalla.BuildGLTexture();
	textpantalla.ReleaseImage();

	textcobija.LoadTGA("colchon.tga");
	textcobija.BuildGLTexture();
	textcobija.ReleaseImage();
	
	textalmu.LoadTGA("almu.tga");
	textalmu.BuildGLTexture();
	textalmu.ReleaseImage();
	
	textpuerta.LoadTGA("puerta.tga");
	textpuerta.BuildGLTexture();
	textpuerta.ReleaseImage();

	textventana.LoadTGA("ventana.tga");
	textventana.BuildGLTexture();
	textventana.ReleaseImage();

	textcasamadera.LoadTGA("pared.tga");
	textcasamadera.BuildGLTexture();
	textcasamadera.ReleaseImage();

	texttejado.LoadTGA("tejado1.tga");
	texttejado.BuildGLTexture();
	texttejado.ReleaseImage();

	textpiso1.LoadTGA("piso2.tga");
	textpiso1.BuildGLTexture();
	textpiso1.ReleaseImage();


	textparedint.LoadTGA("paredint.tga");
	textparedint.BuildGLTexture();
	textparedint.ReleaseImage();

	textescalon.LoadTGA("escalon.tga");
	textescalon.BuildGLTexture();
	textescalon.ReleaseImage();

	textcuadro.LoadTGA("cuadro.tga");
	textcuadro.BuildGLTexture();
	textcuadro.ReleaseImage();

	textbalon.LoadTGA("balon.tga");
	textbalon.BuildGLTexture();
	textbalon.ReleaseImage();

	textpag.LoadTGA("paglibro.tga");
	textpag.BuildGLTexture();
	textpag.ReleaseImage();

	textlomo.LoadTGA("lomo.tga");
	textlomo.BuildGLTexture();
	textlomo.ReleaseImage();
	
	
	textglobo.LoadTGA("cosmog.tga");
	textglobo.BuildGLTexture();
	textglobo.ReleaseImage();





	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

}




void buros(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosBuro, GLfloat yPosBuro, GLfloat zPosBuro) {
	glPushMatrix();
	glScalef(xMadera, yMadera, zMadera);
	glTranslatef(xPosBuro, yPosBuro, zPosBuro);
	//base buro		
	glPushMatrix();
		glScalef(3, .2f, 3);
		maderaBuro.prisma(1.0, 1.0, 1.0, textburo.GLindex);
	glPopMatrix();
	
	//pared
		glPushMatrix();
		glTranslatef(0.0, -0.8f, 1.2);
		glScalef(3, 1.5f, 0.2);
		maderaBuro.prisma(1.0, 1.0, 1.0, textburo.GLindex);
		glPopMatrix();
		
		//frente
		glPushMatrix();
		glTranslatef(0.0, -0.8f, -1.2);
		glScalef(3, 1.5f, 0.2);
		maderaBuro.prisma(1.0, 1.0, 1.0, textburo.GLindex);
		
		//cajon
		glPushMatrix();
		glTranslatef(0.0, 0.0f, -1.0);
		glScalef(0.5, 0.5f, 0.5);
		cajon.prisma(1.0, 1.0, 1.0, textCajon.GLindex);
		
		//jaladera
		glPushMatrix();
		glTranslatef(0.0, 0.0f, -1.0);
		glScalef(1.0, 1.0f, 1.0);
		manija.esfera(0.1, 10.0, 10.0, textManija.GLindex);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		
		//base abajo
		glPushMatrix();
		glTranslatef(0.0, -1.4f, 0.0);
		glScalef(2.8, 0.2f, 2.5);
		maderaBuro.prisma(1.0, 1.0, 1.0, textburo.GLindex);
		glPopMatrix();
		
		//patas
		glPushMatrix();
		glTranslatef(1.0, -2.0f, -1.0);
		glScalef(0.3, 1.0f, 0.3);
		maderaBuro.prisma(1.0, 1.0, 1.0, textburo.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.0, -2.0f, -1.0);
		glScalef(0.3, 1.0f, 0.3);
		maderaBuro.prisma(1.0, 1.0, 1.0, textburo.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.0, -2.0f, 1.0);
		glScalef(0.3, 1.0f, 0.3);
		maderaBuro.prisma(1.0, 1.0, 1.0, textburo.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.0, -2.0f, 1.0);
		glScalef(0.3, 1.0f, 0.3);
		maderaBuro.prisma(1.0, 1.0, 1.0, textburo.GLindex);
		glPopMatrix();

		//costados
		glPushMatrix();
		glTranslatef(1.38, -0.8f, 0.0);
		glScalef(0.2, 1.5f, 2.5);
		maderaBuro.prisma(1.0, 1.0, 1.0, textburo.GLindex);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(-1.38, -0.8f, 0.0);
		glScalef(0.2, 1.5f, 2.5);
		maderaBuro.prisma(1.0, 1.0, 1.0, textburo.GLindex);	
		glPopMatrix();

		//pecera
		glPushMatrix();
		glTranslatef(0.0, 1.0f, 0.0);
		glRotatef(-90, 0.0, 1.0, 0.0);
		pecera.esfera(1.0, 10.0, 10.0, textPez.GLindex);
		glPopMatrix();




	glPopMatrix();




}

void librero(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosLib, GLfloat yPosLib, GLfloat zPosLib) {
	glPushMatrix();
	
		glScalef(xMadera, yMadera, zMadera);
		glTranslatef(xPosLib, yPosLib, zPosLib);

		//base superior
		glPushMatrix();
		glScalef(8, .2f, 3);
		glDisable(GL_LIGHTING);
		libre.prisma(1.0, 1.0, 1.0, textburo.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		//pared
		glPushMatrix();
		glTranslatef(0.0, -2.0f, 1.4);
		glScalef(8, 4.0f, 0.2);
		glDisable(GL_LIGHTING);
		maderaBuro.prisma(1.0, 1.0, 1.0, textburo.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		//base inferior
		glPushMatrix();
		glTranslatef(0.0, -4.1f, 0.0);
		glScalef(8, .2f, 3);
		glDisable(GL_LIGHTING);
		libre.prisma(1.0, 1.0, 1.0, textburo.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		//repisa
		glPushMatrix();
		glTranslatef(0.0, -2.1f, 0.0);
		glScalef(8, .2f, 2.5);
		glDisable(GL_LIGHTING);
		libre.prisma(1.0, 1.0, 1.0, textburo.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//costados
		glPushMatrix();
		glTranslatef(4.1, -2.0f, 0.0);
		glScalef(0.2, 4.3f, 3.0);
		glDisable(GL_LIGHTING);
		maderaBuro.prisma(1.0, 1.0, 1.0, textburo.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-4.1, -2.0f, 0.0);
		glScalef(0.2, 4.3f, 3.0);
		glDisable(GL_LIGHTING);
		maderaBuro.prisma(1.0, 1.0, 1.0, textburo.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		//libros
		glPushMatrix();
		glTranslatef(-1.0, -1.2f, -1.0);
		glScalef(6.0, 1.9f, 0.1);
		glDisable(GL_LIGHTING);
		libros.prisma(1.0, 1.0, 1.0, textlibros.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, -3.0f, -1.0);
		glScalef(7.8, 1.9f, 0.1);
		glDisable(GL_LIGHTING);
		libros.prisma(1.0, 1.0, 1.0, textlibros.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		//portada
		glPushMatrix();
		glTranslatef(2.0, -1.0f, 0.0);
		glScalef(0.1, 1.85f, 2.0);
		glDisable(GL_LIGHTING);
		portada.prisma(1.0, 1.0, 1.0, textportada.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


glPopMatrix();
}

void tele(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosTel, GLfloat yPosTel, GLfloat zPosTel) {
	glPushMatrix();
	glScalef(xMadera, yMadera, zMadera);
	glTranslatef(xPosTel, yPosTel, zPosTel);
	
	glPushMatrix();
	glScalef(3, 1.5f, 2);
	glDisable(GL_LIGHTING);
	mabaul.prisma(1.0, 1.0, 1.0, textmabaul.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.0, 0.0f, -1.0);
	glScalef(3.0, 1.5f, 0.005);
	glDisable(GL_LIGHTING);
	baul.prisma(1.0, 1.0, 1.0, textbaul.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.0, 1.0f, 0.0);
	glScalef(2.5, 2.5f, 1.0);
	glDisable(GL_LIGHTING);
	base.prisma(1.0, 1.0, 1.0, textbase.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	

	glPushMatrix();
	glTranslatef(0.0, 1.6f, -0.5);
	glScalef(2.0, 1.0f, 0.1);
	glDisable(GL_LIGHTING);
	televi.prisma(1.0, 1.0,0.1, texttele.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	

	glPushMatrix();
	glTranslatef(-0.6, 1.0f, -0.5);
	glScalef(1.0, 0.1f, 0.1);
	glDisable(GL_LIGHTING);
	televi.prisma(1.0, 1.0, 0.1, textpantalla.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	
	
	glPopMatrix();
}

void cama(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosCam, GLfloat yPosCam, GLfloat zPosCam) {
	glPushMatrix();
	glScalef(xMadera, yMadera, zMadera);
	glTranslatef(xPosCam, yPosCam, zPosCam);
	//cabecera
	glPushMatrix();
	glScalef(4, 2.5f, .3);
	glDisable(GL_LIGHTING);
	mabaul.prisma(1.0, 1.0, 1.0, textmabaul.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0, 0.0f, 0.0);
	glScalef(0.5, 3.0f, .3);
	glDisable(GL_LIGHTING);
	mabaul.prisma(1.0, 1.0, 1.0, textmabaul.GLindex);
	glEnable(GL_LIGHTING);

		glPushMatrix();
		glTranslatef(0.0, 0.6f, 0.0);
		glScalef(0.5, 0.2f, 0.5);
		glDisable(GL_LIGHTING);
		manija.esfera(0.5, 20.0, 20.0, textManija.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();



	glPopMatrix();


	//patabasepies
	glPushMatrix();
	glTranslatef(-2.0, 0.0f, 0.0);
	glScalef(0.5, 3.0f, .3);
	mabaul.prisma(1.0, 1.0, 1.0, textmabaul.GLindex);
	//esferapata
	glPushMatrix();
	glTranslatef(0.0, 0.6f, 0.0);
	glScalef(0.5, 0.2f, 0.5);
	manija.esfera(0.5, 20.0, 20.0, textManija.GLindex);
	glPopMatrix();
	glPopMatrix();



	//patabasepies
	glPushMatrix();
	glTranslatef(-2.0, 0.0f, 5.0);
	glScalef(0.5, 3.0f, .3);
	mabaul.prisma(1.0, 1.0, 1.0, textmabaul.GLindex);
	//esferapata
	glPushMatrix();
	glTranslatef(0.0, 0.6f, 0.0);
	glScalef(0.5, 0.2f, 0.5);
	manija.esfera(0.5, 20.0, 20.0, textManija.GLindex);
	glPopMatrix();
	glPopMatrix();

	//patabasepies
	glPushMatrix();
	glTranslatef(2.0, 0.0f, 5.0);
	glScalef(0.5, 3.0f, .3);
	mabaul.prisma(1.0, 1.0, 1.0, textmabaul.GLindex);
	//esferapata
	glPushMatrix();
	glTranslatef(0.0, 0.6f, 0.0);
	glScalef(0.5, 0.2f, 0.5);
	manija.esfera(0.5, 20.0, 20.0, textManija.GLindex);
	glPopMatrix();
	glPopMatrix();


	//basepies
	glPushMatrix();
	glTranslatef(0.0, 0.0f, 5.0);
	glScalef(4, 2.5f, .3);
	mabaul.prisma(1.0, 1.0, 1.0, textmabaul.GLindex);
	glPopMatrix();

	//base cama
	
	glPushMatrix();
	glTranslatef(0.0, -1.0f, 2.6);
	glScalef(4, 0.2f, 4.6);
	glDisable(GL_LIGHTING);
	libre.prisma(1.0, 1.0, 1.0, textburo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	//colchon
	glPushMatrix();
	glTranslatef(0.0, -0.4f, 2.6);
	glScalef(4, 1.0f, 4.6);
	glDisable(GL_LIGHTING);
	cobija.prisma(1.0, 1.0, 1.0, textcobija.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.2f, 4.2);
	glScalef(1.5, 0.2f, 1.0);
	glDisable(GL_LIGHTING);
	almu.prisma(1.0, 1.0, 1.0, textalmu.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPopMatrix();

}

void casa(void) {

	glPushMatrix();
	//pared derecha a la puerta
	glPushMatrix();
	glTranslatef(-20.5f, 1.9, 5);
	glScalef(9.0, 3.8f, 0.3);
	maderacasa.prisma(1.0, 1.0, 1.0, textcasamadera.GLindex);
	glPopMatrix();

	//pared derecha a la puerta interior
	glPushMatrix();
	glTranslatef(-20.4f, 1.9, 5.2);
	glScalef(9.0, 3.8f, 0.3);
	glDisable(GL_LIGHTING);
	paredint.prisma(1.0, 1.0, 1.0, textparedint.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	
	//puerta
	glPushMatrix();
	
	
	
	glTranslatef(-15, 2.0, 5);
	glTranslatef(1, 0, 0);
	glRotatef(open, 0, 0.1, 0);
	glTranslatef(-1, 0, 0);
	glScalef(2.0, 3.5f, 0.4);
	glDisable(GL_LIGHTING);
	puerta.prisma(1.0, 1.0, 1.0, textpuerta.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//escalon
	glPushMatrix();
	glTranslatef(-15, 0.3, 4.5);
	glScalef(2.0, 0.4f, 0.4);
	glDisable(GL_LIGHTING);
	escalon.prisma(1.0, 1.0, 1.0, textescalon.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();



	
	//pared tracera
	glPushMatrix();
	glTranslatef(-15, 2.4, 25.0);
	glScalef(19.8, 5.0f, 0.4);
	maderacasa.prisma(1.0, 1.0, 1.0, textcasamadera.GLindex);
	glPopMatrix();


	//pared tracera
	glPushMatrix();
	glTranslatef(-22, 2.8, 24.7);
	glScalef(1.2, 0.8f, 0.2);
	cuadro.prisma(1.0, 1.0, 1.0, textcuadro.GLindex);
	glPopMatrix();


	//pared tracera int
	glPushMatrix();
	glTranslatef(-15, 2.5, 24.9);
	glScalef(19.7, 4.9f, 0.4);
	glDisable(GL_LIGHTING);
	paredint.prisma(1.0, 1.0, 1.0, textparedint.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();



	//pared derecha de la puerta
	glPushMatrix();
	glTranslatef(-9.5, 2.5, 5);
	glScalef(9.0, 5.0f, 0.3);
	maderacasa.prisma(1.0, 1.0, 1.0, textcasamadera.GLindex);
	glPopMatrix();

	//pared derecha de la puerta int
	glPushMatrix();
	glTranslatef(-9.6, 2.5, 5.2);
	glScalef(8.8, 4.9f, 0.3);
	glDisable(GL_LIGHTING);
	paredint.prisma(1.0, 1.0, 1.0, textparedint.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	

	//pared arriba puerta
	glPushMatrix();
	glTranslatef(-19.5, 4.4, 5);
	glScalef(11.0, 1.2f, 0.3);
	maderacasa.prisma(1.0, 1.0, 1.0, textcasamadera.GLindex);
	glPopMatrix();

	//pared arriba puerta int
	glPushMatrix();
	glTranslatef(-19.4, 4.4, 5.2);
	glScalef(10.9, 1.2f, 0.3);
	glDisable(GL_LIGHTING);
	paredint.prisma(1.0, 1.0, 1.0, textparedint.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	


	//ventana
	glPushMatrix();
	glTranslatef(-9.5, 2.0, 5.1);
	glScalef(2.0, 2.0f, 0.7);
	glDisable(GL_LIGHTING);
	ventanas.prisma(1.0, 1.0, 1.0, textventana.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//ventana
	glPushMatrix();
	glTranslatef(-19.5, 2.0, 5.1);
	glScalef(2.0, 2.0f, 0.7);
	glDisable(GL_LIGHTING);
	ventanas.prisma(1.0, 1.0, 1.0, textventana.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	
	//tejado
	glPushMatrix();
	glTranslatef(-5, 6.0, 5);
	glRotatef(90, 0, 0, 1);
	glScalef(2.0, 6.65f, 1.0);
	tejado.cilindro(1.0, 3.0, 3.0, texttejado.GLindex);
	glPopMatrix();


	//pared costado derecho
	glPushMatrix();
	glTranslatef(-24.9, 2.5f, 15.1);
	glScalef(0.2, 5.0f, 20.0);
	glDisable(GL_LIGHTING);
	maderacasa.prisma(1.0, 1.0, 1.0, textcasamadera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//pared costado derecho interior
	glPushMatrix();
	glTranslatef(-24.7, 2.5f, 15.1);
	glScalef(0.2, 4.9f, 20.0);
	glDisable(GL_LIGHTING);
	paredint.prisma(1.0, 1.0, 1.0, textparedint.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();




	//pared costado izquierdo
	glPushMatrix();
	glTranslatef(-5.2, 2.5f, 15.1);
	glScalef(0.2, 5.0f, 20.0);
	glDisable(GL_LIGHTING);
	maderacasa.prisma(1.0, 1.0, 1.0, textcasamadera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//pared costado izquierdo interior
	glPushMatrix();
	glTranslatef(-5.4, 2.5f, 15.1);
	glScalef(0.2, 4.9f, 20.0);
	glDisable(GL_LIGHTING);
	paredint.prisma(1.0, 1.0, 1.0, textparedint.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//piso
	glPushMatrix();
	glTranslatef(-15.0, 0.0f, 15.1);
	glScalef(19.4, .2f, 20);
	glDisable(GL_LIGHTING);
	piso1.prisma(1.0, 1.0, 1.0, textpiso1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//techo primer piso
	glPushMatrix();
	glTranslatef(-15.0, 5.0f, 15.1);
	glScalef(19.4, .2f, 20);
	glDisable(GL_LIGHTING);
	maderacasa.prisma(1.0, 1.0, 1.0, textcasamadera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//segundo piso
	glPushMatrix();
	glTranslatef(-15.0, 8.2f, 13.0);
	glScalef(19.4, 6.0f,15.0 );
	glDisable(GL_LIGHTING);
	maderacasa.prisma(1.0, 1.0, 1.0, textcasamadera.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//ventana superior izquierda
	glPushMatrix();
	glTranslatef(-9.5, 9.5, 5.6);
	glScalef(2.0, 1.5f, 0.4);
	ventanas.prisma(1.0, 1.0, 1.0, textventana.GLindex);
	glPopMatrix();


	//ventana superior central
	glPushMatrix();
	glTranslatef(-15.0, 9.5, 5.6);
	glScalef(2.0, 1.5f, 0.4);
	ventanas.prisma(1.0, 1.0, 1.0, textventana.GLindex);
	glPopMatrix();

	//ventana superior derecha
	glPushMatrix();
	glTranslatef(-21.0, 9.5, 5.6);
	glScalef(2.0, 1.5f, 0.4);
	ventanas.prisma(1.0, 1.0, 1.0, textventana.GLindex);
	glPopMatrix();

	//tejado segundo piso 
	glPushMatrix();
	glTranslatef(-5, 12.0, 5.6);
	glRotatef(90, 0, 0, 1);
	glScalef(1.5, 6.65f, 1.0);
	tejado.cilindro(1.0, 3.0, 3.0, texttejado.GLindex);
	glPopMatrix();


	glPopMatrix();//pop final



	


}






void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
				glEnable ( GL_COLOR_MATERIAL );
					glColor3f(1, 1, 1);
					glCallList(ciudad_display_list);
				glDisable ( GL_COLOR_MATERIAL );
			glPopMatrix();
			
			

			
			//globo
			glPushMatrix();
			glTranslatef(movglovx,0,movglovz);
			glTranslatef(-7, 3, 23);
			glScalef(0.2, 0.2, 0.2);
			glPushMatrix();
			glTranslatef(0, 2, 0);
			glScalef(1, 2, 2);
			globo.esfera(1, 10, 10, textglobo.GLindex);

			glPopMatrix();

			glPopMatrix();
		




			glPushMatrix();
			glRotatef(180, 0, 1, 0);
			tele(1, 0.8, 1, 22, 1, -14);
			glPopMatrix();

			

			glPushMatrix();
			casa();


			glPushMatrix();
			buros(0.5, 0.5, 0.5, -37, 3.0, 48);
			glPopMatrix();


			glPushMatrix();
			cama(1, 0.5, 1, -22, 2.0, 19);
			glPopMatrix();

			glPushMatrix();
			glRotatef(90, 0, 1,0 );
			librero(0.6, 0.4, 0.7, -30, 5.0, -10);
			glPopMatrix();

			glPushMatrix();
			librero(0.6, 0.4, 0.7, -22, 5.0, 33);
			glPopMatrix();


			//balon
			glPushMatrix();
			
			glTranslatef(0, bota, 0);
			glTranslatef(-7, 0.5, 15.0);
			glScalef(0.4, 0.4, 0.4);
			balon.esfera(1, 20, 20, textbalon.GLindex);
			glPopMatrix();
			if (bota>1)
			{
				p_animacion1 = false;
				p_animacion2 = true;
			}
			if (bota<0)
			{
				p_animacion2 = false;
				p_animacion1 = true;
			}


			glPopMatrix();

			//lirbro
			
			glPushMatrix();
			
			glTranslatef(-7, 2.3, 19);
			
			//portada
			glPushMatrix();	
			glTranslatef(0, 0.64, -0.53);		
			glTranslatef(0, -0.5, 0.0);
			glRotatef(open2, 1, 0, 0);
			glRotatef(90, 1, 0, 0);
			glTranslatef(0, 0.5, 0.0);
			glScalef(1.5, 1.0f,0.03);
			glRotatef(180, 0, 1, 0);
			glDisable(GL_LIGHTING);
			portada1.prisma(1.0, 1.0, 1.0, textportada1.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			
			//lomo del libro
			glPushMatrix();
			glTranslatef(0, 0.0, -0.53);
			glRotatef(180, 1, 0, 0);
			glScalef(1.5, 0.3f, 0.05);
			glDisable(GL_LIGHTING);
			lomo.prisma(1.0, 1.0, 1.0, textlomo.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();



			glPushMatrix();
			glScalef(1.5, 0.3, 1);
			pagina.prisma(1, 1, 1, textpag.GLindex);
			glPopMatrix();


			glPopMatrix();

			glEnable ( GL_COLOR_MATERIAL );
			

			

			glColor3f(1.0,1.0,1.0);

		glPopMatrix(); 

	glPopMatrix();

	glutSwapBuffers ( );

}

void animacion()
{
	
		fig3.text_izq-= 0.001;
		fig3.text_der-= 0.001;
		if(fig3.text_izq<-1)
			fig3.text_izq=0;
		if(fig3.text_der<0)
			fig3.text_der=1;

	
		
		
		if (p_animacion)
		{
			open = open+0.3;
			if (open>90)
			{
				p_animacion = false;
			}


		}


		if (p_animacion3)
		{
			open2 = open2 - 0.3;
			if (open2 < -200)
			{
				p_animacion3 = false;
			}


		}



		if (p_animacion1)
		{
			bota += 0.03;
		}

		if (p_animacion2)
		{
			bota -= 0.03;
		}




		if (circuito)
		{
			if (recorrido1)
			{
				movglovz=movglovz-0.05;
				if (movglovz<-17)
				{
					recorrido1 = false;
						recorrido2 = true;
				}
			}
			if (recorrido2)
			{
				movglovx=movglovx-0.05;
				if (movglovx<-16)
				{
					recorrido2 = false;
					recorrido3 = true;
				}
			}

			if (recorrido3)
			{
				movglovz=movglovz+.05;
				if (movglovz>1)
				{
					recorrido3 = false;
					recorrido4 = true;
				}

			}
			if (recorrido4)
			{
				movglovx=movglovx+0.05;
				if (movglovx>1)
				{
					recorrido4 = false;
					recorrido5 = true;
				}
			}
		
		
		
		
		
		
		}










	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'X':
		case 'x':
			p_animacion^=true;
			break;

		case 'C':
		case 'c':
			p_animacion1 ^= true;
			break;
		
		case 'V':
		case 'v':
			p_animacion3 ^= true;
			break;

		case 'B':
		case 'b':
			circuito ^= true;
			break;





		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Final"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
