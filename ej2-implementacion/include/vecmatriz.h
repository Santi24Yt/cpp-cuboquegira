#ifndef VECMATRIZ_H
#define VECMATRIZ_H

#include <cmath>

/**
 * @class Vector3
 * @brief La clase Vector3 representa vectores de tres componentes (x, y, z).
 */
class Vector3 {
  public:
  double x, y, z;

  /**
  * @brief Constructor por defecto.
  * @param x Componente x del vector. Valor por defecto es 0.0.
  * @param y Componente y del vector. Valor por defecto es 0.0.
  * @param z Componente z del vector. Valor por defecto es 0.0.
  */
  Vector3(double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z)
  {
    // this->x = x;
    // this->y = y;
    // this->z = z;
  }

  /**
   * @brief Suma de dos vectores.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @return Vector resultante de la suma.
   */
  static Vector3 add(const Vector3& u, const Vector3& v) {
    return Vector3(u.x + v.y, u.y + v.y, u.z + v.z);
  }

  /**
   * @brief Sobrecarga del operador += para sumar otro vector a este vector.
   * @param v El vector a sumar.
   * @return Referencia al vector resultante después de la suma.
   */
  Vector3& operator+=(const Vector3& v);

  /**
   * @brief Clona el vector actual.
   * @return Copia del vector actual.
   */
  Vector3 clone() const;

  /**
   * @brief Producto cruz de dos vectores.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @return Vector resultante del producto cruz.
   */
  static Vector3 cross(const Vector3& u, const Vector3& v) {
    return Vector3(
      (u.x * v.z) - (u.z * v.y),
      (u.z * v.x) - (u.x * v.z),
      (u.x * v.y) - (u.y * v.x)
    );
  }

  /**
   * @brief Distancia euclidiana entre dos vectores.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @return Distancia euclidiana entre los vectores.
   */
  static double distance(const Vector3& u, const Vector3& v) {
    return sqrt(
      pow(v.x - u.x, 2) +
      pow(v.y - u.y, 2) +
      pow(v.z - u.z, 2)
    );
  }

  /**
   * @brief Producto punto de dos vectores.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @return Producto punto de los vectores.
   */
  static double dot(const Vector3& u, const Vector3& v) {
    return (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
  }

  /**
   * @brief Comprueba si dos vectores son aproximadamente iguales.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @param epsilon Tolerancia para la comparación. Valor por defecto es 0.000001.
   * @return Verdadero si los vectores son aproximadamente iguales.
   */
  static bool equals(const Vector3& u, const Vector3& v, double epsilon = 0.000001) {
    return 
      std::abs(u.x - v.x) <= epsilon &&
      std::abs(u.y - v.y) <= epsilon &&
      std::abs(u.z - v.z) <= epsilon;
  }

  /**
   * @brief Comprueba si dos vectores son exactamente iguales.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @return Verdadero si los vectores son exactamente iguales.
   */
  static bool exactEquals(const Vector3& u, const Vector3& v) {
    return u.x == v.x && u.y == v.y && u.z == v.z;
  }

  /**
   * @brief Normaliza el vector actual.
   * @return Vector normalizado.
   */
  Vector3 normalize() const;

  /**
   * @brief Asigna nuevos valores al vector.
   * @param x Componente x del vector. Valor por defecto es 0.0.
   * @param y Componente y del vector. Valor por defecto es 0.0.
   * @param z Componente z del vector. Valor por defecto es 0.0.
   */
  void set(double x = 0.0, double y = 0.0, double z = 0.0);

  /**
   * @brief Resta dos vectores.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @return Vector resultante de la resta.
   */
  static Vector3 subtract(const Vector3& u, const Vector3& v) {
    return Vector3(u.x - v.x, u.y - v.y, u.z - v.z);
  }

  /**
   * @brief Distancia euclidiana al cuadrado entre dos vectores.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @return Distancia euclidiana al cuadrado entre los vectores.
   */
  static double squaredDistance(const Vector3& u, const Vector3& v) {
    return pow(Vector3::distance(u, v), 2);
  }

  /**
   * @brief Asigna el vector a cero.
   */
  void zero();
};

/**
 * @class Vector4
 * @brief La clase Vector4 representa vectores de tres componentes (x, y, z, w).
 */
class Vector4 {
  public:
  double x, y, z, w;

