from array import array
from random import randrange
import time

#=========================[SETTINGS]=========================
total_range = 100 #settings in integer (1, 4, 9, 16, 25, 36, 49... (1*1, 2*2...) (max. 1.000.000))
ones_in_range = 20 #in percent (1 to 100)
#=========================[SETTINGS]=========================

for x in range(100):
    print()

l = "[log]"
e = '[error]'

print(l, 'software:', __file__)
print(l, 'total range size: ', total_range)

floor = []
counter = 0
for x in range(total_range):
    floor.append(0)  #create array with 100 insides

int_total_range = int(total_range / 2) #float to integer because for loop can not loop 1.5 times
counter = 0

ones_perc = int(ones_in_range * (total_range / 100))
print(l, ones_in_range, 'percent equal', ones_perc, 'ones inside range out of', total_range)

checker = 0
for x in range(100000): #randomizer for ones
    pos_random = randrange(total_range)
    checker += 1
    if floor[pos_random] == 1: #check if one blockes already the position
        checker -= 1
    else:
        floor[pos_random] = 1
    if checker == ones_perc:
        break

temper = 0
works = []
possible = 0
for x in range(1000): #if range is true and can be resolved without calculating
    works.append(x * x)
    if total_range == works[x]:
        rows_calculation = x #creates perfect block shape
        print(l, 'range found at:', total_range, '-', x, '*', x)
        possible = 1
        temper = x

if possible == 0: #finding nearest range if the range is wrong
    print(e, 'settings wrong, range not found, calculating nearest...')
    for x in range(1000):
        if works[x] > total_range:
            total_range = works[x]
            rows_calculation = x #creates perfect block shape
            print(l, 'new range found at:', total_range, 'for', x, '*', x)
            possible = 1
            break

#ERROR WONT WORK WITH WRONG ENTERED RANGE
#new test (find three ones in a row)
threec = 0
for x in range(total_range):
    if (x < total_range - 2):
        if (floor[x] == 1 and floor[x + 1] == 1 and floor[x - 1] == 1):
            if (floor[x + 2] == 0):
                threec += 1

if possible == 1:
    for x in range(total_range): #print out matrix
        floor.append(0)
        if counter == rows_calculation:
            counter = 0
            print()
        print(floor[x], end = ' ')
        counter += 1
else:
    print(e, 'can not resolve settings')

print('\rtotal three rows:', threec)

counter_rc1 = 0
#ones at 'x' row number: 1
for x in range(int(total_range / temper)):
    if (floor[x * temper] == 1):
        counter_rc1 += 1
print('total ones in x-row 1:', counter_rc1)

#GLITCH NEEDS TO BE POLISHED - unnused
#above combined for row 3 and 4
counter_switch = 0
numb_start = 3
for x in range(2): #how many rows after numb_start will be checked
    for x2 in range(int(total_range / temper)):
        if (floor[x2 * temper + numb_start] == 1):
            counter_switch += 1
    #print('total ones in x-row', numb_start, ':', counter_switch)
    counter_switch = 0
    numb_start += 1

#finding nearest zero from upper part (for row 1)
gcounter = 0
for x in range(temper):
    if (floor[x * temper] == 0):
        print('ground found at:', x + 1, 'in row 1')
        break
