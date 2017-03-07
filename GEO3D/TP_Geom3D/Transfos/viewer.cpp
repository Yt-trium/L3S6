#include "viewer.h"

#include <QKeyEvent>
#include <iomanip>


Viewer::Viewer():
	QGLViewer(),
	ROUGE(1,0,0),
	VERT(0,1,0),
	BLEU(0,0,1),
	JAUNE(1,1,0),
	CYAN(0,1,1),
	MAGENTA(1,0,1),
	BLANC(1,1,1),
	GRIS(0.5,0.5,0.5),
	NOIR(0,0,0),
    m_code(3)
{}


void Viewer::init()
{
	makeCurrent();
	glewExperimental = GL_TRUE;
	int glewErr = glewInit();
	if( glewErr != GLEW_OK )
	{
		qDebug("Error %s", glewGetErrorString(glewErr) ) ;
	}
	std::cout << "GL VERSION = " << glGetString(GL_VERSION) << std::endl;

	// la couleur de fond
	glClearColor(0.2,0.2,0.2,0.0);

	// QGLViewer initialisation de la scene
	setSceneRadius(9.0);
	setSceneCenter(qglviewer::Vec(0.0,0.0,0.0));
	camera()->showEntireScene();

	// initilisation des primitives
	m_prim.gl_init();

	// initialisation variables globales
	m_compteur = 0;
	m_angle1 = 0.0;
	m_angle2 = 0.0;

    /*
     * Testez la création des différentes matrices de transformations en les affichant
     * Appliquez ces transformations au point 2,2,2
     * Faites une composition de Translation et de Rotation/Z
     * Vérifier que Translation + Rotation ≠ Rotation + Translation
    */
    /*
    Vec3 p = Vec3(2,2,2);
    Vec4 p1 = Vec4(p,1);
    Mat4 mt = translate(5,1,2);
    Mat4 mr = rotateZ(42);

    Vec4 p2 = p1;
    Vec4 p3 = p1;
    Vec4 p4 = p1;
    p2 = (mt * mr) * p2;
    p3 = (mr * mt) * p3;
    p4 = mt * p4;

    std::cout << "P1 :"   << Vec3(p1)
              << "\nP2 :" << Vec3(p2)
              << "\nP3 :" << Vec3(p3)
              << "\nP4 :" << Vec3(p4)
              << std::endl;
    */
}



void Viewer::draw_repere(const Mat4& global)
{
	//	// exemple de definition de fonction (lambda) locale
	//	float b=2.2f;
	//	auto fonction_locale = [&] (float a)
	//	{
	//		std::cout << "param a="<< a << " & global b="<< b <<std::endl;
	//	};

	//	//appel
	//	fonction_locale(1.1f);


    auto fleche = [&] (float x, float y, float z, Vec3 color) -> void
    {
        Mat4 cyl = global * rotateX(x)*rotateY(y)*rotateZ(z)* scale(1,1,5)*translate(0,0,0.6);
        Mat4 con = global * rotateX(x)*rotateY(y)*rotateZ(z)* scale(2,2,2)*translate(0,0,3);

        m_prim.draw_cylinder(cyl,color);
        m_prim.draw_cone(con,color);
    };

    auto fleche_ = [&] (Mat4 tr, Vec3 coul) -> void
    {
        m_prim.draw_cylinder(tr*translate(0,0,1.5)*scale(0.5,0.5,1.95),coul);
        m_prim.draw_cone(tr*translate(0,0,3),coul);
    };
    /*
    fleche(0,90,0,ROUGE);
    fleche(-90,0,0,VERT);
    fleche(0,0,0,BLEU);
    */
    m_prim.draw_sphere(global,BLANC);
    fleche_(global,BLEU);
    fleche_(global*rotateY(90),ROUGE);
    fleche_(global*rotateX(-90),VERT);
}



