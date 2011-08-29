#!/usr/bin/ruby

=begin
Given a rod of length n inches and a table of prices for i = 1, 2, . . . , n 
determine the maximum revenue obtainable by cutting up the rod and selling the
pieces.
=end

@sizes = [ 0, 1, 2, 3, 4, 5, 6, 7, 8 ]
@prices = [ 0, 1, 5, 8, 9, 10, 17, 17, 20 ]
@result = [ 0 ]

=begin
Solved in a bottom-up fashion using Dynamic Programming. The idea is to
compute the best cutting price starting from size 1 and moving up to the desired
size. This technique is called "memoization" and prevent computation to be
duplicated which would definitely happen if you use the naive way to solve
this.
=end

def rod_cutting size
  (1..size).each do |i|
    @result[i] = @prices[i]

    (1..i/2).each do |j|
      @result[i] = [ @result[i], @result[j] + @result[i - j] ].max
    end
  end

  @result[size]
end
