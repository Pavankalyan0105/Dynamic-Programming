
#function that gives the mimimum noof coins required

def minCoins(coins , sum):
    rows = len(coins)
    cols = sum+1

    table = [[0 for j in range(cols)] for i in range(rows)]

    for i in range(0 , rows):
        table[i][0] = 0

    for i in range(1, cols):
        table[0][i] = i//coins[0]


    for i in range(1 , rows):
        for j in range(1 , cols):
            if(coins[i]>j):
                table[i][j] = table[i-1][j]
            else:
                table[i][j] = min(table[i-1][j],1+table[i][j-coins[i]])

        


    for i in table:
        print(i)

    print("Hence the minimum no:of coins required are  ::: " , table[rows-1][cols-1])


    res_coins = []
    i = rows-1
    j = cols-1

    while i>0 and j>0:

        if (table[i][j] == table[i-1][j]):
            i = i-1
        else:
            res_coins.append(coins[i])
            j = j - coins[i]


    print("And the coins are   " , res_coins)
    




coins = [1,5,6,9]

sum = 10

minCoins(coins , sum)