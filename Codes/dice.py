import random 
# [-----------]
# [           ]
# [           ]
# [           ]
# [-----------]
def printDice(n):
    if n == 1:
        print('[-----------]')
        print('[           ]')
        print('[     O     ]')
        print('[           ]')
        print('[-----------]')
    elif n == 2:
        print('[-----------]')
        print('[           ]')
        print('[   O   O   ]')
        print('[           ]')
        print('[-----------]')
    elif n == 3:
        print('[-----------]')
        print('[  O        ]')
        print('[     O     ]')
        print('[        O  ]')
        print('[-----------]')
    elif n == 4:
        print('[-----------]')
        print('[ O       O ]')
        print('[           ]')
        print('[ O       O ]')
        print('[-----------]')
    elif n ==5:
        print('[-----------]')
        print('[ O       O ]')
        print('[     O     ]')
        print('[ O       O ]')
        print('[-----------]')
    else:
        print('[-----------]')
        print('[ O   O   O ]')
        print('[           ]')
        print('[ O   O   O ]')
        print('[-----------]')

def main():
    while True:
        print("Press r to throw Dice...   ",end='')
        c= input()
        if len(c)==1 and c[0]=='r':
            res = random.randrange(1,6)
            printDice(res)
        elif c[0]=='0':
            return
        else:
            print("Invalid Response")
print("This Dice thows random generated numbers, Press 'r' to start the game,'0' for Exit")
main()
print("Thank You")