  /**
   * @brief Constructor que inicializa los componentes del vector.
   * @param x Componente x del vector (por defecto 0).
   * @param y Componente y del vector (por defecto 0).
   * @param z Componente z del vector (por defecto 0).
   * @param w Componente w del vector (por defecto 0).
   */
  Vector4(double x = 0.0, double y = 0.0, double z = 0.0, double w = 0.0) : x(x), y(y), z(z), w(w)
  {
    // this->x = x;
    // this->y = y;
    // this->z = z;
    // this->w = w;
  }

  /**
   * @brief Devuelve la suma de dos vectores.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @return Vector4 Resultado de la suma de u y v.
   */
  static Vector4 add(const Vector4& u, const Vector4& v) {
    return Vector4(u.x + v.x, u.y + v.y, u.z + v.z, u.w + v.w);
  }

  /**
   * @brief Devuelve una copia del objeto Vector4.
   * @return Vector4 Copia del objeto actual.
   */
  Vector4 clone() const;

  /**
   * @brief Devuelve la distancia euclidiana entre dos vectores.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @return double Distancia euclidiana entre u y v.
   */
  static double distance(const Vector4& u, const Vector4& v) {
    return sqrt(
      pow(v.x - u.x, 2) +
      pow(v.y - u.y, 2) +
      pow(v.z - u.z, 2) +
      pow(v.w - u.w, 2)
    );
  }

  /**
   * @brief Devuelve el producto punto de dos vectores.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @return double Producto punto de u y v.
   */
  static double dot(const Vector4& u, const Vector4& v) {
    return (u.x * v.x) + (u.y * v.y) + (u.z * v.z) + (u.w + v.w);
  }

  /**
   * @brief Verifica si dos vectores son aproximadamente iguales.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @param epsilon Tolerancia para la comparación (por defecto 0.000001).
   * @return bool True si los vectores son aproximadamente iguales, false en caso contrario.
   */
  static bool equals(const Vector4& u, const Vector4& v, double epsilon = 0.000001) {
    return
      std::abs(u.x - v.x) <= epsilon &&
      std::abs(u.y - v.y) <= epsilon &&
      std::abs(u.z - v.z) <= epsilon &&
      std::abs(u.w - v.w) <= epsilon;
  }

  /**
   * @brief Verifica si dos vectores son exactamente iguales.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @return bool True si los vectores son exactamente iguales, false en caso contrario.
   */
  static bool exactEquals(const Vector4& u, const Vector4& v) {
    return u.x == v.x && u.y == v.y && u.z == v.z && u.w == v.w;
  }

  /**
   * @brief Devuelve el vector normalizado.
   * @return Vector4 Vector normalizado.
   */
  Vector4 normalize() const;

  /**
   * @brief Asigna nuevos valores a los componentes del vector.
   * @param x Nuevo valor para el componente x.
   * @param y Nuevo valor para el componente y.
   * @param z Nuevo valor para el componente z.
   * @param w Nuevo valor para el componente w.
   */
  void set(double x, double y, double z, double w);

  /**
   * @brief Devuelve la resta de dos vectores.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @return Vector4 Resultado de la resta de u y v.
   */
  static Vector4 subtract(const Vector4& u, const Vector4& v) {
    return Vector4(u.x - v.x, u.y - v.y, u.z - v.z, u.w - v.w);
  }

  /**
   * @brief Devuelve la distancia euclidiana al cuadrado entre dos vectores.
   * @param u Primer vector.
   * @param v Segundo vector.
   * @return double Distancia euclidiana al cuadrado entre u y v.
   */
  static double squaredDistance(const Vector4& u, const Vector4& v) {
    return pow(Vector4::distance(u, v), 2);
  }

  /**
   * @brief Asigna cero a cada componente del vector.
   */
  void zero();
};

/**
 * @class Matrix3
 * @brief La clase Matrix3 representa matrices de 3 × 3 y se utiliza para la representación y construcción de transformaciones en dos dimensiones.
 */
class Matrix3 {
  public:
  double 
    a00, a01, a02,
    a10, a11, a12,
    a20, a21, a22;

