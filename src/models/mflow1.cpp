class  Mflow1: public Model {
private:
  float m_diameter = 0.0;
  int m_n_wells = 0;

public:
  float getDiameter();
  Mflow1(int id, string name, int precision, Manifold* manifold) :
    Model(id, name, precision, manifold) {
    	m_n_wells = (*manifold).getWells().size();
    }

  void calcDiameter();
};

float Mflow1::getDiameter() {
  calcDiameter();
  return m_diameter;
}

void Mflow1::calcDiameter() {
	float sum_of_diam = 0;
	for (int i = 1; i <= m_n_wells; i++) {
		sum_of_diam += ((
			((*m_manifold).getWells()).at(i).getDiameter() +
			((*m_manifold).getSpools()).at(i).getDiameter()
		) / 2);
	}
	m_diameter = floor(pow(m_n_wells, 2/5) * sum_of_diam/m_n_wells);
}