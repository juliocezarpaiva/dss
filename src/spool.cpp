class Spool {
private:
  int m_id;
  string m_name;
  float m_cost = 0.0;
  float m_diameter = 0.0;

public:
  Spool(int id, string name, float cost, float diameter);

  void SetSpool(int id, string name, float cost, float diameter);

  int getId() { return m_id; }
  string getName() { return m_name; }
  float getCost() { return m_cost; }
  float getDiameter()  { return m_diameter; }

  string toString();
  void fromJson(json json_input);
  string toJson();
};

Spool::Spool(int id, string name, float cost, float diameter) {
  SetSpool(id, name, cost, diameter);
}

void Spool::SetSpool(int id, string name, float cost, float diameter) {
  m_id = id;
  m_name = name;
  m_cost = cost;
  m_diameter = diameter;
}

string Spool::toString() {
  ostringstream spool_stream;
  spool_stream << "Spool(";
  spool_stream << "id: " << m_id << ", ";
  spool_stream << "name: " << m_name << ", ";
  spool_stream << "cost: " << m_cost << ", ";
  spool_stream << "diameter: " << m_diameter;
  spool_stream << ")";
  return spool_stream.str();
}

void Spool::fromJson(json json_input) {
  for (string field : {"id", "name", "cost", "diameter"}) {
    if (json_input[field] == NULL) return;
  }
  m_id = json_input["id"];
  m_name = json_input["name"];
  m_cost = json_input["cost"];
  m_diameter = json_input["diameter"];
}

string Spool::toJson() {
  json j_map = {
    to_string(m_id), {
      {"name", m_name},
      {"cost", to_string(m_cost)},
      {"diameter", to_string(m_diameter)},
    }
  };
  return j_map.dump();
}