class  Mgeometry1: public Model {
private:
  float m_diameter = 0.0;
  int m_n_wells = 0;
  float m_d_min_ws;

public:
  Mgeometry1(int id, string name, int precision, Manifold* manifold) :
  Model(id, name, precision, manifold) {
    m_n_wells = (*manifold).getWells().size();
    m_d_min_ws = getMinDiamOfWellsNSpools();
  }

  float getDiameter();
  float getMinDiamOfWellsNSpools();
  void calcDiameter();
};

float Mgeometry1::getDiameter() {
  calcDiameter();
  return m_diameter;
}

float Mgeometry1::getMinDiamOfWellsNSpools() {
  float min_diam = (*m_manifold).getWells().at(1).getDiameter();
  for (pair<const int, Well> pair : (*m_manifold).getWells()) {
    min_diam = min(min_diam, pair.second.getDiameter());
  }
  for (pair<const int, Spool> pair : (*m_manifold).getSpools()) {
    min_diam = min(min_diam, pair.second.getDiameter());
  }
  return min_diam;
}

void Mgeometry1::calcDiameter() {
  m_diameter = sqrt(m_n_wells)*m_d_min_ws;
}