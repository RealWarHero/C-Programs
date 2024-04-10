from itertools import chain, combinations, product

class SET:
    def init(self):
        self.elements = set()

    def is_member(self, element):
        return element in self.elements

    def powerset(self):
        return list(chain.from_iterable(combinations(self.elements, r) for r in range(len(self.elements)+1)))

    def subset(self, other_set):
        return self.elements.issubset(other_set.elements)

    def union(self, other_set):
        return self.elements.union(other_set.elements)

    def intersection(self, other_set):
        return self.elements.intersection(other_set.elements)

    def complement(self, universal_set):
        return universal_set.elements.difference(self.elements)

    def set_difference(self, other_set):
        return self.elements.difference(other_set.elements)

    def symmetric_difference(self, other_set):
        return self.elements.symmetric_difference(other_set.elements)

    def cartesian_product(self, other_set):
        return set(product(self.elements, other_set.elements))

# Menu driven program
def menu():
    print("1. Add element to set")
    print("2. Check if element is member")
    print("3. List powerset")
    print("4. Check if one set is subset of another")
    print("5. Union of two sets")
    print("6. Intersection of two sets")
    print("7. Complement of a set")
    print("8. Set difference")
    print("9. Symmetric difference")
    print("10. Cartesian product")
    print("11. Exit")

# Example usage:
set1 = SET()
set2 = SET()
universal_set = SET()

while True:
    menu()
    choice = int(input("Enter your choice: "))
    
    if choice == 1:
        element = input("Enter element to add to set: ")
        set1.elements.add(element)
    elif choice == 2:
        element = input("Enter element to check membership: ")
        print("Is member:", set1.is_member(element))
    elif choice == 3:
        print("Powerset:", set1.powerset())
    elif choice == 4:
        if set1.subset(set2):
            print("Set 1 is a subset of Set 2.")
        else:
            print("Set 1 is not a subset of Set 2.")
    elif choice == 5:
        print("Union:", set1.union(set2))
    elif choice == 6:
        print("Intersection:", set1.intersection(set2))
    elif choice == 7:
        print("Complement of Set 1:", set1.complement(universal_set))
    elif choice == 8:
        print("Set difference:", set1.set_difference(set2))
    elif choice == 9:
        print("Symmetric difference:", set1.symmetric_difference(set2))
    elif choice == 10:
        print("Cartesian product:", set1.cartesian_product(set2))
    elif choice == 11:
        print("Exiting program.")
        break
    else:
        print("Invalid choice. Please enter a number between 1 and 11.")