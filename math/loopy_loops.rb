#!/usr/bin/ruby

=begin
Print the numbers from 1 to 1000 without using any loop or conditional
statements. Don’t just write the printf() or cout statement 1000 times.
=end

def loopy_loops_rec idx
  puts @arr.fetch idx
  loopy_loops_rec idx+1
end

def loopy_loops
  @arr = (1..1000).to_a
  loopy_loops_rec 0
end

begin
  loopy_loops
rescue
end
