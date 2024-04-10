from itertools import  *
class Set:
    def init(self):
        self.elements = set()
    def add_element(self, element):
        self.elements.add(element)
    def is_member(self, element):
        return element in self.elements
    def powerset(self):
        all_subsets = [[]]
        for element in self.elements:
            all_subsets += [subset + [element] for subset in all_subsets]
        return all_subsets
    def subset(self, other_set):
        return all(element in other_set.elements for element in self.elements)
    def union(self, other_set):
        return Set.from_list(list(self.elements) + list(other_set.elements))
    def intersection(self, other_set):
        return Set.from_list([element for element in self.elements if element in other_set.elements])
    def complement(self, universal_set):
        return Set.from_list([element for element in universal_set.elements if element not in self.elements])
    def set_difference(self, other_set):
        return Set.from_list([element for element in self.elements if element not in other_set.elements])

    def symmetric_difference(self, other_set):
        return Set.from_list([element for element in self.elements if element not in other_set.elements] +
                             [element for element in other_set.elements if element not in self.elements])

    def cartesian_product(self, other_set):
        cartesian_product_set = Set()
        for element1 in self.elements:
            for element2 in other_set.elements:
                cartesian_product_set.add_element((element1, element2))
        return cartesian_product_set

    @classmethod
    def from_list(cls, elements):
        new_set = Set()
        for element in elements:
            new_set.add_element(element)
        return new_set

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
set1 = Set()
set2 = Set()
universal_set = Set()

while True:
    menu()
    choice = int(input("Enter your choice: "))
    
    if choice == 1:
        element = input("Enter element to add to set: ")
        set1.add_element(element)
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
        print("Union:", set1.union(set2).elements)
    elif choice == 6:
        print("Intersection:", set1.intersection(set2).elements)
    elif choice == 7:
        print("Complement of Set 1:", set1.complement(universal_set).elements)
    elif choice == 8:
        print("Set difference:", set1.set_difference(set2).elements)
    elif choice == 9:
        print("Symmetric difference:", set1.symmetric_difference(set2).elements)
    elif choice == 10:
        print("Cartesian product:", set1.cartesian_product(set2).elements)
    elif choice == 11:
        print("Exiting program.")
        break
    else:
        print("Invalid choice. Please enter a number between 1 and 11.")