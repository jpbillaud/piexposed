#!/usr/bin/ruby

=begin
Write a function that computes a nth fibonacci number defined by:

F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1
=end

=begin
The naive way does not use dynamic programming which incurs an
exponential complexity. With dynamic programming we get a polynomial
complexity.
=end

@m = {}
def fibonacci n
  return 0 if n == 0
  return 1 if n == 1
  return @m[n] if @m.has_key? n
  @m[n] = fibonacci(n-1) + fibonacci(n-2)
  return @m[n]
end
