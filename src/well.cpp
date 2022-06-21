class Well {
private:
  int m_id;
  string m_name;
  float m_diameter = 0.0;

public:
  Well(int id, string name, float diameter);

  void SetWell(int id, string name, float diameter);

  int getId() { return m_id; }
  string getName() { return m_name; }
  float getDiameter()  { return m_diameter; }

  string toString();
  void fromJson(json json_input);
  string toJson();
};

Well::Well(int id, string name, float diameter) {
  SetWell(id, name, diameter);
}

void Well::SetWell(int id, string name, float diameter) {
  m_id = id;
  m_name = name;
  m_diameter = diameter;
}

string Well::toString() {
  ostringstream well_stream;
  well_stream << "Well(";
  well_stream << "id: " << m_id << ", ";
  well_stream << "name: " << m_name << ", ";
  well_stream << "diameter: " << m_diameter;
  well_stream << ")";
  return well_stream.str();
}

void Well::fromJson(json json_input) {
  for (string field : {"id", "name", "diameter"}) {
    if (json_input[field] == NULL) return;
  }
  m_id = json_input["id"];
  m_name = json_input["name"];
  m_diameter = json_input["diameter"];
}

string Well::toJson() {
  json j_map = {
    to_string(m_id), {
      {"name", m_name},
      {"diameter", to_string(m_diameter)},
    }
  };
  return j_map.dump();
}