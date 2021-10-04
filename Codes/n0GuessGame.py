import random
win_no = random.randrange(0, 100)
print (win_no) 

guess_no = int(input("enter no. : "))
guess = 1

while True:
    if win_no==guess_no:                     
        print(f"YOU WINN!! and guess time {guess} ")
        break
        
    else:
        if win_no<guess_no:
            print("TOO HIGH!!")
            guess += 1
            guess_no = int(input("guess again : "))

        else:
            print("TOO LOW!!")
            guess += 1
            guess_no = int(input("guess again. : "))