def compute_degrees(graph,num_vertices):
    in_degrees = [0]*num_vertices
    out_degrees = [0]*num_vertices
    for i in range(num_vertices):
        for j  in range(num_vertices):
            if graph[i][j]==1:
                out_degrees[i] += 1
                in_degrees[i] += 1
    return in_degrees , out_degrees

#main
graph = []
num_vertices = int(input("Enter the number of vertices in the graph : "))
print()
for i in range(num_vertices):
    rows = []
    for j in range(num_vertices):
        cell = int(input(f'Enter the value of {i,j} : '))
        rows.append(cell)
    graph.append(rows)
in_degrees , out_degrees = compute_degrees(graph,num_vertices)
print()
print("Vertex\tIn-Degree\tOut-Degree : ")
for i in range(len(graph)):
    print(f'{i}\t{in_degrees[i]}\t\t{out_degrees[i]}')