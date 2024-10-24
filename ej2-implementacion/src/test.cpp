#include <iostream>
#include "vecmatriz.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;

int test() {

  // NOTE: Se corrigió el producto cruz, había error en eso, por lo tanto
  // también el el lookAt

  glm::vec3 eye(4, 0, 2);
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

  Vector3 cam(4, 0, 2);
  Vector3 centroCubo(0, 0, 0);

  Matrix4 look2 = Matrix4::lookAt(cam, centroCubo, Vector3(0, 1, 0));

  cout << look2 << endl;

  if (true) {
  
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

  cout << "---- Usando mismos signos" << endl;

  if (true) {
  
  glm::vec3 f = glm::normalize(center - eye);
  cout << "glm f/u (center - eye) = <" << f[0] << ", " << f[1] << ", " << f[2] << ">" << endl;

  Vector3 u = Vector3::subtract(centroCubo, cam).normalize();
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
  // Son totalmente distintos (ya no, son signos opuestos)
  }

  return 0;
}