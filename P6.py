def is_complete_graph(graph,num_vertices):
    for i in range(num_vertices):
        for j in range(num_vertices):
            if i!=j and graph[i][j] != 1:
                return False
    return True

#main
graph = []
num_vertices = int(input("Enter the number of vertices present in the graph : "))
print()
for i in range(num_vertices):
    rows = []
    for j in range(num_vertices):
        cell = int(input(f'Enter the value of {i,j} : '))
        rows.append(cell)
    graph.append(rows)
print('\nAdjacency Matrix representation : ')
print(f'{graph}\n')
if(is_complete_graph(graph,num_vertices)):
    print("Enetered graph is a complete graph.")
else:
    print("Entered graph is not a complete graph.")