  /**
   * @brief Constructor por defecto.
   * @param a00 Elemento en la posición (0,0). Valor por defecto es 1.0.
   * @param a01 Elemento en la posición (0,1). Valor por defecto es 0.0.
   * @param a02 Elemento en la posición (0,2). Valor por defecto es 0.0.
   * @param a10 Elemento en la posición (1,0). Valor por defecto es 0.0.
   * @param a11 Elemento en la posición (1,1). Valor por defecto es 1.0.
   * @param a12 Elemento en la posición (1,2). Valor por defecto es 0.0.
   * @param a20 Elemento en la posición (2,0). Valor por defecto es 0.0.
   * @param a21 Elemento en la posición (2,1). Valor por defecto es 0.0.
   * @param a22 Elemento en la posición (2,2). Valor por defecto es 1.0.
   */
  Matrix3(
    double a00 = 1.0, double a01 = 0.0, double a02 = 0.0,
    double a10 = 0.0, double a11 = 1.0, double a12 = 0.0,
    double a20 = 0.0, double a21 = 0.0, double a22 = 1.0
  ) :
    a00(a00), a01(a01), a02(a02),
    a10(a10), a11(a11), a12(a12),
    a20(a20), a21(a21), a22(a22)
  {
    // this->a00 = a00; this->a01 = a01; this->a02 = a02;
    // this->a10 = a10; this->a11 = a11; this->a12 = a12;
    // this->a20 = a20; this->a21 = a21; this->a22 = a22;
  }

  /**
   * @brief Suma de dos matrices.
   * @param m1 Primera matriz.
   * @param m2 Segunda matriz.
   * @return Matriz resultante de la suma.
   */
  static Matrix3 add(const Matrix3& m1, const Matrix3& m2) {
    return Matrix3(
      m1.a00 + m2.a00, m1.a01 + m2.a01, m1.a02 + m2.a02,
      m1.a10 + m2.a10, m1.a11 + m2.a11, m1.a12 + m2.a12,
      m1.a20 + m2.a20, m1.a21 + m2.a21, m1.a22 + m2.a22
    );
  }

  /**
   * @brief Calcula la matriz adjoint.
   * @return Matriz adjoint.
   */
  // NOTE: Se va a tratar como matriz adjunta, para poder calcular más fácil la inversa
  Matrix3 adjoint() const;

  /**
   * @brief Clona la matriz actual.
   * @return Copia de la matriz actual.
   */
  Matrix3 clone() const;

  /**
   * @brief Calcula el determinante de la matriz.
   * @return Determinante de la matriz.
   */
  double determinant() const;

  /**
   * @brief Compara dos matrices con un epsilon.
   * @param m1 Primera matriz.
   * @param m2 Segunda matriz.
   * @param e Epsilon para la comparación.
   * @return Verdadero si las matrices son aproximadamente iguales.
   */
  static bool equalsWithE(const Matrix3& m1, const Matrix3& m2, double e) {
    return
      std::abs(m1.a00 - m2.a00) <= e &&
      std::abs(m1.a01 - m2.a01) <= e &&
      std::abs(m1.a02 - m2.a02) <= e &&
      std::abs(m1.a10 - m2.a10) <= e &&
      std::abs(m1.a11 - m2.a11) <= e &&
      std::abs(m1.a12 - m2.a12) <= e &&
      std::abs(m1.a20 - m2.a20) <= e &&
      std::abs(m1.a21 - m2.a21) <= e &&
      std::abs(m1.a22 - m2.a22) <= e;
  }

  // TODO: Duplicado con exact equals?
  /**
   * @brief Compara dos matrices con un epsilon predeterminado.
   * @param m1 Primera matriz.
   * @param m2 Segunda matriz.
   * @return Verdadero si las matrices son aproximadamente iguales.
   */
  static bool equals(const Matrix3& m1, const Matrix3& m2) {
    return 
      m1.a00 == m2.a00 && m1.a01 == m2.a01 && m1.a02 == m2.a02 &&
      m1.a10 == m2.a10 && m1.a11 == m2.a11 && m1.a12 == m2.a12 &&
      m1.a20 == m2.a20 && m1.a21 == m2.a21 && m1.a22 == m2.a22;
  }

  /**
   * @brief Compara dos matrices exactamente.
   * @param m1 Primera matriz.
   * @param m2 Segunda matriz.
   * @return Verdadero si las matrices son exactamente iguales.
   */
  static bool exactEquals(const Matrix3& m1, const Matrix3& m2) {
    return 
      m1.a00 == m2.a00 && m1.a01 == m2.a01 && m1.a02 == m2.a02 &&
      m1.a10 == m2.a10 && m1.a11 == m2.a11 && m1.a12 == m2.a12 &&
      m1.a20 == m2.a20 && m1.a21 == m2.a21 && m1.a22 == m2.a22;
  }

  /**
   * @brief Asigna la matriz a la matriz identidad.
   */
  void identity();

