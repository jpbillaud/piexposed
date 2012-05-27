=begin
The "kingdom connectivity" problem (challenge from www.interviewstreet.com)

It has been a prosperous year for King Charles and he is rapidly expanding his
kingdom. A beautiful new kingdom has been recently constructed and in this kingdom
there are many cities connected by a number of one-way roads. Two cities may be
directly connected by more than one roads, this is to ensure high connectivity.

In this new kingdom King Charles has made one of the cities at his financial capital
and one as warfare capital and he wants high connectivity between these two capitals.
The connectivity of a pair of cities say city A and city B is defined as the number
of different paths from city A to city B. A path may use a road more than once if
 possible. Two paths are considered different if they do not use exactly the same
sequence of roads.

There are N cities numbered 1 to N in the new kingdom and M one-way roads.
City 1 is the monetary capital and city N is the warfare capital.

You being one of the best programmers in new kingdom need to answer the connectivity
of financial capital and warfare capital ,i.e number of different paths from
city 1 to city N.

Input Description:

First line contains two integers N and M.

Then follow M lines ,each having two integers say x and y, 1<=x,y<=N,
indicating there is a road from city x to city y.

Output Description:

Print the number of different paths from city 1 to city N modulo 1,000,000,000(10^9).
If there are infinitely many different paths print "INFINITE PATHS" (quotes are for clarity).

Sample Input:

5 5
1 2
2 4
2 3
3 4
4 5

Sample Output:

2

Sample Input:

5 5
1 2
4 2
2 3
3 4
4 5

Sample Output:

INFINITE PATHS

Constraints:

2<=N<=10,000(10^4)

1<=M<=1,00,000(10^5) 

Two cities may be connected by more than two roads and in that case those roads are to be
considered different for counting distinct paths
=end

#
# A freshly created kingdom should be empty...
#
def mk_kingdom
  {}
end

#
# This adds a road between two cities of the kingdom
#
def add_roads kingdom, cityA, cityB
  if !kingdom.has_key? cityA
    kingdom[cityA] = [ cityB ]
  else
    kingdom[cityA].push cityB
  end
end

def find_path_rec kingdom, source, destination, discovered, paths_from_city, loop_cities

  # If we reach the destination then we found a path
  return 1 if source == destination

  # If we reach a leaf then no path was found through here
  return 0 if !kingdom.has_key? source

  # Otherwise we do a DFS with backtracking
  kingdom[source].each do |city|

    #
    # If we reach back to a city already discovered then we have a loop in
    # our kingdom. Note that it is not sure that "INFINITE PATHS" applies here
    # since we don't know if this loop is somewhat connected to some path
    # that can reach the destination
    #
    (loop_cities.push city; next) if discovered.include? city

    # The city is marked as discovered
    discovered.push city

    #
    # Maybe we already went through this city in the past in which case we cached
    # the number of paths going down that road
    if paths_from_city.has_key? city
      nb_path = paths_from_city[city]
    else
      # Otherwise we call down recursively with the new city
      nb_path = find_path_rec kingdom, city, destination, discovered, paths_from_city, loop_cities
    end

    #
    # Depending the number of paths found down that path we increment the number of paths
    # of the source
    #
    paths_from_city[source] = 0 if !paths_from_city.has_key? source
    if nb_path
      paths_from_city[source] += nb_path
    end

    #
    # If the source is able to reach the destination one way or another and it also creates
    # a loop with some city then we have an "INFINITE PATHS" case
    #
    (puts "INFINITE PATHS"; exit) if paths_from_city[source] > 0 and loop_cities.include? source

    #
    # Backtracking happens here where we unmark the traversedcity so that it can be reachable
    # through another path
    #
    discovered.pop
  end

  #
  # Whatever is the number of paths reported at the source we bring it one layer up to do the
  # right accounting at the parent of the local source.
  #
  paths_from_city[source]
end

def find_paths kingdom, source, destination
  paths_from_cities = {}
  find_path_rec kingdom, source, destination, [source], paths_from_cities, []
  paths_from_cities[source].modulo(10**9)
end

#
# Let's get the number of cities & roads and create the matching kingdom
#
cities, roads = ARGF.gets.strip.split.map { |x| x.to_i }
kingdom = mk_kingdom
1.upto roads do
  add_roads kingdom, *ARGF.gets.strip.split.map { |x| x.to_i }
end

#
# Find the number of paths to go from the city 1 to city N
#
puts "#{find_paths kingdom, 1, cities}"
