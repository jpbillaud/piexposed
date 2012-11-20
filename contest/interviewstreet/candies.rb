=begin
The "candies" problem (challenge from www.interviewstreet.com)

Alice is a kindergarden teacher. She wants to give some candies to the children
in her class.  All the children sit in a line and each  of them  has a rating
score according to his or her usual performance.  Alice wants to give at least
1 candy for each child. Children get jealous of their immediate neighbors, so if
two children sit next to each other then the one with the higher rating must get
more candies. Alice wants to save money, so she wants to minimize the total
number of candies.
 
 
Input
 
The first line of the input is an integer N, the number of children in Alice's
class. Each of the following N lines contains an integer indicates the rating of
each child.
 
Ouput
 
Output a single line containing the minimum number of candies Alice must give.
    
Sample Input
 
3
1
2
2
 
Sample Ouput
 
4
 
Explanation
 
The number of candies Alice must give are 1, 2 and 1.
    
Constraints:
    
N and the rating  of each child are no larger than 10^5.
=end

nb_kids = ARGF.gets.strip.to_i

kids = [0]
candies = [0]

#
# Naive n^2 approach where the next kid in line gets one candy more than the
# previous one if the previous kid in line as lesser grade. If the previous kid
# has better grade then the next kid in line gets a single candy and we move
# backward adding candies to each each kids on the way until the candies
# distribution is fair based on grades.
#
1.upto nb_kids do |idx|
   kids << ARGF.gets.strip.to_i

   (candies[idx] = candies[idx-1]+1; next) if kids[idx] > kids[idx-1]

   candies[idx] = 1

   (idx-1).downto 1 do |pidx|
      break if kids[pidx] <= kids[idx]
      break if candies[pidx] > candies[idx]

      candies[pidx] += 1
      idx = pidx
   end
end

puts candies.reduce(:+)
