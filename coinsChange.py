def noofWays(coins , sum):
    rows = len(coins)
    cols = sum+1
    # table = [[0]*cols]*rows
    table = [[0 for i in range(cols)] for j in range(rows)]

    for i in table:
        print(i)
    print("-------------------------------------------------- ---------------- --------------")
    

    for i in table:
        i[0] = 1

    for i in range(cols):
        if i%coins[0]==0:
            table[0][i] = 1
        else: 
            table[0][i] = 0 

    for i in range(1, rows):
        for j in range(1 , cols):
            if coins[i]>j:
                table[i][j] = table[i-1][j]
            else:
                table[i][j] = table[i-1][j]+table[i][j - coins[i]]


    for i in table:
        print(i)
    print("No of Ways are" , table[rows-1][cols-1])


coins = [2 , 3 ,5 ,10]
sum = 7
noofWays(coins , sum)