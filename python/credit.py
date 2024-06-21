from cs50 import get_int

def credit(num):
    x= len(str(num))
    num=str(num)
    temp1=temp=temp2=0
    evensum=oddsum=total=final=0
    for i in range(x):
        if i % 2 == 0:
            temp1=int(num[i])
            temp1 *= 2
            if temp1 > 9:
                for i in range(2):
                    temp=str(temp1)
                    final += int(temp[i])

            evensum=temp1+final
            final =0
        else:
            temp2=int(num[i])
            oddsum +=temp2
    total=evensum +oddsum
    return total


number=get_int("Enter a credit card Number: ")

value=credit(number)

if (value  % 10 == 0):
    print("valid credit num ")
else:
    print("invalid credit card num")





