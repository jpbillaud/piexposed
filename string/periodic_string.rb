=begin
Strings such as "000000", "101010" and "11011101" are said periodic since they are made of
repetitions of a given pattern.
=end

def periodic_string? string
  #
  # The easiest way to deal with this is to compare the string with a shifted
  # version of itself. When the shifted version equals to the original string,
  # then the string is periodic with a period equals to the number of 
  # shifts + 1.
  #

  string_to_a = string.chars.to_a

  (0..string.size/2).inject(string.chars.to_a) do |shift_string, period|
    return [true, period + 1] if shift_string.rotate! == string_to_a
    shift_string
  end
  return [false, -1]
end