  /**
   * @brief Calcula la inversa de la matriz.
   * @return Matriz inversa.
   */
  Matrix3 invert() const;

  /**
   * @brief Multiplica dos matrices.
   * @param m1 Primera matriz.
   * @param m2 Segunda matriz.
   * @return Matriz resultante de la multiplicación.
   */
  static Matrix3 multiply(const Matrix3& m1, const Matrix3& m2) {
    return Matrix3(
      m1.a00*m2.a00 + m1.a01*m2.a10 + m1.a02*m2.a20,  m1.a00*m2.a01 + m1.a01*m2.a11 + m1.a02*m2.a21,  m1.a00*m2.a02 + m1.a01*m2.a12 + m1.a02*m2.a22, 
      m1.a10*m2.a00 + m1.a11*m2.a10 + m1.a12*m2.a20,  m1.a10*m2.a01 + m1.a11*m2.a11 + m1.a12*m2.a21,  m1.a10*m2.a02 + m1.a11*m2.a12 + m1.a12*m2.a22,
      m1.a20*m2.a00 + m1.a21*m2.a10 + m1.a22*m2.a20,  m1.a20*m2.a01 + m1.a21*m2.a11 + m1.a22*m2.a21,  m1.a20*m2.a02 + m1.a21*m2.a12 + m1.a22*m2.a22
    );
  }

  /**
   * @brief Multiplica una matriz por un escalar.
   * @param m1 Matriz a multiplicar.
   * @param c Escalar.
   * @return Matriz resultante de la multiplicación por el escalar.
   */
  static Matrix3 multiplyScalar(const Matrix3& m1, double c) {
    return Matrix3(
      m1.a00 * c, m1.a01 * c, m1.a02 * c,
      m1.a10 * c, m1.a11 * c, m1.a12 * c,
      m1.a20 * c, m1.a21 * c, m1.a22 * c
    );
  }

  /**
   * @brief Multiplica una matriz por un vector.
   * @param v Vector a multiplicar.
   * @return Vector resultante de la multiplicación.
   */
  Vector3 multiplyVector(const Vector3& v) const;

  /**
   * @brief Crea una matriz de rotación.
   * @param theta Ángulo de rotación en radianes.
   * @return Matriz de rotación.
   */
  static Matrix3 rotate(double theta) {
    return Matrix3(
      std::cos(theta) , std::sin(theta), 0,
      -std::sin(theta), std::cos(theta), 0,
      0               , 0              , 1
    );
  }

  /**
   * @brief Crea una matriz de escalamiento.
   * @param sx Factor de escala en el eje x.
   * @param sy Factor de escala en el eje y.
   * @return Matriz de escalamiento.
   */
  static Matrix3 scale(double sx, double sy) {
    return Matrix3(
      sx, 0 , 0,
      0 , sy, 0,
      0 , 0 , 1
    );
  }

  /**
   * @brief Asigna nuevos valores a la matriz.
   * @param a00 Elemento en la posición (0,0).
   * @param a01 Elemento en la posición (0,1).
   * @param a02 Elemento en la posición (0,2).
   * @param a10 Elemento en la posición (1,0).
   * @param a11 Elemento en la posición (1,1).
   * @param a12 Elemento en la posición (1,2).
   * @param a20 Elemento en la posición (2,0).
   * @param a21 Elemento en la posición (2,1).
   * @param a22 Elemento en la posición (2,2).
   */
  void set(
    double a00, double a01, double a02,
    double a10, double a11, double a12,
    double a20, double a21, double a22
  );

  /**
   * @brief Resta dos matrices.
   * @param m1 Primera matriz.
   * @param m2 Segunda matriz.
   * @return Matriz resultante de la resta.
   */
  static Matrix3 subtract(const Matrix3& m1, const Matrix3& m2) {
    return Matrix3(
      m1.a00 - m2.a00, m1.a01 - m2.a01, m1.a02 - m2.a02,
      m1.a10 - m2.a10, m1.a11 - m2.a11, m1.a12 - m2.a12,
      m1.a20 - m2.a20, m1.a21 - m2.a21, m1.a22 - m2.a22
    );
  }

  /**
   * @brief Crea una matriz de translación.
   * @param tx Desplazamiento en el eje x.
   * @param ty Desplazamiento en el eje y.
   * @return Matriz de translación.
   */
  static Matrix3 translate(double tx, double ty) {
    return Matrix3(
      1 , 0 , 0,
      0 , 1 , 0,
      tx, ty, 1
    );
  }

