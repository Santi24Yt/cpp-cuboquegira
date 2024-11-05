#include "vecmatriz.h"
#include "imagen.h"
#include <SFML/Graphics.hpp>
// #include <iostream>

using namespace std;

int test();

Matrix4 gentransf(Matrix4 &rot, Matrix4 &trans, Matrix4 &scale) {
  return Matrix4::multiply(Matrix4::multiply(rot, trans), scale);
}

int main() {

  // test();

  Imagen<1000, 800> img1;

  Vector4 cubo[8] = {
    {1, 1, 1, 1},
    {1, 1, -1, 1},
    {1, -1, 1, 1},
    {1, -1, -1, 1},
    {-1, 1, 1, 1},
    {-1, 1, -1, 1},
    {-1, -1, 1, 1},
    {-1, -1, -1, 1},
  };

  Vector4 ejes[3][2] = {
    { Vector4(0,0,0,1), Vector4(1,0,0,1) },
    { Vector4(0,0,0,1), Vector4(0,1,0,1) },
    { Vector4(0,0,0,1), Vector4(0,0,1,1) }
  };
  
  /* V * Modelo * Vista * Proyección */

  Vector3 cam(4, 2, 0);
  Vector3 centroCubo(0, 0, 0);

  Matrix4 look = Matrix4::lookAt(cam, centroCubo, Vector3(0, 1, 0));
  Matrix4 persp = Matrix4::perspective(90, 1000.0/800.0, 0, 8);
  // Matrix4 orth = Matrix4::orthographic(2, -2, -2, 2, -2, 2);
  Matrix4 rot = Matrix4();
  Matrix4 trans = Matrix4();
  Matrix4 scale = Matrix4();
  
  Matrix4 transf = gentransf(rot, trans, scale);
  Matrix4 vista = Matrix4::multiply(look, persp);
  Vector4 cuboimg[8];
  for (int i = 0; i < 8; i++) {
    cuboimg[i] = cubo[i];
  }

  Vector4 ejesimg[3][2];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      ejesimg[i][j] = ejes[i][j];
    }
  }

  bool showpoints = true;
  int aristas[12][2] = {{0,1}, {1,3}, {3,2}, {2,0}, {0,4}, {4,5}, {5,1}, {5,7}, {7,3}, {7,6}, {6,4}, {6,2}};
  unsigned int colors[12] = {0xFF0000FF, 0x00FF00FF, 0x0000FFFF, 0xFFFF00FF,
                             0x00FFFFFF, 0xFF00FFFF, 0xFFFFFFFF, 0xF0A000FF,
                             0x00F0A0FF, 0xF000A0FF, 0xF0A0F0FF, 0xADC034FF};
  int rotspeedy = 0;
  int rotspeedx = 0;
  int rotspeedz = 0;
  double scalex = 1.0;
  double scaley = 1.0;
  double scalez = 1.0;
  double speedx = 0.0;
  double speedy = 0.0;
  double speedz = 0.0;

  sf::RenderWindow window(sf::VideoMode(img1.width, img1.height), "Cubo que gira");
  window.setFramerateLimit(144);

  while(window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        // cerr << "debug: cerrando" << endl;
      }

      if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
          case sf::Keyboard::Z:
            rotspeedy = (rotspeedy + 1) % 11;
            rot = Matrix4::rotateY((M_PI*(0.2*rotspeedy))/144);
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::X:
            rotspeedy = (rotspeedy - 1) % 11;
            rot = Matrix4::rotateY((M_PI*(0.2*rotspeedy))/144);
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::V:
            rotspeedx = (rotspeedx + 1) % 11;
            rot = Matrix4::rotateX((M_PI*(0.2*rotspeedx))/144);
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::C:
            rotspeedx = (rotspeedx - 1) % 11;
            rot = Matrix4::rotateX((M_PI*(0.2*rotspeedx))/144);
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::B:
            rotspeedz = (rotspeedz + 1) % 11;
            rot = Matrix4::rotateZ((M_PI*(0.2*rotspeedz))/144);
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::N:
            rotspeedz = (rotspeedz - 1) % 11;
            rot = Matrix4::rotateZ((M_PI*(0.2*rotspeedz))/144);
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::E:
            scalex = 1.1;
            scale = Matrix4::scale(scalex, scaley, scalez);
            transf = gentransf(rot, trans, scale);
            for (int i = 0; i < 8; i++) {
              cubo[i] = transf.multiplyVector(cubo[i]);
              cuboimg[i] = cubo[i];
            }
            scale = Matrix4();
            scalex = 1.0;
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::R:
            scalex = 0.9;
            scale = Matrix4::scale(scalex, scaley, scalez);
            transf = gentransf(rot, trans, scale);
            for (int i = 0; i < 8; i++) {
              cubo[i] = transf.multiplyVector(cubo[i]);
              cuboimg[i] = cubo[i];
            }
            scale = Matrix4();
            scalex = 1.0;
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::T:
            scaley = 1.1;
            scale = Matrix4::scale(scalex, scaley, scalez);
            transf = gentransf(rot, trans, scale);
            for (int i = 0; i < 8; i++) {
              cubo[i] = transf.multiplyVector(cubo[i]);
              cuboimg[i] = cubo[i];
            }
            scale = Matrix4();
            scaley = 1.0;
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::Y:
            scaley = 0.9;
            scale = Matrix4::scale(scalex, scaley, scalez);
            transf = gentransf(rot, trans, scale);
            for (int i = 0; i < 8; i++) {
              cubo[i] = transf.multiplyVector(cubo[i]);
              cuboimg[i] = cubo[i];
            }
            scale = Matrix4();
            scaley = 1.0;
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::U:
            scalez = 1.1;
            scale = Matrix4::scale(scalex, scaley, scalez);
            transf = gentransf(rot, trans, scale);
            for (int i = 0; i < 8; i++) {
              cubo[i] = transf.multiplyVector(cubo[i]);
              cuboimg[i] = cubo[i];
            }
            scale = Matrix4();
            scalez = 1.0;
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::I:
            scalez = 0.9;
            scale = Matrix4::scale(scalex, scaley, scalez);
            transf = gentransf(rot, trans, scale);
            for (int i = 0; i < 8; i++) {
              cubo[i] = transf.multiplyVector(cubo[i]);
              cuboimg[i] = cubo[i];
            }
            scale = Matrix4();
            scalez = 1.0;
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::W:
            speedx = speedx + 0.1;
            trans = Matrix4::translate(speedx/144, speedy/144, speedz/144);
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::S:
            speedx = speedx - 0.1;
            trans = Matrix4::translate(speedx/144, speedy/144, speedz/144);
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::A:
            speedz = speedz + 0.1;
            trans = Matrix4::translate(speedx/144, speedy/144, speedz/144);
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::D:
            speedz = speedz - 0.1;
            trans = Matrix4::translate(speedx/144, speedy/144, speedz/144);
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::K:
            speedy = speedy - 0.1;
            trans = Matrix4::translate(speedx/144, speedy/144, speedz/144);
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::L:
            speedy = speedy + 0.1;
            trans = Matrix4::translate(speedx/144, speedy/144, speedz/144);
            transf = gentransf(rot, trans, scale);
            break;
          case sf::Keyboard::Space:
            cam = Vector3(cam.x, cam.y+1.0, cam.z);
            look = Matrix4::lookAt(cam, centroCubo, Vector3(0, 1, 0));
            vista = Matrix4::multiply(look, persp);
            break;
          case sf::Keyboard::LShift:
          case sf::Keyboard::RShift:
            cam = Vector3(cam.x, cam.y-1.0, cam.z);
            look = Matrix4::lookAt(cam, centroCubo, Vector3(0, 1, 0));
            vista = Matrix4::multiply(look, persp);
            break;
          case sf::Keyboard::Left:
            cam = Vector3(cam.x, cam.y, cam.z-1.0);
            look = Matrix4::lookAt(cam, centroCubo, Vector3(0, 1, 0));
            vista = Matrix4::multiply(look, persp);
            break;
          case sf::Keyboard::Right:
            cam = Vector3(cam.x, cam.y, cam.z+1.0);
            look = Matrix4::lookAt(cam, centroCubo, Vector3(0, 1, 0));
            vista = Matrix4::multiply(look, persp);
            break;
          case sf::Keyboard::Up:
            cam = Vector3(cam.x-1.0, cam.y, cam.z);
            look = Matrix4::lookAt(cam, centroCubo, Vector3(0, 1, 0));
            vista = Matrix4::multiply(look, persp);
            break;
          case sf::Keyboard::Down:
            cam = Vector3(cam.x+1.0, cam.y, cam.z);
            look = Matrix4::lookAt(cam, centroCubo, Vector3(0, 1, 0));
            vista = Matrix4::multiply(look, persp);
            break;
          default:
            break;
        }
      }
    }

    img1.clear();

    for (int i = 0; i < 8; i++) {
      cubo[i] = transf.multiplyVector(cubo[i]);
      cuboimg[i] = cubo[i];
    }

    for (int i = 0; i < 8; i++) {
      cuboimg[i] = vista.multiplyVector(cubo[i]);
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 2; j++) {
        ejesimg[i][j] = vista.multiplyVector(ejes[i][j]);
      }
    }

    for (int i = 0; i < 8; i++) {
      double w = cuboimg[i].w;
      cuboimg[i] = Vector4(cuboimg[i].x/w, cuboimg[i].y/w, cuboimg[i].z, cuboimg[i].w);
      // cout << cuboimg[i] << endl;
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 2; j++) {
        double w = ejesimg[i][j].w;
        ejesimg[i][j] = Vector4(ejesimg[i][j].x/w, ejesimg[i][j].y/w, ejesimg[i][j].z, ejesimg[i][j].w);
      }
    }

    // cout << "-----" << endl;

    if (showpoints) {
      for (int i = 0; i < 8; i++) {
        int x = (cuboimg[i].x + 1)/2 * 1000;
        int y = (cuboimg[i].y + 1)/2 * 800;
        img1.fillpoint(x, y, 0xAAAAAAFF, 5);
        // cout << "x: " << x << " y: " << y << endl;
      }
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 2; j++) {
        int x = (ejesimg[i][j].x + 1)/2 * 1000;
        int y = (ejesimg[i][j].y + 1)/2 * 800;
        img1.fillpoint(x, y, colors[i], 5);
        // cout << "x: " << x << " y: " << y << endl;
      }
    }
    

    for (int i = 0; i < 12; i++)
    {
      int i1 = aristas[i][0];
      int i2 = aristas[i][1];
      int x = (cuboimg[i1].x + 1)/2 * 1000;
      int y = (cuboimg[i1].y + 1)/2 * 800;
      int x2 = (cuboimg[i2].x + 1)/2 * 1000;
      int y2 = (cuboimg[i2].y + 1)/2 * 800;
      img1.bresenham({x, y}, {x2, y2}, colors[i]);
    }

    for (int i = 0; i < 3; i++) {
      int x = (ejesimg[i][0].x + 1)/2 * 1000;
      int y = (ejesimg[i][0].y + 1)/2 * 800;
      int x2 = (ejesimg[i][1].x + 1)/2 * 1000;
      int y2 = (ejesimg[i][1].y + 1)/2 * 800;
      img1.bresenham({x, y}, {x2, y2}, colors[i]);
    }

    sf::Texture texture;
    texture.create(img1.width, img1.height);
    texture.update(img1.toBuffer().data);

    sf::Sprite sprite(texture);

    window.clear();
    window.draw(sprite);
    window.display();
  }
}