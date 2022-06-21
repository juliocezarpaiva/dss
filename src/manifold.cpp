class Manifold {
private:
  int m_id;
  string m_name;
  map<int, Well> m_connected_wells;
  map<int, Spool> m_connected_spools;
  float m_pipeline_diameter = 0.0;

public:
  Manifold(
    int id, string name,
    map<int, Well> connected_wells, map<int, Spool> connected_spools
  );

  void SetManifold(
    int id, string name,
    map<int, Well> connected_wells, map<int, Spool> connected_spools
  );
  void SetManifoldPipelineDiameter(float pipeline_diameter);

  int getId() { return m_id; }
  string getName() { return m_name; }
  map<int, Well> getWells() { return m_connected_wells; }
  map<int, Spool> getSpools()  { return m_connected_spools; }
  float getDiameter()  { return m_pipeline_diameter; }

  string toString();
  string showWhells();
  string showSpools();
};

Manifold::Manifold(
  int id, string name,
  map<int, Well> connected_wells, map<int, Spool> connected_spools
) {
  SetManifold(id, name, connected_wells, connected_spools);
}

void Manifold::SetManifold(
  int id, string name,
  map<int, Well> connected_wells, map<int, Spool> connected_spools
) {
  m_id = id;
  m_name = name;
  m_connected_wells = connected_wells;
  m_connected_spools = connected_spools;
}

void Manifold::SetManifoldPipelineDiameter(float pipeline_diameter) {
  m_pipeline_diameter = pipeline_diameter;
}

string Manifold::toString() {
  ostringstream manifold_stream;
  manifold_stream << "Manifold(";
  manifold_stream << "id: " << m_id << ", ";
  manifold_stream << "name: " << m_name << ", ";
  manifold_stream << "wells: [" << showWhells() << "], ";
  manifold_stream << "spools: [" << showSpools() << "], ";
  manifold_stream << "diameter: " << m_pipeline_diameter;
  manifold_stream << ")" << endl;
  return manifold_stream.str();
}

string Manifold::showWhells() {
  ostringstream wells_stream;
  map<int, Well>::iterator it;
  for(it = m_connected_wells.begin(); it != m_connected_wells.end()--; it++) {
    wells_stream << (*it).second.toString() << ", ";
  }
  it++;
  wells_stream << (*it).second.toString();
  return wells_stream.str();
}

string Manifold::showSpools() {
  ostringstream spools_stream;
  map<int, Spool>::iterator it;
  for(it = m_connected_spools.begin(); it != m_connected_spools.end()--; it++) {
    spools_stream << (*it).second.toString() << ", ";
  }
  it++;
  spools_stream << (*it).second.toString();
  return spools_stream.str();
}