  /**
   * @brief Calcula la transpuesta de la matriz.
   * @return Matriz transpuesta.
   */
  Matrix3 transpose() const;
};

/**
 * @class Matrix4
 * @brief La clase Matrix4 representa matrices de 4 × 4 y se utiliza para la representación y construcción de transformaciones en tres dimensiones.
 */
class Matrix4 {
  public:
  double 
    a00, a01, a02, a03,
    a10, a11, a12, a13,
    a20, a21, a22, a23,
    a30, a31, a32, a33;

  /**
   * @brief Constructor que inicializa una matriz 4x4 con valores por defecto.
   * @param a00 Valor para el elemento (0,0).
   * @param a01 Valor para el elemento (0,1).
   * @param a02 Valor para el elemento (0,2).
   * @param a03 Valor para el elemento (0,3).
   * @param a10 Valor para el elemento (1,0).
   * @param a11 Valor para el elemento (1,1).
   * @param a12 Valor para el elemento (1,2).
   * @param a13 Valor para el elemento (1,3).
   * @param a20 Valor para el elemento (2,0).
   * @param a21 Valor para el elemento (2,1).
   * @param a22 Valor para el elemento (2,2).
   * @param a23 Valor para el elemento (2,3).
   * @param a30 Valor para el elemento (3,0).
   * @param a31 Valor para el elemento (3,1).
   * @param a32 Valor para el elemento (3,2).
   * @param a33 Valor para el elemento (3,3).
   */
  Matrix4(
      double a00 = 1.0, double a01 = 0.0, double a02 = 0.0, double a03 = 0.0,
      double a10 = 0.0, double a11 = 1.0, double a12 = 0.0, double a13 = 0.0,
      double a20 = 0.0, double a21 = 0.0, double a22 = 1.0, double a23 = 0.0,
      double a30 = 0.0, double a31 = 0.0, double a32 = 0.0, double a33 = 1.0)
    :
      a00(a00), a01(a01), a02(a02), a03(a03),
      a10(a10), a11(a11), a12(a12), a13(a13),
      a20(a20), a21(a21), a22(a22), a23(a23),
      a30(a30), a31(a31), a32(a32), a33(a33)
  {
    // this->a00 = a00; this->a01 = a01; this->a02 = a02; this->a03 = a03;
    // this->a10 = a10; this->a11 = a11; this->a12 = a12; this->a13 = a13;
    // this->a20 = a20; this->a21 = a21; this->a22 = a22; this->a23 = a23;
    // this->a30 = a30; this->a31 = a31; this->a32 = a32; this->a33 = a33;
  }

  /**
   * @brief Devuelve la suma de dos matrices.
   * @param m1 Primera matriz.
   * @param m2 Segunda matriz.
   * @return Matrix4 Resultado de la suma de m1 y m2.
   */
  static Matrix4 add(const Matrix4& m1, const Matrix4& m2) {
    return Matrix4(
      m1.a00 + m2.a00, m1.a01 + m2.a01, m1.a02 + m2.a02, m1.a03 + m2.a03,
      m1.a10 + m2.a10, m1.a11 + m2.a11, m1.a12 + m2.a12, m1.a13 + m2.a13,
      m1.a20 + m2.a20, m1.a21 + m2.a21, m1.a22 + m2.a22, m1.a23 + m2.a23,
      m1.a30 + m2.a30, m1.a31 + m2.a31, m1.a32 + m2.a32, m1.a33 + m2.a33
    );
  }

  /**
   * @brief Devuelve la matriz adjunta de la matriz actual.
   * @return Matrix4 Matriz adjunta.
   */
  // NOTE: Se tomará como matriz adjunta
  Matrix4 adjoint() const;

  /**
   * @brief Devuelve una copia del objeto Matrix4.
   * @return Matrix4 Copia del objeto actual.
   */
  Matrix4 clone() const;

  /**
   * @brief Calcula el determinante de la matriz.
   * @return double Determinante de la matriz.
   */
  double determinant() const;

