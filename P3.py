from itertools import permutations,product

def gen_permutations_repeat(digits,n):
    count = 0
    for perm in product(digits,repeat=n):
        print(*perm) #Print the list elements in a single line with spaces
        count+=1
    return count
def gen_permutations_norepeat(digits,n):
    count = 0
    for perm in permutations(digits,n):
        print(*perm)
        count+=1
    return count
#main
digits = list(input("Enter the digits: "))
repeat = input("Allow repetition? (yes/no)").lower()
if(repeat=="yes"):
    print("Permutation with repetition: ")
    t = gen_permutations_repeat(digits,len(digits))
    print("Total permutations with repetition : ",t)
else:
    print("Permutation without repetition: ")
    t1 = gen_permutations_norepeat(digits,len(digits))
    print("Total permutations without repetition : ",t1)