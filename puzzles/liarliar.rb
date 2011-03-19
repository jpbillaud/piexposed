#!/usr/bin/ruby

class Member
  attr_reader :name
  attr_reader :liars

  def initialize name
    @name = name
    @liars = Array.new
  end

  def << liar
    @liars << liar
  end

  def == other
    @name == other.name
  end
end

@members = Array.new

# parsing 

def parse_members
  open ARGV.first do |f|
    
    nb_members = f.gets.strip.to_i
  
    1.upto nb_members do |number|
      
      # <accuser name> <m>
      pattern = /(\w+)\s+(\d+)/
      pattern =~ f.gets.strip
      match = Regexp.last_match
      
      member_name = match[1]
      nb_liars = match[2].to_i
      
      puts "deal with #{member_name}"
      
      member = members.find member_name
      if member == nil
        member = Member.new member_name
        members << member
      end
      
      1.upto nb_liars do
        liar_name = f.gets.strip
        
        liar = members.find liar_name
        if liar == nil
          liar = Member.new liar_name
          members << liar
        end
        
        member << liar
      end    
    end
  end
end
  
def 

def closure
  puts "#{max} #{min}"
end