  /**
   * @brief Verifica si dos matrices son aproximadamente iguales.
   * @param m1 Primera matriz.
   * @param m2 Segunda matriz.
   * @param epsilon Tolerancia para la comparación.
   * @return bool True si las matrices son aproximadamente iguales, false en caso contrario.
   */
  static bool equalsWithE(const Matrix4& m1, const Matrix4& m2, double epsilon) {
    return
      std::abs(m1.a00 - m2.a00) <= epsilon &&
      std::abs(m1.a01 - m2.a01) <= epsilon &&
      std::abs(m1.a02 - m2.a02) <= epsilon &&
      std::abs(m1.a03 - m2.a03) <= epsilon &&
      std::abs(m1.a10 - m2.a10) <= epsilon &&
      std::abs(m1.a11 - m2.a11) <= epsilon &&
      std::abs(m1.a12 - m2.a12) <= epsilon &&
      std::abs(m1.a13 - m2.a13) <= epsilon &&
      std::abs(m1.a20 - m2.a20) <= epsilon &&
      std::abs(m1.a21 - m2.a21) <= epsilon &&
      std::abs(m1.a22 - m2.a22) <= epsilon &&
      std::abs(m1.a23 - m2.a23) <= epsilon &&
      std::abs(m1.a30 - m2.a30) <= epsilon &&
      std::abs(m1.a31 - m2.a31) <= epsilon &&
      std::abs(m1.a32 - m2.a32) <= epsilon &&
      std::abs(m1.a33 - m2.a33) <= epsilon;
  }

  /**
   * @brief Multiplica la matriz por un escalar.
   * @param scalar Escalar por el cual multiplicar la matriz.
   * @return Matrix4 Resultado de la multiplicación por el escalar.
   */
  Matrix4 multiplyByScalar(double scalar) const;

  /**
   * @brief Multiplica dos matrices.
   * @param m1 Primera matriz.
   * @param m2 Segunda matriz.
   * @return Matrix4 Resultado de la multiplicación de m1 y m2.
   */
  static Matrix4 multiply(const Matrix4& m1, const Matrix4& m2) {
    return Matrix4(
      m1.a00*m2.a00 + m1.a01*m2.a10 + m1.a02*m2.a20 + m1.a03*m2.a30,
      m1.a00*m2.a01 + m1.a01*m2.a11 + m1.a02*m2.a21 + m1.a03*m2.a31,
      m1.a00*m2.a02 + m1.a01*m2.a12 + m1.a02*m2.a22 + m1.a03*m2.a32,
      m1.a00*m2.a03 + m1.a01*m2.a13 + m1.a02*m2.a23 + m1.a03*m2.a33,

      m1.a10*m2.a00 + m1.a11*m2.a10 + m1.a12*m2.a20 + m1.a13*m2.a30,
      m1.a10*m2.a01 + m1.a11*m2.a11 + m1.a12*m2.a21 + m1.a13*m2.a31,
      m1.a10*m2.a02 + m1.a11*m2.a12 + m1.a12*m2.a22 + m1.a13*m2.a32,
      m1.a10*m2.a03 + m1.a11*m2.a13 + m1.a12*m2.a23 + m1.a13*m2.a33,

      m1.a20*m2.a00 + m1.a21*m2.a10 + m1.a22*m2.a20 + m1.a23*m2.a30,
      m1.a20*m2.a01 + m1.a21*m2.a11 + m1.a22*m2.a21 + m1.a23*m2.a31,
      m1.a20*m2.a02 + m1.a21*m2.a12 + m1.a22*m2.a22 + m1.a23*m2.a32,
      m1.a20*m2.a03 + m1.a21*m2.a13 + m1.a22*m2.a23 + m1.a23*m2.a33,

      m1.a30*m2.a00 + m1.a31*m2.a10 + m1.a32*m2.a20 + m1.a33*m2.a30,
      m1.a30*m2.a01 + m1.a31*m2.a11 + m1.a32*m2.a21 + m1.a33*m2.a31,
      m1.a30*m2.a02 + m1.a31*m2.a12 + m1.a32*m2.a22 + m1.a33*m2.a32,
      m1.a30*m2.a03 + m1.a31*m2.a13 + m1.a32*m2.a23 + m1.a33*m2.a33
    );
  }

  /**
   * @brief Invierte la matriz actual.
   * @return Matrix4 Matriz invertida.
   * @throws std::runtime_error Si la matriz es singular (determinante cercano a cero).
   */
  Matrix4 invert() const;

  /**
   * @brief Establece la matriz como una matriz identidad.
   * @return Matrix4& Referencia a la matriz actual.
   */
  Matrix4& identity();

