TODO: Imprimir vectores

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
  return out << v.x << ", " << v.y << ...
}

cout << vector << endl;

TODO: Operador de suma de vectores

inline vec3 operator+(vec3& v1, vec3& v2) {
  return vec3(v1.x + v2.x, v2.y + ...)
}

TODO: Operador de suma de vector matriz
