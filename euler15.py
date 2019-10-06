# Copyright (C) 2019, Bodnar Peter, sajtos0007@gmail.com
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
import math


# to compute the solution we use binomial distribution  reflecting to the binomial model

def binomial(n, k):
    assert 0 <= k <= n
    return math.factorial(n) // (math.factorial(k) * math.factorial(n - k))


# then we get to know the size of the actual grid
print("Welcome to this simple calculator. First of all I need to ged to know the horizontal length of the grid")
a = int(input())
print("Now I need the vertical length of the grid")
b = int(input())
# from the top left corner to the bottom right corner in case of an A * B grid it takes A times B moves we know that
# n =a +  b and k = (a + b)/2
n = a + b
k = (a + b) / 2


def move():
    return str(binomial(n, k))


print(move())