  /**
   * @brief Multiplica cada componente de una matriz por un escalar.
   * @param m1 Matriz a multiplicar.
   * @param c Escalar por el cual multiplicar la matriz.
   * @return Matrix4 Resultado de la multiplicación por el escalar.
   */
  static Matrix4 multiplyScalar(const Matrix4& m1, double c) {
    return Matrix4(
      m1.a00 * c, m1.a01 * c, m1.a02 * c, m1.a03 * c,
      m1.a10 * c, m1.a11 * c, m1.a12 * c, m1.a13 * c,
      m1.a20 * c, m1.a21 * c, m1.a22 * c, m1.a23 * c,
      m1.a30 * c, m1.a31 * c, m1.a32 * c, m1.a33 * c
    );
  }

  /**
   * @brief Multiplica un vector por la matriz.
   * @param v Vector a multiplicar.
   * @return Vector4 Resultado de la multiplicación del vector por la matriz.
   */
  Vector4 multiplyVector(const Vector4& v) const;

  /**
   * @brief Establece nuevos valores para los elementos de la matriz.
   * @param a00 Valor para el elemento (0,0).
   * @param a01 Valor para el elemento (0,1).
   * @param a02 Valor para el elemento (0,2).
   * @param a03 Valor para el elemento (0,3).
   * @param a10 Valor para el elemento (1,0).
   * @param a11 Valor para el elemento (1,1).
   * @param a12 Valor para el elemento (1,2).
   * @param a13 Valor para el elemento (1,3).
   * @param a20 Valor para el elemento (2,0).
   * @param a21 Valor para el elemento (2,1).
   * @param a22 Valor para el elemento (2,2).
   * @param a23 Valor para el elemento (2,3).
   * @param a30 Valor para el elemento (3,0).
   * @param a31 Valor para el elemento (3,1).
   * @param a32 Valor para el elemento (3,2).
   * @param a33 Valor para el elemento (3,3).
   * @return Matrix4& Referencia a la matriz actual.
   */
  Matrix4& set(
    double a00, double a01, double a02, double a03,
    double a10, double a11, double a12, double a13,
    double a20, double a21, double a22, double a23,
    double a30, double a31, double a32, double a33
  );

  /**
   * @brief Devuelve la resta de dos matrices.
   * @param m1 Primera matriz.
   * @param m2 Segunda matriz.
   * @return Matrix4 Resultado de la resta de m1 y m2.
   */
  static Matrix4 subtract(const Matrix4& m1, const Matrix4& m2) {
    return Matrix4(
      m1.a00 - m2.a00, m1.a01 - m2.a01, m1.a02 - m2.a02, m1.a03 - m2.a03,
      m1.a10 - m2.a10, m1.a11 - m2.a11, m1.a12 - m2.a12, m1.a13 - m2.a13,
      m1.a20 - m2.a20, m1.a21 - m2.a21, m1.a22 - m2.a22, m1.a23 - m2.a23,
      m1.a30 - m2.a30, m1.a31 - m2.a31, m1.a32 - m2.a32, m1.a33 - m2.a33
    );
  }

  /**
   * @brief Devuelve la transpuesta de la matriz actual.
   * @return Matrix4 Matriz transpuesta.
   */
  Matrix4 transpose() const;

  // Métodos estáticos de matrices de transformaciones de cámara

  /**
   * @brief Genera una matriz de proyección de perspectiva utilizando un frustum.
   *
   * @param left Límite izquierdo del frustum.
   * @param right Límite derecho del frustum.
   * @param bottom Límite inferior del frustum.
   * @param top Límite superior del frustum.
   * @param near Distancia del plano cercano.
   * @param far Distancia del plano lejano.
   * @return Matrix4 Matriz 4x4 que define el frustum.
   */
  static Matrix4 frustum(double left, double right, double bottom, double top, double near, double far) {
    return Matrix4(
      (2*near)/(right-left)     , 0                         , 0                       , 0,
      0                         , (2*near)/(top-bottom)     , 0                       , 0,
      0                         , 0                         , -(far+near)/(far-near)  , -1, 
      -(right+left)/(right-left), -(top+bottom)/(top-bottom), -(2*near*far)/(far-near), 0
    );
  }

  /**
   * @brief Genera una matriz de vista para una cámara en una posición dada.
   *
   * @param eye Posición de la cámara.
   * @param center Punto al que la cámara está mirando.
   * @param up Vector hacia arriba en el espacio de la cámara.
   * @return Matrix4 Matriz 4x4 que define la vista.
   */
  static Matrix4 lookAt(const Vector3& eye, const Vector3& center, const Vector3& up) {
    Vector3 u = Vector3::subtract(eye, center).normalize();
    Vector3 w = Vector3::cross(u, up).normalize();
    Vector3 v = Vector3::cross(u, w).normalize();
    // TODO: Checar si es correcta
    return Matrix4(
      u.x, u.y, u.z, 0,
      v.x, v.y, v.z, 0,
      w.x, w.y, w.z, 0,
      eye.x, eye.y, eye.z, 1
    );
  }

