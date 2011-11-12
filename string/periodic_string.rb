=begin
Strings such as "000000", "101010" and "11011101" are said periodic since they are made of
repetitions of a given pattern.
=end

def periodic_string? word

  #
  # The easiest way to deal with this is to iteratively increase the pattern,
  # one character at a time. Note that some patterns do no make sense to try
  # so we just skip them.
  #

  #
  # No point to test a pattern size bigger than half of the given word.
  #
  (0..word.size/2).each do |index|

    #
    # If the pattern size does not fit perfeclty we just skip it.
    #
    next if word.size.modulo(index+1) != 0
    nb_patterns = word.size / (index+1)
    return true if word.slice(0..index)*nb_patterns == word
  end
  false
end
