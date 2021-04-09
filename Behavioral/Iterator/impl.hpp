#pragma once

#include <string>
#include <list>
#include <memory>
#include <stack>
#include <unordered_map>

class Graph
{
  struct Vertex;

  using vertex_sptr = std::shared_ptr<Vertex>;
  using vertex_wptr = std::weak_ptr<Vertex>;

  using vertex_list = std::list<vertex_sptr>;
  using edge_list = std::list<vertex_wptr>;

  struct Vertex
  {
    std::string name;
    edge_list edges;
  };


public:
  using size_type = vertex_list::size_type;
  using value_type = vertex_sptr;

  class DfsIterator
  {
  public:
    explicit DfsIterator(value_type vertex);

    friend bool operator!= (const DfsIterator& lhs, const DfsIterator& rhs);

    DfsIterator& operator++ ();

    value_type operator* ();

  private:
    value_type vertex_;
    std::stack<value_type> previous_;
    std::unordered_map<value_type, bool> visited_;
  };

  size_type size() const;

  value_type add_vertex(const std::string& name);
  void add_edge(value_type from, value_type to);

  DfsIterator begin();
  DfsIterator end();

private:
  vertex_list vertices_;
};