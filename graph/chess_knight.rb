=begin
Given a chessboard and a knight positioned on the bottom left square, provide
a method that returns a list of moves that the knight needs to execute so that
it traverses each square of the chessboard exactly once.
=end

#
# The underlying problem is an Hamiltonian Path problem which is a NP-complete
# problem. However, we don't need to go fancy to solve this and a simple graph
# depth-first traverse will do it.
#
# We assume that a graph is given to us with each vertice being a square on the
# chessboard and each edge being a move of the knight from one square to another.
#
# To solve this problem, we do a depth-first traverse starting at the bottom
# left square and we push each vertice on the way of the DFS in a stack of moves.
#
# While traversing a vertice:
#
# - If one of the adjacent vertice is already in the moves stack then it means we
# cannot go any further through this path so we try through another adjacent vertice.
#
# - If none of the next moves (adjacent vertices) attempts resulted into
# a satisfactory path then we back up one level, pop the current vertice and move
# to the next adjacent vertice.
#
# A satisfactory path is detected when a given vertice has all of its adjacent
# vertices in the moves stack and the moves stack size is equal to the number of
# vertices.
#
def find_knight_moves graph, init_vertice
  found_path, moves = traverse_vertice(graph, init_vertice, [])
  return moves if found_path
  nil
end

def traverse_vertice graph, vertice, moves
  moves.push vertice
  vertice.edges.each do |adj_vertice|
    next if moves.include? adj_vertice
    moves.pop if !traverse_vertice(graph, adj_vertice, moves).first
    break
  end

  [ moves.size == graph.vertices.size, moves]
end

