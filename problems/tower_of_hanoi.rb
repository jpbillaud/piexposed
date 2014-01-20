#!/usr/bin/ruby

=begin
According to legend, there is a temple in Hanoi where are located sixty-four golden
rings of graduated sizes and three diamond towers.

Each day, the monks of the temple move a ring from one tower to another according to
the rule that only one ring may be moved each day, that a single move consists of taking
the highest ring from one tower and placing it on another tower, and that no ring may
be placed on top of a smaller ring.

The rings and towers were placed at the beginning of the world, and the monks have
toiled through the ages to move all the rings from the designated starting tower
to the designated finishing tower, at each day making the move that minimizes the
total number of moves required. The world will end when the monks complete their work.
=end

=begin
The intuitive idea is that to move 4 rings one has to move 3 rings, but to move 3
rings one has to move 2 rings, but to move 2 rings one has to move 1 ring...
=end

def tower_of_hanoi_rec nbRingsToMove, curTower, targetTower

  return if nbRingsToMove == 0

  bufTargetTower = ([1, 2, 3] - [curTower, targetTower]).first

  tower_of_hanoi_rec nbRingsToMove-1, curTower, bufTargetTower
  puts "Move ring #{nbRingsToMove} to tower #{targetTower}"
  tower_of_hanoi_rec nbRingsToMove-1, bufTargetTower, targetTower 
end

def tower_of_hanoi nbRings
  tower_of_hanoi_rec nbRings, 1, 3
end
