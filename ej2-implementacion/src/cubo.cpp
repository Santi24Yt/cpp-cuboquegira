#include "vecmatriz.h"
#include "imagen.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int test();

int main() {

  return test();

  Imagen<800, 800> img1;

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
  
  /* V * Modelo * Vista * Proyección */

  Vector3 cam(4, 0, 0);
  Vector3 centroCubo(0, 0, 0);

  Matrix4 look = Matrix4::lookAt(cam, centroCubo, Vector3(0, 1, 0));
  Matrix4 persp = Matrix4::perspective(45, 1270.0/680.0, 1, 100);
  // Matrix4 orth = Matrix4::orthographic(2, -2, -2, 2, -2, 2);

  for (int i = 0; i < 8; i++) {
    cubo[i] = look.multiplyVector(cubo[i]);
    cout << cubo[i] << endl;
  }

  cout << "----" << endl;

  for (int i = 0; i < 8; i++) {
    // cubo[i] = orth.multiplyVector(cubo[i]);
    cubo[i] = persp.multiplyVector(cubo[i]);
    cout << cubo[i] << endl;
  }

  cout << "-----" << endl;

  for (int i = 0; i < 8; i++) {
    int x = (cubo[i].x + 1)/2 * 800;
    int y = (cubo[i].y + 1)/2 * 800;
    // if (i > 1) {
    //   int x2 = (cubo[i-1].x + 1)/2 * 800;
    //   int y2 = (cubo[i-1].y + 1)/2 * 800;
    //   img1.bresenham({x, y}, {x2, y2}, 0xFF0000FF);
    // }
    img1.putPixel(x, y, 0x00FF00FF);
    cout << "x: " << x << " y: " << y << endl;
  }

  // ys = || (yi+1)/2 * h ||

  sf::RenderWindow window(sf::VideoMode(img1.width, img1.height), "Cubo que gira");
  window.setFramerateLimit(144);

  while(window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
        window.close();
        // cerr << "debug: cerrando" << endl;
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
}
