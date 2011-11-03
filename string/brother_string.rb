=begin
Strings such as "abc" and "cab", "aabb" and "baab" are called brother strings since
they contain the same characters.
=end

=begin
Some sort of counting is the best way to go to solve this.
=end

def brother_string? str1, str2
  str1.chars.group_by { |elt| elt } == str2.chars.group_by { |elt| elt }
end
