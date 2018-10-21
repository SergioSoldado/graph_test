#pragma once

#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <memory>
#include <iterator>

namespace arm {

template <typename N, typename E>
class DiGraph {

 public:
  using NodesList = std::set<N>;  //! type declaration for nodes collection
  using EdgesList = std::map<N, std::map<N, E>>;  //! type declaration for edges collection

  DiGraph() = default;
  ~DiGraph() = default;

  /**
   * @brief Adds a node to the graph. If the node already is already present does nothing.
   * @param node Node to add.
   * @return false if the node was already present in the graph, true otherwise.
   */
  bool add(N node) {
    auto ret = _nodes.insert(node);
    if (!ret.second) {
      return false;
    }
    _edges[node];  // create empty entry in map
    return true;
  }

  /**
   * @brief Add nodes to the map along with edge that connecting them. If nodes were already present and already connected then the value for edge replaces the previous value.
   * @param src Node that is the edge source.
   * @param target Node that is the edge target
   * @param edge Edge that connect src to target.
   */
  void add(N src, N target, E edge) {
    add(src);
    add(target);
    _edges[src][target] = edge;
  }

  /**
   * @brief Getter for node collection.
   * @return Node collection.
   */
  const auto& getNodes() const {
    return _nodes;
  }

  /**
   * @brief Getter the edges of a specified node.
   * @param n Node to get edges for.
   * @return Node's edges.
   * @throws Exception if graph doesn't contain node.
   */
  const auto& getEdges(const N& n) const {
    return _edges.at(n);
  }

  bool isConnected(const N& src, const N& target) const {
    auto e = _edges.at(src);
    auto t = e.find(target);
    return t != e.end();
  }

  E getEdge(const N& src, const N& target) const {
    return _edges.at(src).find(target)->second;
  }

 private:
  NodesList _nodes;
  EdgesList _edges;
};

}  // namespace arm
