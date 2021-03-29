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
    




coins = [1,5,6,9]

sum = 10

minCoins(coins , sum)