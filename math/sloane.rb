#!/usr/bin/ruby
# -*- coding: utf-8 -*-

=begin
The "Look and Say" sequence, Sloane number A005150, begins 1, 11, 21, 1211,
111221, 312211, 13112221, 1113213211, ... Each term is constructed from its
predecessor by stating the frequency and number of each group of like digits.
For instance, the term after 1211 is ´one 1, one 2, and two 1s¡, or 111221.
=end

sloane = [1]
puts sloane.inspect

8.times.each do |iteration|
  new_sloane = []
  rep_digit = 1  

  last_sum = sloane.inject(0) do |sum, digit|
    next sum + 1 if digit == rep_digit

    new_sloane << rep_digit
    new_sloane << sum
    rep_digit = digit
    1
  end

  new_sloane << rep_digit
  new_sloane << last_sum

  puts sloane.replace(new_sloane).reverse.inspect
end
