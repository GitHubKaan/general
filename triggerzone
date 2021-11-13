from random import randrange

o = '[LOG]'
s = '[FINAL]'

print(o, 'software start: ' + __file__)

#=========================[SETTINGS]=========================
corpoint1_x = 0 #coordinate point value 1/2 for room
corpoint1_y = 0
corpoint1_z = 0

corpoint2_x = 5 #coordinate point value 2/2 for room
corpoint2_y = 5
corpoint2_z = 5

targpoint_x = 2 #coordinate point value for target
targpoint_y = 3
targpoint_z = 2
#=========================[SETTINGS]=========================

pos = [corpoint1_x, corpoint2_x, corpoint1_y, corpoint2_y, corpoint1_z, corpoint2_z]
final = [0, 0, 0, 0, 0, 0]
targ = [targpoint_x, targpoint_y, targpoint_z]

for x in range(3): #sorts in final like this: max, min, max, min, max, min
    switch = x * 2
    if pos[0 + switch] > pos[1 + switch]:
        final[switch] = pos[0 + switch]
        final[switch + 1] = pos[0 + switch + 1]
    else:
        final[switch] = pos[0 + switch + 1]
        final[switch + 1] = pos[0 + switch]

final_counter = 0 #validation if target is inside range from min to max
for x in range(3):
    switch2 = x * 2
    if targ[x] < final[switch2] and targ[x] > final[switch2 + 1]:
        final_counter += 1

if final_counter == 3: #if 3 than target is inside line x, y and z
    print(s, 'object is inside range')
else:
    print(s, 'object is outside range')