  /**
   * @brief Genera una matriz de proyección ortográfica.
   *
   * @param left Límite izquierdo de la proyección.
   * @param right Límite derecho de la proyección.
   * @param bottom Límite inferior de la proyección.
   * @param top Límite superior de la proyección.
   * @param near Distancia del plano cercano.
   * @param far Distancia del plano lejano.
   * @return Matrix4 Matriz 4x4 que define la proyección ortográfica.
   */
  static Matrix4 orthographic(double left, double right, double bottom, double top, double near, double far) {
    return Matrix4(
      2/(right-left)            , 0                         , 0                     , 0,
      0                         , 2/(top-bottom)            , 0                     , 0,
      0                         , 0                         , -2/(near-far)         , 0,
      -(right+left)/(right-left), -(top+bottom)/(top-bottom), -(near+far)/(near-far), 1
    );
  }

  /**
   * @brief Genera una matriz de proyección de perspectiva utilizando un campo de visión.
   *
   * @param fovy Campo de visión en el eje vertical, en grados.
   * @param aspect Relación de aspecto (ancho/alto).
   * @param near Distancia del plano cercano.
   * @param far Distancia del plano lejano.
   * @return Matrix4 Matriz 4x4 que define la proyección de perspectiva.
   */
  static Matrix4 perspective(double fovy, double aspect, double near, double far) {
    double c = 1/std::tan(fovy/2);
    return Matrix4(
      c/aspect, 0, 0                       , 0 ,
      0       , c, 0                       , 0 ,
      0       , 0, -(far+near)/(far-near)  , -1,
      0       , 0, -(2*near*far)/(far-near), 0
    );
  }

  /**
   * @brief Genera una matriz de rotación alrededor del eje X.
   *
   * @param theta Ángulo de rotación en radianes.
   * @return Matrix4 Matriz 4x4 que define la rotación alrededor del eje X.
   */
  static Matrix4 rotateX(double theta) {
    return Matrix4(
      1, 0, 0, 0,
      0, std::cos(theta), std::sin(theta), 0,
      0, std::sin(theta), std::cos(theta), 0,
      0, 0, 0, 1
    );
	}

  /**
   * @brief Genera una matriz de rotación alrededor del eje Y.
   *
   * @param theta Ángulo de rotación en radianes.
   * @return Matrix4 Matriz 4x4 que define la rotación alrededor del eje Y.
   */
  static Matrix4 rotateY(double theta) {
    return Matrix4(
      std::cos(theta), 0, std::sin(theta), 0,
      0, 1, 0, 0,
      std::sin(theta), 0, std::cos(theta), 0,
      0, 0, 0, 1
    );
	}

  /**
   * @brief Genera una matriz de rotación alrededor del eje Z.
   *
   * @param Vector3 v
   * @return Matrix4 Matriz 4x4 que define la rotación alrededor del eje z.
   */
  // NOTE: Se cambió el vector por un ángulo
  static Matrix4 rotateZ(double theta) {
    return Matrix4(
      std::cos(theta), std::sin(theta), 0, 0,
      -std::sin(theta), std::cos(theta), 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1
    );
	}

  /**
   * @brief Genera una matriz de escalado.
   *
   * @param x Factor de escala en el eje X.
   * @param y Factor de escala en el eje Y.
   * @param z Factor de escala en el eje Z.
   * @return Matrix4 Matriz 4x4 que define el escalado.
   */
  static Matrix4 scale(double x, double y, double z) {
    return Matrix4(
      x, 0, 0, 0,
      0, y, 0, 0,
      0, 0, z, 0,
      0, 0, 0, 1
    );
	}

  /**
   * @brief Genera una matriz de traslación.
   *
   * @param x Desplazamiento en el eje X.
   * @param y Desplazamiento en el eje Y.
   * @param z Desplazamiento en el eje Z.
   * @return Matrix4 Matriz 4x4 que define la traslación.
   */
  static Matrix4 translate(double x, double y, double z) {
    return Matrix4(
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      x, y, z, 1
    );
	}
};

// Aqui empiezan las pruebas
void pruebas();

#endif
