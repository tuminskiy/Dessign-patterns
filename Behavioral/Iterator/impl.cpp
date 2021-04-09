#include "impl.hpp"

#include <algorithm>
#include <iostream>

auto Graph::size() const -> size_type { return vertices_.size(); }

auto Graph::add_vertex(const std::string& name) -> value_type
{
  auto vertex = std::make_shared<Vertex>();
  vertex->name = name;

  vertices_.push_back(vertex);
  return vertex;
}

void Graph::add_edge(value_type from, value_type to) { from->edges.push_back(to); }

auto Graph::begin() -> DfsIterator
{
  return vertices_.empty() ? DfsIterator{nullptr} : DfsIterator{vertices_.front()};
}

auto Graph::end() -> DfsIterator { return DfsIterator{nullptr}; }


Graph::DfsIterator::DfsIterator(value_type vertex) : vertex_(vertex) { }

bool operator!= (const Graph::DfsIterator& lhs, const Graph::DfsIterator& rhs)
{
  return lhs.vertex_ != rhs.vertex_;
}

auto Graph::DfsIterator::operator++ () -> DfsIterator&
{
  if (!vertex_)
    return *this;

  visited_[vertex_] = true;
  previous_.push(vertex_);

  const auto not_visited = [&](vertex_wptr v_wptr) { return !visited_[v_wptr.lock()]; };

  auto it = std::find_if(vertex_->edges.begin(), vertex_->edges.end(), not_visited);

  if (it != vertex_->edges.end()) {
    vertex_ = it->lock();
    return *this;
  }

  while (!previous_.empty()) {
    auto prev_vertex = previous_.top();

    it = std::find_if(prev_vertex->edges.begin(), prev_vertex->edges.end(), not_visited);

    if (it != prev_vertex->edges.end()) {
      vertex_ = it->lock();
      return *this;
    }

    previous_.pop();
  }

  vertex_ = nullptr;
  return *this;
}

auto Graph::DfsIterator::operator* () -> value_type { return vertex_; }



int main()
{
    Graph graph;

    auto vertex_0 = graph.add_vertex("0");
    auto vertex_1 = graph.add_vertex("1");
    auto vertex_2 = graph.add_vertex("2");
    auto vertex_3 = graph.add_vertex("3");
    auto vertex_4 = graph.add_vertex("4");
    auto vertex_5 = graph.add_vertex("5");
    auto vertex_6 = graph.add_vertex("6");

    graph.add_edge(vertex_0, vertex_1);
    graph.add_edge(vertex_0, vertex_3);
    graph.add_edge(vertex_0, vertex_6);

    graph.add_edge(vertex_1, vertex_2);
    graph.add_edge(vertex_1, vertex_5);

    graph.add_edge(vertex_2, vertex_4);
    graph.add_edge(vertex_2, vertex_0);

    graph.add_edge(vertex_3, vertex_0);
    graph.add_edge(vertex_3, vertex_4);

    graph.add_edge(vertex_4, vertex_0);

    for (auto vertex : graph) {
        std::cout << vertex->name << " ";
    }
    // Outout: 0 1 2 4 5 3 6

    return 0;
}