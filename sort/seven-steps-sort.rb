#!/usr/bin/ruby

=begin
Input: 1 2 3 4 5 6 7 8 9 10 J Q K
Output: K Q J 10 9 8 7 6 5 4 3 2 1

Write and algorithm to sort the cards in reverse order in 7 steps.
=end

@cards = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, :J, :Q, :K ]

def seven_steps_sort
  
=begin
The solution is to do seven swaps, the mid one being a stationary swap.
=end

  (0..@cards.size/2).each do |idx|
    @cards[idx], @cards[-(idx+1)] = @cards[-(idx+1)], @cards[idx]
  end
end

seven_steps_sort
