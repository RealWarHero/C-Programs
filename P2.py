class Relation:
    def __init__(self,matrix):
        self.matrix = matrix
    def is_reflexive(self):
        for i in range(len(self.matrix)):
            if self.matrix[i][i]!=1:
                return False
        return True
    def is_symmetric(self):
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[0])):
                if self.matrix[i][j]!=self.matrix[j][i]:
                    return False
        return True
    def is_antisymmetric(self):
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[0])):
                if i!=j and self.matrix[i][j]==1 and self.matrix[j][i]==1:
                    return False
        return True
    def is_transitive(self):
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[0])):
                if self.matrix[i][j]==1:
                    for k in range(len(self.matrix[0])):
                        if self.matrix[j][k]==1 and self.matrix[i][k]!=1:
                            return False
        return True
    def is_equivalence(self):
        if self.is_reflexive() and self.is_symmetric() and self.is_transitive():
            return True
        else:
            return False
    def is_partialorder(self):
        if self.is_reflexive() and self.is_antisymmetric()  and self.is_transitive():
            return True
        else:
            return False
#main
matrix = []
print("Enter the elements of a 3x3 matrix....\n")
for i in range(3):
    row = []
    for j in range(3):
        elem = int(input(f"Enter element at position ({i+1},{j+1}): "))
        row.append(elem)
    matrix.append(row)
rln = Relation(matrix)
if(rln.is_equivalence()):
    print("Entered relation is an equivalence relation")
else:
    print("Entered relation is not an equivalence relation")
if(rln.is_partialorder()):
    print("Entered relation is a partial order relation")
else:
    print("Entered relation is not a partial order relation")
print("Printing the entered matrix....")
for row in matrix:
    for elem in row:
        print(elem," ",end = " ")
    print() 