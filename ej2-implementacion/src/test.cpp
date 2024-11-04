#include <iostream>
#include "vecmatriz.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;

int test() {

  // NOTE: Se corrigió el producto cruz, había error en eso, por lo tanto
  // también el el lookAt
  // NOTE: Estaba mal el lookat, algunos vectores van en un lugar distinto
  // (el acomodo de la matriz)

  cout << endl << "----- LookAt " << endl;

  glm::vec3 eye(4, 2, 2);
  glm::vec3 center(0, 0, 0);
  glm::vec3 up(0, 1, 0);
  glm::mat4 look = glm::lookAt(eye, center, up);

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cout << look[j][i] << " ";
    }
    cout << endl;
  }

  glm::mat4 lookt = glm::transpose(look);
  cout << "transpuesta" << endl;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cout << lookt[j][i] << " ";
    }
    cout << endl;
  }

  Vector3 cam(4, 2, 2);
  Vector3 centroCubo(0, 0, 0);

  Matrix4 look2 = Matrix4::lookAt(cam, centroCubo, Vector3(0, 1, 0));

  cout << look2 << endl;

  if (false) {
  
  glm::vec3 f = glm::normalize(center - eye);
  cout << "glm f/u (center - eye) = <" << f[0] << ", " << f[1] << ", " << f[2] << ">" << endl;

  Vector3 u = Vector3::subtract(cam, centroCubo).normalize();
  cout << "vecmatriz f/u (eye - center) = " << u << endl;
  // Correcto (solo símbolos opuestos)

  glm::vec3 s(normalize(cross(f, up)));
  cout << "glm s/w (f/u x up) = <" << s[0] << ", " << s[1] << ", " << s[2] << ">" << endl;

  Vector3 w = Vector3::cross(u, Vector3(0, 1, 0)).normalize();
  cout << "vecmatriz s/w (f/u x w) = " << w << endl;
  // Correcto solo algunos símbolos mal

  glm::vec3 u2(cross(s, f));
  cout << "glm u/v (s/w x f/u) = <" << u2[0] << ", " << u2[1] << ", " << u2[2] << ">" << endl;

  Vector3 v = Vector3::cross(u, w).normalize();
  cout << "vecmatriz u/v (s/w x f/u) = " << v << endl;
  // Son totalmente distintos (ya no, signos opuestos)
  }


  if (false) {
  cout << "---- Usando mismos signos" << endl;
  
  glm::vec3 f = glm::normalize(center - eye);
  cout << "glm f/u (center - eye) = <" << f[0] << ", " << f[1] << ", " << f[2] << ">" << endl;

  Vector3 u = Vector3::subtract(centroCubo, cam).normalize();
  cout << "vecmatriz f/u (center - eye) = " << u << endl;
  // Correcto (solo símbolos opuestos)

  glm::vec3 s(normalize(cross(f, up)));
  cout << "glm s/w (f/u x up) = <" << s[0] << ", " << s[1] << ", " << s[2] << ">" << endl;

  Vector3 w = Vector3::cross(u, Vector3(0, 1, 0)).normalize();
  cout << "vecmatriz s/w (f/u x w) = " << w << endl;
  // Correcto solo algunos símbolos mal

  glm::vec3 u2(cross(s, f));
  cout << "glm u/v (s/w x f/u) = <" << u2[0] << ", " << u2[1] << ", " << u2[2] << ">" << endl;

  Vector3 v = Vector3::cross(w, u).normalize();
  cout << "vecmatriz u/v (s/w x f/u) = " << v << endl;
  // Son totalmente distintos (ya no, son signos opuestos)
  }

  cout << endl << endl << "---- Perspectiva " << endl;


  glm::mat4 pers = glm::perspective(M_PI/3.0, 1000.0/800.0, 1.0, 8.0);

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cout << pers[j][i] << " ";
    }
    cout << endl;
  }

  Matrix4 persp = Matrix4::perspective(60, 1000.0/800.0, 1, 8);
  cout << persp << endl;

  cout << endl << endl << "----- Todo " << endl;

  glm::vec4 cubo[8] = {
    glm::vec4(1.0, 1.0, 1.0, 1.0),
    glm::vec4(1.0, 1.0, -1.0, 1.0),
    glm::vec4(1.0, -1.0, 1.0, 1.0),
    glm::vec4(1.0, -1.0, -1.0, 1.0),
    glm::vec4(-1.0, 1.0, 1.0, 1.0),
    glm::vec4(-1.0, 1.0, -1.0, 1.0),
    glm::vec4(-1.0, -1.0, 1.0, 1.0),
    glm::vec4(-1.0, -1.0, -1.0, 1.0)
  };

  for (int i = 0; i < 8; i++) {
    cubo[i] = look * cubo[i];
    cout << "<" << cubo[i][0] << ", " << cubo[i][1] << ", " << cubo[i][2] << ", " << cubo[i][3] << ">" << endl;
  }
  
  cout << "----" << endl;

  for (int i = 0; i < 8; i++) {
    cubo[i] = pers * cubo[i];
    cout << "<" << cubo[i][0] << ", " << cubo[i][1] << ", " << cubo[i][2] << ", " << cubo[i][3] << ">" << endl;
  }

  cout << "----" << endl;

  cout << endl << "--- Fin test " << endl;
  return 0;
}
