=begin
Given a string consisting of a, b and c's, we can perform the following operation:
Take any two adjacent distinct characters and replace it with the third character.

For example, if 'a' and 'c' are adjacent, they can be replaced with 'b'. What is the
smallest string which can result by applying this operation repeatedly?

Sample Input:
3
cab
bcab
ccccc

Sample Output:
2
1
5
=end

def string_reduct word

  #
  # Let's build a map of the word as regions of characters.
  #
  map = word.chars.chunk do |c|
    c
  end.map do |c,a|
    { :char => c, :occurence => a.size }
  end

  map.inject([0,0]) do |(index, start_index), entry|
    entry[:index] = index
    entry[:start_index] = start_index

    [index+1, start_index+entry[:occurence]]
  end

  #
  # Bail out if we were able to detect only a single region.
  #
  return map.first[:occurence] if map.size == 1

  #
  # Select the most populated region and find its direct most populated neighbor.
  #
  region = map.max do |x,y|
    x[:occurence] <=> y[:occurence]
  end

  left_neighbor = map.at((region[:index]-1).abs) || { :occurence => -1 }
  right_neighbor = map.at(region[:index]+1) || { :occurence => -1 }

  neighbor = [ right_neighbor, left_neighbor ].max do |x,y|
    x[:occurence] <=> y[:occurence]
  end

  #
  # Insert the character resulting from the reduction
  #
  word_chars = word.split(//)

  region[:occurence] -= 1
  neighbor[:occurence] -= 1

  if region[:index] > neighbor[:index]
    word_chars.delete_at(region[:start_index] + region[:occurence])
    word_chars.delete_at(neighbor[:start_index] + neighbor[:occurence])
    insert_index = neighbor[:start_index] + neighbor[:occurence]
  else
    word_chars.delete_at(neighbor[:start_index] + neighbor[:occurence])
    word_chars.delete_at(region[:start_index] + region[:occurence])
    insert_index = region[:start_index] + region[:occurence]
  end

  #
  # Call recursively with the resulting reducted word
  #
  string_reduct word_chars.insert(insert_index, (["a", "b", "c"] - [region[:char], neighbor[:char]]).first).join
end

1.upto ARGF.gets.strip.to_i do
  puts "#{string_reduct ARGF.gets.strip}"
end
