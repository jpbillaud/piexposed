=begin
The "billboards" problem (challenge from www.interviewstreet.com)

ADZEN is a very popular advertising firm in your city. In every road you can see
their advertising billboards. Recently they are facing a serious challenge,
MG Road the most used and beautiful road in your city has been almost filled by
the billboards and this is having a negative effect on the natural view.

On people's demand ADZEN has decided to remove some of the billboards in such a
way that there are no more than K billboards standing together in any part of
the road.

You may assume the MG Road to be a straight line with N billboards. Initially
there is no gap between any two adjecent billboards.

ADZEN's primary income comes from these billboards so the billboard removing
process has to be done in such a way that the billboards remaining at end should
give maximum possible profit among all possible final configurations.
Total profit of a configuration is the sum of the profit values of all billboards
present in that configuration.

Given N,K and the profit value of each of the N billboards, output the maximum
profit that can be obtained from the remaining billboards under the conditions
given.

Input description

Ist line contain two space seperated integers N and K. Then follow N lines
describing the profit value of each billboard i.e ith line contains the profit
value of ith billboard.

Sample Input
6 2
1
2
3
1
6
10

Sample Output
21

Explanation

In given input there are 6 billboards and after the process no more than 2 should
be together.
So remove 1st and 4th billboards giving a configuration _ 2 3 _ 6 10 having a
profit of 21. No other configuration has a profit more than 21.
So the answer is 21.

Constraints
1 <= N <= 1,00,000(10^5)
1 <= K <= N
0 <= profit value of any billboard <= 2,000,000,000(2*10^9)
=end

# Let's get the number of billboards (N) and grouping constraints (K)
nb_billboards, group_size = ARGF.gets.strip.split.map { |x| x.to_i }

# Keep track of best profit layout per location
best_profit = [0]

# Keep track of the current cluster and its current overall profit
cluster = [[0,-1]]
cluster_sum = 0

1.upto nb_billboards do |location|
   profit = ARGF.gets.strip.to_i

   cluster_sum += profit

   # If there is still some space in the current cluster then we just
   # push the new billboard in there
   if cluster.length < group_size
      best_profit[location] = best_profit[location-1] + profit
      cluster << [profit, location]
      next
   end

   # DP time:
   #
   # BEST_PROFIT[location] =
   # MAX(BEST_PROFIT[location-1],
   #     MAX(0<=i<=K BEST_PROFIT(LOCATION(CLUSTER(i)) - 1) + CLUSTER_SUM -
   #                 SUM(0<=j<=i PROFIT(CLUSTER(j))) + PROFIT(location)))

   # To start we assume that the current billboard won't make any better
   # profit so we don't include it and the best new cluster becomes empty
   best_profit[location] = best_profit[location-1]
   best_cluster = []
   best_cluster_sum = 0

   cluster.each_index do |index|
      billboard = cluster[index]

      # Sliding window since we are trying to split before and after this
      # billboard we remove its profit from the cluster sum
      cluster_sum -= billboard[0]

      # Split location right before this billboard
      split = [0, billboard[1] - 1].max

      # It sounds like this split improves the overall profit so keep it
      if best_profit[location] < best_profit[split] + cluster_sum
         best_profit[location] = best_profit[split] + cluster_sum

         # The new cluster is splitted right at this billboard
         best_cluster = cluster[index+1, cluster.length] << [profit, location]
         best_cluster_sum = cluster_sum
      end
   end

   # Update new best cluster
   cluster = best_cluster
   cluster_sum = best_cluster_sum
end

puts best_profit[-1]

