=begin
The "flowers" problem (challenge from www.interviewstreet.com)

You and your K-1 friends want to buy N flowers. Flower number i has cost ci.
Unfortunately the seller does not like a customer to buy a lot of flowers, so he
tries to change the price of flowers for customer who had bought flowers before.
More precisely if a customer has already bought x flowers, he should pay
(x+1)*ci dollars to buy flower number i.
You and your K-1 firends want to buy all N flowers in such a way that you spend
the as few money as possible.

Input:

   The first line of input contains two integers N and K.
   next line contains N positive integers c1,c2,...,cN respectively.

   Output:

   Print the minimum amount of money you (and your friends) have to pay in order
   to buy all n flowers.

Sample output :

   3 3
   2 5 6

Sample output :

   13

Explanation :
   In the example each of you and your friends should buy one flower. In this
   case you have to pay 13 dollars.

   Constraint :

   1 <= N, K  <= 100
   Each ci is not more than 1000,000
=end

nb_flowers, nb_friends = ARGF.gets.strip.split.map { |x| x.to_i }

flowers = ARGF.gets.strip.split.map { |x| x.to_i }.sort.reverse
friends = [ { :nb_flower => 0, :cost => 0} ] * nb_friends

# Simple greedy approach we just sort the flowers per cost in a decreasing
# order and distribute them one by one to each friend in a round robin manner
# so that the most expensive flowers hit a very small cost penalty
flowers.each do |flower|

   friend_nb_flower = friends[0][:nb_flower]
   friend_cost = friends[0][:cost]

   friends[0] = { :nb_flower => friend_nb_flower+1,
                  :cost => friend_cost + flower*(friend_nb_flower+1) }
   friends.rotate!
end

total_cost = friends.inject(0) do |sum, friend|
   sum += friend[:cost]
end

puts total_cost
