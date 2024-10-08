#include "vecmatriz.h"
#include "imagen.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main() {
  Imagen<1270, 680> img1;

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

  Vector3 cam(3, 0, 0);
  Vector3 centroCubo(0, 0, 0);

  Matrix4 look = Matrix4::lookAt(cam, centroCubo, Vector3(0, 1, 0));
  Matrix4 persp = Matrix4::perspective(70, 1270.0/680.0, 1, 4);

  for (int i = 0; i < 8; i++) {
    cubo[i] = look.multiplyVector(cubo[i]);
    cout << cubo[i] << endl;
  }

  cout << "----" << endl;

  for (int i = 0; i < 8; i++) {
    cubo[i] = persp.multiplyVector(cubo[i]);
    cout << cubo[i] << endl;
  }

  cout << "-----" << endl;

  for (int i = 0; i < 8; i++) {
    int x = (cubo[i].x + 1)/2 * 1270;
    int y = (cubo[i].y + 1)/2 * 680;
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
