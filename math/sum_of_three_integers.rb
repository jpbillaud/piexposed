#!/usr/bin/ruby

=begin
Write a program that takes a list of integers and a target number and determines
if any three integers in the list sum to the target number. If so, return the three
numbers. If not, return an indication that no such integers exist.
=end

@nums = [ 1, 4, 7, 3, 2, 1 ]

def sum_of_three_integers target

  # We start sorting the array in nlog(n)
  @nums.sort!

  #
  # We need to find a+b+c=target. The way to solve this is to go through
  # each element of the array and try to find two other integers in the list
  # that add up to the difference between target and the traversed
  # element. This is something we already solve in sum_of_two_integers.rb.
  #
  # For instance, if the target is 11 and the current traversed element of the
  # array is 1, then we need to find two integers in the remaining list such
  # as a+b=10.
  #
  (0..@nums.size-1).each do |idx|

    subtarget = target - @nums[idx]
    cnums = @nums.dup
    cnums.delete_at idx

    # Then we take the lowest and highest element of the list and do the sum in n:
    # 1- If the sum is higher than target then we remove the highest element
    #    and do the next iteration
    # 2- If the sum is lower than target then we remove the lowest element and
    #    and do the next iteration
    # 3- If the sums is on the target then we return a tuple
    
    while cnums.size != 1 do
      case cnums.first + cnums.last
      when subtarget then return [ @nums[idx], cnums.first, cnums.last ]
      when 0..target-1 then cnums.slice! 0
      else cnums.slice! -1
      end
    end

  end
  nil
end
