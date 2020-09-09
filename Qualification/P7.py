import sys
from enum import Enum

NORTH = "north"
WEST = "west"
SOUTH = "south"
EAST = "east"
BOTTOM = "bottom"
TOP = "top"

def roll_north(side):
  return {
    NORTH : BOTTOM,
    WEST : WEST,
    SOUTH : TOP,
    EAST : EAST,
    BOTTOM : SOUTH,
    TOP : NORTH,
  }[side]

def roll_south(side):
  return {
    NORTH : TOP,
    WEST : WEST,
    SOUTH : BOTTOM,
    EAST : EAST,
    BOTTOM : NORTH,
    TOP : SOUTH,
  }[side]

def roll_west(side):
  return {
    NORTH : NORTH,
    WEST : BOTTOM,
    SOUTH : SOUTH,
    EAST : TOP,
    BOTTOM : EAST,
    TOP : WEST,
  }[side]

def roll_east(side):
  return {
    NORTH : NORTH,
    WEST : TOP,
    SOUTH : SOUTH,
    EAST : BOTTOM,
    BOTTOM : WEST,
    TOP : EAST,
  }[side]

def roll_func(direction):
  return {
    NORTH : roll_north,
    SOUTH : roll_south,
    WEST : roll_west,
    EAST : roll_east,
  }[direction]

count = int(sys.stdin.readline().strip())

while count:
  sides = []

  for i in range(count):
    direction = 


side = NORTH
print(side)
side = roll_north(side)
print(side)