void Viewer::draw_main()
{
    auto angle = [&] (int x) -> float
    {
        float y = x;
        return y;
    };

    auto doigt = [&] (Mat4 tr, float longueur) -> void
    {
        /*
        float alpha = angle(m_compteur);
        m_prim.draw_cube(tr*translate(longueur/2+longueur*2,alpha/7,0)*rotateZ(3*alpha)*scale(longueur,0.5,1),BLEU);
        m_prim.draw_sphere(tr*translate(longueur*2,0,0),BLANC);
        m_prim.draw_cube(tr*translate(longueur/2+longueur,alpha/20,0)*rotateZ(2*alpha)*scale(longueur,0.5,1),VERT);
        m_prim.draw_sphere(tr*translate(longueur,0,0),BLANC);
        m_prim.draw_cube(tr*translate(longueur/2,alpha/100,0)*rotateZ(alpha)*scale(longueur,0.5,1),ROUGE);
        m_prim.draw_sphere(tr,BLANC);
        */
        float a = angle(m_compteur);
        m_prim.draw_sphere(tr, BLANC);
        m_prim.draw_cube(tr*rotateZ(a)*translate(1.5,0,0)*scale(2.0,0.5,0.8),ROUGE);

        tr *= rotateZ(a)*translate(3,0,0);

        m_prim.draw_sphere(tr, BLANC);
        m_prim.draw_cube(tr*rotateZ(a)*translate(1.5,0,0)*scale(2.0,0.5,0.8),VERT);

        tr *= rotateZ(a)*translate(3,0,0);

        m_prim.draw_sphere(tr, BLANC);
        m_prim.draw_cube(tr*rotateZ(a)*translate(1.5,0,0)*scale(2.0,0.5,0.8),BLEU);

    };

    auto main = [&] (Mat4 tr) -> void
    {
        m_prim.draw_cube(tr*scale(4,0.5,4),CYAN);
        doigt(tr*translate(2,0,-1.5)*rotateY(10),2.1);
        doigt(tr*translate(2,0,0),2.2);
        doigt(tr*translate(2,0,1.5)*rotateY(-5),2);
        doigt(tr*translate(0,0,-2)*rotateY(70),1.2);
    };
    Mat4 base;
    // doigt(base, 2);

    m_prim.draw_sphere(base*translate(-17,0,0),BLANC);
    m_prim.draw_cube(base*translate(-12.5,0,0)*scale(8,3,4),CYAN);

    m_prim.draw_sphere(base,BLANC);

    m_prim.draw_cube(base*translate(-4,0,0)*scale(8,1.5,2),CYAN);
    m_prim.draw_sphere(base*translate(-8.25,0,0),BLANC);

    main(base*translate(2.1,0,0));
}

void Viewer::draw_basic()
{
	m_prim.draw_sphere(Mat4(), BLANC);
	m_prim.draw_cube(translate(3,0,0), ROUGE);
	m_prim.draw_cone(translate(0,3,0), VERT);
	m_prim.draw_cylinder(translate(0,0,3), BLEU);
}

void Viewer::draw()
{
	makeCurrent();
	m_prim.set_matrices(getCurrentModelViewMatrix(),getCurrentProjectionMatrix());

	Mat4 glob;

	switch(m_code)
	{
		case 0:
			draw_basic();
		break;
		case 1:
			draw_repere(glob);
		break;
		case 2:
            // coder ici les petits reperes qui tournet autour du grand repere
            draw_repere(glob);
            for(int x = 0; x < 8 ; x++)
                draw_repere(rotateZ(10)*
                            rotateY(-m_compteur+45*x)*
                            translate(6,0,0)*
                            rotateY(-90)*
                            rotateX(m_compteur)*
                            scale(0.5,0.5,0.5));

		break;
		case 3:
			draw_main();
		break;
	}
}


void Viewer::keyPressEvent(QKeyEvent *e)
{

	if (e->modifiers() & Qt::ShiftModifier)
	{
		std::cout << "Shift is on"<< std::endl;
	}

	if (e->modifiers() & Qt::ControlModifier)
	{
		std::cout << "Control is on"<< std::endl;
	}

	switch(e->key())
	{
		case Qt::Key_Escape:
			exit(EXIT_SUCCESS);
			break;

		case Qt::Key_A: // touche 'a'
			if (animationIsStarted())
				stopAnimation();
			else
				startAnimation();
			break;

		case Qt::Key_M:  // change le code execute dans draw()
			m_code = (m_code+1)%4;
			break;
		default:
			break;
	}

	// retrace la fenetre
	updateGL();
	// passe la main a la QGLViewer
	QGLViewer::keyPressEvent(e);
}



void Viewer::animate()
{
    static int sens;
    if(m_code == 3)
    {
        if(m_compteur == 0)
            sens = 1;
        if(m_compteur == 40)
            sens = -1;

        m_compteur += sens;
    }
    else
    {
        m_compteur += 1;
        m_compteur = m_compteur%360;
    }
}




Mat4 Viewer::getCurrentModelViewMatrix() const
{
	GLdouble gl_mvm[16];
	camera()->getModelViewMatrix(gl_mvm);
	Mat4 mvm;
	for(unsigned int i = 0; i < 4; ++i)
	{
		for(unsigned int j = 0; j < 4; ++j)
			mvm[i][j] = float(gl_mvm[i*4+j]);
	}
	return mvm;
}


Mat4 Viewer::getCurrentProjectionMatrix() const
{
	GLdouble gl_pm[16];
	camera()->getProjectionMatrix(gl_pm);
	Mat4 pm;
	for(unsigned int i = 0; i < 4; ++i)
	{
		for(unsigned int j = 0; j < 4; ++j)
			pm[i][j] = float(gl_pm[i*4+j]);
	}
	return pm;
}
