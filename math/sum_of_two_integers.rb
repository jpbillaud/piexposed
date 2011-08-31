#!/usr/bin/ruby

=begin
Write a program that takes a list of integers and a target number and determines
if any two integers in the list sum to the target number. If so, return the two
numbers. If not, return an indication that no such integers exist.
=end

@nums = [ 1, 4, 7, 3, 2, 1 ]

def sum_of_two_integers nums, target

  # We start sorting the array in nlog(n)
  @nums.sort!

  # Then we take the lowest and highest element of the list and do the sum in n:
  # 1- If the sum is higher than target then we remove the highest element
  #    and do the next iteration
  # 2- If the sum is lower than target then we remove the lowest element and
  #    and do the next iteration
  # 3- If the sums is on the target then we return a tuple

  while !@nums.empty? do
    case @nums.first + @nums.last
    when target then return [ @nums.first, @nums.last ]
    when 0..target-1 then @nums.pop
    else @nums.slice! -1
    end
  end
end
