#include "meshtri.h"
#include "matrices.h"


MeshTri::MeshTri()
{
}



void MeshTri::gl_init()
{
	m_shader_flat = new ShaderProgramFlat();
	m_shader_phong = new ShaderProgramPhong();

	//VBO
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_vbo2);

	//VAO
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glEnableVertexAttribArray(m_shader_flat->idOfVertexAttribute);
	glVertexAttribPointer(m_shader_flat->idOfVertexAttribute, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindVertexArray(0);

	//VAO2
	glGenVertexArrays(1, &m_vao2);
	glBindVertexArray(m_vao2);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glEnableVertexAttribArray(m_shader_phong->idOfVertexAttribute);
	glVertexAttribPointer(m_shader_phong->idOfVertexAttribute, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo2);
	glEnableVertexAttribArray(m_shader_phong->idOfNormalAttribute);
	glVertexAttribPointer(m_shader_phong->idOfNormalAttribute, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindVertexArray(0);

	//EBO indices
	glGenBuffers(1, &m_ebo);
}

void MeshTri::gl_update()
{
	//VBO
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, 3 * m_points.size() * sizeof(GLfloat), &(m_points[0][0]), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo2);
	glBufferData(GL_ARRAY_BUFFER, 3 * m_normals.size() * sizeof(GLfloat), &(m_normals[0][0]), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//EBO indices
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,m_indices.size() * sizeof(int), &(m_indices[0]), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}



void MeshTri::set_matrices(const Mat4& view, const Mat4& projection)
{
	viewMatrix = view;
	projectionMatrix = projection;
}


void MeshTri::draw(const Vec3& color)
{
	m_shader_flat->startUseProgram();

	m_shader_flat->sendViewMatrix(viewMatrix);
	m_shader_flat->sendProjectionMatrix(projectionMatrix);

	glUniform3fv(m_shader_flat->idOfColorUniform, 1, glm::value_ptr(color));

	glBindVertexArray(m_vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_ebo);
	glDrawElements(GL_TRIANGLES, m_indices.size(),GL_UNSIGNED_INT,0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	glBindVertexArray(0);

	m_shader_flat->stopUseProgram();
}


void MeshTri::draw_smooth(const Vec3& color)
{
	m_shader_phong->startUseProgram();

	m_shader_phong->sendViewMatrix(viewMatrix);
	m_shader_phong->sendProjectionMatrix(projectionMatrix);

	glUniform3fv(m_shader_phong->idOfColorUniform, 1, glm::value_ptr(color));

	glBindVertexArray(m_vao2);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_ebo);
	glDrawElements(GL_TRIANGLES, m_indices.size(),GL_UNSIGNED_INT,0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	glBindVertexArray(0);

	m_shader_phong->stopUseProgram();
}


void MeshTri::clear()
{
    m_points.clear();
    m_normals.clear();
    m_indices.clear();
}


int MeshTri::add_vertex(const Vec3& P)
{
    m_points.push_back(P);
    return m_points.size()-1;
}

int MeshTri::add_normal(const Vec3& N)
{
    m_normals.push_back(N);
    return m_normals.size()-1;
}

void MeshTri::add_tri(int i1, int i2, int i3)
{
    m_indices.push_back(i1);
    m_indices.push_back(i2);
    m_indices.push_back(i3);
}

void MeshTri::add_quad(int i1, int i2, int i3, int i4)
{
    // decoupe le quad en 2 triangles: attention a l'ordre

    // Triangle 1
    m_indices.push_back(i1);
    m_indices.push_back(i2);
    m_indices.push_back(i3);

    // Triangle 2
    m_indices.push_back(i1);
    m_indices.push_back(i3);
    m_indices.push_back(i4);
}


void MeshTri::create_pyramide()
{
    clear();
    /*
    Vec3 tmp0(-1,0,0), tmp1(1,0,0), tmp2(0,3,0), tmp3(2,3,0);
    add_vertex(tmp0);
    add_vertex(tmp1);
    add_vertex(tmp2);
    add_vertex(tmp3);
    */
    // add_tri(0, 1, 2);

    Vec3 b0(-1,-1,-1),b1(-1,-1,1),b2(1,-1,1),b3(1,-1,-1),b4(0,1,0);
    add_vertex(b0);add_vertex(b1);add_vertex(b2);add_vertex(b3);add_vertex(b4);

    add_quad(3,2,1,0);

    add_tri(0,1,4);
    add_tri(1,2,4);
    add_tri(2,3,4);
    add_tri(3,0,4);

	gl_update();
}

void MeshTri::create_anneau()
{
	clear();

    float alpha = 0.0;
    for(alpha=0.0;alpha<=2*3.141592;alpha+=0.1)
    {
        add_vertex(Vec3(0.5*std::cos(alpha),0.5*std::sin(alpha),0));
        add_vertex(Vec3(1.0*std::cos(alpha),1.0*std::sin(alpha),0));

        add_quad(m_points.size()-4,m_points.size()-3,m_points.size()-1,m_points.size()-2);
    }
    add_quad(m_points.size()-2,m_points.size()-1,1,0);

	gl_update();
}

void MeshTri::create_spirale()
{
	clear();

    float alpha = 0.0;

    add_vertex(Vec3(0.8,0,0));
    add_vertex(Vec3(1,0,0));

    for(alpha=0.0;alpha<=10*3.141592;alpha+=0.005)
    {
        add_vertex(Vec3( (0.8-(alpha/40))*std::cos(alpha)
                        ,(0.8-(alpha/40))*std::sin(alpha)
                        ,alpha/40));
        add_vertex(Vec3( (1.0-(alpha/40))*std::cos(alpha)
                        ,(1.0-(alpha/40))*std::sin(alpha)
                        ,alpha/40));
        /*
        add_vertex(Vec3((alpha/30)*cos(alpha),(alpha/30)*sin(alpha),alpha/30));
        add_vertex(Vec3(((alpha/30)+0.2)*cos(alpha),((alpha/30)+0.2)*sin(alpha),alpha/30));
        */
        add_quad(m_points.size()-4,m_points.size()-3,m_points.size()-1,m_points.size()-2);
    }


	gl_update();
}


void MeshTri::revolution(const std::vector<Vec3>& poly)
{
	clear();

	// Faire varier angle 0 -> 360 par pas de D degre
	//   Faire tourner les sommets du polygon -> nouveau points

	// on obtient une grille de M (360/D x poly.nb) points

	// creation des quads qui relient ces points
	// attention la derniere rangee doit etre reliee a la premiere

	// on peut fermer le haut et le bas par ube ombrelle de triangles
	gl_update();
}

void MeshTri::compute_normals()
{
	// ALGO:
	// init des normale a 0,0,0
	// Pour tous les triangles
	//   calcul de la normale -> N
	//   ajout de N au 3 normales des 3 sommets du triangles
	// Fin_pour
	// Pour toutes les normales
	//   normalisation
	// Fin_pour


}

