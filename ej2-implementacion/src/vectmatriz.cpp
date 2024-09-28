#include <iostream>
#include <cmath>
#include "vecmatriz.h"

using namespace std;

/* Vector3 */
/**
 * @brief Sobrecarga del operador += para sumar otro vector a este vector.
 * @param v El vector a sumar.
 * @return Referencia al vector resultante después de la suma.
 */
Vector3& Vector3::operator+=(const Vector3& v) {
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

/**
 * @brief Clona el vector actual.
 * @return Copia del vector actual.
 */
Vector3 Vector3::clone() const {
  return Vector3(x, y, z);
}

/**
 * @brief Normaliza el vector actual.
 * @return Vector normalizado.
 */
Vector3 Vector3::normalize() const {
  double norma = sqrt(
    pow(x, 2) +
    pow(y, 2) +
    pow(z, 2)
  );
  return Vector3(x/norma, y/norma, z/norma);
}

/**
 * @brief Asigna nuevos valores al vector.
 * @param x Componente x del vector. Valor por defecto es 0.0.
 * @param y Componente y del vector. Valor por defecto es 0.0.
 * @param z Componente z del vector. Valor por defecto es 0.0.
 */
void Vector3::set(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

/**
 * @brief Asigna el vector a cero.
 */
void Vector3::zero() {
  x = 0;
  y = 0;
  z = 0;
}


/* Vector 4 */
/**
  * @brief Devuelve una copia del objeto Vector4.
  * @return Vector4 Copia del objeto actual.
  */
Vector4 Vector4::clone() const {
  return Vector4(x, y, z, w);
}

/**
  * @brief Devuelve el vector normalizado.
  * @return Vector4 Vector normalizado.
  */
Vector4 Vector4::normalize() const {
  double norma = sqrt(
    pow(x, 2) +
    pow(y, 2) +
    pow(z, 2) +
    pow(w, 2)
  );
  return Vector4(x/norma, y/norma, z/norma, w/norma);
}

/**
  * @brief Asigna nuevos valores a los componentes del vector.
  * @param x Nuevo valor para el componente x.
  * @param y Nuevo valor para el componente y.
  * @param z Nuevo valor para el componente z.
  * @param w Nuevo valor para el componente w.
  */
void Vector4::set(double x, double y, double z, double w) {
  this->x = x;
  this->y = y;
  this->z = z;
  this->w = w;
}

/**
  * @brief Asigna cero a cada componente del vector.
  */
void Vector4::zero() {
  x = 0;
  y = 0;
  z = 0;
  w = 0;
}


/* Matrix3 */
/**
  * @brief Calcula la matriz adjoint.
  * @return Matriz adjoint.
  */
Matrix3 Matrix3::adjoint() const {
}

/**
  * @brief Clona la matriz actual.
  * @return Copia de la matriz actual.
  */
Matrix3 Matrix3::clone() const {
  return Matrix3(
    a00, a01, a02,
    a10, a11, a12,
    a20, a21, a22
  );
}

/**
  * @brief Calcula el determinante de la matriz.
  * @return Determinante de la matriz.
  */
double Matrix3::determinant() const {
}

/**
  * @brief Asigna la matriz a la matriz identidad.
  */
void Matrix3::identity() {
  a00 = 1.0; a01 = 0.0; a02 = 0.0;
  a10 = 0.0; a11 = 1.0; a12 = 0.0;
  a20 = 0.0; a21 = 0.0; a22 = 1.0;

}

/**
  * @brief Calcula la inversa de la matriz.
  * @return Matriz inversa.
  */
Matrix3 Matrix3::invert() const {
}

/**
  * @brief Multiplica una matriz por un vector.
  * @param v Vector a multiplicar.
  * @return Vector resultante de la multiplicación.
  */
Vector3 Matrix3::multiplyVector(const Vector3 &v) const {
}

// TODO: Argumentos??
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
void Matrix3::set(
  double a00, double a01, double a02,
  double a10, double a11, double a12,
  double a20, double a21, double a22
) {
  this->a00 = a00; this->a01 = a01; this->a02 = a02;
  this->a10 = a10; this->a11 = a11; this->a12 = a12;
  this->a20 = a20; this->a21 = a21; this->a22 = a22;
}

/**
  * @brief Calcula la transpuesta de la matriz.
  * @return Matriz transpuesta.
  */
Matrix3 Matrix3::transpose() const {
}


/* Matrix4 */
/**
  * @brief Devuelve la matriz adjunta de la matriz actual.
  * @return Matrix4 Matriz adjunta.
  */
Matrix4 Matrix4::adjoint() const {
}

/**
  * @brief Devuelve una copia del objeto Matrix4.
  * @return Matrix4 Copia del objeto actual.
  */
Matrix4 Matrix4::clone() const {
  return Matrix4(
    a00, a01, a02, a03,
    a10, a11, a12, a13,
    a20, a21, a22, a23,
    a30, a31, a32, a33
  );
}

/**
  * @brief Calcula el determinante de la matriz.
  * @return double Determinante de la matriz.
  */
double Matrix4::determinant() const {
}

// TODO: Duplicado??
/**
  * @brief Multiplica la matriz por un escalar.
  * @param scalar Escalar por el cual multiplicar la matriz.
  * @return Matrix4 Resultado de la multiplicación por el escalar.
  */
Matrix4 Matrix4::multiplyByScalar(double scalar) const {
}

/**
  * @brief Invierte la matriz actual.
  * @return Matrix4 Matriz invertida.
  * @throws std::runtime_error Si la matriz es singular (determinante cercano a cero).
  */
Matrix4 Matrix4::invert() const {
}

/**
  * @brief Establece la matriz como una matriz identidad.
  * @return Matrix4& Referencia a la matriz actual.
  */
Matrix4& Matrix4::identity() {
}

/**
  * @brief Multiplica un vector por la matriz.
  * @param v Vector a multiplicar.
  * @return Vector4 Resultado de la multiplicación del vector por la matriz.
  */
Vector4 Matrix4::multiplyVector(const Vector4 &v) const {
}

// TODO: Sin argumentos???
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
Matrix4& Matrix4::set() {
}

/**
  * @brief Devuelve la transpuesta de la matriz actual.
  * @return Matrix4 Matriz transpuesta.
  */
Matrix4 Matrix4::transpose() const {
}


// Aqui empiezan las pruebas
void pruebas()
{
  // Pruebas para Vector3
  cout << "Pruebas para Vector3:" << endl;

  // Crear vectores
  Vector3 v1(1.0, 2.0, 3.0);
  Vector3 v2(4.0, 5.0, 6.0);

  // Producto punto
  double dotProduct = Vector3::dot(v1, v2);
  cout << "Producto punto de v1 y v2: " << dotProduct << endl;

  // Distancia entre vectores
  double dist = Vector3::distance(v1, v2);
  cout << "Distancia entre v1 y v2: " << dist << endl;

  // Distancia al cuadrado
  double squaredDist = Vector3::squaredDistance(v1, v2);
  cout << "Distancia al cuadrado entre v1 y v2: " << squaredDist << endl;

  // Comparar vectores
  bool areEqual = Vector3::equals(v1, v2);
  cout << "v1 y v2 son iguales: " << (areEqual ? "Sí" : "No") << endl;

  bool areExactEqual = Vector3::exactEquals(v1, v2);
  cout << "v1 y v2 son exactamente iguales: " << (areExactEqual ? "Sí" : "No") << endl;

  // Pruebas para Matrix3
  cout << "\nPruebas para Matrix3:" << endl;

  // Crear matrices
  Matrix3 m1;
  Matrix3 m2(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

  // Sumar matrices
  Matrix3 m3 = Matrix3::add(m1, m2);
  cout << "Suma de m1 y m2:" << endl;
  cout << m3.a00 << " " << m3.a01 << " " << m3.a02 << endl;
  cout << m3.a10 << " " << m3.a11 << " " << m3.a12 << endl;
  cout << m3.a20 << " " << m3.a21 << " " << m3.a22 << endl;

  // Restar matrices
  Matrix3 m4 = Matrix3::subtract(m2, m1);
  cout << "Resta de m2 y m1:" << endl;
  cout << m4.a00 << " " << m4.a01 << " " << m4.a02 << endl;
  cout << m4.a10 << " " << m4.a11 << " " << m4.a12 << endl;
  cout << m4.a20 << " " << m4.a21 << " " << m4.a22 << endl;

  // Multiplicación de matrices
  Matrix3 m5 = Matrix3::multiply(m1, m2);
  cout << "Multiplicación de m1 y m2:" << endl;
  cout << m5.a00 << " " << m5.a01 << " " << m5.a02 << endl;
  cout << m5.a10 << " " << m5.a11 << " " << m5.a12 << endl;
  cout << m5.a20 << " " << m5.a21 << " " << m5.a22 << endl;

  // Multiplicación por escalar
  Matrix3 m6 = Matrix3::multiplyScalar(m2, 2.0);
  cout << "Multiplicación de m2 por escalar 2.0:" << endl;
  cout << m6.a00 << " " << m6.a01 << " " << m6.a02 << endl;
  cout << m6.a10 << " " << m6.a11 << " " << m6.a12 << endl;
  cout << m6.a20 << " " << m6.a21 << " " << m6.a22 << endl;

  // Inversión de matriz
  Matrix3 m7 = m2.invert();
  cout << "Inversa de m2:" << endl;
  cout << m7.a00 << " " << m7.a01 << " " << m7.a02 << endl;
  cout << m7.a10 << " " << m7.a11 << " " << m7.a12 << endl;
  cout << m7.a20 << " " << m7.a21 << " " << m7.a22 << endl;

  // Determinante
  double det = m2.determinant();
  cout << "Determinante de m2: " << det << endl;

  // Transpuesta de matriz
  Matrix3 m8 = m2.transpose();
  cout << "Transpuesta de m2:" << endl;
  cout << m8.a00 << " " << m8.a01 << " " << m8.a02 << endl;
  cout << m8.a10 << " " << m8.a11 << " " << m8.a12 << endl;
  cout << m8.a20 << " " << m8.a21 << " " << m8.a22 << endl;

  // Identidad
  Matrix3 m9;
  m9.identity();
  cout << "Matriz identidad:" << endl;
  cout << m9.a00 << " " << m9.a01 << " " << m9.a02 << endl;
  cout << m9.a10 << " " << m9.a11 << " " << m9.a12 << endl;
  cout << m9.a20 << " " << m9.a21 << " " << m9.a22 << endl;

  // Rotación
  Matrix3 m10 = Matrix3::rotate(3.14159265358979 / 4); // 45 grados
  cout << "Rotación de 45 grados:" << endl;
  cout << m10.a00 << " " << m10.a01 << " " << m10.a02 << endl;
  cout << m10.a10 << " " << m10.a11 << " " << m10.a12 << endl;
  cout << m10.a20 << " " << m10.a21 << " " << m10.a22 << endl;

  // Escalamiento
  Matrix3 m11 = Matrix3::scale(2.0, 3.0);
  cout << "Escalamiento (2.0, 3.0):" << endl;
  cout << m11.a00 << " " << m11.a01 << " " << m11.a02 << endl;
  cout << m11.a10 << " " << m11.a11 << " " << m11.a12 << endl;
  cout << m11.a20 << " " << m11.a21 << " " << m11.a22 << endl;

  // Traslación
  Matrix3 m12 = Matrix3::translate(5.0, 10.0);
  cout << "Traslación (5.0, 10.0):" << endl;
  cout << m12.a00 << " " << m12.a01 << " " << m12.a02 << endl;
  cout << m12.a10 << " " << m12.a11 << " " << m12.a12 << endl;
  cout << m12.a20 << " " << m12.a21 << " " << m12.a22 << endl;

  // ejemplos vector4
  Vector4 vectorA(1, 2, 3, 4);
  Vector4 vectorB(5, 6, 7, 8);

  Vector4 sumVector = Vector4::add(vectorA, vectorB);
  Vector4 clonedVector = vectorA.clone();
  double distance = Vector4::distance(vectorA, vectorB);
  double dotProduct1 = Vector4::dot(vectorA, vectorB);
  bool isApproximatelyEqual = Vector4::equals(vectorA, vectorB);
  bool isExactlyEqual = Vector4::exactEquals(vectorA, vectorB);
  Vector4 normalizedVector = vectorA.normalize();
  vectorA.set(10, 20, 30, 40);
  Vector4 differenceVector = Vector4::subtract(vectorA, vectorB);
  double squaredDistance = Vector4::squaredDistance(vectorA, vectorB);
  vectorA.zero();

  // Imprimir resultados
  cout << "Suma de Vector4: (" << sumVector.x << ", " << sumVector.y << ", " << sumVector.z << ", " << sumVector.w << ")\n";
  cout << "Clon Vector4: (" << clonedVector.x << ", " << clonedVector.y << ", " << clonedVector.z << ", " << clonedVector.w << ")\n";
  cout << "Distancia Vector4: " << distance << "\n";
  cout << "Prodcuto punto Vector4: " << dotProduct << "\n";
  cout << "Approximately Equal: " << (isApproximatelyEqual ? "true" : "false") << "\n";
  cout << "Exactly Equal: " << (isExactlyEqual ? "true" : "false") << "\n";
  cout << "Normalized Vector4: (" << normalizedVector.x << ", " << normalizedVector.y << ", " << normalizedVector.z << ", " << normalizedVector.w << ")\n";
  cout << "Difference Vector4: (" << differenceVector.x << ", " << differenceVector.y << ", " << differenceVector.z << ", " << differenceVector.w << ")\n";
  cout << "Squared Distance: " << squaredDistance << "\n";
  cout << "Vector a cero: (" << vectorA.x << ", " << vectorA.y << ", " << vectorA.z << ", " << vectorA.w << ")\n";

  // pruebas Matrix4
  //  Crear matrices
  Matrix4 mat1(1, 2, 3, 4,
               5, 6, 7, 8,
               9, 10, 11, 12,
               13, 14, 15, 16);

  Matrix4 mat2(16, 15, 14, 13,
               12, 11, 10, 9,
               8, 7, 6, 5,
               4, 3, 2, 1);

  // Probar métodos
  Matrix4 identityMat = mat1.identity();
  cout << "Identidad Matrix4:" << endl;
  cout << " " << identityMat.a00 << " " << identityMat.a01 << " " << identityMat.a02 << " " << identityMat.a03 << endl;
  cout << " " << identityMat.a10 << " " << identityMat.a11 << " " << identityMat.a12 << " " << identityMat.a13 << endl;
  cout << " " << identityMat.a20 << " " << identityMat.a21 << " " << identityMat.a22 << " " << identityMat.a23 << endl;
  cout << " " << identityMat.a30 << " " << identityMat.a31 << " " << identityMat.a32 << " " << identityMat.a33 << endl;

  Matrix4 result = mat1.multiplyScalar(mat1, 2.0);
  cout << "Matrix 1 multiplicado por 2.0:" << endl;
  cout << " " << result.a00 << " " << result.a01 << " " << result.a02 << " " << result.a03 << endl;
  cout << " " << result.a10 << " " << result.a11 << " " << result.a12 << " " << result.a13 << endl;
  cout << " " << result.a20 << " " << result.a21 << " " << result.a22 << " " << result.a23 << endl;
  cout << " " << result.a30 << " " << result.a31 << " " << result.a32 << " " << result.a33 << endl;

  result = mat1.subtract(mat2, mat1);
  cout << "Matrix 1 menos Matrix 2:" << endl;
  cout << " " << result.a00 << " " << result.a01 << " " << result.a02 << " " << result.a03 << endl;
  cout << " " << result.a10 << " " << result.a11 << " " << result.a12 << " " << result.a13 << endl;
  cout << " " << result.a20 << " " << result.a21 << " " << result.a22 << " " << result.a23 << endl;
  cout << " " << result.a30 << " " << result.a31 << " " << result.a32 << " " << result.a33 << endl;

  result = mat1.multiply(mat1, mat2);
  cout << "Matrix 1 multiplied by Matrix 2:" << endl;
  cout << " " << result.a00 << " " << result.a01 << " " << result.a02 << " " << result.a03 << endl;
  cout << " " << result.a10 << " " << result.a11 << " " << result.a12 << " " << result.a13 << endl;
  cout << " " << result.a20 << " " << result.a21 << " " << result.a22 << " " << result.a23 << endl;
  cout << " " << result.a30 << " " << result.a31 << " " << result.a32 << " " << result.a33 << endl;

  result = mat1.transpose();
  cout << "Transpose de Matrix 1:" << endl;
  cout << " " << result.a00 << " " << result.a01 << " " << result.a02 << " " << result.a03 << endl;
  cout << " " << result.a10 << " " << result.a11 << " " << result.a12 << " " << result.a13 << endl;
  cout << " " << result.a20 << " " << result.a21 << " " << result.a22 << " " << result.a23 << endl;
  cout << " " << result.a30 << " " << result.a31 << " " << result.a32 << " " << result.a33 << endl;

  result = mat1.invert();
  cout << "Inversa de Matrix 1:" << endl;
  cout << " " << result.a00 << " " << result.a01 << " " << result.a02 << " " << result.a03 << endl;
  cout << " " << result.a10 << " " << result.a11 << " " << result.a12 << " " << result.a13 << endl;
  cout << " " << result.a20 << " " << result.a21 << " " << result.a22 << " " << result.a23 << endl;
  cout << " " << result.a30 << " " << result.a31 << " " << result.a32 << " " << result.a33 << endl;
}
