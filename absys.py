t=int(input())

while t>0:
    nothing=input()
    expression=input()
    numbers=expression.split(" ")
    #print(numbers)
    if numbers[0].isnumeric() and numbers[2].isnumeric():# if both string on left is isnumeric then convert them to string and add them and u are done
        numbers[4]=str(int(numbers[0])+int(numbers[2]))

    elif numbers[0].isnumeric() or numbers[2].isnumeric(): # if only one of them is only numeric
        if numbers[0].isnumeric():
            numbers[2]=str(int(numbers[4])-int(numbers[0]))
        else:
            numbers[0]=str(int(numbers[4])-int(numbers[2]))
    t=t-1
    number=' '.join(numbers)
    print(number)