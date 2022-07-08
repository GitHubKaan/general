from random import randrange
import time
import subprocess

field = [] #create array

for x in range(9): #make 9 fields inside array
    field.append(0)


switcher = randrange(1)
random_field = 0

for x in range(9): #this is for every play
    counter = x+1


    

    #THIS PLACE IS FOR THE AI PART - TACTICAL MOVES
    #(counter) COUNTS EVERY MOVE +1
    #(switcher) (dont use)THE SWITCHER STARTS AUTOMATICALLYWITH 0 OR 1
    #THE SWITCHER SWITCHES EVERY ROUND AUTOMATICALLY
    #(random_field) IS THE POSITION THE SWITCHER ADDS LATER ON THE CHOSEN PLAYER
    #-------------------------------------------------------------------------
    
    for x in range(10000):#random field that is empty
        random_field = randrange(9)
        if field[random_field] == 0:
            break
        
    #-------------------------------------------------------------------------



        
    if switcher == 0:
        field[random_field] = 1 #player one
        switcher = 1
    else:
        field[random_field] = 2 #player two
        switcher = 0

#-down here the win detection part
    #-------------------------------------------------------------

    player_1_win = 0 #1 for win
    player_2_win = 0

#for win on all x rows
    woxsum = 0
    gencount1 = 0
    nowin = 0 #no win == 1
    for wox_1 in range(3):
        for wox_2 in range(3):
            woxsum += field[gencount1]
            gencount1 += 1
        for subtractor in range(3):
            if subtractor == 1:
                subtractor - 1
            if field[gencount1 - (subtractor +1)] == 0:
                nowin = 1
        if nowin == 0:
            if woxsum == 3:
                player_1_win = 1
                break
            if woxsum == 6:
                player_2_win = 2
                break
        woxsum = 0
        gencount1 = 0

#for win on all y rows
    woysum = 0
    winsave = 0
    gencount2 = 0
    for woy_1 in range(3):
        for woy_2 in range(3):
            woysum += field[gencount2 + woy_1]
            if field[gencount2 + woy_1] == 0:
                winsave = 1
            gencount2 += 3
        if winsave == 0:
            if woysum == 3:
                player_1_win = 1
                break
            if woysum == 6:
                player_2_win = 1
                break
        gencount2 = 0
        woysum = 0
        winsave = 0

#for win on x y (also quer)
    for x in range(1): #hier drauß kann man eigentlich eine while true schleife machen
        if field[0] + field[4] + field[8] == 3 and (field[0] and field[4] and field[8] != 0):
            player_1_win = 1
            break
        if field[0] + field[4] + field[8] == 6 and (field[0] and field[4] and field[8] != 0):
            player_2_win = 1
            break
        if field[2] + field[4] + field[6] == 3 and (field[2] and field[4] and field[6] != 0):
            player_1_win = 1
            break
        if field[2] + field[4] + field[6] == 6 and (field[2] and field[4] and field[6] != 0):
            player_2_win = 1
            break
        
    #-----------print out current field
    upper = 0
    for x_main in range(3):
        for x_sec in range(3):
            print(field[upper], end = ' ')
            upper += 1
        print('')
    print('')

    #winner announcement and game stop sequence
    if player_1_win != 0:
        print('player 1 won the game')
        break
    if player_2_win != 0:
        print('player 2 won the game')
        break

    #if noone won the game
    if counter == 9 and player_1_win + player_2_win == 0:
        print('noone won this round')
    
    #time.sleep(0.01) #waiter
