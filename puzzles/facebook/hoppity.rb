#!/usr/bin/ruby

=begin
Dear submitter,

Thank you for your test submission of a puzzle solution to Facebook! After running your solution to hoppity (received on February 24, 2011, 5:08 pm), I have determined it to be correct. Since your test has been successful, you are all set to try one of the other puzzles. Best of luck!

Sincerely,
-The puzzle robot
=end

arg = open ARGV.first do |f|
  f.gets.strip.to_i
end

1.upto(arg) do |number|   
  case
  when number.modulo(3) == 0 && number.modulo(5) == 0 then puts "Hop"
  when number.modulo(3) == 0 then puts "Hoppity"
  when number.modulo(5) == 0 then puts "Hophop"
  end
end
