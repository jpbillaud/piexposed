#!/usr/bin/ruby

=begin
People often give others their telephone number as a word representing the
seven-digit number. For example, if my telephone number were 866-2665, I could
tell people my number is "TOOCOOL", instead of the hard-to-remember seven-digit
number. Note that many other possibilities (most of which are nonsensical) can
represent 866-2665.

Write a routine that takes a seven-digit telephone number and prints out all
of the possible "words" or combinations of letters that can represent the
given number. Because the 0 and 1 keys have no letters on them, you should
change only the digits 2-9 to letters. You'll be passed an array of seven
integers, with each element being one digit in the number. You may assume that
only valid phone numbers will be passed to your routine.
=end

class PhoneNumber
  @@key_letters = [ ["0"],
                    ["1"],
                    ["A", "B", "C"],
                    ["D", "E", "F"],
                    ["G", "H", "I"],
                    ["J", "K", "L"],
                    ["M", "N", "O"],
                    ["P", "Q", "R", "S"],
                    ["T", "U", "V"],
                    ["W", "X", "Y", "Z"] ]

  def initialize number
    @number = number
  end

  def to_words
    do_to_words @number, ""
  end

private

  def do_to_words(number, result)
    (puts result; return) if number.empty?    

    @@key_letters[number.first].each do |char|
      result << char
      do_to_words number.drop(1), result
      result.chop!
    end
  end
end
