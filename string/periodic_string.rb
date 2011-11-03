=begin
Strings such as "000000", "101010" and "11011101" are said periodic since they are made of
repetitions of a given pattern.
=end

def periodic_string? word

  #
  # The easiest way to deal with this is to iteratively increase the pattern,
  # one character at a time. The implementation below is not efficient because
  # it is going through the entire word every single time due to gsub, while in reality
  # we should stop as soon as the pattern is not replicated.
  #
  (0..word.size/2).each do |index|
    return true if word.gsub(/#{word.slice(0..index)}/, "").empty?
  end
  false
end
