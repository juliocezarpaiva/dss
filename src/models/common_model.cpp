class Model {
private:
  int m_id;
  string m_name;
  int m_dec_precision = 2;

public:
  Manifold* m_manifold;
  Model(int id, string name, int precision, Manifold* manifold);

  void SetModel(int id, string name, int precision, Manifold* manifold);

  int getId() { return m_id; }
  string getName() { return m_name; }
  float getDecimalPrecision()  { return m_dec_precision; }
  Manifold getManifold()  { return *m_manifold; }

  string toString();
};

Model::Model(int id, string name, int precision, Manifold* manifold) {
  SetModel(id, name, precision, manifold);
}

void Model::SetModel(int id, string name, int precision, Manifold* manifold) {
  m_id = id;
  m_name = name;
  m_dec_precision = precision;
  m_manifold = manifold;
}

string Model::toString() {
  ostringstream model_stream;
  model_stream << "Model(";
  model_stream << "id: " << m_id << ", ";
  model_stream << "name: " << m_name << ", ";
  model_stream << "dec_precision: " << m_dec_precision;
  model_stream << "manifold: " << (*m_manifold).toString();
  model_stream << ")";
  return model_stream.str();
}